#ifndef COLORS_H
#define COLORS_H

#include <QObject>
#include <QString>


class Colors : public QObject
{
        Q_OBJECT
        Q_PROPERTY(QString primary READ primary WRITE setPrimary NOTIFY primaryChanged)
        Q_PROPERTY(QString accent READ accent WRITE setAccent NOTIFY accentChanged)
        Q_PROPERTY(QString background READ background WRITE setBackground NOTIFY backgroundChanged)
        Q_PROPERTY(QString foreground READ foreground WRITE setForeground NOTIFY foregroundChanged)

        //*****************************************************************************************

        // Main
        Q_PROPERTY(QString mainBackground READ mainBackground WRITE setMainBackground NOTIFY mainBackgroundChanged)


        // Header
        Q_PROPERTY(QString mainHeaderBackground READ mainHeaderBackground WRITE setMainHeaderBackground NOTIFY mainHeaderBackgroundChanged)
        Q_PROPERTY(QString subHeaderBackground READ subHeaderBackground WRITE setSubHeaderBackground NOTIFY subHeaderBackgroundChanged)


        // Panel
        Q_PROPERTY(QString panelBackground READ panelBackground WRITE setPanelBackground NOTIFY panelBackgroundChanged)


        // Line
        Q_PROPERTY(QString line READ line WRITE setLine NOTIFY lineChanged)
        Q_PROPERTY(QString lineDialog READ lineDialog WRITE setLineDialog NOTIFY lineDialogChanged)

        // Text
        Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
        Q_PROPERTY(QString headerText READ headerText WRITE setHeaderText NOTIFY headerTextChanged)
        Q_PROPERTY(QString subHeaderText READ subHeaderText WRITE setSubHeaderText NOTIFY subHeaderTextChanged)
        Q_PROPERTY(QString textField READ textField WRITE setTextField NOTIFY textFieldChanged)
        Q_PROPERTY(QString textFieldText READ textFieldText WRITE setTextFieldText NOTIFY textFieldTextChanged)
        Q_PROPERTY(QString textFieldSelection READ textFieldSelection WRITE setTextFieldSelection NOTIFY textFieldSelectionChanged)
        Q_PROPERTY(QString textFieldEnabled READ textFieldEnabled WRITE setTextFieldEnabled NOTIFY textFieldEnabledChanged)
        Q_PROPERTY(QString textFieldFocus READ textFieldFocus WRITE setTextFieldFocus NOTIFY textFieldFocusChanged)
        Q_PROPERTY(QString textFieldPlaceholder READ textFieldPlaceholder WRITE setTextFieldPlaceholder NOTIFY textFieldPlaceholderChanged)
        Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
        Q_PROPERTY(QString contactUserName READ contactUserName WRITE setContactUserName NOTIFY contactUserNameChanged)
        Q_PROPERTY(QString contactEcoId READ contactEcoId WRITE setContactEcoId NOTIFY contactEcoIdChanged)
        Q_PROPERTY(QString loginText READ loginText WRITE setLoginText NOTIFY loginTextChanged)
        Q_PROPERTY(QString textAreaSelectionColor READ textAreaSelectionColor WRITE setTextAreaSelectionColor NOTIFY textAreaSelectionColorChanged)
        Q_PROPERTY(QString textAreaSelectedColor READ textAreaSelectedColor WRITE setTextAreaSelectedColor NOTIFY textAreaSelectedColorChanged)
        Q_PROPERTY(QString linkMessageTextIn READ linkMessageTextIn WRITE setLinkMessageTextIn NOTIFY linkMessageTextInChanged)
        Q_PROPERTY(QString linkMessageTextOut READ linkMessageTextOut WRITE setLinkMessageTextOut NOTIFY linkMessageTextOutChanged)


        // Button
        Q_PROPERTY(QString backButton READ backButton WRITE setBackButton NOTIFY backButtonChanged)
        Q_PROPERTY(QString backButtonEnabled READ backButtonEnabled WRITE setBackButtonEnabled NOTIFY backButtonEnabledChanged)
        Q_PROPERTY(QString userSwitchButton READ userSwitchButton WRITE setUserSwitchButton NOTIFY userSwitchButtonChanged)
        Q_PROPERTY(QString userSwitchButtonEnabled READ userSwitchButtonEnabled WRITE setUserSwitchButtonEnabled NOTIFY userSwitchButtonEnabledChanged)
        Q_PROPERTY(QString linkButton READ linkButton WRITE setLinkButton NOTIFY linkButtonChanged)
        Q_PROPERTY(QString userDeleteButton READ userDeleteButton WRITE setUserDeleteButton NOTIFY userDeleteButtonChanged)
        Q_PROPERTY(QString userDeleteButtonText READ userDeleteButtonText WRITE setUserDeleteButtonText NOTIFY userDeleteButtonTextChanged)
        Q_PROPERTY(QString addUserButton READ addUserButton WRITE setAddUserButton NOTIFY addUserButtonChanged)
        Q_PROPERTY(QString addUserButtonHover READ addUserButtonHover WRITE setAddUserButtonHover NOTIFY addUserButtonHoverChanged)
        Q_PROPERTY(QString addUserButtonText READ addUserButtonText WRITE setAddUserButtonText NOTIFY addUserButtonTextChanged)
        Q_PROPERTY(QString addUserButtonTextHover READ addUserButtonTextHover WRITE setAddUserButtonTextHover NOTIFY addUserButtonTextHoverChanged)
        Q_PROPERTY(QString textButton READ textButton WRITE setTextButton NOTIFY textButtonChanged)
        Q_PROPERTY(QString textButtonHinted READ textButtonHinted WRITE setTextButtonHinted NOTIFY textButtonHintedChanged)
        Q_PROPERTY(QString textButtonEnabled READ textButtonEnabled WRITE setTextButtonEnabled NOTIFY textButtonEnabledChanged)
        Q_PROPERTY(QString textButtonBackground READ textButtonBackground WRITE setTextButtonBackground NOTIFY textButtonBackgroundChanged)
        Q_PROPERTY(QString popupButtonBackground READ popupButtonBackground WRITE setPopupButtonBackground NOTIFY popupButtonBackgroundChanged)
        Q_PROPERTY(QString popupButtonHoverBackground READ popupButtonHoverBackground WRITE setPopupButtonHoverBackground NOTIFY popupButtonHoverBackgroundChanged)
        Q_PROPERTY(QString popupButtonIcon READ popupButtonIcon WRITE setPopupButtonIcon NOTIFY popupButtonIconChanged)
        Q_PROPERTY(QString popupButtonText READ popupButtonText WRITE setPopupButtonText NOTIFY popupButtonTextChanged)
        Q_PROPERTY(QString popupButtonTextHover READ popupButtonTextHover  WRITE setPopupButtonTextHover  NOTIFY popupButtonTextHoverChanged)


        // Settings
        Q_PROPERTY(QString settingsBackground READ settingsBackground WRITE setSettingsBackground NOTIFY settingsBackgroundChanged)
        Q_PROPERTY(QString settingsSidebarBackground READ settingsSidebarBackground WRITE setSettingsSidebarBackground NOTIFY settingsSidebarBackgroundChanged)
        Q_PROPERTY(QString settingsPanelBackground READ settingsPanelBackground WRITE setSettingsPanelBackground NOTIFY settingsPanelBackgroundChanged)
        Q_PROPERTY(QString settingsPanelText READ settingsPanelText WRITE setSettingsPanelText NOTIFY settingsPanelTextChanged)
        Q_PROPERTY(QString settingsPanelTextField READ settingsPanelTextField WRITE setSettingsPanelTextField NOTIFY settingsPanelTextFieldChanged)

        Q_PROPERTY(QString navbarBackground READ navbarBackground WRITE setNavbarBackground NOTIFY navbarBackgroundChanged)
        Q_PROPERTY(QString navbarChecked READ navbarChecked WRITE setNavbarChecked NOTIFY navbarCheckedChanged)
        Q_PROPERTY(QString navbarHover READ navbarHover WRITE setNavbarHover NOTIFY navbarHoverChanged)
        Q_PROPERTY(QString navbarEnabled READ navbarEnabled WRITE setNavbarEnabled NOTIFY navbarEnabledChanged)
        Q_PROPERTY(QString navbarBackground2 READ navbarBackground2 WRITE setNavbarBackground2 NOTIFY navbarBackground2Changed)
        Q_PROPERTY(QString navbarText READ navbarText WRITE setNavbarText NOTIFY navbarTextChanged)
        Q_PROPERTY(QString navbarText2 READ navbarText2 WRITE setNavbarText2 NOTIFY navbarText2Changed)
        Q_PROPERTY(QString navbarTextChecked READ navbarTextChecked WRITE setNavbarTextChecked NOTIFY navbarTextCheckedChanged)
        Q_PROPERTY(QString navbarTextCheckable READ navbarTextCheckable WRITE setNavbarTextCheckable NOTIFY navbarTextCheckableChanged)

        Q_PROPERTY(QString languageBackground READ languageBackground WRITE setLanguageBackground NOTIFY languageBackgroundChanged)
        Q_PROPERTY(QString languageSelection READ languageSelection WRITE setLanguageSelection NOTIFY languageSelectionChanged)
        Q_PROPERTY(QString languageText READ languageText WRITE setLanguageText NOTIFY languageTextChanged)
        Q_PROPERTY(QString languageTextSelected READ languageTextSelected WRITE setLanguageTextSelected NOTIFY languageTextSelectedChanged)

