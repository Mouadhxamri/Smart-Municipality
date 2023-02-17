
#include "lumiere.h"
#include "ui_lumiere.h"

lumiere::lumiere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lumiere)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}

lumiere::~lumiere()
{
    delete ui;
}

void lumiere::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
        ui->label_msg->setText("il y a un client"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher msg

    else if (data=="0")
       {
        ui->label_msg->setText("il n'y a pas de client");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher msg

    }

                                                                                                                                                                                                                                                           else    ui->label_msg->setText("il y a un client");   // si les données reçues de arduino via la liaison série sont égales à 0

//hgdsd
}
void lumiere::on_activer_bip_clicked()
{
    A.connect_arduino();
    A.write_to_arduino("2"); //envoyer 1 à arduino

}

void lumiere::on_des_bip_clicked()
{
   //s A.write_to_arduino("0"); //envoyer 0 à arduino

   // data=A.read_from_arduino();
    A.close_arduino();

}

void lumiere::on_pushButton_clicked()
{
    close();
    delete ui;

}
