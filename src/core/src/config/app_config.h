#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include <string>
#include <vector>

#include <QObject>
#include <QString>
#include <QMap>
#include <QDir>

using namespace std;

/**
 * @brief The AppConfig class defined that is storing all
 * configuration types and default values
 */
class AppConfig : public QObject
{
        Q_OBJECT

    public:
        /**
         * @brief C-tor
         * @param parent : QObject parent
         */
        AppConfig(QObject *parent = nullptr);

        /**
         * @brief C-tor
         * @param parent : QObject parent
         */
        ~AppConfig();

};

#endif // APP_CONFIG_H
