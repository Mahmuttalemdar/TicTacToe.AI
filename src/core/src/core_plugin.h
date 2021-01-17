#ifndef CORE_PLUGIN_H
#define CORE_PLUGIN_H

#include <QObject>
#include <QQmlExtensionPlugin>
#include <QtPlugin>

/**
 * @brief The CorePlugin class which is defined to
 * store all data and models
 */
class CorePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Core")

public:
    /**
     * @brief C-tor
     * @param parent; parent QObject based component
     */
    CorePlugin(QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~CorePlugin() override;

    /**
     * @brief Registering all qml types
     * @param uri
     */
    void registerTypes(const char* uri) override;

    /**
     * @brief initializeEngine
     * @param engine
     */
    void initializeEngine(QQmlEngine* engine, const char* uri) override;

private:
    bool registered;
};

#endif // CORE_PLUGIN_H
