#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include "core/src/data/tile_shape.h"
#include "core/src/data/game_difficulty.h"

#include <QObject>
#include <QString>

/**
 * @brief The AppConfig class defined that is storing all
 * configuration types and default values
 */
class AppConfig : public QObject
{
        Q_OBJECT
        Q_PROPERTY(TileShape* selectedShape READ selectedShape WRITE setSelectedShape NOTIFY selectedShapeChanged)
        Q_PROPERTY(GameDifficulty* gameDifficulty READ gameDifficulty WRITE setGameDifficulty NOTIFY gameDifficultyChanged)
        Q_PROPERTY(unsigned int gridSize READ gridSize WRITE setGridSize NOTIFY gridSizeChanged)

    public:
        /**
         * @brief C-tor
         * @param parent : QObject parent
         */
        AppConfig(QObject *parent = nullptr);

        /**
         * @brief C-tor
         * @param parent : QObject parent
         */
        ~AppConfig();

        TileShape* selectedShape() const;

        GameDifficulty* gameDifficulty() const;

        unsigned int gridSize() const;

    public slots:
        void setSelectedShape(TileShape* selectedShape);
        void setGameDifficulty(GameDifficulty* gameDifficulty);
        void setGridSize(unsigned int gridSize);

    signals:
        void selectedShapeChanged(TileShape* selectedShape);
        void gameDifficultyChanged(GameDifficulty* gameDifficulty);
        void gridSizeChanged(unsigned int gridSize);

    private:
        TileShape* m_selectedShape;
        GameDifficulty* m_gameDifficulty;
        unsigned int m_gridSize;
};

#endif // APP_CONFIG_H
