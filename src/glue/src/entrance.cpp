#include "entrance.h"
#include "entrance_p.h"

#include <memory>
#include <thread>
#include <chrono>

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QPluginLoader>
#include <QQmlExtensionPlugin>
#include <QObject>
#include <QWindow>
#include <QtPlugin>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QQmlComponent>
#include <QQuickView>
#include <QtPlugin>
#include <QDebug>
#include <QQmlComponent>
#include <QTimer>
#include <QDir>
#include <QtGlobal>
#include <QAbstractEventDispatcher>
#include <QSettings>
#include <QTimer>
#include <QProcess>

#ifdef QT_DEBUG
#include <QQmlDebuggingEnabler>
static QQmlDebuggingEnabler enabler;
#endif


/**
 * Static methods should be defined outside the class.
 */
Entrance* Entrance::instance = nullptr;
std::mutex Entrance::mutex;

Entrance::Entrance()
    : data{ new EntrancePrivate }
{
    // Init Resources From Libraies
    Q_INIT_RESOURCE(main);
    Q_INIT_RESOURCE(Core);
}

Entrance* Entrance::getInstance()
{
    if (instance == nullptr)
    {
        std::lock_guard <std::mutex> lock(mutex);
        if (instance == nullptr)
        {
            instance = new Entrance();
        }
    }
    return instance;
}


int Entrance::run(int argc, char *argv[])
{
    // Pre-Settings of Application
    configureQGuiApplication();

    app = new QGuiApplication(argc, argv);
    engine = new QQmlApplicationEngine();

    // Initialize objects and environments
    initialize();

    // Register all STATIC Plugins
    registerPlugins();

    // Initialize Qml Engine
    createQQmlEngines();

    // Start Statechart
    startStateChart();

    return app->exec();
}

statechart::Main *Entrance::statechart() const
{
    return data->statechart.get();
}

AppConfig* Entrance::appConfig() const
{
    return data->appConfig.get();
}

Theme* Entrance::theme() const
{
    return data->theme.get();
}

GameController* Entrance::gameController() const
{
    return data->gameController.get();
}

bool Entrance::configureQGuiApplication()
{
    QGuiApplication::setApplicationName("TicTacToe.AI");
    QGuiApplication::setOrganizationName("AlemdarCorp");
    QGuiApplication::setApplicationVersion("0.1.0");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    return true;
}

bool Entrance::registerPlugins()
{
    try
    {
        Q_IMPORT_PLUGIN(CorePlugin)
        Q_IMPORT_PLUGIN(UIComponentsPlugin)
        Q_IMPORT_PLUGIN(UIScreensPlugin)
        Q_IMPORT_PLUGIN(InterfacesPlugin)
        Q_IMPORT_PLUGIN(GluePlugin)

        // TODO :: LOG
        // KYCLog(Initializing plugins)
        for (auto const &plugin : QPluginLoader::staticPlugins())
        {
            auto name = plugin.metaData()["IID"].toString("");

            auto iid = name.toStdString();
            auto instance = qobject_cast<QQmlExtensionPlugin*>(plugin.instance());

            qDebug() << instance << iid.c_str();
            if (instance != nullptr)
            {
                instance->registerTypes(iid.c_str());
                instance->initializeEngine(engine, iid.c_str());
            }
        }
    }
    catch (std::exception& e)
    {
        // TODO :: LOG
        // KYCLog(e.what())
        qDebug() << "Failed to register plugins: " << e.what();
        return false;
    }

    return true;
}

bool Entrance::createQQmlEngines()
{
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine->load(url);

    return true;
}

void Entrance::startStateChart()
{
    if(data->statechart)
    {
        data->statechart->start();
    }
    else
    {
        qDebug() << "Statechat not initialized, please call 'initialize()' function first.";
    }
}

bool Entrance::initialize()
{
    // Initialize objects
    data->statechart = std::make_unique<statechart::Main>();
    data->appConfig = std::make_unique<AppConfig>();
    data->theme = std::make_unique<Theme>();
    data->gameController = std::make_unique<GameController>(3, 5);

    // Set app configs
    data->gameController->setAppConfig(data->appConfig.get());

    return true;
}


