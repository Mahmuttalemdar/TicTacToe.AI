#include "board.h"
#include "player.h"
#include "tile.h"

Board::Board(unsigned int gridSize)
  : m_gridSize(gridSize)
  , m_utilityValue(0)
  , m_depth(0)
  , m_rowPlayed(0)
  , m_columnPlayed(0)
  , m_cachedLastRowPlayed(0)
  , m_cachedLastColumnPlayed(0)
  , m_gameState(GameState::ONGOING)
{
    // Intialize With All Blanks
    std::vector<std::vector<Tile>> boardData(gridSize, std::vector<Tile>(gridSize));

    // Set Board Game Data Structure
    m_gameBoard = std::move(boardData);
}

Board::Board(const Board& board)
{
    m_gridSize = board.m_gridSize;
    m_utilityValue = board.m_utilityValue;
    m_depth = board.m_depth;
    m_rowPlayed = board.m_rowPlayed;
    m_columnPlayed = board.m_columnPlayed;
    m_cachedLastRowPlayed = board.m_cachedLastRowPlayed;
    m_cachedLastColumnPlayed = board.m_cachedLastColumnPlayed;
    m_gameBoard = board.m_gameBoard;
    m_gameState = board.m_gameState;
}

Board& Board::operator=(const Board& board)
{
    m_gridSize = board.m_gridSize;
    m_utilityValue = board.m_utilityValue;
    m_depth = board.m_depth;
    m_rowPlayed = board.m_rowPlayed;
    m_columnPlayed = board.m_columnPlayed;
    m_cachedLastRowPlayed = board.m_cachedLastRowPlayed;
    m_cachedLastColumnPlayed = board.m_cachedLastColumnPlayed;
    m_gameBoard = board.m_gameBoard;
    m_gameState = board.m_gameState;

    return *this;
}

Board::Board(const Board& board, unsigned int row, unsigned int column, Player player)
{
    m_gridSize = board.m_gridSize;
    m_utilityValue = board.m_utilityValue;
    m_depth = board.m_depth + 1;
    m_rowPlayed = row;
    m_columnPlayed = column;
    m_cachedLastRowPlayed = 0;
    m_cachedLastColumnPlayed = 0;
    m_gameBoard = board.m_gameBoard;
    m_gameBoard[row][column].SetPlayer(player);
    m_gameState = board.m_gameState;
}

Board::Board(Board&& board)
{
    m_gridSize = std::move(board.m_gridSize);
    m_utilityValue = std::move(board.m_utilityValue);
    m_depth = std::move(board.m_depth);
    m_rowPlayed = std::move(board.m_rowPlayed);
    m_columnPlayed = std::move(board.m_columnPlayed);
    m_cachedLastRowPlayed = std::move(board.m_cachedLastRowPlayed);
    m_cachedLastColumnPlayed = std::move(board.m_cachedLastColumnPlayed);
    m_gameBoard = std::move(board.m_gameBoard);
    m_gameState = std::move(board.m_gameState);
}

Board& Board::operator=(Board&& board)
{
    m_gridSize = std::move(board.m_gridSize);
    m_utilityValue = std::move(board.m_utilityValue);
    m_depth = std::move(board.m_depth);
    m_rowPlayed = std::move(board.m_rowPlayed);
    m_columnPlayed = std::move(board.m_columnPlayed);
    m_cachedLastRowPlayed = std::move(board.m_cachedLastRowPlayed);
    m_cachedLastColumnPlayed = std::move(board.m_cachedLastColumnPlayed);
    m_gameBoard = std::move(board.m_gameBoard);
    m_gameState = std::move(board.m_gameState);
    return *this;
}

Board::~Board() {}

unsigned int Board::getGridSize() const
{
    return m_gridSize;
}

void Board::setGridSize(unsigned int value)
{
    m_gridSize = value;
}

const int& Board::getUtilityValue() const
{
    return m_utilityValue;
}

void Board::setUtilityValue(const int& value)
{
    m_utilityValue = value;
}

unsigned int Board::getDepth() const
{
    return m_depth;
}

void Board::setDepth(unsigned int value)
{
    m_depth = value;
}

unsigned int Board::getRowPlayed() const
{
    return m_rowPlayed;
}

unsigned int Board::getColumnPlayed() const
{
    return m_columnPlayed;
}

