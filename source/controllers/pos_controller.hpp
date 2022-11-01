#ifndef POS_CONTROLLER_H
#define POS_CONTROLLER_H

#include <QObject>

namespace simulator {
namespace controllers {

class PosController : public QObject {
    Q_OBJECT

public:
    explicit PosController(QObject* parent = nullptr);

    ~PosController();

public slots:
    void keyClicked(int keyCode);
};

} // namespace controllers
} // namespace simulator

#endif // SIMULATOR_CONTROLLER_H
