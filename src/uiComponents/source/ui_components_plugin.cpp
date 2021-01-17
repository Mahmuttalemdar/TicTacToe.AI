#include "ui_components_plugin.h"

#include <QQmlContext>
#include <QQmlEngine>

static inline void initResources()
{
    // Initialize resources
    Q_INIT_RESOURCE(Theme);
    Q_INIT_RESOURCE(UIComponents);
}

static inline void cleanupResources()
{
    // Cleanup resources
    Q_CLEANUP_RESOURCE(Theme);
    Q_CLEANUP_RESOURCE(UIComponents);
}

static void initProviders() {}

static void cleanupProviders() {}

UIComponentsPlugin::UIComponentsPlugin(QObject* parent)
  : QQmlExtensionPlugin(parent)
  , registered(false)
{
    initResources();
}

UIComponentsPlugin::~UIComponentsPlugin()
{
    if (registered) {
        cleanupResources();
        cleanupProviders();
    }
}

void UIComponentsPlugin::registerTypes(const char* uri)
{
    Q_UNUSED(uri)

    registered = true;
    initProviders();

    qmlRegisterModule("UIComponents.Backgrounds", 1, 0);
    qmlRegisterModule("UIComponents.Buttons", 1, 0);
    qmlRegisterModule("UIComponents.Sheets", 1, 0);
    qmlRegisterModule("UIComponents.Text", 1, 0);
}

void UIComponentsPlugin::initializeEngine(QQmlEngine* engine, const char* uri)
{
    Q_UNUSED(uri)
    engine->addImportPath(QLatin1String(":/imports"));
}
