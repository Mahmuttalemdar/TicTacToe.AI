#include "game_difficulty.h"

GameDifficulty::GameDifficulty(QObject* parent)
    : QObject(parent)
{

}

GameDifficulty::~GameDifficulty()
{

}

GameDifficulty::Difficulty GameDifficulty::difficulty() const
{
    return m_difficulty;
}

unsigned int GameDifficulty::getDifficultyValue() const
{
    unsigned int depthValue = 0;

    switch(m_difficulty)
    {
    case GameDifficulty::Difficulty::Easy:
        depthValue = 1;
        break;
    case GameDifficulty::Difficulty::Medium:
        depthValue = 3;
        break;
    case GameDifficulty::Difficulty::Hard:
        depthValue = 5;
        break;
    default:
        depthValue = 1;
        break;
    }

    return depthValue;
}

void GameDifficulty::setDifficulty(GameDifficulty::Difficulty difficulty)
{
    if (m_difficulty == difficulty)
        return;

    m_difficulty = difficulty;
    emit difficultyChanged(m_difficulty);
}
