#include "display_controller.hpp"

using namespace simulator::controllers;

DisplayController::DisplayController(QObject* parent)
    : QObject(parent)
    , mImage(320, 240, QImage::Format_ARGB32)
{
    mImage.fill(QColor("white").rgba());
}

DisplayController::~DisplayController()
{
}

void DisplayController::setImage(const QImage& image)
{
    mImage = image;
    emit imageChanged();
}
