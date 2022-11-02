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

    int nextKey() noexcept;

public slots:
    void keyClicked(int keyCode);

private:
    std::list<int> mKeys {};
};

} // namespace controllers
} // namespace simulator

#endif // KEYPAD_CONTROLLER_HPP
