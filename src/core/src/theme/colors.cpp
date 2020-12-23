#include "colors.h"


 Colors::Colors(QObject *parent)
     : QObject(parent)
 {

 }

 Colors::~Colors()
 {

 }

 const QString &Colors::primary() const
 {
     return primary_;
 }

 void Colors::setPrimary(const QString &color)
 {
     primary_ = color;
     emit primaryChanged();
 }

 const QString &Colors::accent() const
 {
     return accent_;
 }

 void Colors::setAccent(const QString &color)
 {
     accent_ = color;
     emit accentChanged();
 }

 const QString &Colors::background() const
 {
     return background_;
 }

 void Colors::setBackground(const QString &color)
 {
     background_ = color;
     emit backgroundChanged();
 }

 const QString &Colors::foreground() const
 {
     return foreground_;
 }

 void Colors::setForeground(const QString &color)
 {
     foreground_ = color;
     emit foregroundChanged();
 }

 const QString &Colors::white() const
 {
     return  white_;
 }
 void Colors::setWhite(const QString& color)
 {
     white_ = color;
     emit whiteChanged();
 }

 const QString &Colors::black() const
 {
     return black_;
 }
 void Colors::setBlack(const QString& color)
 {
    black_ = color;
    emit blackChanged();
 }

 const QString &Colors::blue() const
 {
     return blue_;
 }

 void Colors::setBlue(const QString &color)
 {
     blue_ = color;
     emit blueChanged();
 }

 const QString &Colors::darkBlue() const
 {
     return darkBlue_;
 }

 void Colors::setDarkBlue(const QString &color)
 {
     darkBlue_ = color;
     emit blueChanged();
 }

 const QString &Colors::whitishBlue() const
 {
     return whitishBlue_;
 }

 void Colors::setWhitishBlue(const QString& color)
 {
     whitishBlue_ = color;
     emit whitishBlueChanged();
 }

 const QString &Colors::lightBlue() const
 {
    return lightBlue_;
 }
 void Colors::setLightBlue(const QString& color)
 {
     lightBlue_ = color;
     emit lightBlueChanged();
 }

 const QString &Colors::skyBlue() const
 {
    return skyBlue_;
 }

 void Colors::setSkyBlue(const QString& color)
 {
     skyBlue_ = color;
     emit skyBlueChanged();
 }

 const QString &Colors::gray() const
 {
    return gray_;
 }

 void Colors::setGray(const QString& color)
 {
     gray_ = color;
     emit grayChanged();
 }

 const QString &Colors::gray2() const
 {
    return gray2_;
 }

 void Colors::setGray2(const QString& color)
 {
     gray2_ = color;
     emit gray2Changed();
 }

 const QString &Colors::gray3() const
 {
    return gray3_;
 }

 void Colors::setGray3(const QString& color)
 {
     gray3_ = color;
     emit gray3Changed();
 }

 const QString &Colors::gray4() const
 {
    return gray4_;
 }

 void Colors::setGray4(const QString& color)
 {
     gray4_ = color;
     emit gray3Changed();
 }

 const QString &Colors::lightGray() const
 {
    return lightGray_;
 }

 void Colors::setLightGray(const QString& color)
 {
     lightGray_ = color;
     emit lightGrayChanged();
 }
 const QString &Colors::whitishGray() const
 {
    return whitishGray_;
 }

 void Colors::setWhitishGray(const QString& color)
 {
     whitishGray_ = color;
     emit whitishGrayChanged();
 }

 const QString &Colors::blackishGray() const
 {
     return blackishGray_;
 }

 void Colors::setBlackishGray(const QString& color)
 {
     blackishGray_ = color;
     emit blackishGrayChanged();
 }

 const QString &Colors::colorLineGray() const
 {
    return colorLineGray_;
 }

 void Colors::setColorLineGray(const QString& color)
 {
     colorLineGray_ = color;
     emit colorLineGrayChanged();
 }

 const QString &Colors::colorAccentBlue() const
 {
     return colorAccentBlue_;
 }
 void Colors::setColorAccentBlue(const QString& color)
 {
     colorAccentBlue_ = color;
     emit colorAccentBlueChanged();
 }

 const QString &Colors::colorAccentHoverBlue() const
 {
     return colorAccentHoverBlue_;
 }
 void Colors::setColorAccentHoverBlue(const QString& color)
 {
     colorAccentHoverBlue_ = color;
     emit colorAccentHoverBlueChanged();
 }

 const QString &Colors::colorAccentMediumHintedBlue() const
 {
     return colorAccentMediumHintedBlue_;
 }
 void Colors::setColorAccentMediumHintedBlue(const QString& color)
 {
     colorAccentMediumHintedBlue_ = color;
     emit colorAccentMediumHintedBlueChanged();
 }

 const QString &Colors::colorAccentMediumHintedRed() const
 {
     return colorAccentMediumHintedRed_;
 }
 void Colors::setColorAccentMediumHintedRed(const QString& color)
 {
        colorAccentMediumHintedRed_ = color;
        emit colorAccentMediumHintedRedChanged();
 }

 const QString &Colors::colorAccentMediumBlue() const
 {
     return colorAccentMediumBlue_;
 }
 void Colors::setColorAccentMediumBlue(const QString& color)
 {
     colorAccentMediumBlue_ = color;
     emit colorAccentMediumBlueChanged();
 }

 const QString &Colors::greenPositive() const
 {
     return  greenPositive_;
 }
 void Colors::setGreenPositive(const QString& color)
 {
     greenPositive_ = color;
     emit greenPositiveChanged();
 }

 const QString &Colors::green() const
 {
     return  green_;
 }
 void Colors::setGreen(const QString &color)
 {
     green_ = color;
     emit greenChanged();
 }

 const QString &Colors::redNegative() const
 {
     return  redNegative_;
 }
 void Colors::setRedNegative(const QString& color)
 {
     redNegative_ = color;
     emit redNegativeChanged();
 }

 const QString &Colors::redWarning() const
 {
     return redWarning_;
 }
 void Colors::setRedWarning(const QString& color)
 {
     redWarning_ = color;
     emit redWarningChanged();
 }

 const QString &Colors::dropShadow1() const
 {
     return dropShadow1_;
 }
 void Colors::setDropShadow1(const QString& color)
 {
     dropShadow1_ = color;
     emit dropShadow1Changed();
 }

 const QString &Colors::dropShadow2() const
 {
    return dropShadow2_;
 }
 void Colors::setDropShadow2(const QString& color)
 {
     dropShadow2_ = color;
     emit dropShadow2Changed();
 }

 const QString &Colors::dropShadow3() const
 {
    return dropShadow3_;
 }
 void Colors::setDropShadow3(const QString& color)
 {
     dropShadow3_ = color;
     emit dropShadow3Changed();
 }

 const QString &Colors::toolTipText() const
 {
     return toolTipText_;
 }

 void Colors::setToolTipText(QString toolTipText)
 {
     if (toolTipText_ == toolTipText)
         return;

     toolTipText_ = toolTipText;
     emit toolTipTextChanged();
 }

 const QString &Colors::toolTipBackground() const
 {
     return toolTipBackground_;
 }

 void Colors::setToolTipBackground(QString toolTipBackground)
 {
     if (toolTipBackground_ == toolTipBackground)
         return;

     toolTipBackground_ = toolTipBackground;
     emit toolTipBackgroundChanged();
 }

 QString Colors::lineDialog() const
 {
     return m_lineDialog;
 }

 void Colors::setLineDialog(QString lineDialog)
 {
     if (m_lineDialog == lineDialog)
         return;

     m_lineDialog = lineDialog;
     emit lineDialogChanged(m_lineDialog);
 }



















