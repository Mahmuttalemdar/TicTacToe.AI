#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include <memory>
#include <random>

class Board;
class Player;

/**
 * @brief The A.I Implementation Using Mini-max and Depth Bound
 */
class AIPlayer
{
public:
    /**
     * @brief C-tor
     */
    /**
     * @brief C-tor
     * @param aiPlayer: player data for ai
     * @param opponentPlayer: player data for opponent
     * @param maxDept: max dept bound for ai calculation
     */
    AIPlayer(const Player& aiPlayer, const Player& opponentPlayer, const unsigned int& maxDept);

    /**
     * @brief D-tor
     */
    virtual ~AIPlayer();

    /**
     * @brief play: take current board and calculate to best move depend on it.
     * @param currentBoard: instance of current board
     * @return true: played a point, false: something is wrong
     */
    bool play(Board& currentBoard);

    /**
     * @brief playPosition: take current board and calculate to best move depend on it
     * and update row and column values according to new values
     * @param currentBoardModel
     * @param row: updated row value according to best move.
     * @param column: updated column value according to best move.
     * @return true: played a point, false: something is wrong
     */
    bool playPosition(Board& currentBoardModel, unsigned int& row, unsigned int& column);

    /**
     * @brief Getter: which player trying to get max value by ai
     * @return Player data
     */
    const Player& getMaxPlayer() const;

    /**
     * @brief Setter: set which player trying to get max value by ai
     * @param Player class
     */
    void setMaxPlayer(Player& player);

private:
    /**
     * @brief miniMaxDecision: Generate possible moves and try to calculate alfa & beta values
     * @param currentBoard: current instance of board
     * @return Board: return board whith best move
     */
    Board miniMaxDecision(Board* currentBoard);

    /**
     * @brief evalutaionFunciton: calculate board utility value depending on GameState and Player
     * @param currentBoard: current instance of board
     * @param player: Player
     * @return utility value of current board according to player
     */
    int evalutaionFunciton(Board& currentBoard, Player player);

    /**
     * @brief maxValue: terminate game or try to calculate next max value
     * according to player
     * @param childBoard: possible move on child board
     * @param alpha: current alpha value
     * @param beta: current beta value
     * @return next max value
     */
    int maxValue(Board& childBoard, int alpha, int beta);

    /**
     * @brief minValue: terminate game or try to calculate next min value
     * according to player
     * @param childBoard: possible move on child board
     * @param alpha: current alpha value
     * @param beta: current beta value
     * @return next min value
     */
    int minValue(Board& childBoard, int alpha, int beta);

    /**
     * @brief isTerminalStateOrDepthBound: check is terminal state or deep bound
     * @param childBoard: possible child board
     * @return false: game is still running, true: game is end
     */
    bool isTerminalStateOrDepthBound(Board& childBoard);

    /**
     * @brief heuristic: an intuitive approach to the current state of the board
     * @param gameBoard: instance of current board
     * @param player: data of player (human or ai)
     * @return winnign spot or best move for current payer
     */
    int heuristic(const Board& gameBoard, const Player& player);

    /**
     * @brief checkRow: Checking For Various Possible Wins Acros Different Conditions
     * @param gameBoard: instance of current board
     * @param player: data of player (human or ai)
     * @return winnign spot or best move for current payer
     */
    int checkRow(const Board& gameBoard, const Player& player);

    /**
     * @brief checkColumns: Checking For Various Possible Wins Acros Different Conditions
     * @param gameBoard: instance of current board
     * @param player: data of player (human or ai)
     * @return winnign spot or best move for current payer
     */
    int checkColumns(const Board& gameBoard, const Player& player);

    /**
     * @brief checkDiagonal: Checking For Various Possible Wins Acros Different Conditions
     * @param gameBoard: instance of current board
     * @param player: data of player (human or ai)
     * @return winnign spot or best move for current payer
     */
    int checkDiagonal(const Board& gameBoard, const Player& player);

    /**
     * @brief checkAntiDiagonal: Checking For Various Possible Wins Acros Different Conditions
     * @param gameBoard: instance of current board
     * @param player: data of player (human or ai)
     * @return winnign spot or best move for current payer
     */
    int checkAntiDiagonal(const Board& gameBoard, const Player& player);

private:
    // This player (AI)
    std::unique_ptr<Player> m_maxPlayer;

    // Opponent player (HUMAN)
    std::unique_ptr<Player> m_minOpponent;

    // Depth of search space before terminal
    unsigned int m_maxDept;

    // Random value
    std::mt19937 m_seenGen;
};

#endif // AI_PLAYER_H
