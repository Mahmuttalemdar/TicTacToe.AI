#include "ai_player.h"
#include "core/src/game/player.h"
#include "core/src/game/board.h"
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

AIPlayer::~AIPlayer()
{}

bool AIPlayer::play(Board& currentBoard)
{
    try
    {
        // Get copy of current board
        auto copyBoard = currentBoard;

        // Calculate the best move
        auto bestMove = MiniMaxDecision(&currentBoard);

        // Play at the coordinates
        currentBoard.playAt(bestMove.getRowPlayed(), bestMove.getColumnPlayed(), *m_maxPlayer.get());

        // True: played a row or cloumn
        return true;
    }
    catch (std::exception& expt)
    {
        std::cout << expt.what();
        return false;
    }
}

bool AIPlayer::playPosition(Board& currentBoardModel, unsigned int& row, unsigned int& column)
{    
    try {
        // calculate the best move
        auto bestMove = MiniMaxDecision(&currentBoardModel);
        //set the best moves
        row = bestMove.getRowPlayed();
        column = bestMove.getColumnPlayed();

        return true;
    }
    catch(std::exception& expt){
        //We werent able to lay for some reason
        //Debugging Purposes
        std::cout << expt.what();
        return false;
    }
    return true;
}

const Player& AIPlayer::getMaxPlayer() const
{
    return *m_maxPlayer.get();
}

void AIPlayer::setMaxPlayer(Player& player)
{
    m_maxPlayer.reset(&player);
}

Board AIPlayer::MiniMaxDecision(Board* currentBoard)
{
    auto possibleMoves = currentBoard->generatePossibleStates(*m_maxPlayer.get());

    if(possibleMoves.size() == 0) {
        throw std::runtime_error(std::string("No move option to play").append(std::string("AI")));
    }

    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();

    Board* bestMove = &(*possibleMoves[0]);
    for(auto& stateNode : possibleMoves)
    {
        // Emin değiliz
        stateNode->setUtilityValue(minValue(*stateNode, alpha, beta));

        if(stateNode->getUtilityValue() > alpha)
        {
            alpha = stateNode->getUtilityValue();
            bestMove = &*stateNode;
        }
    }

    return std::move(*bestMove);
}

int AIPlayer::evalutaionFunciton(Board& currentBoard, Player player)
{
    // WON :: If you have won = INF
    if(currentBoard.checkGameState() == Board::GameState::WON)
    {
        return std::numeric_limits<int>::max();
    }
    // LOSS :: If your opponent has won = -INF
    else if(currentBoard.checkGameState() == Board::GameState::LOSS)
    {
        return std::numeric_limits<int>::min();
    }
    // DRAW :: If draw
    else if(currentBoard.checkGameState() == Board::GameState::DRAW)
    {
        return 0;
    }
    // ONGOING :: Game is still on going
    else
    {
        if(player.GetType() == m_maxPlayer.get()->GetType())
        {
            return heuristic(currentBoard, *m_maxPlayer.get());
        }
        else{
            return -heuristic(currentBoard, *m_minOpponent.get());
        }
    }
}

int AIPlayer::maxValue(Board& childBoard, int alpha, int beta)
{
    // Check is terminal state
    if(isTerminalStateOrDepthBound(childBoard))
    {
        return evalutaionFunciton(childBoard, *m_maxPlayer.get());
    }

    // Set to -INF or min(int)
    int nodeValue = std::numeric_limits<int>::min();

    std::shared_ptr<Board> currentChildBoard;
    while (childBoard.nextChildBoard(*m_maxPlayer.get(), currentChildBoard))
    {
        nodeValue = std::max(nodeValue, minValue(*currentChildBoard, alpha, beta));
        if( nodeValue >= beta)
        {
            return nodeValue;
        }

        alpha = std::max(alpha, nodeValue);
    }

    return nodeValue;
}

