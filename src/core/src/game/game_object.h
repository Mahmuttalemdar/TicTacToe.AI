#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <QUuid>

/**
 * @brief The GameObject class: Entity of object which is represented
 * on UI or Backend side
 */
class GameObject
{
    public:
        /**
         * @brief C-tor
         */
        GameObject();

        /**
         * @brief D-tor
         */
        virtual ~GameObject();

        /**
         * @brief get unique id o object
         * @return
         */
        const QUuid& getID() const;

    private:
        QUuid m_id;

};

#endif // GAME_OBJECT_H
