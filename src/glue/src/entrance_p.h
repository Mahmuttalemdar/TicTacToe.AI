#ifndef ENTRANCE_P_H
#define ENTRANCE_P_H

#include <memory>

#include "statechart/Main.h"
#include <core/src/settings/game_settings.h>
#include <interfaces/src/controllers/game_controller.h>

struct EntrancePrivate
{
    // CORE
    std::unique_ptr<statechart::Main> statechart{};
    std::unique_ptr<GameSettings> gameSettings{};

    // INTERFACES
    std::unique_ptr<GameController> gameController{};
};

#endif // ENTRANCE_P_H
