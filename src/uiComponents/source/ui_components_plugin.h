#ifndef UI_COMPONENTS_PLUGIN_H
#define UI_COMPONENTS_PLUGIN_H

#include <QObject>
#include <QQmlExtensionPlugin>
#include <QtPlugin>

/**
 * @brief The UIComponentsPlugin class; providing
 * sub or custom components for screens
 */
class UIComponentsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "UIComponents")

public:
    /**
     * @brief C-tor
     * @param parent: constructs an object with parent object parent
     */
    UIComponentsPlugin(QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~UIComponentsPlugin() override;

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

#endif // UI_COMPONENTS_PLUGIN_H
