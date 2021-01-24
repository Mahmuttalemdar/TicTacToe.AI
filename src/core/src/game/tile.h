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
    enum class State
    {
        BLANK,
        OCCUPIED
    };

    /**
     * @brief C-tor
     */
    Tile();

    /**
     * @brief D-tor
     */
    virtual ~Tile();

    /**
     * @brief Setter: set row number to tile
     * @param value: row number of tile
     */
    void setRow(const unsigned int& row);

    /**
     * @brief Getter: get current row number
     * @return value: row number of tile
     */
    const unsigned int& row() const;

    /**
     * @brief Setter: set column number to tile
     * @param value: column number of tile
     */
    void setColumn(const unsigned int& column);

    /**
     * @brief Getter: get current column number
     * @return value: column number of tile
     */
    const unsigned int& column() const;

    /**
     * @brief Setter: set player to selected tile
     * @param value: Player data
     */
    void setPlayer(const Player& player);

    /**
     * @brief Getter: get which player played to this tile
     * @return value: HUMAN, AI or NONE
     */
    const Player& player() const;

    /**
     * @brief Setter: set state of tile, which player played or tile is empty:BLANK?
     * @param value: tile state
     */
    void setState(const State& state);

    /**
     * @brief Getter: get current state of tile
     * @return value: tile state
     */
    const State& state() const;

private:
    // Tile row value
    unsigned int m_row = 0;

    // Tile column value
    unsigned int m_column = 0;

    // State of tile
    State m_state;

    // Which player using this tile or BLANK
    Player m_player;
};

#endif // TILE_H
