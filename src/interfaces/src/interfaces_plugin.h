#ifndef INTERFACES_PLUGIN_H
#define INTERFACES_PLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QQmlExtensionPlugin>

/**
 * @brief The InterfacesPlugin class which is defined to
 * store all data and models
 */
class InterfacesPlugin: public QQmlExtensionPlugin
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "Interfaces")

    public:
        /**
         * @brief C-tor
         * @param parent; parent QObject based component
         */
        InterfacesPlugin(QObject *parent = nullptr);

        /**
         * @brief D-tor
         */
        ~InterfacesPlugin() override;

        /**
         * @brief Registering all qml types
         * @param uri
         */
        void registerTypes(const char *uri) override;

        /**
         * @brief initializeEngine
         * @param engine
         */
        void initializeEngine(QQmlEngine *engine, const char * uri) override;

    private:
        bool registered;
};

#endif // INTERFACES_PLUGIN_H
