#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <thread>
#include <mutex>

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "statechart/Main.h"
#include <core/src/settings/game_settings.h>
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
        Q_PROPERTY(GameSettings *gameSettings READ gameSettings NOTIFY gameSettingsChanged)
        Q_PROPERTY(Theme *theme READ theme NOTIFY themeChanged)
        Q_PROPERTY(GameController* gameController READ gameController NOTIFY gameControllerChanged)

    public:
        /**
         * @brief Getter: statechart
         * @return : statechart::Main
         */
        statechart::Main* statechart() const;

        /**
         * @brief Getter: GameSettings
         * @return : GameSettings
         */
        GameSettings* gameSettings() const;

        /**
         * @brief Getter: Theme
         * @return : Theme
         */
        Theme *theme() const;

        /**
         * @brief Getter: GameController
         * @return : GameController
         */
        GameController* gameController() const;

    Q_SIGNALS:
        void gameSettingsChanged();
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
        void registerPlugins(void);

        /**
        * @brief Initialize QQmlApplicationEngine
        * @return
        */
        void createQQmlEngines(void) const;

        /**
         * @brief startStateChart
         */
        void startStateChart(void) const;

        /**
         * @brief configureQGuiApplication
         */
        void configureQGuiApplication(void) const;

        /**
         * @brief initialize
         */
        void initialize(void) const;

    private:
        static Entrance *instance;
        static std::mutex mutex;

    protected:
        EntrancePrivate* data;

    private:
        QPointer<QGuiApplication> m_app{};
        QPointer<QQmlApplicationEngine> m_engine{};
};

#endif //ENTRANCE_H

