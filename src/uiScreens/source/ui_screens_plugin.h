#ifndef UI_SCREENS_PLUGIN_H
#define UI_SCREENS_PLUGIN_H

#include <QObject>
#include <QQmlExtensionPlugin>
#include <QtPlugin>

/**
 * @brief The UIScreensPlugin class; providing
 * all screens and pages to qml engine
 */
class UIScreensPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "UIScreens")

public:
    /**
     * @brief C-tor
     * @param parent; parent QObject based component
     */
    UIScreensPlugin(QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~UIScreensPlugin() override;

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

#endif // UI_SCREENS_PLUGIN_H
