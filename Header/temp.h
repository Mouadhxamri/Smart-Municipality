#ifndef TEMP_H
#define TEMP_H
#include "arduno_temp.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class temp; }
QT_END_NAMESPACE

class temp : public QMainWindow
{
    Q_OBJECT

public:
    temp(QWidget *parent = nullptr);
    ~temp();
    //void update_label();

private:
    Ui::temp *ui;
   arduno_temp a;
   QByteArray data;
private slots:
   void update_label();

   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
   void on_pushButton_3_clicked();
};
#endif // TEMP_H
