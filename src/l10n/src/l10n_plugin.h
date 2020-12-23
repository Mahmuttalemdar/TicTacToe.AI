#ifndef L10N_PLUGIN_H
#define L10N_PLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QQmlExtensionPlugin>

/**
 * @brief The LocalizationPlugin class which is defined to
 * store all data and models
 */
class LocalizationPlugin : public QQmlExtensionPlugin
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "Localization")

    public:
        /**
         * @brief C-tor
         * @param parent; parent QObject based component
         */
        LocalizationPlugin(QObject *parent = nullptr);

        /**
         * @brief D-tor
         */
        ~LocalizationPlugin() override;

        /**
         * @brief Registering all qml types
         * @param uri
         */
        void registerTypes(const char *uri) override;

        /**
         * @brief initializeEngine
         * @param engine
         */
        void initializeEngine(QQmlEngine *engine, const char *uri) override;

    private:
        bool registered;
};

#endif // L10N_PLUGIN_H
