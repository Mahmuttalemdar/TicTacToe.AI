#include "tile.h"
#include "player.h"

Tile::Tile()
  : m_row(0)
  , m_column(0)
  , m_state(State::BLANK)
  , m_player(Player::Type::NONE)
{}

Tile::~Tile() {}

void Tile::setRow(const unsigned int& row)
{
    m_row = row;
}

const unsigned int& Tile::row() const
{
    return m_row;
}

void Tile::setColumn(const unsigned int& column)
{
    m_column = column;
}

const unsigned int& Tile::column() const
{
    return m_column;
}

void Tile::setPlayer(const Player& player)
{
    if (player.type() == Player::Type::NONE) {
        setState(State::BLANK);
    } else {
        setState(State::OCCUPIED);
    }

    m_player = player;
}

const Player& Tile::player() const
{
    return m_player;
}

void Tile::setState(const Tile::State& state)
{
    m_state = state;
}

const Tile::State& Tile::state() const
{
    return m_state;
}