int AIPlayer::minValue(Board& childBoard, int alpha, int beta)
{
    // Check is terminal state
    if(isTerminalStateOrDepthBound(childBoard))
    {
        return evalutaionFunciton(childBoard, *m_minOpponent.get());
    }

    // Set to +INF or max(int)
    int nodeValue = std::numeric_limits<int>::max();

    std::shared_ptr<Board> currentChildBoard;
    while (childBoard.nextChildBoard(*m_minOpponent.get(), currentChildBoard))
    {
        nodeValue = std::min(nodeValue, maxValue(*currentChildBoard, alpha, beta));
        if( nodeValue <= alpha)
        {
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
    if(gameState == Board::GameState::WON
            || gameState == Board::GameState::LOSS
            || gameState == Board::GameState::DRAW)
    {
        return true;
    }
    // We have reach our max dept
    else if(childBoard.getDepth() >= m_maxDept)
    {
        return true;
    }
    // Game still running
    else
    {
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
    for (unsigned int  row =  0 ; row < gameBoard.getGridSize(); row++)
    {
        // Loop through each column
        for (unsigned int column = 0 ; column < gameBoard.getGridSize(); column++)
        {
            // BLANK CHECK
            if(gameBoard.getTile(row, column).GetState() != Tile::State::BLANK)
            {
                if(countOccupiedTile == 0)
                {
                    countOccupiedTile++;
                    firstEncounteredType = gameBoard.getTile(row, column).GetPlayer().GetType();
                }
                else if (firstEncounteredType != gameBoard.getTile(row, column).GetPlayer().GetType())
                {
                    countOccupiedTile++;
                    break;
                }
            }
            else
            {
                countBlankTile++;
            }
        }

        // Winning state guards
        if(countOccupiedTile < 2
                && countBlankTile == 1
                && (firstEncounteredType == player.GetType()) )
        {
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
    for (unsigned int  column =  0 ; column < gameBoard.getGridSize(); column++)
    {
        // Loop through each row
        for (unsigned int row = 0 ; row < gameBoard.getGridSize(); row++)
        {
            // BLANK CHECK
            if(gameBoard.getTile(row, column).GetState() != Tile::State::BLANK)
            {
                if(countOccupiedTile == 0)
                {
                    countOccupiedTile++;
                    firstEncounteredType = gameBoard.getTile(row, column).GetPlayer().GetType();
                }
                else if (firstEncounteredType != gameBoard.getTile(row, column).GetPlayer().GetType())
                {
                    countOccupiedTile++;
                    break;
                }
            }
            else
            {
                countBlankTile++;
            }
        }

        // Winning state guards
        if(countOccupiedTile < 2
                && countBlankTile == 1
                && (firstEncounteredType == player.GetType()) )
        {
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
    for (unsigned int  item =  0 ; item < gameBoard.getGridSize(); item++)
    {
        // BLANK CHECK
        if(gameBoard.getTile(item, item).GetState() != Tile::State::BLANK)
        {
            if(countOccupiedTile == 0)
            {
                countOccupiedTile++;
                firstEncounteredType = gameBoard.getTile(item, item).GetPlayer().GetType();
            }
            else if (firstEncounteredType != gameBoard.getTile(item, item).GetPlayer().GetType())
            {
                countOccupiedTile++;
                break;
            }
        }
        else
        {
            countBlankTile++;
        }
    }

    // Winning state guards
    if(countOccupiedTile < 2
            && countBlankTile == 1
            && (firstEncounteredType == player.GetType()) )
    {
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
    for (unsigned int  row =  0 ; row < gameBoard.getGridSize(); row++)
    {
        // Loop through each column
        for (unsigned int column = 0 ; column < gameBoard.getGridSize(); column++)
        {
            // Check is anti diagonal?
            if((row + column) == gameBoard.getGridSize() - 1)
            {
                // BLANK CHECK
                if(gameBoard.getTile(row, column).GetState() != Tile::State::BLANK)
                {
                    if(countOccupiedTile == 0)
                    {
                        countOccupiedTile++;
                        firstEncounteredType = gameBoard.getTile(row, column).GetPlayer().GetType();
                    }
                    else if (firstEncounteredType != gameBoard.getTile(row, column).GetPlayer().GetType())
                    {
                        countOccupiedTile++;
                        break;
                    }
                }
                else
                {
                    countBlankTile++;
                }
            }
        }
    }

    // Winning state guards
    if(countOccupiedTile < 2
            && countBlankTile == 1
            && (firstEncounteredType == player.GetType()) )
    {
        countWinningSpot++;
    }

    return countWinningSpot;
}
