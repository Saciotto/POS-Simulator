#ifndef KEYPAD_CONTROLLER_HPP
#define KEYPAD_CONTROLLER_HPP

#include <QObject>
#include <list>

namespace simulator {
namespace controllers {

class KeypadController : public QObject {
    Q_OBJECT

public:
    explicit KeypadController(QObject* parent = nullptr);

    ~KeypadController();

public slots:
    void keyEvent(bool isPressed, int keyCode);

signals:
    void keyChanged(bool isPressed, int keyCode);

};

} // namespace controllers
} // namespace simulator

#endif // KEYPAD_CONTROLLER_HPP
