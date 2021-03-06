#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <QObject>
#include <memory>

#include "core/src/ai/ai_player.h"
#include "core/src/game/board.h"
#include "core/src/game/player.h"
#include "core/src/model/tile_shape_model.h"
#include "core/src/settings/game_settings.h"
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
    void setStateChart(statechart::Main* stateChart);

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
    /**
     * @brief Setter: lock a player thats can not move
     * @param isPlayLock: can player move or not?
     */
    void setIsPlayLock(bool isPlayLock);

    /**
     * @brief Setter: set tile shape model to current controller
     * @param tileShapeModel: model data of tiles
     */
    void setTileShapeModel(TileShapeModel* tileShapeModel);

    /**
     * @brief handleAIPlayedAt: play coordinates and lock player
     * @param row: coordinate x on board
     * @param column: coordinate y on board
     */
    void handleAIPlayedAt(unsigned int row, unsigned int column);

    /**
     * @brief handleGameDifficultyChanged: set game difficulty according to given param
     * @param difficulty: current game difficulty
     */
    void handleGameDifficultyChanged(GameDifficulty::Difficulty difficulty);

    /**
     * @brief Slot: capture when grid size changed
     * @param value: grid size
     */
    void handleGridSizeChanged(unsigned int gridSize);

    /**
     * @brief Slot: capture when player name changed
     * @param value: player name
     */
    void handleHumanPlayerNameChanged(QString playerName);

    /**
     * @brief Slot: capture when player name changed
     * @param value: player name
     */
    void handleAiPlayerNameChanged(QString playerName);

    /**
     * @brief Slot: capture when try to restart game
     */
    void handleRestartGame();

signals:
    /**
     * @brief Signal: emit signal when isPlayLock changed
     * @param value: isPlayLock
     */
    void isPlayLockChanged(bool isPlayLock);

    /**
     * @brief Signal: emit signal when aiPlayedAt
     * @param row: coordinate x on board
     * @param column: coordinate y on board
     */
    void aiPlayedAt(unsigned int row, unsigned int column);

    /**
     * @brief Signal: emit signal when updateAIPlayerOnUI
     * @param row: coordinate x on board
     * @param column: coordinate y on board
     */
    void updateAIPlayerOnUI(unsigned int row, unsigned int column);

    /**
     * @brief Signal: emit signal when game board changed
     * @param value: Board data
     */
    void gameBoardChanged(Board* gameBoard);

    /**
     * @brief Signal: emit signal when tile shape model changed
     * @param value: TileShapeModel data
     */
    void tileShapeModelChanged(TileShapeModel* tileShapeModel);

private:
    // Game settings
    GameSettings* m_gameSettings;

    // Player lock flag
    bool m_isPlayLock = false;

    // Player (Human)
    Player m_humanPlayer;

    // Player (AI)
    Player m_aiPlayer;

    // Game Board
    Board* m_gameBoard;

    // AI player
    AIPlayer* m_aiImplement;

    // Tile shape model
    TileShapeModel* m_tileShapeModel;

    // State chart
    statechart::Main* m_statechart;
};

#endif // GAME_CONTROLLER_H