        Q_PROPERTY(QString infoText READ infoText WRITE setInfoText NOTIFY infoTextChanged)
        Q_PROPERTY(QString infoHeaderText READ infoHeaderText WRITE setInfoHeaderText NOTIFY infoHeaderTextChanged)
        Q_PROPERTY(QString infoSubHeaderText READ infoSubHeaderText WRITE setInfoSubHeaderText NOTIFY infoSubHeaderTextChanged)


        // List Items
        Q_PROPERTY(QString delegateBackground READ delegateBackground WRITE setDelegateBackground NOTIFY delegateBackgroundChanged)
        Q_PROPERTY(QString delegateSelectedBackground READ delegateSelectedBackground WRITE setDelegateSelectedBackground NOTIFY delegateSelectedBackgroundChanged)
        Q_PROPERTY(QString delegateHoveredBackground READ delegateHoveredBackground WRITE setDelegateHoveredBackground NOTIFY delegateHoveredBackgroundChanged)

        Q_PROPERTY(QString delegateText READ delegateText WRITE setDelegateText NOTIFY delegateTextChanged)
        Q_PROPERTY(QString delegateSelectedText READ delegateSelectedText WRITE setDelegateSelectedText NOTIFY delegateSelectedTextChanged)
        Q_PROPERTY(QString delegateHoveredText READ delegateHoveredText WRITE setDelegateHoveredText NOTIFY delegateHoveredTextChanged)
        Q_PROPERTY(QString lastMessageColor READ lastMessageColor WRITE setLastMessageColor NOTIFY lastMessageColorChanged)
        Q_PROPERTY(QString lastMessageColor2 READ lastMessageColor2 WRITE setLastMessageColor2 NOTIFY lastMessageColor2Changed)


        // StartScreen
        Q_PROPERTY(QString startScreenBackground READ startScreenBackground WRITE setStartScreenBackground NOTIFY startScreenBackgroundChanged)
        Q_PROPERTY(QString startScreenHeaderText READ startScreenHeaderText WRITE setStartScreenHeaderText NOTIFY startScreenHeaderTextChanged)

        Q_PROPERTY(QString activityItemBackground READ activityItemBackground WRITE setActivityItemBackground NOTIFY activityItemBackgroundChanged)
        Q_PROPERTY(QString activityItemText READ activityItemText WRITE setActivityItemText NOTIFY activityItemTextChanged)

        Q_PROPERTY(QString newActivityButton READ newActivityButton WRITE setNewActivityButton NOTIFY newActivityButtonChanged)
        Q_PROPERTY(QString newActivityButtonBackground READ newActivityButtonBackground WRITE setNewActivityButtonBackground NOTIFY newActivityButtonBackgroundChanged)
        Q_PROPERTY(QString newActivityButtonText READ newActivityButtonText WRITE setNewActivityButtonText NOTIFY newActivityButtonTextChanged)


        // Activity Area
        Q_PROPERTY(QString activitySidebarBackground READ activitySidebarBackground WRITE setActivitySidebarBackground NOTIFY activitySidebarBackgroundChanged)


        // Search Field
        Q_PROPERTY(QString searchFieldBackground READ searchFieldBackground WRITE setSearchFieldBackground NOTIFY searchFieldBackgroundChanged)
        Q_PROPERTY(QString searchFieldBackground2 READ searchFieldBackground2 WRITE setSearchFieldBackground2 NOTIFY searchFieldBackground2Changed)
        Q_PROPERTY(QString searchFieldText READ searchFieldText WRITE setSearchFieldText NOTIFY searchFieldTextChanged)
        Q_PROPERTY(QString searchFieldIcon READ searchFieldIcon WRITE setSearchFieldIcon NOTIFY searchFieldIconChanged)
        Q_PROPERTY(QString searchFieldIconHover READ searchFieldIconHover WRITE setSearchFieldIconHover NOTIFY searchFieldIconHoverChanged)


        // New Activity Popup
        Q_PROPERTY(QString newActivityPopupBackground READ newActivityPopupBackground WRITE setNewActivityPopupBackground NOTIFY newActivityPopupBackgroundChanged)
        Q_PROPERTY(QString newActivityPopupHeaderText READ newActivityPopupHeaderText WRITE setNewActivityPopupHeaderText NOTIFY newActivityPopupHeaderTextChanged)


        // Activity Area
        Q_PROPERTY(QString activityAreaBackground READ activityAreaBackground WRITE setActivityAreaBackground NOTIFY activityAreaBackgroundChanged)


        // Chat Section
        Q_PROPERTY(QString chatSectionBackground READ chatSectionBackground WRITE setChatSectionBackground NOTIFY chatSectionBackgroundChanged)
        Q_PROPERTY(QString chatSectionLine READ chatSectionLine WRITE setChatSectionLine NOTIFY chatSectionLineChanged)
        Q_PROPERTY(QString chatSectionText READ chatSectionText WRITE setChatSectionText NOTIFY chatSectionTextChanged)


        // Chat Bubble
        Q_PROPERTY(QString chatBubbleBackgroundIn READ chatBubbleBackgroundIn WRITE setChatBubbleBackgroundIn NOTIFY chatBubbleBackgroundInChanged)
        Q_PROPERTY(QString chatBubbleBackgroundOut READ chatBubbleBackgroundOut WRITE setChatBubbleBackgroundOut NOTIFY chatBubbleBackgroundOutChanged)

        Q_PROPERTY(QString chatBubbleTextIn READ chatBubbleTextIn WRITE setChatBubbleTextIn NOTIFY chatBubbleTextInChanged)
        Q_PROPERTY(QString chatBubbleTextOut READ chatBubbleTextOut WRITE setChatBubbleTextOut NOTIFY chatBubbleTextOutChanged)

        Q_PROPERTY(QString chatBubbleDateTextIn READ chatBubbleDateTextIn WRITE setChatBubbleDateTextIn NOTIFY chatBubbleDateTextInChanged)
        Q_PROPERTY(QString chatBubbleDateTextOut READ chatBubbleDateTextOut WRITE setChatBubbleDateTextOut NOTIFY chatBubbleDateTextOutChanged)

        Q_PROPERTY(QString chatBubbleMediaTextIn READ chatBubbleMediaTextIn WRITE setChatBubbleMediaTextIn NOTIFY chatBubbleMediaTextInChanged)
        Q_PROPERTY(QString chatBubbleMediaTextOut READ chatBubbleMediaTextOut WRITE setChatBubbleMediaTextOut NOTIFY chatBubbleMediaTextOutChanged)
        Q_PROPERTY(QString chatBubbleMediaIcon READ chatBubbleMediaIcon WRITE setChatBubbleMediaIcon NOTIFY chatBubbleIconChanged)
        Q_PROPERTY(QString chatBubbleMediaBackground READ chatBubbleMediaBackground WRITE setChatBubbleMediaBackground NOTIFY chatBubbleMediaBackgroundChanged)

        Q_PROPERTY(QString chatBubbleSignatureText READ chatBubbleSignatureText WRITE setChatBubbleSignatureText NOTIFY chatBubbleSignatureTextChanged)
        Q_PROPERTY(QString chatBubbleSignatureTextSigning READ chatBubbleSignatureTextSigning WRITE setChatBubbleSignatureTextSigning NOTIFY chatBubbleSignatureTextSigningChanged)
        Q_PROPERTY(QString chatBubbleSignatureTextRejected READ chatBubbleSignatureTextRejected WRITE setChatBubbleSignatureTextRejected NOTIFY chatBubbleSignatureTextRejectedChanged)


        // Chat Footerbar
        Q_PROPERTY(QString chatFooterBackground READ chatFooterBackground WRITE setChatFooterBackground NOTIFY chatFooterBackgroundChanged)
        Q_PROPERTY(QString chatFooterText READ chatFooterText WRITE setChatFooterText NOTIFY chatFooterTextChanged)
        Q_PROPERTY(QString chatFooterTextBackground READ chatFooterTextBackground WRITE setChatFooterTextBackground NOTIFY chatFooterTextBackgroundChanged)

        // Transaction Progressbar
        Q_PROPERTY(QString transactionProgressBarBackground READ transactionProgressBarBackground WRITE setTransactionProgressBarBackground NOTIFY transactionProgressBarBackgroundChanged)

        //*****************************************************************************************

        Q_PROPERTY(QString black READ black WRITE setBlack NOTIFY blackChanged)
        Q_PROPERTY(QString white READ white WRITE setWhite NOTIFY whiteChanged)

        Q_PROPERTY(QString blue READ blue WRITE setBlue NOTIFY blueChanged)
        Q_PROPERTY(QString darkBlue READ darkBlue WRITE setDarkBlue NOTIFY darkBlueChanged)
        Q_PROPERTY(QString lightBlue READ lightBlue WRITE setLightBlue NOTIFY lightBlueChanged)
        Q_PROPERTY(QString skyBlue READ skyBlue WRITE setSkyBlue NOTIFY skyBlueChanged)
        Q_PROPERTY(QString whitishBlue READ whitishBlue WRITE setWhitishBlue NOTIFY whitishBlueChanged)

