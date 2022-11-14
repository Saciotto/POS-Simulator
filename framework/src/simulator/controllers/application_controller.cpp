#include "application_controller.hpp"

#include "api/binding.hpp"

using namespace simulator::controllers;
using namespace simulator::framework;

ApplicationController::ApplicationController()
    : QObject()
    , mDisplay(320, 240, QImage::Format_ARGB32)
{
    mDisplay.fill(QColor("white").rgba());
}

ApplicationController::~ApplicationController()
{
}

QImage ApplicationController::displayImage() const
{
    return mDisplay;
}

void ApplicationController::setDisplayImage(const QImage& display)
{
    mDisplay = display;
    emit imageChanged(mDisplay);
}

bool ApplicationController::isTouchPressed() const
{
    return mIsTouchPressed;
}

QPoint ApplicationController::getTouchPosition() const
{
    return mLastTouchPositon;
}

bool ApplicationController::isKeyPressed() const
{
    return mIsKeyPressed;
}

int ApplicationController::getKey() const
{
    return mLastKey;
}

void ApplicationController::process()
{
    runApplication(this);
    emit finished();
}

void ApplicationController::touch(bool isPressed, int x, int y)
{
    mIsTouchPressed = isPressed;
    mLastTouchPositon.setX(x);
    mLastTouchPositon.setY(y);
}

void ApplicationController::keyEvent(bool isPressed, int keyCode)
{
    mIsKeyPressed = isPressed;
    mLastKey = keyCode;
}
