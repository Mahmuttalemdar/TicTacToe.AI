#ifndef TILE_SHAPE_H
#define TILE_SHAPE_H

#include <QObject>
#include <QString>

/**
 * @brief The TileShape class which is define tile data for board architecture
 */
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
     * @param type: enum value of TileShapeType
     * @param image: path of tile image
     * @param parent: constructs an object with parent object parent
     */
    TileShape(const TileShapeType& type, const QString& image, QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~TileShape();

    /**
     * @brief Getter: get tile shape type
     * @return value: enum value of TileShapeType
     */
    TileShapeType type() const;

    /**
     * @brief Getter: get tile image
     * @return value: path of tile image
     */
    QString image() const;

public slots:
    /**
     * @brief Setter: set image path as string value
     * @param value: path of tile image
     */
    void setImage(QString image);

signals:
    /**
     * @brief Signal: emit signal when image changed
     * @param value: path of tile image
     */
    void imageChanged(QString image);

private:
    // enum value of TileShapeType
    TileShapeType m_type;

    // path of tile image
    QString m_image;
};

Q_DECLARE_METATYPE(TileShape*)
Q_DECLARE_METATYPE(const TileShape*)

#endif // TILE_SHAPE_H
