#include "theme.h"

namespace FontFactor {
    constexpr auto small                          = 0.8;
    constexpr auto medium                         = 0.9;
    constexpr auto large                          = 1.1;
}


Theme::Theme(QObject *parent)
    : QObject(parent)
    , colors_(new Colors(parent))
    , lightColors_(new Colors(parent))
    , darkColors_(new Colors(parent))
    , sizes_(new Sizes(parent))
    , fonts_(new Fonts(parent))
{
    // Light theme colors
    setDefaultLightColors();

    // Dark theme colors
    setDefaultDarkColors();

    // Set default theme
    changeTheme(ThemeName::Light);

    // Set font factor
    changeFontSize(FontSize::Medium);
}

Theme::~Theme()
{
    if(colors_)
    {
        colors_->deleteLater();
        delete colors_;
        colors_ = nullptr;
    }

    if(lightColors_)
    {
        lightColors_->deleteLater();
        delete lightColors_;
        lightColors_ = nullptr;
    }

    if(darkColors_)
    {
        darkColors_->deleteLater();
        delete darkColors_;
        darkColors_ = nullptr;
    }
}

Colors* Theme::colors()
{
    return colors_;
}

void Theme::setColors(Colors* colors)
{
    if(colors)
    {
        colors_ = colors;
        emit colorsChanged();
    }
}

Sizes *Theme::sizes() const
{
    return sizes_;
}

Theme::FontSize Theme::fontSize() const
{
    return fontSize_;
}

void Theme::changeTheme(Theme::ThemeName themeName)
{
    switch (themeName)
    {
        case Theme::ThemeName::Light:
            setColors(lightColors_);
            name_ = themeName;
            emit nameChanged();
            //MPC_LOG_INFO(loggingModuleNames::coreLogModuleName, "Theme changed to Light.")
            break;
        case Theme::ThemeName::Dark:
            setColors(darkColors_);
            name_ = themeName;
            emit nameChanged();
            //MPC_LOG_INFO(loggingModuleNames::coreLogModuleName, "Theme changed to Dark.")
            break;
        default:
            setColors(lightColors_);
            name_ = themeName;
            emit nameChanged();
            //MPC_LOG_INFO(loggingModuleNames::coreLogModuleName, "Theme changed to Light.")
            break;
    }
}

void Theme::changeFontSize(Theme::FontSize fontSize)
{
    switch (fontSize)
    {
        case Theme::FontSize::Small:
            sizes_->setFontScaleFactor(FontFactor::small);
            emit sizesChanged();

            fontSize_ = FontSize::Small;
            emit fontSizeChanged();

            //MPC_LOG_INFO(loggingModuleNames::coreLogModuleName, "Theme, font size changed to small.")
            break;
        case Theme::FontSize::Medium:
            sizes_->setFontScaleFactor(FontFactor::medium);
            emit sizesChanged();

            fontSize_ = FontSize::Medium;
            emit fontSizeChanged();

            //MPC_LOG_INFO(loggingModuleNames::coreLogModuleName, "Theme, font size changed to medium.")
            break;
        case Theme::FontSize::Large:
            sizes_->setFontScaleFactor(FontFactor::large);
            emit sizesChanged();

            fontSize_ = FontSize::Large;
            emit fontSizeChanged();

            //MPC_LOG_INFO(loggingModuleNames::coreLogModuleName, "Theme, font size changed to large.")
            break;
        default:
            sizes_->setFontScaleFactor(FontFactor::medium);
            emit sizesChanged();
            fontSize_ = FontSize::Medium;
            emit fontSizeChanged();
            //MPC_LOG_INFO(loggingModuleNames::coreLogModuleName, "Theme, font size changed to medium.")
            break;
    }
}


