#include "application_controller.h"
#include <KYCEngine/log.h>

#include <QString>
#include <QtAndroid>
#include <QStandardPaths>
#include <QDir>

ApplicationController::ApplicationController()
    : m_homePath("")
    , m_tessDataPath("")
{
    if(!RequestPermissions())
    {
        // TODO cut application here or request again!
    }

    if(!initializeHomePath())
    {
        // TODO cut application here and fix home path!
    }

    if(!initializeTesseractBasePath())
    {
        // TODO cut application here and fix tessratc base path!
    }

}

ApplicationController::~ApplicationController()
{}

const QString &ApplicationController::getTesseractBasePath() const
{
    return m_tessDataPath;
}

bool ApplicationController::RequestPermissions()
{
    // READ EXTERNAL DEVICES
    auto  readResult = QtAndroid::checkPermission(QString("android.permission.READ_EXTERNAL_STORAGE"));
    if(readResult == QtAndroid::PermissionResult::Denied)
    {
        QtAndroid::PermissionResultMap resultHash = QtAndroid::requestPermissionsSync(QStringList({"android.permission.READ_EXTERNAL_STORAGE"}));
        if(resultHash["android.permission.READ_EXTERNAL_STORAGE"] == QtAndroid::PermissionResult::Denied)
        {
            return false;
        }
    }

    // WRITE EXTERNAL DEVICES
    auto  writeResult = QtAndroid::checkPermission(QString("android.permission.WRITE_EXTERNAL_STORAGE"));
    if(writeResult == QtAndroid::PermissionResult::Denied)
    {
        QtAndroid::PermissionResultMap resultHash = QtAndroid::requestPermissionsSync(QStringList({"android.permission.WRITE_EXTERNAL_STORAGE"}));
        if(resultHash["android.permission.WRITE_EXTERNAL_STORAGE"] == QtAndroid::PermissionResult::Denied)
        {
            return false;
        }
    }

    return true;
}

bool ApplicationController::initializeHomePath()
{
    // Android: HomeLocation works, iOS: not writable
    // Android: AppDataLocation works out of the box, iOS you must create the DIR first !!
    m_homePath = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(0);

    kyc_engine::KYCLog(kyc_engine::LogLevel::Info, "KYCCrossApp", "ApplicationController", "Home path: %s", m_homePath.toStdString().c_str());
    QDir homeDir(m_homePath);
    if (!homeDir.exists())
    {
        bool ok = homeDir.mkpath(m_homePath);
        if(!ok)
        {
            kyc_engine::KYCLog(kyc_engine::LogLevel::Warning, "KYCCrossApp", "ApplicationController", "Couldn't create dir: %s", m_homePath.toStdString().c_str());
            return false;
        }
        kyc_engine::KYCLog(kyc_engine::LogLevel::Debug, "KYCCrossApp", "ApplicationController", "Created directory path: %s", m_homePath.toStdString().c_str());
    }

    return true;
}

bool ApplicationController::initializeTesseractBasePath()
{
    // Check and create to the writable path
    m_tessDataPath = m_homePath + "/tessdata/";
    QDir homeDir(m_homePath);
    if (!homeDir.exists())
    {
        kyc_engine::KYCLog(kyc_engine::LogLevel::Warning, "KYCCrossApp", "ApplicationController", "Couldn't find correct home path: %s", m_homePath.toStdString().c_str());
        return false;
    }
    else
    {
        bool ok = homeDir.mkpath(m_tessDataPath);
        if(!ok)
        {
            kyc_engine::KYCLog(kyc_engine::LogLevel::Warning, "KYCCrossApp", "ApplicationController", "Couldn't create dir: %s", m_tessDataPath.toStdString().c_str());
            return false;
        }
        kyc_engine::KYCLog(kyc_engine::LogLevel::Debug, "KYCCrossApp", "ApplicationController", "Created directory path: %s", m_tessDataPath.toStdString().c_str());
    }

    QFile trainDataFile(":/Tesseract/kyc.traineddata");
    if (!trainDataFile.open(QIODevice::ReadOnly))
    {
        kyc_engine::KYCLog(kyc_engine::LogLevel::Warning, "KYCCrossApp", "ApplicationController", "Couldn't open file: %s", trainDataFile.fileName().toStdString().c_str());
        return false;
    }

    if(!trainDataFile.copy(m_tessDataPath + "kyc.traineddata"))
    {
        kyc_engine::KYCLog(kyc_engine::LogLevel::Warning, "KYCCrossApp", "ApplicationController", "Couldn't copy file % to dir: %s"
                           , trainDataFile.fileName().toStdString().c_str()
                           , m_tessDataPath.toStdString().c_str());
        return false;
    }

    return true;
}