        Q_PROPERTY(QString gray READ gray WRITE setGray NOTIFY grayChanged)
        Q_PROPERTY(QString gray2 READ gray2 WRITE setGray2 NOTIFY gray2Changed)
        Q_PROPERTY(QString gray3 READ gray3 WRITE setGray3 NOTIFY gray3Changed)
        Q_PROPERTY(QString gray4 READ gray4 WRITE setGray4 NOTIFY gray4Changed)
        Q_PROPERTY(QString lightGray READ lightGray WRITE setLightGray NOTIFY lightGrayChanged)
        Q_PROPERTY(QString whitishGray READ whitishGray WRITE setWhitishGray NOTIFY whitishGrayChanged)
        Q_PROPERTY(QString blackishGray READ blackishGray WRITE setBlackishGray NOTIFY blackishGrayChanged)
        Q_PROPERTY(QString colorLineGray READ colorLineGray WRITE setColorLineGray NOTIFY colorLineGrayChanged)

        Q_PROPERTY(QString colorAccentBlue READ colorAccentBlue WRITE setColorAccentBlue NOTIFY colorAccentBlueChanged)
        Q_PROPERTY(QString colorAccentHoverBlue READ colorAccentHoverBlue WRITE setColorAccentHoverBlue NOTIFY colorAccentHoverBlueChanged)
        Q_PROPERTY(QString colorAccentMediumHintedBlue READ colorAccentMediumHintedBlue WRITE setColorAccentMediumHintedBlue NOTIFY colorAccentMediumHintedBlueChanged)
        Q_PROPERTY(QString colorAccentMediumHintedRed READ colorAccentMediumHintedRed WRITE setColorAccentMediumHintedRed NOTIFY colorAccentMediumHintedRedChanged)
        Q_PROPERTY(QString colorAccentMediumBlue READ colorAccentMediumBlue WRITE setColorAccentMediumBlue NOTIFY colorAccentMediumBlueChanged)
        Q_PROPERTY(QString greenPositive READ greenPositive WRITE setGreenPositive NOTIFY greenPositiveChanged)
        Q_PROPERTY(QString green READ green WRITE setGreen NOTIFY greenChanged)
        Q_PROPERTY(QString redNegative READ redNegative WRITE setRedNegative NOTIFY redNegativeChanged)
        Q_PROPERTY(QString redWarning READ redWarning WRITE setRedWarning NOTIFY redWarningChanged)

        Q_PROPERTY(QString dropShadow1 READ dropShadow1 WRITE setDropShadow1 NOTIFY dropShadow1Changed)
        Q_PROPERTY(QString dropShadow2 READ dropShadow2 WRITE setDropShadow2 NOTIFY dropShadow2Changed)
        Q_PROPERTY(QString dropShadow3 READ dropShadow3 WRITE setDropShadow3 NOTIFY dropShadow3Changed)
        Q_PROPERTY(QString dropShadow4 READ dropShadow4 WRITE setDropShadow4 NOTIFY dropShadow4Changed)

        Q_PROPERTY(QString toolTipText READ toolTipText WRITE setToolTipText NOTIFY toolTipTextChanged)
        Q_PROPERTY(QString toolTipBackground READ toolTipBackground WRITE setToolTipBackground NOTIFY toolTipBackgroundChanged)

    public:

        explicit Colors(QObject *parent = nullptr);
        ~Colors();

    public:
        const QString &primary() const;
        void setPrimary(const QString& color);

        const QString &accent() const;
        void setAccent(const QString& color);

        const QString &background() const;
        void setBackground(const QString& color);

        const QString &foreground() const;
        void setForeground(const QString& color);

        const QString &white() const;
        void setWhite(const QString& color);

        const QString &black() const;
        void setBlack(const QString& color);

        const QString &blue() const;
        void setBlue(const QString& color);

        const QString &darkBlue() const;
        void setDarkBlue(const QString& color);

        const QString &whitishBlue() const;
        void setWhitishBlue(const QString& color);

        const QString &lightBlue() const;
        void setLightBlue(const QString& color);

        const QString &skyBlue() const;
        void setSkyBlue(const QString& color);

        const QString &gray() const;
        void setGray(const QString& color);

        const QString &gray2() const;
        void setGray2(const QString& color);

        const QString &gray3() const;
        void setGray3(const QString& color);

        const QString &gray4() const;
        void setGray4(const QString& color);

        const QString &lightGray() const;
        void setLightGray(const QString& color);

        const QString &whitishGray() const;
        void setWhitishGray(const QString& color);

        const QString &blackishGray() const;
        void setBlackishGray(const QString& color);

        const QString &colorLineGray() const;
        void setColorLineGray(const QString& color);



        const QString &colorAccentBlue() const;
        void setColorAccentBlue(const QString& color);

        const QString &colorAccentHoverBlue() const;
        void setColorAccentHoverBlue(const QString& color);

        const QString &colorAccentMediumHintedBlue() const;
        void setColorAccentMediumHintedBlue(const QString& color);

        const QString &colorAccentMediumHintedRed() const;
        void setColorAccentMediumHintedRed(const QString& color);

        const QString &colorAccentMediumBlue() const;
        void setColorAccentMediumBlue(const QString& color);

        const QString &greenPositive() const;
        void setGreenPositive(const QString& color);

        const QString &green() const;
        void setGreen(const QString& color);

        const QString &redNegative() const;
        void setRedNegative(const QString& color);

        const QString &redWarning() const;
        void setRedWarning(const QString& color);

        const QString &dropShadow1() const;
        void setDropShadow1(const QString& color);

        const QString &dropShadow2() const;
        void setDropShadow2(const QString& color);

        const QString &dropShadow3() const;
        void setDropShadow3(const QString& color);

        const QString &toolTipText() const;
        void setToolTipText(QString toolTipText);

        const QString &toolTipBackground() const;
        void setToolTipBackground(QString toolTipBackground);

        QString mainBackground() const
        {
            return m_mainBackground;
        }

        QString mainHeaderBackground() const
        {
            return m_mainHeaderBackground;
        }

        QString subHeaderBackground() const
        {
            return m_subHeaderBackground;
        }

        QString line() const
        {
            return m_line;
        }

        QString text() const
        {
            return m_text;
        }

        QString headerText() const
        {
            return m_headerText;
        }

        QString panelBackground() const
        {
            return m_panelBackground;
        }

        QString subHeaderText() const
        {
            return m_subHeaderText;
        }

        QString textField() const
        {
            return m_textField;
        }

        QString textFieldEnabled() const
        {
            return m_textFieldEnabled;
        }

        QString textFieldFocus() const
        {
            return m_textFieldFocus;
        }

        QString textFieldText() const
        {
            return m_textFieldText;
        }

        QString textFieldSelection() const
        {
            return m_textFieldSelection;
        }

        QString textFieldPlaceholder() const
        {
            return m_textFieldPlaceholder;
        }

        QString userSwitchButton() const
        {
            return m_userSwitchButton;
        }

        QString userSwitchButtonEnabled() const
        {
            return m_userSwitchButtonEnabled;
        }

        QString linkButton() const
        {
            return m_linkButton;
        }

        QString backButton() const
        {
            return m_backButton;
        }

        QString backButtonEnabled() const
        {
            return m_backButtonEnabled;
        }

        QString settingsSidebarBackground() const
        {
            return m_settingsSidebarBackground;
        }

        QString navbarBackground() const
        {
            return m_navbarBackground;
        }

        QString navbarBackground2() const
        {
            return m_navbarBackground2;
        }

        QString navbarText() const
        {
            return m_navbarText;
        }

        QString navbarText2() const
        {
            return m_navbarText2;
        }

        QString navbarTextChecked() const
        {
            return m_navbarTextChecked;
        }

        QString navbarTextCheckable() const
        {
            return m_navbarTextCheckable;
        }

        QString navbarChecked() const
        {
            return m_navbarChecked;
        }

        QString navbarHover() const
        {
            return m_navbarHover;
        }

        QString navbarEnabled() const
        {
            return m_navbarEnabled;
        }

        QString contactUserName() const
        {
            return m_contactUserName;
        }

        QString contactEcoId() const
        {
            return m_contactEcoId;
        }

        QString loginText() const
        {
            return m_loginText;
        }

        QString delegateBackground() const
        {
            return m_delegateBackground;
        }

        QString delegateText() const
        {
            return m_delegateText;
        }

        QString lastMessageColor() const
        {
            return m_lastMessageColor;
        }

        QString lastMessageColor2() const
        {
            return m_lastMessageColor2;
        }

        QString delegateSelectedBackground() const
        {
            return m_delegateSelectedBackground;
        }

        QString delegateHoveredBackground() const
        {
            return m_delegateHoveredBackground;
        }

        QString delegateSelectedText() const
        {
            return m_delegateSelectedText;
        }

        QString delegateHoveredText() const
        {
            return m_delegateHoveredText;
        }

        QString userDeleteButton() const
        {
            return m_userDeleteButton;
        }

        QString userDeleteButtonText() const
        {
            return m_userDeleteButtonText;
        }

        QString addUserButton() const
        {
            return m_addUserButton;
        }

        QString addUserButtonText() const
        {
            return m_addUserButtonText;
        }

        QString addUserButtonTextHover() const
        {
            return m_addUserButtonTextHover;
        }

        QString addUserButtonHover() const
        {
            return m_addUserButtonHover;
        }

        QString settingsBackground() const
        {
            return m_settingsBackground;
        }

        QString settingsPanelBackground() const
        {
            return m_settingsPanelBackground;
        }

