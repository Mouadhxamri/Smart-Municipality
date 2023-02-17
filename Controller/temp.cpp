#include "temp.h"
#include "ui_temp.h"


temp::temp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::temp)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
    switch(ret)
    {
    case(0):qDebug()<<"arduino is available and connecyed to :"<<a.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is availble but not connected to :"<<a.getarduino_port_name();
        break;
     case(-1):qDebug()<<"arduino is not availble";
    }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


}
temp::~temp()
{
    delete ui;
}
void temp::update_label()
{
   data=a.read_from_arduino();
   if(data=="2")
   {
       ui->label_etat->setText("temperatur normal ");
   }
   else if(data=="1")
       ui->label_etat->setText("temperature elevee");
}
/*
void detectiongaz::update_label()
{
   data=a.read_from_arduino();
  //fonction mtaa int lel string
  QString n = QString::number(data);
       ui->label_etat->setText(n);

}
*/

void temp::on_pushButton_2_clicked()
{
    a.write_to_arduino("3");

}

void temp::on_pushButton_clicked()
{

}

void temp::on_pushButton_3_clicked()
{
    a.write_to_arduino("2");

}
