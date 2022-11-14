#ifndef POS_CONTROLLER_HPP
#define POS_CONTROLLER_HPP

#include <QObject>
#include <QThread>

#include "application_controller.hpp"
#include "display_controller.hpp"
#include "keypad_controller.hpp"
#include "touchscreen_controller.hpp"

namespace simulator {
namespace controllers {

class PosController : public QObject {
    Q_OBJECT
    Q_PROPERTY(simulator::controllers::KeypadController* keypad READ keypadController CONSTANT)
    Q_PROPERTY(simulator::controllers::DisplayController* display READ displayController CONSTANT)
    Q_PROPERTY(simulator::controllers::ApplicationController* app READ applicationController CONSTANT)
    Q_PROPERTY(simulator::controllers::TouchscreenController* touchscreen READ touchscreenController CONSTANT)

public:
    explicit PosController(QObject* parent = nullptr);

    ~PosController();

    KeypadController* keypadController();
    DisplayController* displayController();
    ApplicationController* applicationController();
    TouchscreenController* touchscreenController();

    void startApplication();

private:
    KeypadController* mKeypadController;
    DisplayController* mDisplayController;
    ApplicationController* mAppController;
    TouchscreenController* mTouchscreenController;

    QThread* mAppThread;
};

} // namespace controllers
} // namespace simulator

#endif // POS_CONTROLLER_HPP
