#ifndef TILE_SHAPE_MODEL_H
#define TILE_SHAPE_MODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "core/src/data/tile_shape.h"

class TileShapeModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum TileShapeRoles
    {
        TypeRole = Qt::UserRole + 1,
        ImageRole,
    };

    /**
     * @brief C-tor
     * @param parent; parent QObject based component
     */
    TileShapeModel(QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~TileShapeModel();

    void addTileShape(TileShape* tileShape);

    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    QHash<int, QByteArray> roleNames() const;

    TileShape* getByIndex(const int index) const;

private:
signals:
    void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

private:
    QList<TileShape*> m_tileShapeList;
};

#endif // TILE_SHAPE_MODEL_H
