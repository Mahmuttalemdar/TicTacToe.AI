#include "player.h"

Player::Player(const Type& type)
    : m_type(type)
{}

Player::~Player()
{}

void Player::SetType(const Type &type)
{
    m_type = type;
}

const Player::Type& Player::GetType() const
{
    return m_type;
}

void Player::SetPlayerName(const QString& playerName)
{
    m_playerName = playerName;
}

const QString& Player::GetPlayerName() const
{
    return m_playerName;
}
