#ifndef MASTER_CONTROLLER_H
#define MASTER_CONTROLLER_H

#include <QObject>

#include "controllers/pos_controller.hpp"

namespace simulator {
namespace controllers {

class PosController;

class MasterController : public QObject {
    Q_OBJECT
    Q_PROPERTY(simulator::controllers::PosController* pos READ posController CONSTANT)

public:
    explicit MasterController(QObject* parent = nullptr);

    ~MasterController();

    PosController* posController();

private:
    PosController *mPosController;
};

} // namespace controllers
} // namespace simulator

#endif // MASTER_CONTROLLER_H
