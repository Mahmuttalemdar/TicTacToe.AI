#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include <memory>
#include <random>

class Board;
class Player;

/**
 * @brief The Is A.I Implementation Using Mini-max and Depth Bound
 */
class AIPlayer
{
public:
    /**
     * @brief C-tor
     */
    AIPlayer(const Player& aiPlayer, const Player& opponentPlayer, const unsigned int& maxDept);

    /**
     * @brief D-tor
     */
    virtual ~AIPlayer();

    bool play(Board& currentBoard);

    bool playPosition(Board& currentBoardModel, unsigned int& row, unsigned int& column);

    const Player& getMaxPlayer() const;

    void setMaxPlayer(Player& player);

private:
    Board MiniMaxDecision(Board* currentBoard);

    // Evaluation Function State
    int evalutaionFunciton(Board& currentBoard, Player player);
    // max function
    int maxValue(Board& childBoard, int alpha, int beta);
    // min function
    int minValue(Board& childBoard, int alpha, int beta);
    // Is terminal state or depth bound
    bool isTerminalStateOrDepthBound(Board& childBoard);

    // Evaluation Function Helpers
    // Huerstic Function
    int heuristic(const Board& gameBoard, const Player& player);
    // Checking For Various Possible Wins Acros Different Conditions
    int checkRow(const Board& gameBoard, const Player& player);
    int checkColumns(const Board& gameBoard, const Player& player);
    int checkDiagonal(const Board& gameBoard, const Player& player);
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
