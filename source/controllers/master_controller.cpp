#include "master_controller.hpp"

using namespace simulator::controllers;

MasterController::MasterController(QObject* parent)
    : QObject(parent)
{
    mPosController = new PosController(this);
}

MasterController::~MasterController()
{
}

PosController* MasterController::posController()
{
    return mPosController;
}
