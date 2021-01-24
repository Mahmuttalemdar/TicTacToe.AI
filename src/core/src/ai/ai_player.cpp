#include "ai_player.h"
#include "core/src/game/board.h"
#include "core/src/game/player.h"
#include "core/src/game/tile.h"

#include <iostream>

AIPlayer::AIPlayer(const Player& aiPlayer, const Player& opponentPlayer, const unsigned int& maxDept)
  : m_maxPlayer(std::make_unique<Player>(aiPlayer))
  , m_minOpponent(std::make_unique<Player>(opponentPlayer))
  , m_maxDept(maxDept)
{
    std::random_device rd;
    m_seenGen = std::mt19937(rd());
}

AIPlayer::~AIPlayer() {}

bool AIPlayer::play(Board& currentBoard)
{
    try {
        // Calculate the best move
        auto bestMove = miniMaxDecision(&currentBoard);

        // Play at the coordinates
        currentBoard.playAt(bestMove.rowPlayed(), bestMove.columnPlayed(), *m_maxPlayer.get());

        // True: played a row or cloumn
        return true;
    } catch (std::exception& expt) {
        std::cout << expt.what();
        return false;
    }
}

bool AIPlayer::playPosition(Board& currentBoardModel, unsigned int& row, unsigned int& column)
{
    try {
        // calculate the best move
        auto bestMove = miniMaxDecision(&currentBoardModel);
        // set the best moves
        row = bestMove.rowPlayed();
        column = bestMove.columnPlayed();

        return true;
    } catch (std::exception& expt) {
        // We werent able to lay for some reason
        // Debugging Purposes
        std::cout << expt.what();
        return false;
    }
    return true;
}

const Player& AIPlayer::maxPlayer() const
{
    return *m_maxPlayer.get();
}

void AIPlayer::setMaxPlayer(Player& player)
{
    m_maxPlayer.reset(&player);
}

Board AIPlayer::miniMaxDecision(Board* currentBoard)
{
    auto possibleMoves = currentBoard->generatePossibleStates(*m_maxPlayer.get());

    if (possibleMoves.size() == 0) {
        throw std::runtime_error(std::string("No move option to play").append(std::string("AI")));
    }

    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();

    Board* bestMove = &(*possibleMoves[0]);
    for (auto& stateNode : possibleMoves) {
        stateNode->setUtilityValue(minValue(*stateNode, alpha, beta));
        if (stateNode->utilityValue() > alpha) {
            alpha = stateNode->utilityValue();
            bestMove = &*stateNode;
        }
    }

    return std::move(*bestMove);
}

int AIPlayer::evalutaionFunciton(Board& currentBoard, Player player)
{
    // WON :: If you have won = INF
    if (currentBoard.checkGameState() == Board::GameState::WON) {
        return std::numeric_limits<int>::max();
    }
    // LOSS :: If your opponent has won = -INF
    else if (currentBoard.checkGameState() == Board::GameState::LOSS) {
        return std::numeric_limits<int>::min();
    }
    // DRAW :: If draw
    else if (currentBoard.checkGameState() == Board::GameState::DRAW) {
        return 0;
    }
    // ONGOING :: Game is still on going
    else {
        if (player.type() == m_maxPlayer.get()->type()) {
            return heuristic(currentBoard, *m_maxPlayer.get());
        } else {
            return -heuristic(currentBoard, *m_minOpponent.get());
        }
    }
}

int AIPlayer::maxValue(Board& childBoard, int alpha, int beta)
{
    // Check is terminal state
    if (isTerminalStateOrDepthBound(childBoard)) {
        return evalutaionFunciton(childBoard, *m_maxPlayer.get());
    }

    // Set to -INF or min(int)
    int nodeValue = std::numeric_limits<int>::min();

    std::shared_ptr<Board> currentChildBoard;
    while (childBoard.nextChildBoard(*m_maxPlayer.get(), currentChildBoard)) {
        nodeValue = std::max(nodeValue, minValue(*currentChildBoard, alpha, beta));
        if (nodeValue >= beta) {
            return nodeValue;
        }

        alpha = std::max(alpha, nodeValue);
    }

    return nodeValue;
}

int AIPlayer::minValue(Board& childBoard, int alpha, int beta)
{
    // Check is terminal state
    if (isTerminalStateOrDepthBound(childBoard)) {
        return evalutaionFunciton(childBoard, *m_minOpponent.get());
    }

    // Set to +INF or max(int)
    int nodeValue = std::numeric_limits<int>::max();

    std::shared_ptr<Board> currentChildBoard;
    while (childBoard.nextChildBoard(*m_minOpponent.get(), currentChildBoard)) {
        nodeValue = std::min(nodeValue, maxValue(*currentChildBoard, alpha, beta));
        if (nodeValue <= alpha) {
            return nodeValue;
        }

        beta = std::min(beta, nodeValue);
    }

    return nodeValue;
}

bool AIPlayer::isTerminalStateOrDepthBound(Board& childBoard)
{
    // Get game state from cuurent board
    auto gameState = childBoard.checkGameState();

    // Game has eded with a win for someone or draw
    if (gameState == Board::GameState::WON || gameState == Board::GameState::LOSS || gameState == Board::GameState::DRAW) {
        return true;
    }
    // We have reach our max dept
    else if (childBoard.depth() >= m_maxDept) {
        return true;
    }
    // Game still running
    else {
        return false;
    }
}

