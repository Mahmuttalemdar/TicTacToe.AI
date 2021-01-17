#include "tile_shape.h"

TileShape::TileShape(const TileShape::TileShapeType& type, const QString& image, QObject* parent)
  : QObject(parent)
  , m_type(type)
  , m_image(image)
{}

TileShape::~TileShape() {}

TileShape::TileShapeType TileShape::type() const
{
    return m_type;
}

QString TileShape::image() const
{
    return m_image;
}

void TileShape::setImage(QString image)
{
    if (m_image == image)
        return;

    m_image = image;
    emit imageChanged(m_image);
}
