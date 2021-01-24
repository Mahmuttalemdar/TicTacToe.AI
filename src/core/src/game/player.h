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
     * @param constructs an object depend on player type
     */
    Player(const Type& type = Type::NONE);

    /**
     * @brief D-tor
     */
    virtual ~Player();

    /**
     * @brief Setter: Modifies the player type
     * @param value: player type (HUMAN or AI)
     */
    void setType(const Type& type);

    /**
     * @brief Getter: Returns current type of type
     * @return value: player type (HUMAN or AI)
     */
    const Type& type() const;

    /**
     * @brief Setter: Modifies the player name
     * @param value: Name of Human player or Default AI Name
     */
    void setPlayerName(const QString& playerName);

    /**
     * @brief Getter: Returns current name of player
     * @return value: playerName as String
     */
    const QString& playerName() const;

private:
    // Player type
    Type m_type;

    // Player name
    QString m_playerName;
};

#endif // PLAYER_H
