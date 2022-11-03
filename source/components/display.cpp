#include "display.hpp"

#include <QPainter>

using namespace simulator::components;

Display::Display(QQuickItem* parent)
    : QQuickPaintedItem(parent),
      mImage(320, 240, QImage::Format_ARGB32)
{
    mImage.fill(QColor("white").rgba());
}

Display::~Display()
{
}

const QImage& Display::image()
{
    return mImage;
}

void Display::setImage(const QImage& image)
{
    mImage = image;
    update();
}

void Display::paint(QPainter* painter)
{
    const QImage scaled = mImage.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QRect rect(scaled.rect());
    const QRect devRect(0, 0, painter->device()->width(), painter->device()->height());
    rect.moveCenter(devRect.center());
    painter->drawImage(rect.topLeft(), scaled);
}
