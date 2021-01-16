#include "entrance.h"
#include "entrance_p.h"

#include <QtPlugin>
#include <QPluginLoader>
#include <QQmlExtensionPlugin>
#include <QDebug>

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

    m_app = new QGuiApplication(argc, argv);
    m_engine = new QQmlApplicationEngine();

    // Initialize objects and environments
    initialize();

    // Register all static plugins
    registerPlugins();

    // Initialize Qml Engine
    createQQmlEngines();

    // Start Statechart
    startStateChart();

    return m_app->exec();
}

statechart::Main *Entrance::statechart() const
{
    return data->statechart.get();
}

GameSettings* Entrance::gameSettings() const
{
    return data->gameSettings.get();
}

Theme* Entrance::theme() const
{
    return data->theme.get();
}

GameController* Entrance::gameController() const
{
    return data->gameController.get();
}

void Entrance::configureQGuiApplication() const
{
    QGuiApplication::setApplicationName("TicTacToe.AI");
    QGuiApplication::setOrganizationName("AlemdarCorp");
    QGuiApplication::setApplicationVersion("0.1.0");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
}

void Entrance::registerPlugins()
{
    try
    {
        Q_IMPORT_PLUGIN(CorePlugin)
        Q_IMPORT_PLUGIN(UIComponentsPlugin)
        Q_IMPORT_PLUGIN(UIScreensPlugin)
        Q_IMPORT_PLUGIN(InterfacesPlugin)
        Q_IMPORT_PLUGIN(GluePlugin)

        for (auto const &plugin : QPluginLoader::staticPlugins())
        {
            auto name = plugin.metaData()["IID"].toString("");
            auto iid = name.toStdString();
            auto instance = qobject_cast<QQmlExtensionPlugin*>(plugin.instance());

            qDebug() << "Initialized plugin: "<< instance << " : "<<iid.c_str();
            if (instance != nullptr)
            {
                instance->registerTypes(iid.c_str());
                instance->initializeEngine(m_engine, iid.c_str());
            }
        }
    }
    catch (std::exception& e)
    {
        qCritical() << "Failed to register plugins: " << e.what();
    }
}

void Entrance::createQQmlEngines() const
{
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    m_engine->load(url);
}

void Entrance::startStateChart() const
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

void Entrance::initialize() const
{
    // Initialize objects
    data->statechart = std::make_unique<statechart::Main>();
    data->gameSettings = std::make_unique<GameSettings>();
    data->theme = std::make_unique<Theme>();
    data->gameController = std::make_unique<GameController>(data->gameSettings.get());
    data->gameController->setStateChart(data->statechart.get());
}
