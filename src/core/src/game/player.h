#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

/**
 * @brief The Player class: holds the all player
 * data, type and reprensetation
 */
class Player
{
public:
    // Player types
    enum class Type
    {
        HUMAN,
        AI,
        NONE
    };

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

    /**
     * @brief Modifies the player name
     * @param name: Name of Human player or Default AI Name
     */
    void SetPlayerName(const QString& playerName);

    /**
     * @brief Returns current name of player
     * @return playerName as String
     */
    const QString& GetPlayerName() const;

private:
    Type m_type;
    QString m_playerName;
};

#endif // PLAYER_H