void Theme::setDefaultLightColors()
{
    // Main
    lightColors_->setMainBackground("#FFFFFF");

    // Header
    lightColors_->setMainHeaderBackground("#2B2C2E");
    lightColors_->setSubHeaderBackground("#F6F6F6");

    // Panel
    lightColors_->setPanelBackground("#FFFFFF");

    // Line
    //lightColors_->setLine("#C9C9C9");
    lightColors_->setLine("#F6F4F6");
    lightColors_->setLineDialog("#dad4d3");

    // Text
    lightColors_->setText("#000000");
    lightColors_->setHeaderText("#FFFFFF");
    lightColors_->setSubHeaderText("#000000");
    lightColors_->setTextField("#EFEFEF");
    lightColors_->setTextFieldText("#505050");
    lightColors_->setTextFieldEnabled("#FFFFFF");
    lightColors_->setTextFieldFocus("#00589C");
    lightColors_->setTextFieldSelection("#2000589C");
    lightColors_->setTextFieldPlaceholder("#C9C9C9");
    lightColors_->setContactUserName("#505050");
    lightColors_->setContactEcoId("#737373");
    lightColors_->setLoginText("#505050");
    lightColors_->setTextAreaSelectionColor("#2000589C");
    lightColors_->setTextAreaSelectedColor("#505050");
    lightColors_->setLinkMessageTextIn("#00589C");
    lightColors_->setLinkMessageTextOut("#00589C");


    // Button
    lightColors_->setUserSwitchButton("#000000");
    lightColors_->setUserSwitchButtonEnabled("#000000");
    lightColors_->setLinkButton("#00589C");
    lightColors_->setBackButton("#00589C");
    lightColors_->setBackButtonEnabled("#00589C");
    lightColors_->setUserDeleteButton("#d63c31");
    lightColors_->setUserDeleteButtonText("#FFFFFF");
    lightColors_->setAddUserButton("#00589C");
    lightColors_->setAddUserButtonHover("#2000589C");
    lightColors_->setAddUserButtonText("#00589C");
    lightColors_->setAddUserButtonTextHover("#00589C");
    lightColors_->setTextButton("#A5A5A5");
    lightColors_->setTextButtonHinted("#737373");
    lightColors_->setTextButtonEnabled("#00589C");
    lightColors_->setTextButtonBackground("#EFEFEF");

    lightColors_->setPopupButtonBackground("#FFFFFF");
    lightColors_->setPopupButtonHoverBackground("#C7EDFC");
    lightColors_->setPopupButtonIcon("#00EFEFEF");
    lightColors_->setPopupButtonText("#00589C");
    lightColors_->setPopupButtonTextHover("#737373");

    // Shadows
    lightColors_->setDropShadow1("#15000000");
    lightColors_->setDropShadow2("#80000000");
    lightColors_->setDropShadow3("#30000000");
    lightColors_->setDropShadow4("#60000000");

    // Settings
    lightColors_->setSettingsBackground("#EFEFEF");
    lightColors_->setSettingsSidebarBackground("#EFEFEF");
    lightColors_->setSettingsPanelBackground("#FFFFFF");
    lightColors_->setSettingsPanelText("#000000");
    lightColors_->setSettingsPanelTextField("#C9C9C9");
    lightColors_->setNavbarBackground("#FFFFFF");
    lightColors_->setNavbarChecked("#00589C");
    lightColors_->setNavbarHover("#EFEFEF");
    lightColors_->setNavbarEnabled("#FFFFFF");
    lightColors_->setNavbarBackground2("#FFFFFF");
    lightColors_->setNavbarText("#00589C");
    lightColors_->setNavbarText2("#505050");
    lightColors_->setNavbarTextChecked("#FFFFFF");
    lightColors_->setNavbarTextCheckable("#505050");

    lightColors_->setLanguageBackground("#FFFFFF");
    lightColors_->setLanguageSelection("#C9C9C9");
    lightColors_->setLanguageText("#000000");
    lightColors_->setLanguageTextSelected("#FFFFFF");

    lightColors_->setInfoText("#737373");
    lightColors_->setInfoHeaderText("#000000");
    lightColors_->setInfoSubHeaderText("#505050");

    // List Items
    lightColors_->setDelegateBackground("#FFFFFF");
    lightColors_->setDelegateSelectedBackground("#00589C");
    lightColors_->setDelegateHoveredBackground("#C7EDFC");
    lightColors_->setDelegateText("#505050");
    lightColors_->setDelegateSelectedText("#FFFFFF");
    lightColors_->setDelegateHoveredText("#737373");
    lightColors_->setLastMessageColor("#FFFFFF");
    lightColors_->setLastMessageColor2("#737373");

    // Start Screen
    lightColors_->setStartScreenBackground("#FFFFFF");
    lightColors_->setStartScreenHeaderText("#505050");
    lightColors_->setActivityItemBackground("#FFFFFF");
    lightColors_->setActivityItemText("#505050");

    lightColors_->setNewActivityButton("#00589C");
    lightColors_->setNewActivityButtonText("#00589C");
    lightColors_->setNewActivityButtonBackground("#FFFFFF");

    // Activity Area
    lightColors_->setActivitySidebarBackground("#FFFFFF");

    // Search Field
    lightColors_->setSearchFieldBackground("#FFFFFF");
    lightColors_->setSearchFieldBackground2("#EFEFEF");
    lightColors_->setSearchFieldText("#000000");
    lightColors_->setSearchFieldIcon("#737373");
    lightColors_->setSearchFieldIconHover("#00589C");

    // New Chat
    lightColors_->setNewActivityPopupBackground("#FFFFFF");
    lightColors_->setNewActivityPopupHeaderText("#505050");

    // Activity Area
    lightColors_->setActivityAreaBackground("#FFFFFF");

    // Chat Section
    lightColors_->setChatSectionBackground("#FFFFFF");
    lightColors_->setChatSectionLine("#D0D1D3");
    lightColors_->setChatSectionText("#737373");

    // Chat Bubble
    lightColors_->setChatBubbleBackgroundIn("#f5f5f5");
    lightColors_->setChatBubbleBackgroundOut("#E3F2FD");
    lightColors_->setChatBubbleTextIn("#525252");
    lightColors_->setChatBubbleTextOut("#525252");
    lightColors_->setChatBubbleDateTextIn("#525252");
    lightColors_->setChatBubbleDateTextOut("#525252");
    lightColors_->setChatBubbleMediaTextIn("#000000");
    lightColors_->setChatBubbleMediaTextOut("#000000");
    lightColors_->setChatBubbleMediaIcon("#00589C");
    lightColors_->setChatBubbleMediaBackground("#A4A5A6");
    lightColors_->setChatBubbleSignatureText("#505050");
    lightColors_->setChatBubbleSignatureTextSigning("#00589C");
    lightColors_->setChatBubbleSignatureTextRejected("#B7464B");

    // Chat Footer
    lightColors_->setChatFooterBackground("#EFEFEF");
    lightColors_->setChatFooterText("#505050");
    lightColors_->setChatFooterTextBackground("#FFFFFF");

    // Transaction Progressbar
    lightColors_->setTransactionProgressBarBackground("#E6E6E6");

    // Defined Colors
    lightColors_->setGray("#737373");

    // Set default light color palette
    lightColors_->setPrimary("#00589C");
    lightColors_->setBlue("#00589C");
    lightColors_->setBlack("#000000");
    lightColors_->setWhite("#FFFFFF");
    lightColors_->setDarkBlue("#004174");
    lightColors_->setLightBlue("#006fc4");
    lightColors_->setSkyBlue("#0e81fe");
    lightColors_->setWhitishBlue("#e3f2fd");

    lightColors_->setBlackishGray("#292929");
    lightColors_->setGray2("#A5A5A5");
    lightColors_->setGray3("#505050");
    lightColors_->setGray4("#F6F6F6");
    lightColors_->setLightGray("#C9C9C9");
    lightColors_->setWhitishGray("#EFEFEF");
    lightColors_->setColorLineGray("#F6F4F6");

    lightColors_->setColorAccentBlue("#00589C");
    lightColors_->setColorAccentHoverBlue("#2000589C");
    lightColors_->setColorAccentMediumBlue("#13539f");
    lightColors_->setColorAccentMediumHintedBlue("#3313539f");
    lightColors_->setColorAccentMediumHintedRed("#33EC411C");
    lightColors_->setGreenPositive("#7ED321");
    lightColors_->setGreen("#43b581");
    lightColors_->setRedNegative("#BA2020");
    lightColors_->setRedWarning("#B33A3A");

    lightColors_->setToolTipText("#000000");
    lightColors_->setToolTipBackground("#EFEFEF");

}

