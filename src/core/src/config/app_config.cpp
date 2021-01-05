#include "app_config.h"

AppConfig::AppConfig(QObject *parent)
    : QObject{parent}
    , m_selectedShape(new TileShape(TileShape::TileShapeType::None, "", parent))
    , m_gameDifficulty(new GameDifficulty(parent))
    , m_gridSize(3)
{}

AppConfig::~AppConfig()
{}

TileShape* AppConfig::selectedShape() const
{
    return m_selectedShape;
}

GameDifficulty* AppConfig::gameDifficulty() const
{
    return m_gameDifficulty;
}

unsigned int AppConfig::gridSize() const
{
    return m_gridSize;
}

void AppConfig::setSelectedShape(TileShape* selectedShape)
{
    if (m_selectedShape == selectedShape)
        return;

    m_selectedShape = selectedShape;
    emit selectedShapeChanged(m_selectedShape);
}

void AppConfig::setGameDifficulty(GameDifficulty* gameDifficulty)
{
    if (m_gameDifficulty == gameDifficulty)
        return;

    m_gameDifficulty = gameDifficulty;
    emit gameDifficultyChanged(m_gameDifficulty);
}

void AppConfig::setGridSize(unsigned int gridSize)
{
    if (m_gridSize == gridSize)
        return;

    m_gridSize = gridSize;
    emit gridSizeChanged(m_gridSize);
}
