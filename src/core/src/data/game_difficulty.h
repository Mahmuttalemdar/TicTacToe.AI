#ifndef GAME_DIFFICULTY_H
#define GAME_DIFFICULTY_H

#include <QObject>
#include <QString>

/**
 * @brief The GameDifficulty class which is store difficulty level of game
 */
class GameDifficulty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Difficulty difficulty READ difficulty WRITE setDifficulty NOTIFY difficultyChanged)

public:

    enum Difficulty
    {
        None = 0,
        Easy,
        Medium,
        Hard
    };
    Q_ENUM(Difficulty)

    /**
     * @brief C-tor
     * @param constructs an object with parent object parent
     */
    GameDifficulty(QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~GameDifficulty();

    /**
     * @brief Getter: get difficulty value of game
     * @return value: enum value of GameDifficulty
     */
    Difficulty difficulty() const;

    /**
     * @brief Getter: convert enum value to difficulty weight
     * @return value: weight of GameDifficulty
     */
    unsigned int getDifficultyValue() const;

public slots:
    /**
     * @brief Setter: set difficulty of game
     * @param value: enum value of GameDifficulty
     */
    void setDifficulty(Difficulty difficulty);
signals:
    /**
     * @brief Signal: emit signal when difficulty changed
     * @param value: enum value of GameDifficulty
     */
    void difficultyChanged(Difficulty difficulty);

private:
    // enum value of GameDifficulty
    Difficulty m_difficulty;
};

Q_DECLARE_METATYPE(GameDifficulty*)
Q_DECLARE_METATYPE(const GameDifficulty*)

#endif // GAME_DIFFICULTY_H