        QString settingsPanelText() const
        {
            return m_settingsPanelText;
        }

        QString settingsPanelTextField() const
        {
            return m_settingsPanelTextField;
        }

        QString languageBackground() const
        {
            return m_languageBackground;
        }

        QString languageSelection() const
        {
            return m_languageSelection;
        }

        QString languageText() const
        {
            return m_languageText;
        }

        QString languageTextSelected() const
        {
            return m_languageTextSelected;
        }

        QString infoText() const
        {
            return m_infoText;
        }

        QString infoHeaderText() const
        {
            return m_infoHeaderText;
        }

        QString infoSubHeaderText() const
        {
            return m_infoSubHeaderText;
        }

        QString textAreaSelectionColor() const
        {
            return m_textAreaSelectionColor;
        }

        QString textAreaSelectedColor() const
        {
            return m_textAreaSelectedColor;
        }

        QString startScreenBackground() const
        {
            return m_startScreenBackground;
        }

        QString startScreenHeaderText() const
        {
            return m_startScreenHeaderText;
        }

        QString activityItemBackground() const
        {
            return m_activityItemBackground;
        }

        QString activityItemText() const
        {
            return m_activityItemText;
        }

        QString newActivityButton() const
        {
            return m_newActivityButton;
        }

        QString newActivityButtonBackground() const
        {
            return m_newActivityButtonBackground;
        }

        QString newActivityButtonText() const
        {
            return m_newActivityButtonText;
        }

        QString activitySidebarBackground() const
        {
            return m_activitySidebarBackground;
        }

        QString searchFieldBackground() const
        {
            return m_searchFieldBackground;
        }

        QString searchFieldText() const
        {
            return m_searchFieldText;
        }

        QString searchFieldIcon() const
        {
            return m_searchFieldIcon;
        }

        QString searchFieldIconHover() const
        {
            return m_searchFieldIconHover;
        }

        QString searchFieldBackground2() const
        {
            return m_searchFieldBackground2;
        }

        QString newActivityPopupBackground() const
        {
            return m_newActivityPopupBackground;
        }

        QString newActivityPopupHeaderText() const
        {
            return m_newActivityPopupHeaderText;
        }

        QString textButton() const
        {
            return m_textButton;
        }

        QString textButtonHinted() const
        {
            return m_textButtonHinted;
        }

        QString textButtonEnabled() const
        {
            return m_textButtonEnabled;
        }

        QString textButtonBackground() const
        {
            return m_textButtonBackground;
        }

        QString activityAreaBackground() const
        {
            return m_activityAreaBackground;
        }

        QString chatSectionBackground() const
        {
            return m_chatSectionBackground;
        }

        QString chatSectionLine() const
        {
            return m_chatSectionLine;
        }

        QString chatSectionText() const
        {
            return m_chatSectionText;
        }

        QString chatBubbleBackgroundIn() const
        {
            return m_chatBubbleBackgroundIn;
        }

        QString chatBubbleBackgroundOut() const
        {
            return m_chatBubbleBackgroundOut;
        }

        QString dropShadow4() const
        {
            return m_dropShadow4;
        }

        QString chatBubbleMediaIcon() const
        {
            return m_chatBubbleMediaIcon;
        }

        QString chatBubbleMediaBackground() const
        {
            return m_chatBubbleMediaBackground;
        }

        QString chatBubbleTextIn() const
        {
            return m_chatBubbleTextIn;
        }

        QString chatBubbleTextOut() const
        {
            return m_chatBubbleTextOut;
        }

        QString chatBubbleDateTextIn() const
        {
            return m_chatBubbleDateTextIn;
        }

        QString chatBubbleDateTextOut() const
        {
            return m_chatBubbleDateTextOut;
        }

        QString chatBubbleMediaTextIn() const
        {
            return m_chatBubbleMediaTextIn;
        }

        QString chatBubbleMediaTextOut() const
        {
            return m_chatBubbleMediaTextOut;
        }

        QString chatBubbleSignatureText() const
        {
            return m_chatBubbleSignatureText;
        }

        QString chatBubbleSignatureTextSigning() const
        {
            return m_chatBubbleSignatureTextSigning;
        }

        QString chatBubbleSignatureTextRejected() const
        {
            return m_chatBubbleSignatureTextRejected;
        }

        QString chatFooterBackground() const
        {
            return m_chatFooterBackground;
        }

        QString chatFooterText() const
        {
            return m_chatFooterText;
        }

        QString chatFooterTextBackground() const
        {
            return m_chatFooterTextBackground;
        }

        QString popupButtonBackground() const
        {
            return m_popupButtonBackground;
        }

        QString popupButtonIcon() const
        {
            return m_popupButtonIcon;
        }

        QString popupButtonText() const
        {
            return m_popupButtonText;
        }

        QString transactionProgressBarBackground() const
        {
            return m_transactionProgressBarBackground;
        }

        QString popupButtonHoverBackground() const
        {
            return m_popupButtonHoverBackground;
        }

        QString popupButtonTextHover() const
        {
            return m_popupButtonTextHover;
        }

        QString linkMessageTextIn() const
        {
            return m_linkMessageTextIn;
        }

        QString linkMessageTextOut() const
        {
            return m_linkMessageTextOut;
        }

        QString lineDialog() const;

public slots:
        void setMainBackground(QString mainBackground)
        {
            if (m_mainBackground == mainBackground)
                return;

            m_mainBackground = mainBackground;
            emit mainBackgroundChanged(m_mainBackground);
        }

        void setMainHeaderBackground(QString mainHeaderBackground)
        {
            if (m_mainHeaderBackground == mainHeaderBackground)
                return;

            m_mainHeaderBackground = mainHeaderBackground;
            emit mainHeaderBackgroundChanged(m_mainHeaderBackground);
        }

        void setSubHeaderBackground(QString subHeaderBackground)
        {
            if (m_subHeaderBackground == subHeaderBackground)
                return;

            m_subHeaderBackground = subHeaderBackground;
            emit subHeaderBackgroundChanged(m_subHeaderBackground);
        }

        void setLine(QString line)
        {
            if (m_line == line)
                return;

            m_line = line;
            emit lineChanged(m_line);
        }

        void setText(QString text)
        {
            if (m_text == text)
                return;

            m_text = text;
            emit textChanged(m_text);
        }

        void setHeaderText(QString headerText)
        {
            if (m_headerText == headerText)
                return;

            m_headerText = headerText;
            emit headerTextChanged(m_headerText);
        }

        void setPanelBackground(QString panelBackground)
        {
            if (m_panelBackground == panelBackground)
                return;

            m_panelBackground = panelBackground;
            emit panelBackgroundChanged(m_panelBackground);
        }

        void setSubHeaderText(QString subHeaderText)
        {
            if (m_subHeaderText == subHeaderText)
                return;

            m_subHeaderText = subHeaderText;
            emit subHeaderTextChanged(m_subHeaderText);
        }

        void setTextField(QString textField)
        {
            if (m_textField == textField)
                return;

            m_textField = textField;
            emit textFieldChanged(m_textField);
        }

        void setTextFieldEnabled(QString textFieldEnabled)
        {
            if (m_textFieldEnabled == textFieldEnabled)
                return;

            m_textFieldEnabled = textFieldEnabled;
            emit textFieldEnabledChanged(m_textFieldEnabled);
        }

        void setTextFieldFocus(QString textFieldFocus)
        {
            if (m_textFieldFocus == textFieldFocus)
                return;

            m_textFieldFocus = textFieldFocus;
            emit textFieldFocusChanged(m_textFieldFocus);
        }

        void setTextFieldText(QString textFieldText)
        {
            if (m_textFieldText == textFieldText)
                return;

            m_textFieldText = textFieldText;
            emit textFieldTextChanged(m_textFieldText);
        }

        void setTextFieldSelection(QString textFieldSelection)
        {
            if (m_textFieldSelection == textFieldSelection)
                return;

            m_textFieldSelection = textFieldSelection;
            emit textFieldSelectionChanged(m_textFieldSelection);
        }

        void setTextFieldPlaceholder(QString textFieldPlaceholder)
        {
            if (m_textFieldPlaceholder == textFieldPlaceholder)
                return;

            m_textFieldPlaceholder = textFieldPlaceholder;
            emit textFieldPlaceholderChanged(m_textFieldPlaceholder);
        }

        void setUserSwitchButton(QString userSwitchButton)
        {
            if (m_userSwitchButton == userSwitchButton)
                return;

            m_userSwitchButton = userSwitchButton;
            emit userSwitchButtonChanged(m_userSwitchButton);
        }

        void setUserSwitchButtonEnabled(QString userSwitchButtonEnabled)
        {
            if (m_userSwitchButtonEnabled == userSwitchButtonEnabled)
                return;

            m_userSwitchButtonEnabled = userSwitchButtonEnabled;
            emit userSwitchButtonEnabledChanged(m_userSwitchButtonEnabled);
        }

        void setLinkButton(QString linkButton)
        {
            if (m_linkButton == linkButton)
                return;

            m_linkButton = linkButton;
            emit linkButtonChanged(m_linkButton);
        }

        void setBackButton(QString backButton)
        {
            if (m_backButton == backButton)
                return;

            m_backButton = backButton;
            emit backButtonChanged(m_backButton);
        }