unsigned int Board::getCachedLastRowPlayed() const
{
    return m_cachedLastRowPlayed;
}

void Board::setCachedLastRowPlayed(unsigned int value)
{
    m_cachedLastRowPlayed = value;
}

unsigned int Board::getCachedLastColumnPlayed() const
{
    return m_cachedLastColumnPlayed;
}

void Board::setCachedLastColumnPlayed(unsigned int value)
{
    m_cachedLastColumnPlayed = value;
}

bool Board::isPlayed(unsigned int row, unsigned int column)
{
    if (getTile(row, column).GetState() == Tile::State::BLANK) {
        return false;
    }

    return true;
}

const std::vector<std::vector<Tile>>& Board::getGameBoard()
{
    return m_gameBoard;
}

const Tile& Board::getTile(unsigned int row, unsigned int column) const
{
    return m_gameBoard[row][column];
}

std::ostream& operator<<(std::ostream& os, const Tile& tile)
{
    switch (tile.GetPlayer().GetType()) {
        case Player::Type::NONE:
            os << "";
            break;
        case Player::Type::AI:
            os << "O";
        case Player::Type::HUMAN:
            os << "X";
        default:
            os << "";
            break;
    }

    return os;
}

void Board::playAt(unsigned int row, unsigned int column, Player player)
{
    if (getTile(row, column).GetState() == Tile::State::BLANK) {
        m_gameBoard[row][column].SetPlayer(player);
    } else {
        throw std::runtime_error("You can not play there, another tile has already taken.");
    }
}

const std::vector<std::unique_ptr<Board>> Board::generatePossibleStates(Player player)
{
    // empty vector of BoardModel
    std::vector<std::unique_ptr<Board>> movesSet;

    // Lopps Through each Row
    for (unsigned int row = 0; row < getGridSize(); row++) {
        // Loop through each colum
        for (unsigned int column = 0; column < getGridSize(); column++) {
            // if we have a free spot generate a possible outcome
            if (getTile(row, column).GetState() == Tile::State::BLANK) {
                Board newBoard = *this;
                std::unique_ptr<Board> possibleGameState(new Board(std::move(newBoard), row, column, player));

                // add this to a vector of valid moves
                movesSet.push_back(std::move(possibleGameState));
            }
        }
    }

    // move the board fields out
    return movesSet;
}

