#include "keypad_controller.hpp"

using namespace simulator::controllers;

KeypadController::KeypadController(QObject* parent)
    : QObject(parent)
{
}

KeypadController::~KeypadController()
{
}

void KeypadController::keyEvent(bool isPressed, int keyCode)
{
    emit keyChanged(isPressed, keyCode);
}
