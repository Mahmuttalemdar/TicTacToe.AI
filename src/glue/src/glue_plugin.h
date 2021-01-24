#ifndef GLUE_PLUGIN_H
#define GLUE_PLUGIN_H

#include <QObject>
#include <QQmlExtensionPlugin>
#include <QtPlugin>

/**
 * @brief The GluePlugin class which is defined
 * to collect all module and module data's and send them to UI side
 */
class GluePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Glue")

public:
    /**
     * @brief C-tor
     * @param parent: constructs an object with parent object parent
     */
    GluePlugin(QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~GluePlugin() override;

    /**
     * @brief registerTypes: Registering all qml types
     * @param uri
     */
    void registerTypes(const char* uri) override;

    /**
     * @brief initializeEngine: initialize qml engine
     * @param engine
     */
    void initializeEngine(QQmlEngine* engine, const char* uri) override;

private:
    bool registered;
};

#endif // GLUE_PLUGIN_H
