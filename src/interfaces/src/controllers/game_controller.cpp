#include "game_controller.h"

#include <thread>

#include <QObject>

GameController::GameController(const unsigned int gridSize, const unsigned int aiLevel, QObject* parent)
    : QObject(parent)
    , m_gridSize(gridSize)
    , m_aiLevel(aiLevel)
    , m_isPlayLock(false)
    , m_humanPlayer(Player::Type::HUMAN)
    , m_aiPlayer(Player::Type::AI)
    , m_gameBoard(new Board(m_gridSize))
    , m_aiImplement(new AIPlayer(m_aiPlayer, m_humanPlayer, m_aiLevel))
    , m_tileShapeModel(new TileShapeModel(parent))
{
    // Initialize tile shape model
    initializeModels();

    // Makes symbol connection for moves processed (ieA.I) to the controller receiving the move
    QObject::connect(this, &GameController::aiPlayedAt, this, &GameController::handleAIPlayedAt);
}

GameController::~GameController()
{}

void GameController::setAppConfig(AppConfig* config)
{
    if(config)
    {
        m_appConfig = config;
    }
}

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

        //check if the game is on goiing
        if (this->m_gameBoard->checkGameState() != Board::GameState::ONGOING)
        {
            return;
        }

        //launches and detaches a seperate thread for a.i processing
        std::thread(&GameController::aiThinkAndPlay, this).detach();
    }
    catch (...)
    {

    }
}

void GameController::selectShapeByIndex(unsigned int index)
{
    m_appConfig->setSelectedShape(m_tileShapeModel->getByIndex(index));
}

unsigned int GameController::gridSize() const
{
    return m_gridSize;
}

unsigned int GameController::aiLevel() const
{
    return m_aiLevel;
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

    //emits a threads safe signl from the a.i to the board
    emit aiPlayedAt(rowAI,columnAI);
}

void GameController::setGridSize(unsigned int gridSize)
{
    if (m_gridSize == gridSize)
        return;

    m_gridSize = gridSize;
    emit gridSizeChanged(m_gridSize);
}

void GameController::setAiLevel(unsigned int aiLevel)
{
    if (m_aiLevel == aiLevel)
        return;

    m_aiLevel = aiLevel;
    emit aiLevelChanged(m_aiLevel);
}

void GameController::setIsPlayLock(bool isPlayLock)
{
    if (m_isPlayLock == isPlayLock)
        return;

    m_isPlayLock = isPlayLock;
    emit isPlayLockChanged(m_isPlayLock);
}

void GameController::handleAIPlayedAt(unsigned int row, unsigned int column)
{
    m_gameBoard->playAt(row, column, m_aiPlayer);
    if (m_gameBoard->checkGameState() == Board::GameState::ONGOING)
    {
        setIsPlayLock(false);
    }

    emit updateAIPlayerOnUI(row,column);
}

void GameController::setTileShapeModel(TileShapeModel* tileShapeModel)
{
    if (m_tileShapeModel == tileShapeModel)
        return;

    m_tileShapeModel = tileShapeModel;
    emit tileShapeModelChanged(m_tileShapeModel);
}
