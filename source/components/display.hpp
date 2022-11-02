#ifndef POSDISPLAY_H
#define POSDISPLAY_H

#include <QImage>
#include <QMutex>
#include <QtQuick/QQuickPaintedItem>

namespace simulator {
namespace components {

class Display : public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)

public:
    explicit Display(QQuickItem* parent = nullptr);
    ~Display();

    const QImage& image();
    void setImage(const QImage& image);

signals:
    void imageChanged();

protected:
    void paint(QPainter* painter) override;

private:
    QImage mImage { nullptr };
};

} // namespace components
} // namespace simulator

#endif // POSDISPLAY_H
