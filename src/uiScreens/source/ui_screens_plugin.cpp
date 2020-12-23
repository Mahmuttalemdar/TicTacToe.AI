#include "ui_screens_plugin.h"

#include <QQmlContext>
#include <QQmlEngine>

static inline void initResources()
{
    // Initialize resources
    Q_INIT_RESOURCE(UIScreens);
}

static inline void cleanupResources()
{
    // Cleanup resources
    Q_CLEANUP_RESOURCE(UIScreens);
}

static void initProviders() {}

static void cleanupProviders() {}

UIScreensPlugin::UIScreensPlugin(QObject *parent)
    : QQmlExtensionPlugin(parent)
    , registered(false)
{
    initResources();
}

UIScreensPlugin::~UIScreensPlugin()
{
    if (registered)
    {
        cleanupResources();
        cleanupProviders();
    }
}
void UIScreensPlugin::registerTypes(const char *uri)
{
    Q_UNUSED(uri)

    registered = true;
    initProviders();

    qmlRegisterModule("UIScreens.StartScreen", 1, 0);
    qmlRegisterModule("UIScreens.LoginScreen", 1, 0);
    qmlRegisterModule("UIScreens.DetectionScreen", 1, 0);
    qmlRegisterModule("UIScreens.NFCScreen", 1, 0);
}

void UIScreensPlugin::initializeEngine(QQmlEngine *engine, const char * uri)
{
    Q_UNUSED(uri)
    engine->addImportPath(QLatin1String(":/imports"));
}
