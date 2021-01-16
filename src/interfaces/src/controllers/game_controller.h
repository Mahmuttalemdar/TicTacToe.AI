#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <QObject>
#include <memory>

#include "core/src/settings/game_settings.h"
#include "core/src/game/board.h"
#include "core/src/game/player.h"
#include "core/src/ai/ai_player.h"
#include "core/src/model/tile_shape_model.h"
#include "statechart/Main.h"

class GameController : public QObject
{
        Q_OBJECT
        Q_PROPERTY(bool isPlayLock READ isPlayLock WRITE setIsPlayLock NOTIFY isPlayLockChanged)
        Q_PROPERTY(Board* gameBoard READ gameBoard NOTIFY gameBoardChanged)
        Q_PROPERTY(TileShapeModel* tileShapeModel READ tileShapeModel WRITE setTileShapeModel NOTIFY tileShapeModelChanged)

    public:
        /**
         * @brief C-tor
         */
        explicit GameController(GameSettings* gameSettings, QObject* parent = nullptr);

        /**
         * @brief C-tor
         */
        GameController(QObject* parent = nullptr);

        /**
         * @brief D-tor
         */
        ~GameController();

        /**
         * @brief isPlayed: Is played to this tile by a player
         * @param row : played tile row number
         * @param column : played tile column number
         * @return true: played this tile, false: not played
         */
        Q_INVOKABLE bool isPlayed(unsigned int row, unsigned int column);

        /**
         * @brief humanPlayedAt: Firing after human played a tile on board
         * @param row : played tile row number
         * @param column : played tile column number
         */
        Q_INVOKABLE void humanPlayedAt(unsigned int row, unsigned int column);

        /**
         * @brief selectShapeByIndex: On option screen, player will choose a tile type
         * @param index : index parameter on model
         */
        Q_INVOKABLE void selectShapeByIndex(unsigned int index);

        /**
         * @brief isPlayLock: Is current player can able to move a tile or not
         * @return: true: ai, false: human
         */
        bool isPlayLock() const;

        /**
         * @brief gameBoard: Storing all game logic and board data
         * @return: an instance of game board
         */
        Board* gameBoard() const;

        /**
         * @brief tileShapeModel: getter for model which is storing tile shapes
         * @return: an instance of tile shapes
         */
        TileShapeModel* tileShapeModel() const;

        /**
         * @brief setStateChart: Alias of statechart whichs is comming from entrance
         * @param stateChart: statechart::Main
         */
        void setStateChart(statechart::Main *stateChart);

    private:
        /**
         * @brief initializeModels: init function to construct all models
         */
        void initializeModels();

        /**
         * @brief aiThinkAndPlay: Get latest board and try to find best move
         */
        void aiThinkAndPlay();

    public slots:
        void setIsPlayLock(bool isPlayLock);
        void setTileShapeModel(TileShapeModel* tileShapeModel);
        void handleAIPlayedAt(unsigned int row, unsigned int column);
        void handleGameDifficultyChanged(GameDifficulty::Difficulty difficulty);
        void handleGridSizeChanged(unsigned int gridSize);
        void handleHumanPlayerNameChanged(QString playerName);
        void handleAiPlayerNameChanged(QString playerName);
        void handleRestartGame();

    signals:
        void isPlayLockChanged(bool isPlayLock);
        void aiPlayedAt(unsigned int row, unsigned int column);
        void updateAIPlayerOnUI(unsigned int row, unsigned int column);
        void gameBoardChanged(Board* gameBoard);
        void tileShapeModelChanged(TileShapeModel* tileShapeModel);

    private:
        GameSettings* m_gameSettings;
        bool m_isPlayLock = false;
        Player m_humanPlayer;
        Player m_aiPlayer;
        Board* m_gameBoard;
        AIPlayer* m_aiImplement;
        TileShapeModel* m_tileShapeModel;
        statechart::Main* m_statechart;
};

#endif //GAME_CONTROLLER_H
