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
     * @param parent: constructs an object with parent object parent
     */
    TileShapeModel(QObject* parent = nullptr);

    /**
     * @brief D-tor
     */
    ~TileShapeModel();

    /**
     * @brief addTileShape: add new tile shape to model
     * @param tileShape: new tile shape data
     */
    void addTileShape(TileShape* tileShape);

    /**
     * @brief rowCount: get row count of current model.
     * @param parent:
     * @return value: model lenght
     */
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    /**
     * @brief data: get data acconrding to role and model imdex
     * @param index: data index
     * @param role: data role
     * @return get data as a Variant format for UI side
     */
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    /**
     * @brief roleNames: store and get all role names
     * @return get hash of role names
     */
    QHash<int, QByteArray> roleNames() const;

    /**
     * @brief getByIndex: get specified data from model by index
     * @param index: number of index(should be small than model length
     * @return
     */
    TileShape* getByIndex(const int index) const;

private:
signals:
    /**
     * @brief Signal: emit signal when data changed
     */
    void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

private:
    // List of all tile shape data
    QList<TileShape*> m_tileShapeList;
};

#endif // TILE_SHAPE_MODEL_H