Board::GameState Board::checkGameState()
{
    // ROWS
    for (unsigned int row = 0; row < getGridSize(); row++) {
        unsigned int rowCount = 0;

        for (unsigned int column = 0; column < getGridSize() - 1; column++) {
            if (m_gameBoard[row][column].GetPlayer().GetType() == m_gameBoard[row][column + 1].GetPlayer().GetType() &&
                m_gameBoard[row][column].GetState() != Tile::State::BLANK) {
                ++rowCount;
                m_winnerList.append(QPoint(row, column));
            } else {
                break;
            }
        }

        // If one row is fill (this mean HUMAN or AI WON)
        if (rowCount == getGridSize() - 1) {
            m_winnerList.append(QPoint(0, rowCount));
            if (m_gameBoard[row][0].GetPlayer().GetType() == Player::Type::AI) {
                setGameState(GameState::WON);
                return GameState::WON;
            } else {
                setGameState(GameState::LOSS);
                return GameState::LOSS;
            }

        } else {
            m_winnerList.clear();
        }
    }

    // COLUMNS
    for (unsigned int column = 0; column < getGridSize(); column++) {
        unsigned int columnCount = 0;
        for (unsigned int row = 0; row < getGridSize() - 1; row++) {
            if (m_gameBoard[row][column].GetPlayer().GetType() == m_gameBoard[row + 1][column].GetPlayer().GetType() &&
                m_gameBoard[row][column].GetState() != Tile::State::BLANK) {
                ++columnCount;
                m_winnerList.append(QPoint(row, column));
            } else {
                break;
                ;
            }
        }

        // If one row is fill (this mean HUMAN or AI WON)
        if (columnCount == getGridSize() - 1) {
            m_winnerList.append(QPoint(columnCount, 0));
            if (m_gameBoard[0][column].GetPlayer().GetType() == Player::Type::AI) {
                setGameState(GameState::WON);
                return GameState::WON;
            } else {
                setGameState(GameState::LOSS);
                return GameState::LOSS;
            }

        } else {
            m_winnerList.clear();
        }
    }

    // DIAGONAL
    unsigned int diagonalCount = 0;
    for (unsigned int index = 0; index < getGridSize() - 1; index++) {
        if (m_gameBoard[index][index].GetPlayer().GetType() == m_gameBoard[index + 1][index + 1].GetPlayer().GetType() &&
            m_gameBoard[index][index].GetState() != Tile::State::BLANK) {
            ++diagonalCount;
        } else {
            break;
            ;
        }
    }

    // If one row is fill (this mean HUMAN or AI WON)
    if (diagonalCount == getGridSize() - 1) {
        if (m_gameBoard[0][0].GetPlayer().GetType() == Player::Type::AI) {
            setGameState(GameState::WON);
            return GameState::WON;
        } else {
            setGameState(GameState::LOSS);
            return GameState::LOSS;
        }
    }

    // ANTI DIAGONAL
    unsigned int antiDiagonalCount = 0;
    for (unsigned int index = 0; index < getGridSize() - 1; index++) {
        if (m_gameBoard[index][getGridSize() - index - 1].GetPlayer().GetType() ==
              m_gameBoard[index + 1][getGridSize() - index - 2].GetPlayer().GetType() &&
            m_gameBoard[index][getGridSize() - index - 1].GetState() != Tile::State::BLANK) {
            ++antiDiagonalCount;
        } else {
            break;
            ;
        }
    }

    // If one row is fill (this mean HUMAN or AI WON)
    if (antiDiagonalCount == getGridSize() - 1) {
        if (m_gameBoard[0][getGridSize() - 1].GetPlayer().GetType() == Player::Type::AI) {
            setGameState(GameState::WON);
            return GameState::WON;
        } else {
            setGameState(GameState::LOSS);
            return GameState::LOSS;
        }
    }

    // ONGOING
    for (unsigned int i = 0; i < getGridSize(); i++) {
        for (unsigned int j = 0; j < getGridSize(); j++) {
            if (m_gameBoard[i][j].GetState() == Tile::State::BLANK) {
                setGameState(GameState::ONGOING);
                return GameState::ONGOING;
            }
        }
    }

    // DRAW
    setGameState(GameState::DRAW);
    return GameState::DRAW;
}

bool Board::nextChildBoard(Player player, std::shared_ptr<Board>& childBoard)
{
    // Check is children board already implemented or null
    if (!childBoard) {
        childBoard = std::make_shared<Board>(m_gridSize);
    }

    for (unsigned int row = childBoard->getCachedLastRowPlayed(); row < getGridSize(); row++) {
        for (unsigned int column = childBoard->getCachedLastColumnPlayed(); column < getGridSize(); column++) {
            if (getTile(row, column).GetState() == Tile::State::BLANK &&
                (childBoard->getRowPlayed() != row || childBoard->getColumnPlayed() != column)) {
                auto childBoardPtr = childBoard.get();

                std::destroy_at(childBoardPtr);
                std::uninitialized_fill_n(childBoardPtr, 1, Board(*this, row, column, player));
                childBoard->setCachedLastRowPlayed(row);
                childBoard->setCachedLastColumnPlayed(column);
                return true;
            }
        }

        childBoard->setCachedLastColumnPlayed(0);
    }

    return false;
}

void Board::restart()
{
    m_rowPlayed = 0;
    m_columnPlayed = 0;
    m_cachedLastRowPlayed = 0;
    m_cachedLastColumnPlayed = 0;
    m_utilityValue = 0;
    m_depth = 0;

    // Intialize With All Blanks
    std::vector<std::vector<Tile>> boardData(m_gridSize, std::vector<Tile>(m_gridSize));

    // Set Board Game Data Structure
    m_gameBoard.clear();
    m_gameBoard = std::move(boardData);

    // Restart game state
    setGameState(GameState::ONGOING);
}

QList<QPoint> Board::getWinnerList()
{
    return m_winnerList;
}

Board::GameState Board::gameState() const
{
    return m_gameState;
}

void Board::setGameState(Board::GameState gameState)
{
    if (m_gameState == gameState)
        return;

    m_gameState = gameState;
    emit gameStateChanged(m_gameState);
}
