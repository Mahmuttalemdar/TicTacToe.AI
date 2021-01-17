#ifndef TILE_SHAPE_H
#define TILE_SHAPE_H

#include <QObject>
#include <QString>

class TileShape : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString image READ image WRITE setImage NOTIFY imageChanged)

public:
    enum TileShapeType
    {
        None = 0,
        TileA,
        TileK,
        TileM,
        TileO,
        TileU,
        TileX,
    };
    Q_ENUM(TileShapeType)

    /**
     * @brief C-tor
     * @param parent; parent QObject based component
     */
    TileShape(const TileShapeType& type, const QString& image, QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~TileShape();

    TileShapeType type() const;

    QString image() const;

public slots:
    void setImage(QString image);

signals:
    void imageChanged(QString image);

private:
    TileShapeType m_type;
    QString m_image;
};

Q_DECLARE_METATYPE(TileShape*)
Q_DECLARE_METATYPE(const TileShape*)

#endif // TILE_SHAPE_H