int AIPlayer::heuristic(const Board& gameBoard, const Player& player)
{
    // ROW
    auto countRow = checkRow(gameBoard, player);

    // COLUMN
    auto countColumn = checkColumns(gameBoard, player);

    // DIAGONAL
    auto countDiagonal = checkDiagonal(gameBoard, player);

    // ANTI DIAGONAL
    auto countAntiDiagonal = checkAntiDiagonal(gameBoard, player);

    // Return total value
    return countRow + countColumn + countDiagonal + countAntiDiagonal;
}

int AIPlayer::checkRow(const Board& gameBoard, const Player& player)
{
    // How many winning state we have?
    int countWinningSpot = 0;

    // How many tile already fill?
    int countOccupiedTile = 0;

    // How many tile is blank on one row?
    int countBlankTile = 0;

    // First encountered tile type(depended on player type)
    Player::Type firstEncounteredType = Player::Type::NONE;

    // Check each row for winning spot
    for (unsigned int row = 0; row < gameBoard.gridSize(); row++) {
        // Loop through each column
        for (unsigned int column = 0; column < gameBoard.gridSize(); column++) {
            // BLANK CHECK
            if (gameBoard.tile(row, column).state() != Tile::State::BLANK) {
                if (countOccupiedTile == 0) {
                    countOccupiedTile++;
                    firstEncounteredType = gameBoard.tile(row, column).player().type();
                } else if (firstEncounteredType != gameBoard.tile(row, column).player().type()) {
                    countOccupiedTile++;
                    break;
                }
            } else {
                countBlankTile++;
            }
        }

        // Winning state guards
        if (countOccupiedTile < 2 && countBlankTile == 1 && (firstEncounteredType == player.type())) {
            countWinningSpot++;
        }

        // Reset
        firstEncounteredType = Player::Type::NONE;
        countOccupiedTile = 0;
        countBlankTile = 0;
    }

    return countWinningSpot;
}

int AIPlayer::checkColumns(const Board& gameBoard, const Player& player)
{
    // How many winning state we have?
    int countWinningSpot = 0;

    // How many tile already fill?
    int countOccupiedTile = 0;

    // How many tile is blank on one row?
    int countBlankTile = 0;

    // First encountered tile type(depended on player type)
    Player::Type firstEncounteredType = Player::Type::NONE;

    // Check each column for winning spot
    for (unsigned int column = 0; column < gameBoard.gridSize(); column++) {
        // Loop through each row
        for (unsigned int row = 0; row < gameBoard.gridSize(); row++) {
            // BLANK CHECK
            if (gameBoard.tile(row, column).state() != Tile::State::BLANK) {
                if (countOccupiedTile == 0) {
                    countOccupiedTile++;
                    firstEncounteredType = gameBoard.tile(row, column).player().type();
                } else if (firstEncounteredType != gameBoard.tile(row, column).player().type()) {
                    countOccupiedTile++;
                    break;
                }
            } else {
                countBlankTile++;
            }
        }

        // Winning state guards
        if (countOccupiedTile < 2 && countBlankTile == 1 && (firstEncounteredType == player.type())) {
            countWinningSpot++;
        }

        // Reset
        firstEncounteredType = Player::Type::NONE;
        countOccupiedTile = 0;
        countBlankTile = 0;
    }

    return countWinningSpot;
}

int AIPlayer::checkDiagonal(const Board& gameBoard, const Player& player)
{
    // How many winning state we have?
    int countWinningSpot = 0;

    // How many tile already fill?
    int countOccupiedTile = 0;

    // How many tile is blank on one row?
    int countBlankTile = 0;

    // First encountered tile type(depended on player type)
    Player::Type firstEncounteredType = Player::Type::NONE;

    // Check each column for winning spot
    for (unsigned int item = 0; item < gameBoard.gridSize(); item++) {
        // BLANK CHECK
        if (gameBoard.tile(item, item).state() != Tile::State::BLANK) {
            if (countOccupiedTile == 0) {
                countOccupiedTile++;
                firstEncounteredType = gameBoard.tile(item, item).player().type();
            } else if (firstEncounteredType != gameBoard.tile(item, item).player().type()) {
                countOccupiedTile++;
                break;
            }
        } else {
            countBlankTile++;
        }
    }

    // Winning state guards
    if (countOccupiedTile < 2 && countBlankTile == 1 && (firstEncounteredType == player.type())) {
        countWinningSpot++;
    }

    return countWinningSpot;
}

int AIPlayer::checkAntiDiagonal(const Board& gameBoard, const Player& player)
{
    // How many winning state we have?
    int countWinningSpot = 0;

    // How many tile already fill?
    int countOccupiedTile = 0;

    // How many tile is blank on one row?
    int countBlankTile = 0;

    // First encountered tile type(depended on player type)
    Player::Type firstEncounteredType = Player::Type::NONE;

    // Check each row for winning spot
    for (unsigned int row = 0; row < gameBoard.gridSize(); row++) {
        // Loop through each column
        for (unsigned int column = 0; column < gameBoard.gridSize(); column++) {
            // Check is anti diagonal?
            if ((row + column) == gameBoard.gridSize() - 1) {
                // BLANK CHECK
                if (gameBoard.tile(row, column).state() != Tile::State::BLANK) {
                    if (countOccupiedTile == 0) {
                        countOccupiedTile++;
                        firstEncounteredType = gameBoard.tile(row, column).player().type();
                    } else if (firstEncounteredType != gameBoard.tile(row, column).player().type()) {
                        countOccupiedTile++;
                        break;
                    }
                } else {
                    countBlankTile++;
                }
            }
        }
    }

    // Winning state guards
    if (countOccupiedTile < 2 && countBlankTile == 1 && (firstEncounteredType == player.type())) {
        countWinningSpot++;
    }

    return countWinningSpot;
}
