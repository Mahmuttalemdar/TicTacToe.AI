#include "fonts.h"
#include <QFontDatabase>

namespace FontFiles {
constexpr auto robotoMedium = ":/imports/Theme/fonts/Roboto/Roboto-Medium.ttf";
constexpr auto OpenSansRegular = ":/imports/Theme/fonts/Open_Sans/OpenSans-Regular.ttf";
}

Fonts::Fonts(QObject* parent)
  : QObject(parent)
{
    // Install Application Fonts from QRC
    int id = QFontDatabase::addApplicationFont(FontFiles::robotoMedium);
    roboto_ = QFontDatabase::applicationFontFamilies(id).first();
    robotoChanged();

    id = QFontDatabase::addApplicationFont(FontFiles::OpenSansRegular);
    openSans_ = QFontDatabase::applicationFontFamilies(id).first();
    openSansChanged();
}

Fonts::~Fonts() {}

QString Fonts::roboto() const
{
    return roboto_;
}

QString Fonts::openSans() const
{
    return openSans_;
}
