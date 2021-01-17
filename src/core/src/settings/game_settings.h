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
     * @param parent : QObject parent
     */
    GameSettings(QObject* parent = nullptr);

    /**
     * @brief C-tor
     * @param parent : QObject parent
     */
    ~GameSettings();

    TileShape* humanTile() const;

    TileShape* aiTile() const;

    GameDifficulty* gameDifficulty() const;

    unsigned int gridSize() const;

    QString humanPlayerName() const;

    QString aiPlayerName() const;

    unsigned int getAILevel();

public slots:
    void setHumanTile(TileShape* humanTile);
    void setAiTile(TileShape* aiTile);
    void setGameDifficulty(GameDifficulty* gameDifficulty);
    void setGridSize(unsigned int gridSize);
    void setHumanPlayerName(QString humanPlayerName);
    void setAiPlayerName(QString aiPlayerName);

signals:
    void humanTileChanged(TileShape* humanTile);
    void aiTileChanged(TileShape* aiTile);
    void gameDifficultyChanged(GameDifficulty* gameDifficulty);
    void gridSizeChanged(unsigned int gridSize);
    void humanPlayerNameChanged(QString humanPlayerName);
    void aiPlayerNameChanged(QString aiPlayerName);

private:
    TileShape* m_humanTile;
    TileShape* m_aiTile;
    GameDifficulty* m_gameDifficulty;
    unsigned int m_gridSize;
    QString m_humanPlayerName;
    QString m_aiPlayerName;
};

#endif // GAME_SETTINGS_H
