#include "player.h"

Player::Player(const Type& type)
  : m_type(type)
{}

Player::~Player() {}

void Player::setType(const Type& type)
{
    m_type = type;
}

const Player::Type& Player::type() const
{
    return m_type;
}

void Player::setPlayerName(const QString& playerName)
{
    m_playerName = playerName;
}

const QString& Player::playerName() const
{
    return m_playerName;
}
