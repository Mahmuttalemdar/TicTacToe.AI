#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <QObject>
#include <memory>

#include "core/src/game/board.h"
#include "core/src/game/player.h"
#include "core/src/ai/ai_player.h"

class GameController : public QObject
{
        Q_OBJECT
        Q_PROPERTY(unsigned int gridSize READ gridSize WRITE setGridSize NOTIFY gridSizeChanged)
        Q_PROPERTY(unsigned int aiLevel READ aiLevel WRITE setAiLevel NOTIFY aiLevelChanged)
        Q_PROPERTY(bool isPlayLock READ isPlayLock WRITE setIsPlayLock NOTIFY isPlayLockChanged)
        Q_PROPERTY(Board* gameBoard READ gameBoard NOTIFY gameBoardChanged)

    public:
        /**
          * @brief C-tor
          */
        GameController(const unsigned int gridSize = 3, const unsigned int aiLevel = 2, QObject* parent = nullptr);

        /**
          * @brief D-tor
          */
        ~GameController();

        Q_INVOKABLE bool isPlayed(unsigned int row, unsigned int column);
        Q_INVOKABLE void humanPlayedAt(unsigned int row, unsigned int column);

        unsigned int gridSize() const;
        unsigned int aiLevel() const;
        bool isPlayLock() const;

        Board* gameBoard() const;

    private:
        void aiThinkAndPlay();

    public slots:
        void setGridSize(unsigned int gridSize);
        void setAiLevel(unsigned int aiLevel);
        void setIsPlayLock(bool isPlayLock);
        void handleAIPlayedAt(unsigned int row, unsigned int column);

    signals:
        void gridSizeChanged(unsigned int gridSize);
        void aiLevelChanged(unsigned int aiLevel);
        void isPlayLockChanged(bool isPlayLock);
        void aiPlayedAt(unsigned int row, unsigned int column);
        void updateAIPlayerOnUI(unsigned int row, unsigned int column);

        void gameBoardChanged(Board* gameBoard);

        private:
        unsigned int m_gridSize;
        unsigned int m_aiLevel = 0;

        //Stop A Player From Playing A Second Time Until The Lock Is Released
        bool m_isPlayLock = false;

        Player m_humanPlayer = Player::Type::NONE;
        Player m_aiPlayer;
        Board* m_gameBoard;
        AIPlayer* m_aiImplement;
};

#endif //GAME_CONTROLLER_H