        void setBackButtonEnabled(QString backButtonEnabled)
        {
            if (m_backButtonEnabled == backButtonEnabled)
                return;

            m_backButtonEnabled = backButtonEnabled;
            emit backButtonEnabledChanged(m_backButtonEnabled);
        }

        void setSettingsSidebarBackground(QString settingsSidebarBackground)
        {
            if (m_settingsSidebarBackground == settingsSidebarBackground)
                return;

            m_settingsSidebarBackground = settingsSidebarBackground;
            emit settingsSidebarBackgroundChanged(m_settingsSidebarBackground);
        }

        void setNavbarBackground(QString navbarBackground)
        {
            if (m_navbarBackground == navbarBackground)
                return;

            m_navbarBackground = navbarBackground;
            emit navbarBackgroundChanged(m_navbarBackground);
        }

        void setNavbarBackground2(QString navbarBackground2)
        {
            if (m_navbarBackground2 == navbarBackground2)
                return;

            m_navbarBackground2 = navbarBackground2;
            emit navbarBackground2Changed(m_navbarBackground2);
        }

        void setNavbarText(QString navbarText)
        {
            if (m_navbarText == navbarText)
                return;

            m_navbarText = navbarText;
            emit navbarTextChanged(m_navbarText);
        }

        void setNavbarText2(QString navbarText2)
        {
            if (m_navbarText2 == navbarText2)
                return;

            m_navbarText2 = navbarText2;
            emit navbarText2Changed(m_navbarText2);
        }

        void setNavbarTextChecked(QString navbarTextChecked)
        {
            if (m_navbarTextChecked == navbarTextChecked)
                return;

            m_navbarTextChecked = navbarTextChecked;
            emit navbarTextCheckedChanged(m_navbarTextChecked);
        }

        void setNavbarTextCheckable(QString navbarTextCheckable)
        {
            if (m_navbarTextCheckable == navbarTextCheckable)
                return;

            m_navbarTextCheckable = navbarTextCheckable;
            emit navbarTextCheckableChanged(m_navbarTextCheckable);
        }

        void setNavbarChecked(QString navbarChecked)
        {
            if (m_navbarChecked == navbarChecked)
                return;

            m_navbarChecked = navbarChecked;
            emit navbarCheckedChanged(m_navbarChecked);
        }

        void setNavbarHover(QString navbarHover)
        {
            if (m_navbarHover == navbarHover)
                return;

            m_navbarHover = navbarHover;
            emit navbarHoverChanged(m_navbarHover);
        }

        void setNavbarEnabled(QString navbarEnabled)
        {
            if (m_navbarEnabled == navbarEnabled)
                return;

            m_navbarEnabled = navbarEnabled;
            emit navbarEnabledChanged(m_navbarEnabled);
        }

        void setContactUserName(QString contactUserName)
        {
            if (m_contactUserName == contactUserName)
                return;

            m_contactUserName = contactUserName;
            emit contactUserNameChanged(m_contactUserName);
        }

        void setContactEcoId(QString contactEcoId)
        {
            if (m_contactEcoId == contactEcoId)
                return;

            m_contactEcoId = contactEcoId;
            emit contactEcoIdChanged(m_contactEcoId);
        }

        void setLoginText(QString loginText)
        {
            if (m_loginText == loginText)
                return;

            m_loginText = loginText;
            emit loginTextChanged(m_loginText);
        }

        void setDelegateBackground(QString delegateBackground)
        {
            if (m_delegateBackground == delegateBackground)
                return;

            m_delegateBackground = delegateBackground;
            emit delegateBackgroundChanged(m_delegateBackground);
        }

        void setDelegateText(QString delegateText)
        {
            if (m_delegateText == delegateText)
                return;

            m_delegateText = delegateText;
            emit delegateTextChanged(m_delegateText);
        }

        void setLastMessageColor(QString lastMessageColor)
        {
            if (m_lastMessageColor == lastMessageColor)
                return;

            m_lastMessageColor = lastMessageColor;
            emit lastMessageColorChanged(m_lastMessageColor);
        }

        void setLastMessageColor2(QString lastMessageColor2)
        {
            if (m_lastMessageColor2 == lastMessageColor2)
                return;

            m_lastMessageColor2 = lastMessageColor2;
            emit lastMessageColor2Changed(m_lastMessageColor2);
        }

        void setDelegateSelectedBackground(QString delegateSelectedBackground)
        {
            if (m_delegateSelectedBackground == delegateSelectedBackground)
                return;

            m_delegateSelectedBackground = delegateSelectedBackground;
            emit delegateSelectedBackgroundChanged(m_delegateSelectedBackground);
        }

        void setDelegateHoveredBackground(QString delegateHoveredBackground)
        {
            if (m_delegateHoveredBackground == delegateHoveredBackground)
                return;

            m_delegateHoveredBackground = delegateHoveredBackground;
            emit delegateHoveredBackgroundChanged(m_delegateHoveredBackground);
        }

        void setDelegateSelectedText(QString delegateSelectedText)
        {
            if (m_delegateSelectedText == delegateSelectedText)
                return;

            m_delegateSelectedText = delegateSelectedText;
            emit delegateSelectedTextChanged(m_delegateSelectedText);
        }

        void setDelegateHoveredText(QString delegateHoveredText)
        {
            if (m_delegateHoveredText == delegateHoveredText)
                return;

            m_delegateHoveredText = delegateHoveredText;
            emit delegateHoveredTextChanged(m_delegateHoveredText);
        }

        void setUserDeleteButton(QString userDeleteButton)
        {
            if (m_userDeleteButton == userDeleteButton)
                return;

            m_userDeleteButton = userDeleteButton;
            emit userDeleteButtonChanged(m_userDeleteButton);
        }

        void setUserDeleteButtonText(QString userDeleteButtonText)
        {
            if (m_userDeleteButtonText == userDeleteButtonText)
                return;

            m_userDeleteButtonText = userDeleteButtonText;
            emit userDeleteButtonTextChanged(m_userDeleteButtonText);
        }

        void setAddUserButton(QString addUserButton)
        {
            if (m_addUserButton == addUserButton)
                return;

            m_addUserButton = addUserButton;
            emit addUserButtonChanged(m_addUserButton);
        }

        void setAddUserButtonText(QString addUserButtonText)
        {
            if (m_addUserButtonText == addUserButtonText)
                return;

            m_addUserButtonText = addUserButtonText;
            emit addUserButtonTextChanged(m_addUserButtonText);
        }

        void setAddUserButtonTextHover(QString addUserButtonTextHover)
        {
            if (m_addUserButtonTextHover == addUserButtonTextHover)
                return;

            m_addUserButtonTextHover = addUserButtonTextHover;
            emit addUserButtonTextHoverChanged(m_addUserButtonTextHover);
        }

        void setAddUserButtonHover(QString addUserButtonHover)
        {
            if (m_addUserButtonHover == addUserButtonHover)
                return;

            m_addUserButtonHover = addUserButtonHover;
            emit addUserButtonHoverChanged(m_addUserButtonHover);
        }

        void setSettingsBackground(QString settingsBackground)
        {
            if (m_settingsBackground == settingsBackground)
                return;

            m_settingsBackground = settingsBackground;
            emit settingsBackgroundChanged(m_settingsBackground);
        }

        void setSettingsPanelBackground(QString settingsPanelBackground)
        {
            if (m_settingsPanelBackground == settingsPanelBackground)
                return;

            m_settingsPanelBackground = settingsPanelBackground;
            emit settingsPanelBackgroundChanged(m_settingsPanelBackground);
        }

        void setSettingsPanelText(QString settingsPanelText)
        {
            if (m_settingsPanelText == settingsPanelText)
                return;

            m_settingsPanelText = settingsPanelText;
            emit settingsPanelTextChanged(m_settingsPanelText);
        }

        void setSettingsPanelTextField(QString settingsPanelTextField)
        {
            if (m_settingsPanelTextField == settingsPanelTextField)
                return;

            m_settingsPanelTextField = settingsPanelTextField;
            emit settingsPanelTextFieldChanged(m_settingsPanelTextField);
        }

        void setLanguageBackground(QString languageBackground)
        {
            if (m_languageBackground == languageBackground)
                return;

            m_languageBackground = languageBackground;
            emit languageBackgroundChanged(m_languageBackground);
        }

        void setLanguageSelection(QString languageSelection)
        {
            if (m_languageSelection == languageSelection)
                return;

            m_languageSelection = languageSelection;
            emit languageSelectionChanged(m_languageSelection);
        }

        void setLanguageText(QString languageText)
        {
            if (m_languageText == languageText)
                return;

            m_languageText = languageText;
            emit languageTextChanged(m_languageText);
        }

        void setLanguageTextSelected(QString languageTextSelected)
        {
            if (m_languageTextSelected == languageTextSelected)
                return;

            m_languageTextSelected = languageTextSelected;
            emit languageTextSelectedChanged(m_languageTextSelected);
        }

        void setInfoText(QString infoText)
        {
            if (m_infoText == infoText)
                return;

            m_infoText = infoText;
            emit infoTextChanged(m_infoText);
        }

        void setInfoHeaderText(QString infoHeaderText)
        {
            if (m_infoHeaderText == infoHeaderText)
                return;

            m_infoHeaderText = infoHeaderText;
            emit infoHeaderTextChanged(m_infoHeaderText);
        }

