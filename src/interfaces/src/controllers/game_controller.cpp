#include "game_controller.h"

#include <thread>

#include <QObject>
#include <QScxmlStateMachine>

GameController::GameController(GameSettings* gameSettings, QObject* parent)
  : QObject(parent)
  , m_gameSettings(gameSettings)
  , m_isPlayLock(false)
  , m_humanPlayer(Player::Type::HUMAN)
  , m_aiPlayer(Player::Type::AI)
  , m_gameBoard(new Board(m_gameSettings->gridSize()))
  , m_aiImplement(new AIPlayer(m_aiPlayer, m_humanPlayer, m_gameSettings->getAILevel()))
  , m_tileShapeModel(new TileShapeModel(parent))
{
    // Initialize tile shape model
    initializeModels();

    // Connect to game settings
    QObject::connect(
      m_gameSettings->gameDifficulty(), &GameDifficulty::difficultyChanged, this, &GameController::handleGameDifficultyChanged);
    QObject::connect(m_gameSettings, &GameSettings::gridSizeChanged, this, &GameController::handleGridSizeChanged);
    QObject::connect(m_gameSettings, &GameSettings::humanPlayerNameChanged, this, &GameController::handleHumanPlayerNameChanged);
    QObject::connect(m_gameSettings, &GameSettings::aiPlayerNameChanged, this, &GameController::handleAiPlayerNameChanged);

    // Makes symbol connection for moves processed (ieA.I) to the controller receiving the move
    QObject::connect(this, &GameController::aiPlayedAt, this, &GameController::handleAIPlayedAt);
}

GameController::GameController(QObject* parent)
  : QObject(parent)
{}

GameController::~GameController() {}

bool GameController::isPlayed(unsigned int row, unsigned int column)
{
    return m_gameBoard->isPlayed(row, column);
}

void GameController::humanPlayedAt(unsigned int row, unsigned int column)
{
    try {
        // Sets the player lock to false so the current human player cannot play on board until the a.i has produced a move
        setIsPlayLock(true);
        m_gameBoard->playAt(row, column, m_humanPlayer);

        // check if the game is on goiing
        if (this->m_gameBoard->checkGameState() != Board::GameState::ONGOING) {
            return;
        }

        // launches and detaches a seperate thread for a.i processing
        std::thread(&GameController::aiThinkAndPlay, this).detach();
    } catch (...) {
    }
}

void GameController::selectShapeByIndex(unsigned int index)
{
    m_gameSettings->setHumanTile(m_tileShapeModel->getByIndex(index));

    if (index == 3) {
        m_gameSettings->setAiTile(m_tileShapeModel->getByIndex(0));
    } else {
        m_gameSettings->setAiTile(m_tileShapeModel->getByIndex(3));
    }
}

bool GameController::isPlayLock() const
{
    return m_isPlayLock;
}

Board* GameController::gameBoard() const
{
    return m_gameBoard;
}

TileShapeModel* GameController::tileShapeModel() const
{
    return m_tileShapeModel;
}

void GameController::setStateChart(statechart::Main* stateChart)
{
    if (stateChart) {
        m_statechart = stateChart;
        m_statechart->connectToEvent("restartGame", this, &GameController::handleRestartGame);
    }
}

void GameController::initializeModels()
{
    m_tileShapeModel->addTileShape(new TileShape(TileShape::TileShapeType::TileA, "qrc:/imports/Theme/images/Tiles/TileA.svg"));
    m_tileShapeModel->addTileShape(new TileShape(TileShape::TileShapeType::TileK, "qrc:/imports/Theme/images/Tiles/TileK.svg"));
    m_tileShapeModel->addTileShape(new TileShape(TileShape::TileShapeType::TileM, "qrc:/imports/Theme/images/Tiles/TileM.svg"));
    m_tileShapeModel->addTileShape(new TileShape(TileShape::TileShapeType::TileO, "qrc:/imports/Theme/images/Tiles/TileO.svg"));
    m_tileShapeModel->addTileShape(new TileShape(TileShape::TileShapeType::TileU, "qrc:/imports/Theme/images/Tiles/TileU.svg"));
    m_tileShapeModel->addTileShape(new TileShape(TileShape::TileShapeType::TileX, "qrc:/imports/Theme/images/Tiles/TileX.svg"));
}

void GameController::aiThinkAndPlay()
{
    unsigned int rowAI = 0;
    unsigned int columnAI = 0;
    m_aiImplement->playPosition(*m_gameBoard, rowAI, columnAI);

    // emits a threads safe signl from the a.i to the board
    emit aiPlayedAt(rowAI, columnAI);
}

void GameController::setIsPlayLock(bool isPlayLock)
{
    if (m_isPlayLock == isPlayLock)
        return;

    m_isPlayLock = isPlayLock;
    emit isPlayLockChanged(m_isPlayLock);
}

void GameController::setTileShapeModel(TileShapeModel* tileShapeModel)
{
    if (m_tileShapeModel == tileShapeModel)
        return;

    m_tileShapeModel = tileShapeModel;
    emit tileShapeModelChanged(m_tileShapeModel);
}

void GameController::handleAIPlayedAt(unsigned int row, unsigned int column)
{
    m_gameBoard->playAt(row, column, m_aiPlayer);
    if (m_gameBoard->checkGameState() == Board::GameState::ONGOING) {
        setIsPlayLock(false);
    }

    emit updateAIPlayerOnUI(row, column);
}

void GameController::handleGameDifficultyChanged(GameDifficulty::Difficulty difficulty)
{
    switch (difficulty) {
        case GameDifficulty::Difficulty::Easy:
            m_gameBoard->setDepth(m_gameSettings->getAILevel());
            m_gameSettings->setAiPlayerName("EasyBot.AI");
            break;
        case GameDifficulty::Difficulty::Medium:
            m_gameBoard->setDepth(m_gameSettings->getAILevel());
            m_gameSettings->setAiPlayerName("MediumBot.AI");
            break;
        case GameDifficulty::Difficulty::Hard:
            m_gameBoard->setDepth(m_gameSettings->getAILevel());
            m_gameSettings->setAiPlayerName("HardBot.AI");
            break;
        default:
            m_gameBoard->setDepth(m_gameSettings->getAILevel());
            m_gameSettings->setAiPlayerName("EasyBot.AI");
            break;
    }

    m_gameBoard->restart();
}

void GameController::handleGridSizeChanged(unsigned int gridSize)
{
    m_gameBoard->setGridSize(gridSize);
    m_gameBoard->restart();
}

void GameController::handleHumanPlayerNameChanged(QString playerName)
{
    m_humanPlayer.SetPlayerName(playerName);
    m_gameBoard->restart();
}

void GameController::handleAiPlayerNameChanged(QString playerName)
{
    m_aiPlayer.SetPlayerName(playerName);
    m_gameBoard->restart();
}

void GameController::handleRestartGame()
{
    setIsPlayLock(false);
    m_gameBoard->restart();
}
