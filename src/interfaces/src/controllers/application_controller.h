#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include <QString>

class ApplicationController
{
public:
    /**
     * @brief C-tor
     */
    ApplicationController();

    /**
     * @brief D-tor
     */
    ~ApplicationController();

    /**
     * @brief Get traninned data base folder path
     * @return path of data folder
     */
    const QString &getTesseractBasePath() const;

private:
    /**
     * @brief Request all neccessary permission from mobile phone
     * @return true: permission granted
     */
    bool RequestPermissions();

    /**
     * @brief initialize home directory or create it
     * @return if true: directory created
     */
    bool initializeHomePath();

    /**
     * @brief move traniined data file to tesseract base data path location
     * if location not found create it and move tranined data files
     * @return if true: file moved correctly
     */
    bool initializeTesseractBasePath();

private:
    QString m_homePath;
    QString m_tessDataPath;


};
#endif //APPLICATION_CONTROLLER_H
