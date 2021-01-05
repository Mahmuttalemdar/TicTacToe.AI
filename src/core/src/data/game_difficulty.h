#ifndef GAME_DIFFICULTY_H
#define GAME_DIFFICULTY_H

#include <QString>
#include <QObject>

class GameDifficulty : public QObject
{
        Q_OBJECT
        Q_PROPERTY(Difficulty difficulty READ difficulty WRITE setDifficulty NOTIFY difficultyChanged)

    public:
        enum Difficulty {
            None = 0,
            Easy,
            Medium,
            Hard
        };
        Q_ENUM(Difficulty)

        /**
         * @brief C-tor
         * @param parent; parent QObject based component
         */
        GameDifficulty(QObject* parent = nullptr);

        /**
         * @brief D-tor
         */
        ~GameDifficulty();

        Difficulty difficulty() const;

        unsigned int getDifficultyValue() const;

    public slots:
        void setDifficulty(Difficulty difficulty);
    signals:
        void difficultyChanged(Difficulty difficulty);

    private:
        Difficulty m_difficulty;
};

Q_DECLARE_METATYPE(GameDifficulty *)
Q_DECLARE_METATYPE(const GameDifficulty *)

#endif // GAME_DIFFICULTY_H
