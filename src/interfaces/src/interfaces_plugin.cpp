#include "interfaces_plugin.h"
#include "src/controllers/game_controller.h"

#include <QQmlContext>
#include <QQmlEngine>

static inline void initResources()
{}

static inline void cleanupResources()
{}

static void initProviders() {}

static void cleanupProviders() {}

InterfacesPlugin::InterfacesPlugin(QObject *parent)
    : QQmlExtensionPlugin(parent)
    , registered(false)
{
    initResources();
}

InterfacesPlugin::~InterfacesPlugin()
{
    if (registered)
    {
        cleanupResources();
        cleanupProviders();
    }
}

void InterfacesPlugin::registerTypes(const char * uri)
{
    Q_UNUSED(uri)

    registered = true;
    initProviders();

    qmlRegisterType<GameController>("Core.Interface", 1, 0, "GameController");
}

void InterfacesPlugin::initializeEngine(QQmlEngine *engine, const char * uri)
{
    Q_UNUSED(engine)
    Q_UNUSED(uri)
}
