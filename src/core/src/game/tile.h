#ifndef TILE_H
#define TILE_H

#include "player.h"

#include <memory>

/**
 * @brief The Tile class: holds the visual representation
 * of Symbol and State for piece of board
 */
class Tile
{
public:
    // Tile states
    // enum class State { Normal, Dragged, Highlighted, Removed, Selected };
    enum class State
    {
        BLANK,
        OCCUPIED
    };

    /**
     * @brief C-tor
     * @param player: HUMAN, AI or NONE
     */
    Tile();

    /**
     * @brief D-tor
     */
    virtual ~Tile();

    /**
     * @brief Modifies the tile row
     * @param row: unsigned int
     */
    void SetRow(const unsigned int& row);

    /**
     * @brief Returns current row value
     * @return row: unsigned int
     */
    const unsigned int& GetRow() const;

    /**
     * @brief Modifies the tile column
     * @param column: unsigned int
     */
    void SetColumn(const unsigned int& column);

    /**
     * @brief Returns current column value
     * @return column: unsigned int
     */
    const unsigned int& GetColumn() const;

    /**
     * @brief SetPlayer: Set player to selected tile
     * @param player: Player
     */
    void SetPlayer(const Player& player);

    /**
     * @brief Which player played to this tile
     * @return HUMAN, AI or NONE
     */
    const Player& GetPlayer() const;

    /**
     * @brief Modifies the tile column
     * @param column: unsigned int
     */
    void SetState(const State& state);

    /**
     * @brief Returns current state of tile
     * @return State
     */
    const State& GetState() const;

private:
    unsigned int m_row = 0;
    unsigned int m_column = 0;
    State m_state;
    Player m_player;
};

#endif // TILE_H