        void setInfoSubHeaderText(QString infoSubHeaderText)
        {
            if (m_infoSubHeaderText == infoSubHeaderText)
                return;

            m_infoSubHeaderText = infoSubHeaderText;
            emit infoSubHeaderTextChanged(m_infoSubHeaderText);
        }

        void setTextAreaSelectionColor(QString textAreaSelectionColor)
        {
            if (m_textAreaSelectionColor == textAreaSelectionColor)
                return;

            m_textAreaSelectionColor = textAreaSelectionColor;
            emit textAreaSelectionColorChanged(m_textAreaSelectionColor);
        }

        void setTextAreaSelectedColor(QString textAreaSelectedColor)
        {
            if (m_textAreaSelectedColor == textAreaSelectedColor)
                return;

            m_textAreaSelectedColor = textAreaSelectedColor;
            emit textAreaSelectedColorChanged(m_textAreaSelectedColor);
        }

        void setStartScreenBackground(QString startScreenBackground)
        {
            if (m_startScreenBackground == startScreenBackground)
                return;

            m_startScreenBackground = startScreenBackground;
            emit startScreenBackgroundChanged(m_startScreenBackground);
        }

        void setStartScreenHeaderText(QString startScreenHeaderText)
        {
            if (m_startScreenHeaderText == startScreenHeaderText)
                return;

            m_startScreenHeaderText = startScreenHeaderText;
            emit startScreenHeaderTextChanged(m_startScreenHeaderText);
        }

        void setActivityItemBackground(QString activityItemBackground)
        {
            if (m_activityItemBackground == activityItemBackground)
                return;

            m_activityItemBackground = activityItemBackground;
            emit activityItemBackgroundChanged(m_activityItemBackground);
        }

        void setActivityItemText(QString activityItemText)
        {
            if (m_activityItemText == activityItemText)
                return;

            m_activityItemText = activityItemText;
            emit activityItemTextChanged(m_activityItemText);
        }

        void setNewActivityButton(QString newActivityButton)
        {
            if (m_newActivityButton == newActivityButton)
                return;

            m_newActivityButton = newActivityButton;
            emit newActivityButtonChanged(m_newActivityButton);
        }

        void setNewActivityButtonBackground(QString newActivityButtonBackground)
        {
            if (m_newActivityButtonBackground == newActivityButtonBackground)
                return;

            m_newActivityButtonBackground = newActivityButtonBackground;
            emit newActivityButtonBackgroundChanged(m_newActivityButtonBackground);
        }

        void setNewActivityButtonText(QString newActivityButtonText)
        {
            if (m_newActivityButtonText == newActivityButtonText)
                return;

            m_newActivityButtonText = newActivityButtonText;
            emit newActivityButtonTextChanged(m_newActivityButtonText);
        }

        void setActivitySidebarBackground(QString activitySidebarBackground)
        {
            if (m_activitySidebarBackground == activitySidebarBackground)
                return;

            m_activitySidebarBackground = activitySidebarBackground;
            emit activitySidebarBackgroundChanged(m_activitySidebarBackground);
        }

        void setSearchFieldBackground(QString searchFieldBackground)
        {
            if (m_searchFieldBackground == searchFieldBackground)
                return;

            m_searchFieldBackground = searchFieldBackground;
            emit searchFieldBackgroundChanged(m_searchFieldBackground);
        }

        void setSearchFieldText(QString searchFieldText)
        {
            if (m_searchFieldText == searchFieldText)
                return;

            m_searchFieldText = searchFieldText;
            emit searchFieldTextChanged(m_searchFieldText);
        }

        void setSearchFieldIcon(QString searchFieldIcon)
        {
            if (m_searchFieldIcon == searchFieldIcon)
                return;

            m_searchFieldIcon = searchFieldIcon;
            emit searchFieldIconChanged(m_searchFieldIcon);
        }

        void setSearchFieldIconHover(QString searchFieldIconHover)
        {
            if (m_searchFieldIconHover == searchFieldIconHover)
                return;

            m_searchFieldIconHover = searchFieldIconHover;
            emit searchFieldIconHoverChanged(m_searchFieldIconHover);
        }

        void setSearchFieldBackground2(QString searchFieldBackground2)
        {
            if (m_searchFieldBackground2 == searchFieldBackground2)
                return;

            m_searchFieldBackground2 = searchFieldBackground2;
            emit searchFieldBackground2Changed(m_searchFieldBackground2);
        }

        void setNewActivityPopupBackground(QString newActivityPopupBackground)
        {
            if (m_newActivityPopupBackground == newActivityPopupBackground)
                return;

            m_newActivityPopupBackground = newActivityPopupBackground;
            emit newActivityPopupBackgroundChanged(m_newActivityPopupBackground);
        }

        void setNewActivityPopupHeaderText(QString newActivityPopupHeaderText)
        {
            if (m_newActivityPopupHeaderText == newActivityPopupHeaderText)
                return;

            m_newActivityPopupHeaderText = newActivityPopupHeaderText;
            emit newActivityPopupHeaderTextChanged(m_newActivityPopupHeaderText);
        }

        void setTextButton(QString textButton)
        {
            if (m_textButton == textButton)
                return;

            m_textButton = textButton;
            emit textButtonChanged(m_textButton);
        }

        void setTextButtonHinted(QString textButtonHinted)
        {
            if (m_textButtonHinted == textButtonHinted)
                return;

            m_textButtonHinted = textButtonHinted;
            emit textButtonHintedChanged(m_textButtonHinted);
        }

        void setTextButtonEnabled(QString textButtonEnabled)
        {
            if (m_textButtonEnabled == textButtonEnabled)
                return;

            m_textButtonEnabled = textButtonEnabled;
            emit textButtonEnabledChanged(m_textButtonEnabled);
        }

        void setTextButtonBackground(QString textButtonBackground)
        {
            if (m_textButtonBackground == textButtonBackground)
                return;

            m_textButtonBackground = textButtonBackground;
            emit textButtonBackgroundChanged(m_textButtonBackground);
        }

        void setActivityAreaBackground(QString activityAreaBackground)
        {
            if (m_activityAreaBackground == activityAreaBackground)
                return;

            m_activityAreaBackground = activityAreaBackground;
            emit activityAreaBackgroundChanged(m_activityAreaBackground);
        }

        void setChatSectionBackground(QString chatSectionBackground)
        {
            if (m_chatSectionBackground == chatSectionBackground)
                return;

            m_chatSectionBackground = chatSectionBackground;
            emit chatSectionBackgroundChanged(m_chatSectionBackground);
        }

        void setChatSectionLine(QString chatSectionLine)
        {
            if (m_chatSectionLine == chatSectionLine)
                return;

            m_chatSectionLine = chatSectionLine;
            emit chatSectionLineChanged(m_chatSectionLine);
        }

        void setChatSectionText(QString chatSectionText)
        {
            if (m_chatSectionText == chatSectionText)
                return;

            m_chatSectionText = chatSectionText;
            emit chatSectionLineChanged(m_chatSectionText);
        }

        void setChatBubbleBackgroundIn(QString chatBubbleBackgroundIn)
        {
            if (m_chatBubbleBackgroundIn == chatBubbleBackgroundIn)
                return;

            m_chatBubbleBackgroundIn = chatBubbleBackgroundIn;
            emit chatBubbleBackgroundInChanged(m_chatBubbleBackgroundIn);
        }

        void setChatBubbleBackgroundOut(QString chatBubbleBackgroundOut)
        {
            if (m_chatBubbleBackgroundOut == chatBubbleBackgroundOut)
                return;

            m_chatBubbleBackgroundOut = chatBubbleBackgroundOut;
            emit chatBubbleBackgroundOutChanged(m_chatBubbleBackgroundOut);
        }

        void setDropShadow4(QString dropShadow4)
        {
            if (m_dropShadow4 == dropShadow4)
                return;

            m_dropShadow4 = dropShadow4;
            emit dropShadow4Changed(m_dropShadow4);
        }

        void setChatBubbleMediaIcon(QString chatBubbleMediaIcon)
        {
            if (m_chatBubbleMediaIcon == chatBubbleMediaIcon)
                return;

            m_chatBubbleMediaIcon = chatBubbleMediaIcon;
            emit chatBubbleIconChanged(m_chatBubbleMediaIcon);
        }

        void setChatBubbleMediaBackground(QString chatBubbleMediaBackground)
        {
            if (m_chatBubbleMediaBackground == chatBubbleMediaBackground)
                return;

            m_chatBubbleMediaBackground = chatBubbleMediaBackground;
            emit chatBubbleMediaBackgroundChanged(m_chatBubbleMediaBackground);
        }

        void setChatBubbleTextIn(QString chatBubbleTextIn)
        {
            if (m_chatBubbleTextIn == chatBubbleTextIn)
                return;

            m_chatBubbleTextIn = chatBubbleTextIn;
            emit chatBubbleTextInChanged(m_chatBubbleTextIn);
        }

        void setChatBubbleTextOut(QString chatBubbleTextOut)
        {
            if (m_chatBubbleTextOut == chatBubbleTextOut)
                return;

            m_chatBubbleTextOut = chatBubbleTextOut;
            emit chatBubbleTextOutChanged(m_chatBubbleTextOut);
        }

        void setChatBubbleDateTextIn(QString chatBubbleDateTextIn)
        {
            if (m_chatBubbleDateTextIn == chatBubbleDateTextIn)
                return;

            m_chatBubbleDateTextIn = chatBubbleDateTextIn;
            emit chatBubbleDateTextInChanged(m_chatBubbleDateTextIn);
        }

