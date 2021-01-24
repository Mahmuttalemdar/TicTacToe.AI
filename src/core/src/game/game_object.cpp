#include "game_object.h"

GameObject::GameObject()
  : m_id(QUuid::createUuid())
{}

GameObject::~GameObject() {}

const QUuid& GameObject::id() const
{
    return m_id;
}
