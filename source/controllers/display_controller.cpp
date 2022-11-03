#include "display_controller.hpp"
#include <QDebug>

using namespace simulator::controllers;
using namespace std::chrono;

DisplayController::DisplayController(QObject *parent)
    : QObject(parent),
      mImage(320, 240, QImage::Format_ARGB32)
{
    mImage.fill(QColor("white").rgba());
    startTimer(100ms);
}

DisplayController::~DisplayController()
{
}

void DisplayController::setImage(const QImage& image)
{
    mImage = image;
}

void DisplayController::setPixel(int x, int y, int r, int g, int b)
{
    const QColor qc(r, g, b);
    mImage.setPixelColor(x, y, qc);
}

void DisplayController::timerEvent(QTimerEvent *event)
{
    emit imageChanged();
}