        void setChatBubbleDateTextOut(QString chatBubbleDateTextOut)
        {
            if (m_chatBubbleDateTextOut == chatBubbleDateTextOut)
                return;

            m_chatBubbleDateTextOut = chatBubbleDateTextOut;
            emit chatBubbleDateTextOutChanged(m_chatBubbleDateTextOut);
        }

        void setChatBubbleMediaTextIn(QString chatBubbleMediaTextIn)
        {
            if (m_chatBubbleMediaTextIn == chatBubbleMediaTextIn)
                return;

            m_chatBubbleMediaTextIn = chatBubbleMediaTextIn;
            emit chatBubbleMediaTextInChanged(m_chatBubbleMediaTextIn);
        }

        void setChatBubbleMediaTextOut(QString chatBubbleMediaTextOut)
        {
            if (m_chatBubbleMediaTextOut == chatBubbleMediaTextOut)
                return;

            m_chatBubbleMediaTextOut = chatBubbleMediaTextOut;
            emit chatBubbleMediaTextOutChanged(m_chatBubbleMediaTextOut);
        }

        void setChatBubbleSignatureText(QString chatBubbleSignatureText)
        {
            if (m_chatBubbleSignatureText == chatBubbleSignatureText)
                return;

            m_chatBubbleSignatureText = chatBubbleSignatureText;
            emit chatBubbleSignatureTextChanged(m_chatBubbleSignatureText);
        }

        void setChatBubbleSignatureTextSigning(QString chatBubbleSignatureTextSigning)
        {
            if (m_chatBubbleSignatureTextSigning == chatBubbleSignatureTextSigning)
                return;

            m_chatBubbleSignatureTextSigning = chatBubbleSignatureTextSigning;
            emit chatBubbleSignatureTextSigningChanged(m_chatBubbleSignatureTextSigning);
        }

        void setChatBubbleSignatureTextRejected(QString chatBubbleSignatureTextRejected)
        {
            if (m_chatBubbleSignatureTextRejected == chatBubbleSignatureTextRejected)
                return;

            m_chatBubbleSignatureTextRejected = chatBubbleSignatureTextRejected;
            emit chatBubbleSignatureTextRejectedChanged(m_chatBubbleSignatureTextRejected);
        }

        void setChatFooterBackground(QString chatFooterBackground)
        {
            if (m_chatFooterBackground == chatFooterBackground)
                return;

            m_chatFooterBackground = chatFooterBackground;
            emit chatFooterBackgroundChanged(m_chatFooterBackground);
        }

        void setChatFooterText(QString chatFooterText)
        {
            if (m_chatFooterText == chatFooterText)
                return;

            m_chatFooterText = chatFooterText;
            emit chatFooterTextChanged(m_chatFooterText);
        }

        void setChatFooterTextBackground(QString chatFooterTextBackground)
        {
            if (m_chatFooterTextBackground == chatFooterTextBackground)
                return;

            m_chatFooterTextBackground = chatFooterTextBackground;
            emit chatFooterTextBackgroundChanged(m_chatFooterTextBackground);
        }

        void setPopupButtonBackground(QString popupButtonBackground)
        {
            if (m_popupButtonBackground == popupButtonBackground)
                return;

            m_popupButtonBackground = popupButtonBackground;
            emit popupButtonBackgroundChanged(m_popupButtonBackground);
        }

        void setPopupButtonIcon(QString popupButtonIcon)
        {
            if (m_popupButtonIcon == popupButtonIcon)
                return;

            m_popupButtonIcon = popupButtonIcon;
            emit popupButtonIconChanged(m_popupButtonIcon);
        }

        void setPopupButtonText(QString popupButtonText)
        {
            if (m_popupButtonText == popupButtonText)
                return;

            m_popupButtonText = popupButtonText;
            emit popupButtonTextChanged(m_popupButtonText);
        }
        
        void setTransactionProgressBarBackground(QString transactionProgressBarBackground)
        {
            if (m_transactionProgressBarBackground == transactionProgressBarBackground)
                return;

            m_transactionProgressBarBackground = transactionProgressBarBackground;
            emit transactionProgressBarBackgroundChanged(m_transactionProgressBarBackground);
        }

        void setPopupButtonHoverBackground(QString popupButtonHoverBackground)
        {
            if (m_popupButtonHoverBackground == popupButtonHoverBackground)
                return;

            m_popupButtonHoverBackground = popupButtonHoverBackground;
            emit popupButtonHoverBackgroundChanged(m_popupButtonHoverBackground);
        }

        void setPopupButtonTextHover(QString popupButtonTextHover)
        {
            if (m_popupButtonTextHover == popupButtonTextHover)
                return;

            m_popupButtonTextHover = popupButtonTextHover;
            emit popupButtonTextHoverChanged(m_popupButtonTextHover);
        }

        void setLinkMessageTextIn(QString linkMessageTextIn)
        {
            if (m_linkMessageTextIn == linkMessageTextIn)
                return;

            m_linkMessageTextIn = linkMessageTextIn;
            emit linkMessageTextInChanged(m_linkMessageTextIn);
        }

        void setLinkMessageTextOut(QString linkMessageTextOut)
        {
            if (m_linkMessageTextOut == linkMessageTextOut)
                return;

            m_linkMessageTextOut = linkMessageTextOut;
            emit linkMessageTextOutChanged(m_linkMessageTextOut);
        }

        void setLineDialog(QString lineDialog);

Q_SIGNALS:
        void primaryChanged();
        void accentChanged();
        void backgroundChanged();
        void foregroundChanged();
        void whiteChanged();
        void blackChanged();

        void blueChanged();
        void darkBlueChanged();
        void lightBlueChanged();
        void skyBlueChanged();
        void whitishBlueChanged();

        void grayChanged();
        void gray2Changed();
        void gray3Changed();
        void gray4Changed();
        void lightGrayChanged();
        void whitishGrayChanged();
        void blackishGrayChanged();

        void colorLineGrayChanged();
        void colorAccentBlueChanged();
        void colorAccentHoverBlueChanged();
        void colorAccentMediumHintedBlueChanged();
        void colorAccentMediumHintedRedChanged();
        void colorAccentMediumBlueChanged();
        void greenPositiveChanged();
        void greenChanged();
        void redNegativeChanged();
        void redWarningChanged();

        void dropShadow1Changed();
        void dropShadow2Changed();
        void dropShadow3Changed();

        void toolTipTextChanged();
        void toolTipBackgroundChanged();

        void mainBackgroundChanged(QString mainBackground);

        void mainHeaderBackgroundChanged(QString mainHeaderBackground);

        void subHeaderBackgroundChanged(QString subHeaderBackground);

        void lineChanged(QString line);

        void textChanged(QString text);

        void headerTextChanged(QString headerText);

        void panelBackgroundChanged(QString panelBackground);

        void subHeaderTextChanged(QString subHeaderText);

        void textFieldChanged(QString textField);

        void textFieldEnabledChanged(QString textFieldEnabled);

        void textFieldFocusChanged(QString textFieldFocus);

        void textFieldTextChanged(QString textFieldText);

        void textFieldSelectionChanged(QString textFieldSelection);

        void textFieldPlaceholderChanged(QString textFieldPlaceholder);

        void switchButtonChanged(QString switchButton);

        void switchButtonEnabledChanged(QString switchButtonEnabled);

        void userSwitchButtonChanged(QString userSwitchButton);

        void userSwitchButtonEnabledChanged(QString userSwitchButtonEnabled);

        void linkButtonChanged(QString linkButton);

        void backButtonChanged(QString backButton);

        void backButtonEnabledChanged(QString backButtonEnabled);

        void settingsSidebarBackgroundChanged(QString settingsSidebarBackground);

        void navbarBackgroundChanged(QString navbarBackground);

        void navbarBackground2Changed(QString navbarBackground2);

        void navbarTextChanged(QString navbarText);

        void navbarText2Changed(QString navbarText2);

        void navbarTextCheckedChanged(QString navbarTextChecked);

        void navbarTextCheckableChanged(QString navbarTextCheckable);

        void navbarCheckedChanged(QString navbarChecked);

        void navbarHoverChanged(QString navbarHover);

        void navbarEnabledChanged(QString navbarEnabled);

        void contactUserNameChanged(QString contactUserName);

        void contactEcoIdChanged(QString contactEcoId);

        void loginTextChanged(QString loginText);

        void delegateBackgroundChanged(QString delegateBackground);

        void delegateTextChanged(QString delegateText);

        void lastMessageColorChanged(QString lastMessageColor);

        void lastMessageColor2Changed(QString lastMessageColor2);

        void delegateSelectedBackgroundChanged(QString delegateSelectedBackground);

        void delegateHoveredBackgroundChanged(QString delegateHoveredBackground);

        void delegateSelectedTextChanged(QString delegateSelectedText);

        void delegateHoveredTextChanged(QString delegateHoveredText);

        void userDeleteButtonChanged(QString userDeleteButton);

        void userDeleteButtonTextChanged(QString userDeleteButtonText);

        void addUserButtonChanged(QString addUserButton);

        void addUserButtonTextChanged(QString addUserButtonText);

        void addUserButtonTextHoverChanged(QString addUserButtonTextHover);

