#ifndef DISPLAY_CONTROLLER_HPP
#define DISPLAY_CONTROLLER_HPP

#include <QObject>
#include <QImage>

namespace simulator {
namespace controllers {

class DisplayController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage image MEMBER mImage NOTIFY imageChanged)

public:
    explicit DisplayController(QObject *parent = nullptr);

    ~DisplayController();

    void setImage(const QImage& image);

signals:
    void imageChanged();

private:
    QImage mImage;
};

} // namespace controllers
} // namespace simulator

#endif // DISPLAY_CONTROLLER_HPP