void Theme::setDefaultDarkColors()
{
    // Main
    darkColors_->setMainBackground("#3B3B3B");

    // Header
    darkColors_->setMainHeaderBackground("#1F1F1F");
    darkColors_->setSubHeaderBackground("#282828");

    // Panel
    darkColors_->setPanelBackground("#323232");

    // Line
    darkColors_->setLine("#404040");
    darkColors_->setLineDialog("#dad4d3");

    // Text
    darkColors_->setText("#FFFFFF");
    darkColors_->setHeaderText("#FFFFFF");
    darkColors_->setSubHeaderText("#FFFFFF");
    darkColors_->setTextField("#3B3B3B");
    darkColors_->setTextFieldText("#C9C9C9");
    darkColors_->setTextFieldEnabled("#323232");
    darkColors_->setTextFieldFocus("#00589C");
    darkColors_->setTextFieldSelection("#2000589C");
    darkColors_->setTextFieldPlaceholder("#737373");
    darkColors_->setContactUserName("#EFEFEF");
    darkColors_->setContactEcoId("#A5A5A5");
    darkColors_->setLoginText("#EFEFEF");
    darkColors_->setTextAreaSelectionColor("#2000589C");
    darkColors_->setTextAreaSelectedColor("#505050");
    darkColors_->setLinkMessageTextIn("#93caf5");
    darkColors_->setLinkMessageTextOut("#00589C");

    // Button
    darkColors_->setUserSwitchButton("#EFEFEF");
    darkColors_->setUserSwitchButtonEnabled("#000000");
    darkColors_->setLinkButton("#EFEFEF");
    darkColors_->setBackButton("#EFEFEF");
    darkColors_->setBackButtonEnabled("#00589C");
    darkColors_->setUserDeleteButton("#505050");
    darkColors_->setUserDeleteButtonText("#d63c31");
    darkColors_->setAddUserButton("#00589C");
    darkColors_->setAddUserButtonHover("#C9C9C9");
    darkColors_->setAddUserButtonText("#FFFFFF");
    darkColors_->setAddUserButtonTextHover("#00589C");
    darkColors_->setTextButton("#FFFFFF");
    darkColors_->setTextButtonHinted("#00589C");
    darkColors_->setTextButtonEnabled("#FFFFFF");
    darkColors_->setTextButtonBackground("#666666");

    darkColors_->setPopupButtonBackground("#3B3B3B");
    darkColors_->setPopupButtonHoverBackground("#737373");
    darkColors_->setPopupButtonIcon("#0000589C");
    darkColors_->setPopupButtonText("#EFEFEF");
    darkColors_->setPopupButtonTextHover("#000000");

    // Shadows
    darkColors_->setDropShadow1("#15000000");
    darkColors_->setDropShadow2("#1F1F1F");
    darkColors_->setDropShadow3("#30000000");
    darkColors_->setDropShadow4("#60000000");

    // Settings
    darkColors_->setSettingsBackground("#323232");
    darkColors_->setSettingsSidebarBackground("#3B3B3B");
    darkColors_->setSettingsPanelBackground("#666666");
    darkColors_->setSettingsPanelText("#FFFFFF");
    darkColors_->setSettingsPanelTextField("#FFFFFF");
    darkColors_->setNavbarBackground("#323232");
    darkColors_->setNavbarChecked("#00589C");
    darkColors_->setNavbarHover("#3B3B3B");
    darkColors_->setNavbarEnabled("#C9C9C9");
    darkColors_->setNavbarBackground2("#282828");
    darkColors_->setNavbarText("#EFEFEF");
    darkColors_->setNavbarText2("#A5A5A5");
    darkColors_->setNavbarTextChecked("#FFFFFF");
    darkColors_->setNavbarTextCheckable("#EFEFEF");

    darkColors_->setLanguageBackground("#666666");
    darkColors_->setLanguageSelection("#282828");
    darkColors_->setLanguageText("#FFFFFF");
    darkColors_->setLanguageTextSelected("#FFFFFF");

    darkColors_->setInfoText("#EFEFEF");
    darkColors_->setInfoHeaderText("#FFFFFF");
    darkColors_->setInfoSubHeaderText("#FFFFFF");


    // List Items
    darkColors_->setDelegateBackground("#323232");
    darkColors_->setDelegateSelectedBackground("#00589C");
    darkColors_->setDelegateHoveredBackground("#666666");
    darkColors_->setDelegateText("#EFEFEF");
    darkColors_->setDelegateSelectedText("#FFFFFF");
    darkColors_->setDelegateHoveredText("#EFEFEF");
    darkColors_->setLastMessageColor("#EFEFEF");
    darkColors_->setLastMessageColor2("#A5A5A5");

    // Start Screen
    darkColors_->setStartScreenBackground("#3B3B3B");
    darkColors_->setStartScreenHeaderText("#FFFFFF");
    darkColors_->setActivityItemBackground("#3B3B3B");
    darkColors_->setActivityItemText("#EFEFEF");

    darkColors_->setNewActivityButton("#00589C");
    darkColors_->setNewActivityButtonText("#FFFFFF");
    darkColors_->setNewActivityButtonBackground("#3B3B3B");

    // Activity Area
    darkColors_->setActivitySidebarBackground("#3B3B3B");

    // Search Field
    darkColors_->setSearchFieldBackground("#EFEFEF");
    darkColors_->setSearchFieldBackground2("#1F1F1F");
    darkColors_->setSearchFieldText("#000000");
    darkColors_->setSearchFieldIcon("#737373");
    darkColors_->setSearchFieldIconHover("#00589C");

    // New Chat
    darkColors_->setNewActivityPopupBackground("#3B3B3B");
    darkColors_->setNewActivityPopupHeaderText("#FFFFFF");

    // Activity Area
    darkColors_->setActivityAreaBackground("#323232");

    // Chat Section
    darkColors_->setChatSectionBackground("#323232");
    darkColors_->setChatSectionLine("#737373");
    darkColors_->setChatSectionText("#EFEFEF");

    // Chat Bubble
    darkColors_->setChatBubbleBackgroundIn("#666666");
    //darkColors_->setChatBubbleBackgroundIn("#CB886E");
    darkColors_->setChatBubbleBackgroundOut("#85929E");
    darkColors_->setChatBubbleTextIn("#FFFFFF");
    darkColors_->setChatBubbleTextOut("#FFFFFF");
    darkColors_->setChatBubbleDateTextIn("#FFFFFF");
    darkColors_->setChatBubbleDateTextOut("#FFFFFF");
    darkColors_->setChatBubbleMediaTextIn("#FFFFFF");
    darkColors_->setChatBubbleMediaTextOut("#FFFFFF");
    darkColors_->setChatBubbleMediaIcon("#00589C");
    darkColors_->setChatBubbleMediaBackground("#323232");
    darkColors_->setChatBubbleSignatureText("#FFFFFF");
    darkColors_->setChatBubbleSignatureTextSigning("#00589C");
    darkColors_->setChatBubbleSignatureTextRejected("#961717");

    // Chat Footer
    darkColors_->setChatFooterBackground("#282828");
    darkColors_->setChatFooterText("#FFFFFF");
    darkColors_->setChatFooterTextBackground("#666666");

    // Transaction Progressbar
    darkColors_->setTransactionProgressBarBackground("#E6E6E6");

    // Defined Colors
    darkColors_->setGray("#737373");

    // Set default light color palette
    darkColors_->setPrimary("#00589C");
    darkColors_->setBlue("#00589C");
    darkColors_->setBlack("#000000");
    darkColors_->setWhite("#FFFFFF");
    darkColors_->setDarkBlue("#004174");
    darkColors_->setLightBlue("#006fc4");
    darkColors_->setSkyBlue("#0e81fe");
    darkColors_->setWhitishBlue("#e3f2fd");

    darkColors_->setBlackishGray("#292929");
    darkColors_->setGray2("#A5A5A5");
    darkColors_->setGray3("#505050");
    darkColors_->setGray4("#F6F6F6");
    darkColors_->setLightGray("#C9C9C9");
    darkColors_->setWhitishGray("#EFEFEF");
    darkColors_->setColorLineGray("#F6F4F6");

    darkColors_->setColorAccentBlue("#00589C");
    darkColors_->setColorAccentHoverBlue("#2000589C");
    darkColors_->setColorAccentMediumBlue("#13539f");
    darkColors_->setColorAccentMediumHintedBlue("#3313539f");
    darkColors_->setColorAccentMediumHintedRed("#33EC411C");
    darkColors_->setGreenPositive("#7ED321");
    darkColors_->setGreen("#43b581");
    darkColors_->setRedNegative("#BA2020");
    darkColors_->setRedWarning("#B33A3A");

    darkColors_->setToolTipText("#000000");
    darkColors_->setToolTipBackground("#EFEFEF");
}

Theme::ThemeName Theme::name() const
{
    return name_;
}

Fonts *Theme::fonts() const
{
    return fonts_;
}
