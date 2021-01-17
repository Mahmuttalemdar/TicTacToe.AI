#ifndef FONTS_H
#define FONTS_H

#include <QObject>
#include <QString>

class Fonts : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString roboto READ roboto NOTIFY robotoChanged)
    Q_PROPERTY(QString openSans READ openSans NOTIFY openSansChanged)

public:
    explicit Fonts(QObject* parent = nullptr);
    ~Fonts();

    QString roboto() const;

    QString openSans() const;

public Q_SLOTS:

Q_SIGNALS:

    void robotoChanged();

    void openSansChanged();

private:
    QString roboto_{};
    QString openSans_{};
};

#endif // FONTS_H
