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
    m_gameBoard[row][column].setPlayer(player);
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

unsigned int Board::gridSize() const
{
    return m_gridSize;
}

void Board::setGridSize(unsigned int value)
{
    m_gridSize = value;
}

const int& Board::utilityValue() const
{
    return m_utilityValue;
}

void Board::setUtilityValue(const int& value)
{
    m_utilityValue = value;
}

unsigned int Board::depth() const
{
    return m_depth;
}

void Board::setDepth(unsigned int value)
{
    m_depth = value;
}

unsigned int Board::rowPlayed() const
{
    return m_rowPlayed;
}

unsigned int Board::columnPlayed() const
{
    return m_columnPlayed;
}

unsigned int Board::cachedLastRowPlayed() const
{
    return m_cachedLastRowPlayed;
}

void Board::setCachedLastRowPlayed(unsigned int value)
{
    m_cachedLastRowPlayed = value;
}

unsigned int Board::cachedLastColumnPlayed() const
{
    return m_cachedLastColumnPlayed;
}

void Board::setCachedLastColumnPlayed(unsigned int value)
{
    m_cachedLastColumnPlayed = value;
}

bool Board::isPlayed(unsigned int row, unsigned int column)
{
    if (tile(row, column).state() == Tile::State::BLANK) {
        return false;
    }

    return true;
}

const std::vector<std::vector<Tile>>& Board::gameBoard()
{
    return m_gameBoard;
}

const Tile& Board::tile(unsigned int row, unsigned int column) const
{
    return m_gameBoard[row][column];
}

std::ostream& operator<<(std::ostream& os, const Tile& tile)
{
    switch (tile.player().type()) {
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
    if (tile(row, column).state() == Tile::State::BLANK) {
        m_gameBoard[row][column].setPlayer(player);
    } else {
        throw std::runtime_error("You can not play there, another tile has already taken.");
    }
}

const std::vector<std::unique_ptr<Board>> Board::generatePossibleStates(Player player)
{
    // empty vector of BoardModel
    std::vector<std::unique_ptr<Board>> movesSet;

    // Lopps Through each Row
    for (unsigned int row = 0; row < gridSize(); row++) {
        // Loop through each colum
        for (unsigned int column = 0; column < gridSize(); column++) {
            // if we have a free spot generate a possible outcome
            if (tile(row, column).state() == Tile::State::BLANK) {
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
    for (unsigned int row = 0; row < gridSize(); row++) {
        unsigned int rowCount = 0;

        for (unsigned int column = 0; column < gridSize() - 1; column++) {
            if (m_gameBoard[row][column].player().type() == m_gameBoard[row][column + 1].player().type() &&
                m_gameBoard[row][column].state() != Tile::State::BLANK) {
                ++rowCount;
                m_winnerList.append(QPoint(row, column));
            } else {
                break;
            }
        }

        // If one row is fill (this mean HUMAN or AI WON)
        if (rowCount == gridSize() - 1) {
            m_winnerList.append(QPoint(0, rowCount));
            if (m_gameBoard[row][0].player().type() == Player::Type::AI) {
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
    for (unsigned int column = 0; column < gridSize(); column++) {
        unsigned int columnCount = 0;
        for (unsigned int row = 0; row < gridSize() - 1; row++) {
            if (m_gameBoard[row][column].player().type() == m_gameBoard[row + 1][column].player().type() &&
                m_gameBoard[row][column].state() != Tile::State::BLANK) {
                ++columnCount;
                m_winnerList.append(QPoint(row, column));
            } else {
                break;
                ;
            }
        }

        // If one row is fill (this mean HUMAN or AI WON)
        if (columnCount == gridSize() - 1) {
            m_winnerList.append(QPoint(columnCount, 0));
            if (m_gameBoard[0][column].player().type() == Player::Type::AI) {
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
    for (unsigned int index = 0; index < gridSize() - 1; index++) {
        if (m_gameBoard[index][index].player().type() == m_gameBoard[index + 1][index + 1].player().type() &&
            m_gameBoard[index][index].state() != Tile::State::BLANK) {
            ++diagonalCount;
        } else {
            break;
            ;
        }
    }

    // If one row is fill (this mean HUMAN or AI WON)
    if (diagonalCount == gridSize() - 1) {
        if (m_gameBoard[0][0].player().type() == Player::Type::AI) {
            setGameState(GameState::WON);
            return GameState::WON;
        } else {
            setGameState(GameState::LOSS);
            return GameState::LOSS;
        }
    }

    // ANTI DIAGONAL
    unsigned int antiDiagonalCount = 0;
    for (unsigned int index = 0; index < gridSize() - 1; index++) {
        if (m_gameBoard[index][gridSize() - index - 1].player().type() ==
              m_gameBoard[index + 1][gridSize() - index - 2].player().type() &&
            m_gameBoard[index][gridSize() - index - 1].state() != Tile::State::BLANK) {
            ++antiDiagonalCount;
        } else {
            break;
            ;
        }
    }

    // If one row is fill (this mean HUMAN or AI WON)
    if (antiDiagonalCount == gridSize() - 1) {
        if (m_gameBoard[0][gridSize() - 1].player().type() == Player::Type::AI) {
            setGameState(GameState::WON);
            return GameState::WON;
        } else {
            setGameState(GameState::LOSS);
            return GameState::LOSS;
        }
    }

    // ONGOING
    for (unsigned int i = 0; i < gridSize(); i++) {
        for (unsigned int j = 0; j < gridSize(); j++) {
            if (m_gameBoard[i][j].state() == Tile::State::BLANK) {
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

    for (unsigned int row = childBoard->cachedLastRowPlayed(); row < gridSize(); row++) {
        for (unsigned int column = childBoard->cachedLastColumnPlayed(); column < gridSize(); column++) {
            if (tile(row, column).state() == Tile::State::BLANK &&
                (childBoard->rowPlayed() != row || childBoard->columnPlayed() != column)) {
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

QList<QPoint> Board::winnerList()
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
