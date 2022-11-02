#ifndef POS_CONTROLLER_HPP
#define POS_CONTROLLER_HPP

#include <QObject>

namespace simulator {
namespace controllers {

class KeypadController;
class DisplayController;

class PosController : public QObject {
    Q_OBJECT
    Q_PROPERTY(simulator::controllers::KeypadController* keypad READ keypadController CONSTANT)
    Q_PROPERTY(simulator::controllers::DisplayController* display READ displayController CONSTANT)

public:
    explicit PosController(QObject* parent = nullptr);

    ~PosController();

    KeypadController* keypadController();
    DisplayController* displayController();

private:
    KeypadController* mKeypadController;
    DisplayController* mDisplayController;
};

} // namespace controllers
} // namespace simulator

#endif // POS_CONTROLLER_HPP
