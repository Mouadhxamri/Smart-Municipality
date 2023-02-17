#ifndef LUMIERE_H
#define LUMIERE_H
#include "arduino.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class lumiere;
}
QT_END_NAMESPACE
class lumiere : public QMainWindow
{
    Q_OBJECT

public:
    explicit lumiere(QWidget *parent = nullptr);
    ~lumiere();
private slots:
    void update_label();

    void on_activer_bip_clicked();

    void on_des_bip_clicked();

    void on_pushButton_clicked();

private:
    Ui::lumiere *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A;
};

#endif // LUMIERE_H




