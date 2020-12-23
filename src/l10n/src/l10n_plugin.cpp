#include "l10n_plugin.h"
#include <QObject>
#include <QtPlugin>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDebug>
#include <QtQml/QQmlExtensionPlugin>

static inline void initResources()
{}

static void initProviders()
{}

static void cleanupProviders()
{}

LocalizationPlugin::LocalizationPlugin(QObject *parent)
    : QQmlExtensionPlugin(parent)
    , registered(false)
{
    initResources();
    registerTypes(nullptr);
}

LocalizationPlugin::~LocalizationPlugin()
{
    if (registered) {
        cleanupProviders();
    }
}


void LocalizationPlugin::registerTypes(const char *uri)
{
    Q_UNUSED(uri)

    if (registered) {
        return;
    }

    qDebug() << "l10n plugin registering types";
    registered = true;
    initProviders();
}

void LocalizationPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(engine)
    Q_UNUSED(uri)
}
