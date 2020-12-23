#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief The Player class: holds the all player
 * data, type and reprensetation
 */
class Player
{
    public:
        // Player types
        enum class Type { HUMAN, AI, NONE };

        /**
         * @brief C-tor
         * @param symbol: X or O
         */
        Player(const Type& type = Type::NONE);

        /**
         * @brief D-tor
         */
        virtual ~Player();

        /**
         * @brief Modifies the player type
         * @param type: HUMAN or AI
         */
        void SetType(const Type& type);

        /**
         * @brief Returns current type of type
         * @return Type
         */
        const Type& GetType() const;

    private:
        Type m_type;
};

#endif // PLAYER_H
