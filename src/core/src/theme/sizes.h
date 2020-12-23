#ifndef SIZE_H
#define SIZE_H

#include <QObject>
#include <QString>


class Sizes : public QObject
{
        Q_OBJECT
        Q_PROPERTY(int textExtraLarge READ textExtraLarge WRITE seTextExtraLarge NOTIFY textExtraLargeChanged)
        Q_PROPERTY(int textLarge READ textLarge WRITE setTextLarge NOTIFY textLargeChanged)
        Q_PROPERTY(int textNormal READ textNormal WRITE setTextNormal NOTIFY textNormalChanged)
        Q_PROPERTY(int textSmall READ textSmall WRITE setTextSmall NOTIFY textSmallChanged)
        Q_PROPERTY(int textExtraSmall READ textExtraSmall WRITE setTextExtraSmall NOTIFY textExtraSmallChanged)

        Q_PROPERTY(int searchFieldHeight READ searchFieldHeight WRITE setSearchFieldHeight NOTIFY searchFieldHeightChanged)


    public:
        explicit Sizes(QObject *parent = nullptr);
        ~Sizes();

        void setFontScaleFactor(double factor);

        int textExtraLarge() const
        {
            return m_textExtraLarge;
        }

        int textLarge() const
        {
            return m_textLarge;
        }

        int textNormal() const
        {
            return m_textNormal;
        }

        int textSmall() const
        {
            return m_textSmall;
        }

        int textExtraSmall() const
        {
            return m_textExtraSmall;
        }

        int searchFieldHeight() const
        {
            return m_searchFieldHeight;
        }

    public Q_SLOTS:

        void seTextExtraLarge(int textExtraLarge)
        {
            if (m_textExtraLarge == textExtraLarge)
                return;

            m_textExtraLarge = textExtraLarge;
            emit textExtraLargeChanged(m_textExtraLarge);
        }

        void setTextLarge(int textLarge)
        {
            if (m_textLarge == textLarge)
                return;

            m_textLarge = textLarge;
            emit textLargeChanged(m_textLarge);
        }

        void setTextNormal(int textNormal)
        {
            if (m_textNormal == textNormal)
                return;

            m_textNormal = textNormal;
            emit textNormalChanged(m_textNormal);
        }

        void setTextSmall(int textSmall)
        {
            if (m_textSmall == textSmall)
                return;

            m_textSmall = textSmall;
            emit textSmallChanged(m_textSmall);
        }

        void setTextExtraSmall(int textExtraSmall)
        {
            if (m_textExtraSmall == textExtraSmall)
                return;

            m_textExtraSmall = textExtraSmall;
            emit textExtraSmallChanged(m_textExtraSmall);
        }

        void setSearchFieldHeight(int searchFieldHeight)
        {
            if (m_searchFieldHeight == searchFieldHeight)
                return;

            m_searchFieldHeight = searchFieldHeight;
            emit searchFieldHeightChanged(m_searchFieldHeight);
        }

    Q_SIGNALS:
        void textExtraLargeChanged(int textExtraLarge);

        void textLargeChanged(int textLarge);

        void textNormalChanged(int textNormal);

        void textSmallChanged(int textSmall);

        void textExtraSmallChanged(int textExtraSmall);

        void searchFieldHeightChanged(int searchFieldHeight);

    private:
        double fontScaleFactor = 1.0;
        int m_textExtraLarge = 16;
        int m_textLarge = 14;
        int m_textNormal = 12;
        int m_textSmall = 10;
        int m_textExtraSmall = 8;
        int m_searchFieldHeight;
};


#endif // SIZE_H
