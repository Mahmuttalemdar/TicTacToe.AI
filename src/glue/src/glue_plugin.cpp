#include <QQmlContext>
#include <QQmlEngine>

#include "entrance.h"
#include "glue_plugin.h"

static inline void initResources()
{}

static inline void cleanupResources()
{}

static void initProviders() {}

static void cleanupProviders() {}

GluePlugin::GluePlugin(QObject *parent)
    : QQmlExtensionPlugin(parent)
    , registered(false)
{}

GluePlugin::~GluePlugin()
{
    if (registered)
    {
        cleanupResources();
        cleanupProviders();
    }
}

void GluePlugin::registerTypes(const char * uri)
{
    Q_UNUSED(uri)

    registered = true;
    initProviders();
}

void GluePlugin::initializeEngine(QQmlEngine *engine, const char *)
{
    engine->rootContext()->setContextProperty("entrance", Entrance::getInstance());
}
