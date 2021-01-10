#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <QObject>
#include <memory>

#include "core/src/settings/game_settings.h"
#include "core/src/game/board.h"
#include "core/src/game/player.h"
#include "core/src/ai/ai_player.h"
#include "core/src/model/tile_shape_model.h"

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

        Q_INVOKABLE bool isPlayed(unsigned int row, unsigned int column);
        Q_INVOKABLE void humanPlayedAt(unsigned int row, unsigned int column);
        Q_INVOKABLE void selectShapeByIndex(unsigned int index);

        bool isPlayLock() const;

        Board* gameBoard() const;
        TileShapeModel* tileShapeModel() const;

    private:
        void initializeModels();
        void aiThinkAndPlay();

    public slots:
        void setIsPlayLock(bool isPlayLock);
        void setTileShapeModel(TileShapeModel* tileShapeModel);

        void handleAIPlayedAt(unsigned int row, unsigned int column);
        void handleGameDifficultyChanged(GameDifficulty::Difficulty difficulty);
        void handleGridSizeChanged(unsigned int gridSize);
        void handleHumanPlayerNameChanged(QString playerName);
        void handleAiPlayerNameChanged(QString playerName);

    signals:
        void isPlayLockChanged(bool isPlayLock);
        void aiPlayedAt(unsigned int row, unsigned int column);
        void updateAIPlayerOnUI(unsigned int row, unsigned int column);
        void gameBoardChanged(Board* gameBoard);
        void tileShapeModelChanged(TileShapeModel* tileShapeModel);

    private:
        GameSettings* m_gameSettings;
        //Stop A Player From Playing A Second Time Until The Lock Is Released
        bool m_isPlayLock = false;
        Player m_humanPlayer;
        Player m_aiPlayer;
        Board* m_gameBoard;
        AIPlayer* m_aiImplement;
        TileShapeModel* m_tileShapeModel;
};

#endif //GAME_CONTROLLER_H
