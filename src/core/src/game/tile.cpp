#include "tile.h"
#include "player.h"

Tile::Tile()
  : m_row(0)
  , m_column(0)
  , m_state(State::BLANK)
  , m_player(Player::Type::NONE)
{}

Tile::~Tile() {}

void Tile::SetRow(const unsigned int& row)
{
    m_row = row;
}

const unsigned int& Tile::GetRow() const
{
    return m_row;
}

void Tile::SetColumn(const unsigned int& column)
{
    m_column = column;
}

const unsigned int& Tile::GetColumn() const
{
    return m_column;
}

void Tile::SetPlayer(const Player& player)
{
    if (player.GetType() == Player::Type::NONE) {
        SetState(State::BLANK);
    } else {
        SetState(State::OCCUPIED);
    }

    m_player = player;
}

const Player& Tile::GetPlayer() const
{
    return m_player;
}

void Tile::SetState(const Tile::State& state)
{
    m_state = state;
}

const Tile::State& Tile::GetState() const
{
    return m_state;
}
