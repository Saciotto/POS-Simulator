#include "pos_controller.hpp"

#include <QDebug>

using namespace simulator::controllers;

PosController::PosController(QObject* parent)
    : QObject(parent)
{
}

PosController::~PosController()
{
}

void PosController::keyClicked(int keyCode)
{
    qDebug() << "Key pressed:" << keyCode;
}
