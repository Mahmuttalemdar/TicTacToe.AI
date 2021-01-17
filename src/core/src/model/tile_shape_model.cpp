#include "tile_shape_model.h"

TileShapeModel::TileShapeModel(QObject* parent)
  : QAbstractListModel(parent)
{}

TileShapeModel::~TileShapeModel() {}

void TileShapeModel::addTileShape(TileShape* tileShape)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_tileShapeList << tileShape;
    endInsertRows();
}

int TileShapeModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return m_tileShapeList.count();
}

QVariant TileShapeModel::data(const QModelIndex& index, int role) const
{
    if (index.row() < 0 || index.row() >= m_tileShapeList.count()) {
        return QVariant();
    }

    const TileShape& tileShape = *m_tileShapeList[index.row()];

    if (role == TypeRole) {
        return tileShape.type();
    } else if (role == ImageRole) {
        return tileShape.image();
    }

    return QVariant();
}

QHash<int, QByteArray> TileShapeModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "shapeType";
    roles[ImageRole] = "shapeImage";

    return roles;
}

TileShape* TileShapeModel::getByIndex(const int index) const
{
    if (m_tileShapeList.count() > index) {
        return m_tileShapeList.at(index);
    } else {
        return new TileShape(TileShape::TileShapeType::None, "");
    }
}
