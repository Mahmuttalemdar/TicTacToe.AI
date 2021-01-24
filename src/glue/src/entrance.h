#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <mutex>
#include <thread>

#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>

#include "statechart/Main.h"
#include <core/src/settings/game_settings.h>
#include <interfaces/src/controllers/game_controller.h>

struct EntrancePrivate;

/**
 * @brief The Entrance class;
 * Collection all modules and them functionality, storing all application thread states and basic configurations
 * then sending to UI Side
 */
class Entrance : public QObject
{
    Q_OBJECT
    Q_PROPERTY(statechart::Main* statechart READ statechart NOTIFY statechartChanged)
    Q_PROPERTY(GameSettings* gameSettings READ gameSettings NOTIFY gameSettingsChanged)
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
     * @brief Getter: GameController
     * @return : GameController
     */
    GameController* gameController() const;

Q_SIGNALS:
    /**
     * @brief Signal: emit signal when game settings changed
     */
    void gameSettingsChanged();

    /**
     * @brief Signal: emit signal when statechart changed
     */
    void statechartChanged();

    /**
     * @brief Signal: emit signal when game controller changed
     */
    void gameControllerChanged();

private:
    /**
     * @brief C-tor
     */
    Entrance(void);

    /**
     * @brief Deleted copy C-tor
     */
    Entrance(const Entrance&) = delete;

    /**
     * @brief Deleted = operator for singleton object
     * @return reference of Entrance object
     */
    Entrance& operator=(const Entrance&) = delete;

    /**
     * @brief D-tor
     */
    ~Entrance(void) = default;

public:
    /**
     * @brief getInstance: retrieve global singleton Entrance instance
     * @return the only instance of Entrance in the app
     */
    static Entrance* getInstance(void);

    /**
     * @brief run: show time for game engine
     * @param argc
     * @param argv
     * @return
     */
    int run(int argc, char* argv[]);

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
     * @brief startStateChart: call start function on statechart
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
    static Entrance* instance;
    static std::mutex mutex;

protected:
    EntrancePrivate* data;

private:
    QPointer<QGuiApplication> m_app{};
    QPointer<QQmlApplicationEngine> m_engine{};
};

#endif // ENTRANCE_H
