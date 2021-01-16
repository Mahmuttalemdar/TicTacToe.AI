#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <ostream>

#include <QList>
#include <QPoint>
#include <QObject>

class Tile;
class Player;

/**
 * @brief The Player class: holds the board state
 * and board grid size
 */
class Board : public QObject
{
        Q_OBJECT
        Q_PROPERTY(GameState gameState READ gameState WRITE setGameState NOTIFY gameStateChanged)
    public:
        enum GameState
        {
            WON = 0
            , LOSS
            , ONGOING
            , DRAW
        };
        Q_ENUM(GameState)

        /**
         * @brief C-tor
         * @param gridSize: size of board
         */
        Board(unsigned int gridSize = 3);

        /**
         * @brief Copy C-tor
         */
        Board(const Board& board);

        /**
         * @brief Copy Operator =
         */
        Board& operator =(const Board& board);

        /**
         * @brief Special constructor for create new board state
         * from current state
         */
        Board(const Board& board, unsigned  int row, unsigned int  column, Player player);

        /**
         * @brief Move C-tor
         */
        Board(Board&& board);

        /**
         * @brief Move Operator =
         */
        Board& operator =(Board&& board);

        /**
         * @brief D-tor
         */
        virtual ~Board();

        /**
         * @brief GetGameBoard
         * @return board grid
         */
        const std::vector<std::vector<Tile>>& getGameBoard();

        /**
         * @brief Get tile from tile board
         * @param row
         * @param column
         * @return : Tile
         */
        const Tile& getTile(unsigned int row, unsigned int column) const;

        /**
         * @brief getGridSize of current board
         * @return : grid size
         */
        unsigned int getGridSize() const;

        /**
         * @brief setGridSize to current board
         * @param value: grid size
         */
        void setGridSize(unsigned int value);

        /**
         * @brief getUtilityValue
         * @return
         */
        const int& getUtilityValue() const;

        /**
         * @brief setUtilityValue
         * @param value
         */
        void setUtilityValue(const int& value);

        /**
         * @brief getDepth
         * @return
         */
        unsigned int getDepth() const;

        /**
         * @brief setDepth
         * @param value
         */
        void setDepth(unsigned int value);

        /**
         * @brief getRow_played
         * @return
         */
        unsigned int getRowPlayed() const;

        /**
         * @brief getColumnPlayed
         * @return
         */
        unsigned int getColumnPlayed() const;

        /**
         * @brief getCachedLastRowPlayed
         * @return
         */
        unsigned int getCachedLastRowPlayed() const;

        /**
         * @brief setDepth
         * @param value
         */
        void setCachedLastRowPlayed(unsigned int value);

        /**
         * @brief getCachedLastRowPlayed
         * @return
         */
        unsigned int getCachedLastColumnPlayed() const;

        /**
         * @brief setDepth
         * @param value
         */
        void setCachedLastColumnPlayed(unsigned int value);

        friend std::ostream& operator<<(std::ostream& os, const Tile& tile);

        bool isPlayed(unsigned int row, unsigned int column);

        /**
         * @brief play at
         * @param row
         * @param column
         * @param playerCharacter
         */
        void playAt(unsigned int row, unsigned int column, Player player);

        /**
         * @brief generatePossibleStates: Guess possible states of current board
         * @param player
         * @return
         */
        const std::vector<std::unique_ptr<Board>> generatePossibleStates(Player player);

        GameState checkGameState();

        bool nextChildBoard(Player player, std::shared_ptr<Board>& childBoard);

        void restart();

        Q_INVOKABLE QList<QPoint> getWinnerList();

        GameState gameState() const;

    public slots:
        void setGameState(GameState gameState);

    signals:
        void gameStateChanged(GameState gameState);

    private:
        unsigned int m_gridSize = 0;
        int m_utilityValue = 0;
        unsigned int m_depth = 0;
        unsigned int m_rowPlayed = 0;
        unsigned int m_columnPlayed = 0;
        unsigned int m_cachedLastRowPlayed = 0;
        unsigned int m_cachedLastColumnPlayed = 0;

        std::vector<std::vector<Tile>> m_gameBoard;
        std::shared_ptr<Board> m_childrenBoard = nullptr;
        QList<QPoint> m_winnerList;
        GameState m_gameState;
};

Q_DECLARE_METATYPE(Board *)
Q_DECLARE_METATYPE(const Board *)

#endif // BOARD_H
