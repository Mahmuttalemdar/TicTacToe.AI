#include "game_object.h"

GameObject::GameObject()
    : m_id(QUuid::createUuid())
{}

GameObject::~GameObject()
{}

const QUuid& GameObject::getID() const
{
    return m_id;
}
