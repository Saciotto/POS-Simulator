#ifndef TOUCHSCREEN_CONTROLLER_HPP
#define TOUCHSCREEN_CONTROLLER_HPP

#include <QObject>

namespace simulator {
namespace controllers {

class TouchscreenController : public QObject {
    Q_OBJECT

public:
    explicit TouchscreenController(QObject* parent = nullptr);

    ~TouchscreenController();

public slots:
    void touch(bool isPressed, int x, int y);

signals:
    void touched(bool isPressed, int x, int y);
};

} // namespace controllers
} // namespace simulator

#endif // TOUCHSCREEN_CONTROLLER_HPP
