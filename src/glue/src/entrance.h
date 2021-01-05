#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <memory>
#include <thread>
#include <mutex>

#include <QObject>
#include <QWindow>
#include <QQmlComponent>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "statechart/Main.h"
#include <core/src/config/app_config.h>
#include <core/src/theme/theme.h>
#include <interfaces/src/controllers/game_controller.h>


struct EntrancePrivate;

/**
 * @brief The Entrance class;
 * Collection all modules and them functionality
 * Sending to UI Side
 */
class Entrance : public QObject
{
        Q_OBJECT
        Q_PROPERTY(statechart::Main *statechart READ statechart NOTIFY statechartChanged)
        Q_PROPERTY(AppConfig *appConfig READ appConfig NOTIFY appConfigChanged)
        Q_PROPERTY(Theme *theme READ theme NOTIFY themeChanged)
        Q_PROPERTY(GameController* gameController READ gameController NOTIFY gameControllerChanged)

    public:
        /**
         * Access Providers
         */
        statechart::Main* statechart() const;
        AppConfig* appConfig() const;
        Theme *theme() const;
        GameController* gameController() const;

    Q_SIGNALS:
        void appConfigChanged();
        void statechartChanged();
        void themeChanged();
        void gameControllerChanged();

    private:
        /**
         * C-tor of sdk engine
         * storing all application thread states and basic configurations
         */
        Entrance(void);

        /**
         * Deleted copy C-tor
         */
        Entrance(const Entrance &) = delete;

        /**
         * Deleted = operator for singleton object
         * @return reference of Entrance object
         */
        Entrance &operator=(const Entrance &) = delete;

        /**
         * D-tor of sdk engine
         */
        ~Entrance(void) = default;

    public:
        /**
        * retrieve global singleton Entrance instance
        * @return the only instance of Entrance in the app
        */
        static Entrance *getInstance(void);

        /**
         * @brief run
         * @param argc
         * @param argv
         * @return
         */
        int run(int argc, char *argv[]);

    private:
        /**
        * @brief Imports necessary plugins
        * @return
        */
        bool registerPlugins(void);

        /**
        * @brief Initialize QQmlApplicationEngine
        * @return
        */
        bool createQQmlEngines(void);

        /**
         * @brief startStateChart
         */
        void startStateChart(void);

        /**
         * @brief configureQGuiApplication
         */
        bool configureQGuiApplication(void);

        /**
         * @brief initialize
         */
        bool initialize(void);

    private:
        static Entrance *instance;
        static std::mutex mutex;

    protected:
        EntrancePrivate* data;

    private:
        QPointer<QGuiApplication> app;
        QObject* appRoot_{};
        QWindow* appWindow_{};

        // QQmlApplicationEngine* splashscreenEngine_;
        QPointer<QQmlApplicationEngine> engine;
};

#endif //ENTRANCE_H

