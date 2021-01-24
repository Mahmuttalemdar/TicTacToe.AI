#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include <vector>

#include <QList>
#include <QObject>
#include <QPoint>

class Tile;
class Player;

/**
 * @brief The Board class which store all board data, player and curren tile list
 */
class Board : public QObject
{
    Q_OBJECT
    Q_PROPERTY(GameState gameState READ gameState WRITE setGameState NOTIFY gameStateChanged)

public:
    enum GameState
    {
        WON = 0,
        LOSS,
        ONGOING,
        DRAW
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
    Board& operator=(const Board& board);

    /**
     * @brief Special constructor for create new board state
     * from current state
     */
    Board(const Board& board, unsigned int row, unsigned int column, Player player);

    /**
     * @brief Move C-tor
     */
    Board(Board&& board);

    /**
     * @brief Move Operator =
     */
    Board& operator=(Board&& board);

    /**
     * @brief D-tor
     */
    virtual ~Board();

    /**
     * @brief GetGameBoard
     * @return board grid
     */
    const std::vector<std::vector<Tile>>& gameBoard();

    /**
     * @brief getTile: get tile by (row & colum) from current instance of tile list
     * @param row: coordinate x on board
     * @param column: coordinate y on board
     * @return Tile data
     */
    const Tile& tile(unsigned int row, unsigned int column) const;

    /**
     * @brief Getter: get grid size of current board
     * @return grid size value
     */
    unsigned int gridSize() const;

    /**
     * @brief Setter: set grid size to current board
     * @param value: grid size
     */
    void setGridSize(unsigned int value);

    /**
     * @brief Getter: get utility value of current board
     * @return value: utility value of current board
     */
    const int& utilityValue() const;

    /**
     * @brief Setter: utility value to current board
     * @param value: utility value of current board
     */
    void setUtilityValue(const int& value);

    /**
     * @brief Getter: get depth value of current board
     * @return value: depth value of current board
     */
    unsigned int depth() const;

    /**
     * @brief Setter: utility value to current board
     * @param value: depth value of current board
     */
    void setDepth(unsigned int value);

    /**
     * @brief Getter: get played row value on current board
     * @return value: get played row value on current board
     */
    unsigned int rowPlayed() const;

    /**
     * @brief Getter: get played column value on current board
     * @return value: get played column value on current board
     */
    unsigned int columnPlayed() const;

    /**
     * @brief Getter: get cached last row played value on current board
     * @return value: cached last row played value on current board
     */
    unsigned int cachedLastRowPlayed() const;

    /**
     * @brief Setter: set cached last row played value to current board
     * @param value: cached last row played value on current board
     */
    void setCachedLastRowPlayed(unsigned int value);

    /**
     * @brief Getter: get cached last column played value on current board
     * @return value: cached last column played value on current board
     */
    unsigned int cachedLastColumnPlayed() const;

    /**
     * @brief Setter: set cached last column played value to current board
     * @param value: cached last column played value on current board
     */
    void setCachedLastColumnPlayed(unsigned int value);

    /**
     * @brief operator <<: overloaded operator to print current tile
     * @param os: osstream from current terminal
     * @param tile: Tile type
     * @return updated osstream
     */
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile);

    /**
     * @brief isPlayed: check is played this coordinat according to row & column values
     * @param row: coordinate x on board
     * @param column: coordinate y on board
     * @return true: this point already played, false: this point has BLANK tile
     */
    bool isPlayed(unsigned int row, unsigned int column);

    /**
     * @brief playAt: play at the point which is depending on coordinates and player type
     * @param row: coordinate x on board
     * @param column: coordinate y on board
     * @param player: Player data
     */
    void playAt(unsigned int row, unsigned int column, Player player);

    /**
     * @brief generatePossibleStates: generate possible child states from current board
     * @param player: Player data
     * @return vector of possible Board's
     */
    const std::vector<std::unique_ptr<Board>> generatePossibleStates(Player player);

    /**
     * @brief checkGameState: is game state WON, LOSS, ONGOING or DRAW
     * @return enum value of Game state from current Board
     */
    GameState checkGameState();

    /**
     * @brief nextChildBoard: try to generate possible next child board from current board
     * @param player: Player data
     * @param childBoard: generated possible child board
     * @return true: generated, false: not generated
     */
    bool nextChildBoard(Player player, std::shared_ptr<Board>& childBoard);

    /**
     * @brief restart: restart game with latest game settings
     */
    void restart();

    /**
     * @brief Getter: If somebody finished game with a WON result, get tile list according to him
     * @return list of tile which is played from winner player
     */
    Q_INVOKABLE QList<QPoint> winnerList();

    /**
     * @brief Getter: get game state value of current board
     * @return value: game state
     */
    GameState gameState() const;

public slots:
    /**
     * @brief Setter: set grid size to current board
     * @param value: grid size
     */
    void setGameState(GameState gameState);

signals:
    /**
     * @brief Signal: emit signal when difficulty changed
     * @param value: gameState
     */
    void gameStateChanged(GameState gameState);

private:
    // Grid size of current board
    unsigned int m_gridSize = 0;

    // Utility value of current board
    int m_utilityValue = 0;

    // Depth value of current board
    unsigned int m_depth = 0;

    // Row number which is played on current board
    unsigned int m_rowPlayed = 0;

    // Column number which is played on current board
    unsigned int m_columnPlayed = 0;

    // Cached last row number which is cached on current board
    unsigned int m_cachedLastRowPlayed = 0;

    // Cached last column number which is cached on current board
    unsigned int m_cachedLastColumnPlayed = 0;

    // Data of game board
    std::vector<std::vector<Tile>> m_gameBoard;

    // Child board data
    std::shared_ptr<Board> m_childrenBoard = nullptr;

    // If game and with WON result, store winning path
    QList<QPoint> m_winnerList;

    // Current game state
    GameState m_gameState;
};

Q_DECLARE_METATYPE(Board*)
Q_DECLARE_METATYPE(const Board*)

#endif // BOARD_H
