#include "pos_controller.hpp"

#include "display_controller.hpp"
#include "keypad_controller.hpp"

using namespace simulator::controllers;

PosController::PosController(QObject* parent)
    : QObject(parent)
{
    mKeypadController = new KeypadController(this);
    mDisplayController = new DisplayController(this);
}

PosController::~PosController()
{
}

KeypadController* PosController::keypadController()
{
    return mKeypadController;
}

DisplayController* PosController::displayController()
{
    return mDisplayController;
}
