#include "touchscreen_controller.hpp"

using namespace simulator::controllers;

TouchscreenController::TouchscreenController(QObject* parent)
    : QObject(parent)
{
}

TouchscreenController::~TouchscreenController()
{
}

void TouchscreenController::touch(bool isPressed, int x, int y)
{
    emit touched(isPressed, x, y);
}
