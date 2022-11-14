#ifndef APPLICATION_CONTROLLER_HPP
#define APPLICATION_CONTROLLER_HPP

#include <QImage>
#include <QObject>

namespace simulator {
namespace controllers {

class ApplicationController : public QObject {
    Q_OBJECT

public:
    explicit ApplicationController();

    ~ApplicationController();

    QImage displayImage() const;
    void setDisplayImage(const QImage& display);

    bool isTouchPressed() const;
    QPoint getTouchPosition() const;

    bool isKeyPressed() const;
    int getKey() const;

public slots:
    void process();
    void touch(bool isPressed, int x, int y);
    void keyEvent(bool isPressed, int keyCode);

signals:
    void imageChanged(const QImage& image);
    void finished();

private:
    QImage mDisplay;
    QPoint mLastTouchPositon;
    int mLastKey = 0;
    bool mIsTouchPressed = false;
    bool mIsKeyPressed = false;
};

} // namespace controllers
} // namespace simulator

#endif // APPLICATION_CONTROLLER_HPP
