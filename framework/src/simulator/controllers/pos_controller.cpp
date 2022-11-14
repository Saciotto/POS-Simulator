#include "pos_controller.hpp"

#include <QThread>

using namespace simulator::controllers;

PosController::PosController(QObject* parent)
    : QObject(parent)
{
    mKeypadController = new KeypadController(this);
    mDisplayController = new DisplayController(this);
    mTouchscreenController = new TouchscreenController(this);
    mAppController = new ApplicationController();

    mAppThread = new QThread();
    mAppController->moveToThread(mAppThread);

    // Connect thread lifecycle to app controller
    connect(mAppThread, &QThread::started, mAppController, &ApplicationController::process);
    connect(mAppController, &ApplicationController::finished, mAppThread, &QThread::quit);
    connect(mAppController, &ApplicationController::finished, mAppController, &ApplicationController::deleteLater);
    connect(mAppThread, &QThread::finished, mAppThread, &QThread::deleteLater);

    // Connect display to app controller
    connect(mAppController, &ApplicationController::imageChanged, mDisplayController, &DisplayController::setImage);

    // Connect touchscreen to app controller
    connect(mTouchscreenController, &TouchscreenController::touched, mAppController, &ApplicationController::touch, Qt::DirectConnection);

    // Connect keypad to app controller
    connect(mKeypadController, &KeypadController::keyChanged, mAppController, &ApplicationController::keyEvent, Qt::DirectConnection);
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

ApplicationController* PosController::applicationController()
{
    return mAppController;
}

TouchscreenController* PosController::touchscreenController()
{
    return mTouchscreenController;
}

void PosController::startApplication()
{
    mAppThread->start();
}
