#ifndef THEME_H
#define THEME_H

#include "colors.h"
#include "sizes.h"
#include "fonts.h"

#include <QObject>
#include <QPointer>
#include <QString>
#include <QImage>

class Theme : public QObject
{
        Q_OBJECT
        Q_PROPERTY(Colors* colors READ colors NOTIFY colorsChanged)
        Q_PROPERTY(Sizes* sizes READ sizes NOTIFY sizesChanged)
        Q_PROPERTY(Fonts* fonts READ fonts NOTIFY fontsChanged)
        Q_PROPERTY(ThemeName name READ name NOTIFY nameChanged)
        Q_PROPERTY(FontSize fontSize READ fontSize NOTIFY fontSizeChanged)

    public:
        /**
         * @brief C-tor
         * @param parent
         */
        explicit Theme(QObject *parent = nullptr);

        /**
         * @brief D-tor
         */
        ~Theme();

        /**
         * @brief Enums of theme type
         */
        enum ThemeName {
            Light,
            Dark
        };
        Q_ENUM(ThemeName)

        /**
         * @brief Enums of font size
         */
        enum FontSize {
            Small,
            Medium,
            Large
        };
        Q_ENUM(FontSize)

        /**
         * @brief get colors object
         * @return pointer of colors
         */
        Colors* colors();

        /**
         * @brief set Colors object
         * @param pointer of colors
         */
        void setColors(Colors* colors);

        /**
         * @brief get current theme name
         * @return
         */
        ThemeName name() const;

        /**
         * @brief Font size of selected theme
         * @return
         */
        Sizes* sizes() const;

        /**
         * @brief Font families holder
         * @return
         */
        Fonts* fonts() const;

        /**
         * @brief fontSize
         * @return
         */
        FontSize fontSize() const;

    public:
        /**
         * @brief changeTheme signal
         * @param Light or Dark Theme
         */
        Q_INVOKABLE void changeTheme(ThemeName themeName);

        /**
         * @brief changedFontSize signal
         * @param Small, Medium, Large
         */
        Q_INVOKABLE void changeFontSize(FontSize fontSize);

    private:
        /**
         * @brief Set default light color
         */
        void setDefaultLightColors();

        /**
         * @brief Set default dark color
         */
        void setDefaultDarkColors();


    Q_SIGNALS:
        void colorsChanged();

        void nameChanged();

        void sizesChanged();

        void fontSizeChanged();

        void fontsChanged();

    private:

        // Set Default Theme to Light
        ThemeName themeName {ThemeName::Light};

        // Active colors
        Colors* colors_{};

        // Light color palette
        Colors* lightColors_{};

        // Dark color palette
        Colors* darkColors_{};

        // Theme name
        ThemeName name_{};

        // Font Sizes
        FontSize fontSize_ {FontSize::Medium};

        // Constants
        Sizes* sizes_{};

        // Fonts
        Fonts* fonts_{};
};

#endif // THEME_H
