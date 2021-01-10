#include "game_settings.h"

GameSettings::GameSettings(QObject *parent)
    : QObject{parent}
    , m_humanTile(new TileShape(TileShape::TileShapeType::None, "", parent))
    , m_aiTile(new TileShape(TileShape::TileShapeType::None, "", parent))
    , m_gameDifficulty(new GameDifficulty(parent))
    , m_gridSize(3)
    , m_humanPlayerName("Player1")
    , m_aiPlayerName("EasyBot.AI")
{}

GameSettings::~GameSettings()
{}

TileShape* GameSettings::humanTile() const
{
    return m_humanTile;
}

TileShape* GameSettings::aiTile() const
{
    return m_aiTile;
}

GameDifficulty* GameSettings::gameDifficulty() const
{
    return m_gameDifficulty;
}

unsigned int GameSettings::gridSize() const
{
    return m_gridSize;
}

QString GameSettings::humanPlayerName() const
{
    return m_humanPlayerName;
}

QString GameSettings::aiPlayerName() const
{
    return m_aiPlayerName;
}

unsigned int GameSettings::getAILevel()
{
    unsigned int aiLevel = 1;
    switch (m_gameDifficulty->difficulty())
    {
    case GameDifficulty::Difficulty::Easy:
        aiLevel = 1;
        break;
    case GameDifficulty::Difficulty::Medium:
        aiLevel = 3;
        break;
    case GameDifficulty::Difficulty::Hard:
        aiLevel = 5;
        break;
    default:
        aiLevel = 1;
        break;
    }

    return aiLevel;
}

void GameSettings::setHumanTile(TileShape* humanTile)
{
    if (m_humanTile == humanTile)
        return;

    m_humanTile = humanTile;
    emit humanTileChanged(m_humanTile);
}

void GameSettings::setAiTile(TileShape* aiTile)
{
    if (m_aiTile == aiTile)
        return;

    m_aiTile = aiTile;
    emit aiTileChanged(m_aiTile);
}

void GameSettings::setGameDifficulty(GameDifficulty* gameDifficulty)
{
    if (m_gameDifficulty == gameDifficulty)
        return;

    m_gameDifficulty = gameDifficulty;
    emit gameDifficultyChanged(m_gameDifficulty);
}

void GameSettings::setGridSize(unsigned int gridSize)
{
    if (m_gridSize == gridSize)
        return;

    m_gridSize = gridSize;
    emit gridSizeChanged(m_gridSize);
}

void GameSettings::setHumanPlayerName(QString humanPlayerName)
{
    if (m_humanPlayerName == humanPlayerName)
        return;

    m_humanPlayerName = humanPlayerName;
    emit humanPlayerNameChanged(m_humanPlayerName);
}

void GameSettings::setAiPlayerName(QString aiPlayerName)
{
    if (m_aiPlayerName == aiPlayerName)
        return;

    m_aiPlayerName = aiPlayerName;
    emit aiPlayerNameChanged(m_aiPlayerName);
}
