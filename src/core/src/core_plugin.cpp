#include "core_plugin.h"
#include "src/theme/theme.h"
#include "src/theme/colors.h"
#include "src/theme/sizes.h"
#include "src/theme/fonts.h"

#include "src/config/app_config.h"
#include "src/data/game_difficulty.h"

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

CorePlugin::CorePlugin(QObject *parent)
    : QQmlExtensionPlugin(parent)
    , registered(false)
{
    initResources();
}

CorePlugin::~CorePlugin()
{
    if (registered)
    {
        cleanupResources();
        cleanupProviders();
    }
}

void CorePlugin::registerTypes(const char * uri)
{
    Q_UNUSED(uri)

    registered = true;
    initProviders();

    qmlRegisterType<Theme>("Core.Theme", 1, 0, "Theme");
    qmlRegisterType<Colors>("Core.Theme", 1, 0, "Colors");
    qmlRegisterType<Sizes>("Core.Theme", 1, 0, "Sizes");
    qmlRegisterType<Fonts>("Core.Theme", 1, 0, "Fonts");

    qmlRegisterType<AppConfig>("Core.Data", 1, 0, "AppConfig");
    qmlRegisterType<GameDifficulty>("Core.Data", 1, 0, "GameDifficulty");
}

void CorePlugin::initializeEngine(QQmlEngine *engine, const char * uri)
{
    Q_UNUSED(engine)
    Q_UNUSED(uri)
}
