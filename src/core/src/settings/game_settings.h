#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include "core/src/data/game_difficulty.h"
#include "core/src/data/tile_shape.h"

#include <QObject>
#include <QString>

/**
 * @brief The GameSettings class defined that is storing all
 * configuration types and default values
 */
class GameSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TileShape* humanTile READ humanTile WRITE setHumanTile NOTIFY humanTileChanged)
    Q_PROPERTY(TileShape* aiTile READ aiTile WRITE setAiTile NOTIFY aiTileChanged)
    Q_PROPERTY(GameDifficulty* gameDifficulty READ gameDifficulty WRITE setGameDifficulty NOTIFY gameDifficultyChanged)
    Q_PROPERTY(unsigned int gridSize READ gridSize WRITE setGridSize NOTIFY gridSizeChanged)
    Q_PROPERTY(QString humanPlayerName READ humanPlayerName WRITE setHumanPlayerName NOTIFY humanPlayerNameChanged)
    Q_PROPERTY(QString aiPlayerName READ aiPlayerName WRITE setAiPlayerName NOTIFY aiPlayerNameChanged)

public:
    /**
     * @brief C-tor
     * @param parent: constructs an object with parent object parent
     */
    GameSettings(QObject* parent = nullptr);

    /**
     * @brief C-tor
     * @param parent : QObject parent
     */
    ~GameSettings();

    /**
     * @brief Getter: get tile shape from human
     * @return value: enum value of TileShape
     */
    TileShape* humanTile() const;

    /**
     * @brief Getter: get tile shape from ai
     * @return value: enum value of TileShape
     */
    TileShape* aiTile() const;

    /**
     * @brief Getter: get game difficulty
     * @return value: enum value of GameDifficulty
     */
    GameDifficulty* gameDifficulty() const;

    /**
     * @brief Getter: get grid size
     * @return value: grid size for board
     */
    unsigned int gridSize() const;

    /**
     * @brief Getter: get player name for human
     * @return value: human name
     */
    QString humanPlayerName() const;

    /**
     * @brief Getter: get player name for ai
     * @return value: ai name
     */
    QString aiPlayerName() const;

    /**
     * @brief getAILevel: convert game difficulty enum valu to integer number
     * @return value: ai difficulty level according to GameDifficulty
     */
    unsigned int getAILevel();

public slots:
    /**
     * @brief Setter: set tile shape to human player
     * @param value: tile shape
     */
    void setHumanTile(TileShape* humanTile);

    /**
     * @brief Setter: set tile shape to ai player
     * @param value: tile shape
     */
    void setAiTile(TileShape* aiTile);

    /**
     * @brief Setter: set game difficulty
     * @param value: enum value of GameDifficulty
     */
    void setGameDifficulty(GameDifficulty* gameDifficulty);

    /**
     * @brief Setter: set grid size for board
     * @param value: grid size
     */
    void setGridSize(unsigned int gridSize);

    /**
     * @brief Setter: human player name
     * @param value: player name
     */
    void setHumanPlayerName(QString humanPlayerName);

    /**
     * @brief Setter: ai player name
     * @param value: player name
     */
    void setAiPlayerName(QString aiPlayerName);

signals:
    /**
     * @brief Signal: emit signal when human tile changed
     * @param value: value of TileShape
     */
    void humanTileChanged(TileShape* humanTile);

    /**
     * @brief Signal: emit signal when ai tile changed
     * @param value: value of TileShape
     */
    void aiTileChanged(TileShape* aiTile);

    /**
     * @brief Signal: emit signal when game difficulty changed
     * @param value: value of GameDifficulty
     */
    void gameDifficultyChanged(GameDifficulty* gameDifficulty);

    /**
     * @brief Signal: emit signal when grid size changed
     * @param value: gridSize
     */
    void gridSizeChanged(unsigned int gridSize);

    /**
     * @brief Signal: emit signal when human player name changed
     * @param value: player name
     */
    void humanPlayerNameChanged(QString humanPlayerName);

    /**
     * @brief Signal: emit signal when ai player name changed
     * @param value: player name
     */
    void aiPlayerNameChanged(QString aiPlayerName);

private:
    // Store Human tile data
    TileShape* m_humanTile;

    // Store AI tile data
    TileShape* m_aiTile;

    // Game difficulty
    GameDifficulty* m_gameDifficulty;

    // Grid size
    unsigned int m_gridSize;

    // Player name for human
    QString m_humanPlayerName;

    // Player name for AI
    QString m_aiPlayerName;
};

#endif // GAME_SETTINGS_H