        void addUserButtonHoverChanged(QString addUserButtonHover);

        void settingsBackgroundChanged(QString settingsBackground);

        void settingsPanelBackgroundChanged(QString settingsPanelBackground);

        void settingsPanelTextChanged(QString settingsPanelText);

        void settingsPanelTextFieldChanged(QString settingsPanelTextField);

        void languageBackgroundChanged(QString languageBackground);

        void languageSelectionChanged(QString languageSelection);

        void languageTextChanged(QString languageText);

        void languageTextSelectedChanged(QString languageTextSelected);

        void infoTextChanged(QString infoText);

        void infoHeaderTextChanged(QString infoHeaderText);

        void infoSubHeaderTextChanged(QString infoSubHeaderText);

        void textAreaSelectionColorChanged(QString textAreaSelectionColor);

        void textAreaSelectedColorChanged(QString textAreaSelectedColor);

        void startScreenBackgroundChanged(QString startScreenBackground);

        void startScreenHeaderTextChanged(QString startScreenHeaderText);

        void activityItemBackgroundChanged(QString activityItemBackground);

        void activityItemTextChanged(QString activityItemText);

        void newActivityButtonChanged(QString newActivityButton);

        void newActivityButtonBackgroundChanged(QString newActivityButtonBackground);

        void newActivityButtonTextChanged(QString newActivityButtonText);

        void activitySidebarBackgroundChanged(QString activitySidebarBackground);

        void searchFieldBackgroundChanged(QString searchFieldBackground);

        void searchFieldTextChanged(QString searchFieldText);

        void searchFieldIconChanged(QString searchFieldIcon);

        void searchFieldIconHoverChanged(QString searchFieldIconHover);

        void searchFieldBackground2Changed(QString searchFieldBackground2);

        void newActivityPopupBackgroundChanged(QString newActivityPopupBackground);

        void newActivityPopupHeaderTextChanged(QString newActivityPopupHeaderText);

        void textButtonChanged(QString textButton);

        void textButtonHintedChanged(QString textButtonHinted);

        void textButtonEnabledChanged(QString textButtonEnabled);

        void textButtonBackgroundChanged(QString textButtonBackground);

        void activityAreaBackgroundChanged(QString activityAreaBackground);

        void chatSectionBackgroundChanged(QString chatSectionBackground);

        void chatSectionLineChanged(QString chatSectionLine);

        void chatSectionTextChanged(QString chatSectionText);

        void chatBubbleBackgroundInChanged(QString chatBubbleBackgroundIn);

        void chatBubbleBackgroundOutChanged(QString chatBubbleBackgroundOut);

        void dropShadow4Changed(QString dropShadow4);

        void chatBubbleIconChanged(QString chatBubbleMediaIcon);

        void chatBubbleMediaBackgroundChanged(QString chatBubbleMediaBackground);

        void chatBubbleTextInChanged(QString chatBubbleTextIn);

        void chatBubbleTextOutChanged(QString chatBubbleTextOut);

        void chatBubbleDateTextInChanged(QString chatBubbleDateTextIn);

        void chatBubbleDateTextOutChanged(QString chatBubbleDateTextOut);

        void chatBubbleMediaTextInChanged(QString chatBubbleMediaTextIn);

        void chatBubbleMediaTextOutChanged(QString chatBubbleMediaTextOut);

        void chatBubbleSignatureTextChanged(QString chatBubbleSignatureText);

        void chatBubbleSignatureTextSigningChanged(QString chatBubbleSignatureTextSigning);

        void chatBubbleSignatureTextRejectedChanged(QString chatBubbleSignatureTextRejected);

        void chatFooterBackgroundChanged(QString chatFooterBackground);

        void chatFooterTextChanged(QString chatFooterText);

        void chatFooterTextBackgroundChanged(QString chatFooterTextBackground);

        void popupButtonBackgroundChanged(QString popupButtonBackground);

        void popupButtonIconChanged(QString popupButtonIcon);

        void popupButtonTextChanged(QString popupButtonText);

        void transactionProgressBarBackgroundChanged(QString transactionProgressBarBackground);

        void popupButtonHoverBackgroundChanged(QString popupButtonHoverBackground);

        void popupButtonTextHoverChanged(QString popupButtonTextHover);

        void linkMessageTextInChanged(QString linkMessageTextIn);

        void linkMessageTextOutChanged(QString m_linkMessageTextOut);

        void lineDialogChanged(QString lineDialog);

private:

        // Set Default Theme to Light
        QString primary_;
        QString accent_;
        QString background_;
        QString foreground_;
        QString white_;
        QString black_;
        QString blue_;
        QString darkBlue_;

        QString whitishBlue_;
        QString lightBlue_;
        QString skyBlue_;

        QString gray_;
        QString gray2_;
        QString gray3_;
        QString gray4_;
        QString lightGray_;
        QString whitishGray_;
        QString blackishGray_;
        QString colorLineGray_;
        QString colorAccentBlue_;

        QString colorAccentHoverBlue_;
        QString colorAccentMediumHintedBlue_;
        QString colorAccentMediumHintedRed_;
        QString colorAccentMediumBlue_;
        QString greenPositive_;
        QString redNegative_;
        QString redWarning_;
        QString dropShadow1_;
        QString dropShadow2_;
        QString dropShadow3_;
        QString green_;

        QString toolTipText_;
        QString toolTipBackground_;
        QString m_mainBackground;
        QString m_mainHeaderBackground;
        QString m_subHeaderBackground;
        QString m_line;
        QString m_text;
        QString m_headerText;
        QString m_panelBackground;
        QString m_subHeaderText;
        QString m_textField;
        QString m_textFieldEnabled;
        QString m_textFieldFocus;
        QString m_textFieldText;
        QString m_textFieldSelection;
        QString m_textFieldPlaceholder;
        QString m_switchButton;
        QString m_switchButtonEnabled;
        QString m_userSwitchButton;
        QString m_userSwitchButtonEnabled;
        QString m_linkButton;
        QString m_backButton;
        QString m_backButtonEnabled;
        QString m_settingsSidebarBackground;
        QString m_navbarBackground;
        QString m_navbarBackground2;
        QString m_navbarText;
        QString m_navbarText2;
        QString m_navbarTextChecked;
        QString m_navbarTextCheckable;
        QString m_navbarChecked;
        QString m_navbarHover;
        QString m_navbarEnabled;
        QString m_contactUserName;
        QString m_contactEcoId;
        QString m_loginText;
        QString m_delegateBackground;
        QString m_delegateText;
        QString m_lastMessageColor;
        QString m_lastMessageColor2;
        QString m_delegateSelectedBackground;
        QString m_delegateHoveredBackground;
        QString m_delegateSelectedText;
        QString m_delegateHoveredText;
        QString m_userDeleteButton;
        QString m_userDeleteButtonText;
        QString m_addUserButton;
        QString m_addUserButtonText;
        QString m_addUserButtonTextHover;
        QString m_addUserButtonHover;
        QString m_settingsBackground;
        QString m_settingsPanelBackground;
        QString m_settingsPanelText;
        QString m_settingsPanelTextField;
        QString m_languageBackground;
        QString m_languageSelection;
        QString m_languageText;
        QString m_languageTextSelected;
        QString m_infoText;
        QString m_infoHeaderText;
        QString m_infoSubHeaderText;
        QString m_textAreaSelectionColor;
        QString m_textAreaSelectedColor;
        QString m_startScreenBackground;
        QString m_startScreenHeaderText;
        QString m_activityItemBackground;
        QString m_activityItemText;
        QString m_newActivityButton;
        QString m_newActivityButtonBackground;
        QString m_newActivityButtonText;
        QString m_activitySidebarBackground;
        QString m_searchFieldBackground;
        QString m_searchFieldText;
        QString m_searchFieldIcon;
        QString m_searchFieldIconHover;
        QString m_searchFieldBackground2;
        QString m_newActivityPopupBackground;
        QString m_newActivityPopupHeaderText;
        QString m_textButton;
        QString m_textButtonHinted;
        QString m_textButtonEnabled;
        QString m_textButtonBackground;
        QString m_activityAreaBackground;
        QString m_chatSectionBackground;
        QString m_chatSectionLine;
        QString m_chatSectionText;
        QString m_chatBubbleBackgroundIn;
        QString m_chatBubbleBackgroundOut;
        QString m_dropShadow4;
        QString m_chatBubbleMediaIcon;
        QString m_chatBubbleMediaBackground;
        QString m_chatBubbleTextIn;
        QString m_chatBubbleTextOut;
        QString m_chatBubbleDateTextIn;
        QString m_chatBubbleDateTextOut;
        QString m_chatBubbleMediaTextIn;
        QString m_chatBubbleMediaTextOut;
        QString m_chatBubbleSignatureText;
        QString m_chatBubbleSignatureTextSigning;
        QString m_chatBubbleSignatureTextRejected;
        QString m_chatFooterBackground;
        QString m_chatFooterText;
        QString m_chatFooterTextBackground;
        QString m_popupButtonBackground;
        QString m_popupButtonIcon;
        QString m_popupButtonText;
        QString m_transactionProgressBarBackground;
        QString m_popupButtonHoverBackground;
        QString m_popupButtonTextHover;
        QString m_linkMessageTextIn;
        QString m_linkMessageTextOut;
        QString m_lineDialog;
};


#endif // COLORS_H
