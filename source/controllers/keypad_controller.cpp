#include "keypad_controller.hpp"

using namespace simulator::controllers;

KeypadController::KeypadController(QObject* parent)
    : QObject(parent)
{
}

KeypadController::~KeypadController()
{
}

void KeypadController::keyClicked(int keyCode)
{
    mKeys.push_back(keyCode);
}

int KeypadController::nextKey() noexcept
{
    if (mKeys.size() == 0)
        return 0;
    int key = mKeys.front();
    mKeys.pop_front();
    return key;
}
