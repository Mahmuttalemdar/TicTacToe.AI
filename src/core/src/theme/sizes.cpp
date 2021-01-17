#include "sizes.h"

namespace Constants {
constexpr auto textExtraLarge = 16;
constexpr auto textLarge = 14;
constexpr auto textNormal = 12;
constexpr auto textSmall = 10;
constexpr auto textExtraSmall = 8;
constexpr auto searchFieldHeight = 40;
}

Sizes::Sizes(QObject* parent)
  : QObject(parent)
{}

Sizes::~Sizes() {}

void Sizes::setFontScaleFactor(double factor)
{
    fontScaleFactor = factor;

    seTextExtraLarge(Constants::textExtraLarge * fontScaleFactor);
    setTextLarge(Constants::textLarge * fontScaleFactor);
    setTextNormal(Constants::textNormal * fontScaleFactor);
    setTextSmall(Constants::textSmall * fontScaleFactor);
    setTextExtraSmall(Constants::textExtraSmall * fontScaleFactor);
    setSearchFieldHeight(Constants::searchFieldHeight * fontScaleFactor);
}
