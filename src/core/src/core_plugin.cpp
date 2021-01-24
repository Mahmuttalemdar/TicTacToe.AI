#include "core_plugin.h"

#include "src/data/game_difficulty.h"
#include "src/data/tile_shape.h"
#include "src/game/board.h"
#include "src/settings/game_settings.h"

#include <QQmlContext>
#include <QQmlEngine>

static inline void initResources()
{
    // Initialize resources
    Q_INIT_RESOURCE(Core);
}

static inline void cleanupResources()
{
    // Cleanup resources
    Q_CLEANUP_RESOURCE(Core);
}

static void initProviders() {}

static void cleanupProviders() {}

CorePlugin::CorePlugin(QObject* parent)
  : QQmlExtensionPlugin(parent)
  , registered(false)
{
    initResources();
}

CorePlugin::~CorePlugin()
{
    if (registered) {
        cleanupResources();
        cleanupProviders();
    }
}

void CorePlugin::registerTypes(const char* uri)
{
    Q_UNUSED(uri)

    registered = true;
    initProviders();

    qmlRegisterType<GameSettings>("Core.Data", 1, 0, "GameSettings");
    qmlRegisterType<GameDifficulty>("Core.Data", 1, 0, "GameDifficulty");
    qmlRegisterType<Board>("Core.Data", 1, 0, "GameBoard");
}

void CorePlugin::initializeEngine(QQmlEngine* engine, const char* uri)
{
    Q_UNUSED(engine)
    Q_UNUSED(uri)
}
