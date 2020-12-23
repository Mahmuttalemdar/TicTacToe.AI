#ifndef BOARD_STATE_H
#define BOARD_STATE_H

#include "game_object.h"
#include "board.h"
#include "player.h"

#include <vector>
#include <memory>


/**
 * @brief The BoardModel class - Represent A Board Instance
 */
class BoardModel : public GameObject
{
    public:
        /**
         * @brief C-tor
         * @param gridSize : row and col size of board
         */
        BoardModel(const unsigned int gridSize = 3);

        /**
         * @brief play at
         * @param row
         * @param column
         * @param playerCharacter
         */
        void playAt(unsigned int row, unsigned int column, Player player);

        /**
         * @brief drawBoard: draws the current playing board
         */
        void drawBoard() const;

        //GameState checkGameState() const;

        std::vector<std::unique_ptr<Board>> generatePossibleStates(Player player);

        bool nextChildBoard(Player player, Board* childBoard);

        void reset();

    private:
        unsigned int m_gridSize = 0;

        std::unique_ptr<Board> m_gameBoard;
        std::shared_ptr<Board> m_childrenBoard = nullptr;
};


#endif // BOARD_STATE_H
