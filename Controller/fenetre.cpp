#include "fenetre.h"
#include "ui_fenetre.h"
#include <citoyent.h>
#include <commerciale.h>
#include "ui_mainwindow.h"
#include "QPushButton"
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>

#include <QSystemTrayIcon>

#include "notification.h"
#include <QIntValidator>
#include <QValidator>

fenetre::fenetre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fenetre)
{
    ui->setupUi(this);
    ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
    ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
    
    ui->cx_idf->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_ref_2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_1->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_telph->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_codepostale->setValidator(new QIntValidator(0,9999,this));
    QRegExp rx("(|\"|/|\\.,|[A-Z,a-z]){30}");
        ui->lineEdit_nom->setValidator(new QRegExpValidator(rx, this));
       // QRegExp rx10("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");


            QRegularExpression rx11("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                                  QRegularExpression::CaseInsensitiveOption);
            ui->lineEdit_mail->setValidator(new QRegularExpressionValidator(rx11, this));

          //  ui->lineEdit_mail->setValidator(new QRegExpValidator(rx10, this));
        QRegExp rx1("(|\"|/|\\.,|[A-Z,a-z]){30}");
            ui->lineEdit_prenom->setValidator(new QRegExpValidator(rx1, this));
            QRegExp rx2("(|\"|/|\\.,|[A-Z,a-z]){30}");
                ui->lineEdit_profession->setValidator(new QRegExpValidator(rx2, this));
                QRegExp rx3("(|\"|/|\\.,|[A-Z,a-z]){30}");
                    ui->lineEdit_ville->setValidator(new QRegExpValidator(rx3, this));
                    QRegExp rx4("(|\"|/|\\.,|[A-Z,a-z]){30}");
                        ui->lineEdit_lieu->setValidator(new QRegExpValidator(rx4, this));
                        QRegExp rx5("(|\"|/|\\.,|[A-Z,a-z]){30}");
                            ui->lineEdit_3->setValidator(new QRegExpValidator(rx5, this));
                            QRegExp rx6("(|\"|/|\\.,|[A-Z,a-z]){30}");
                                ui->lineEdit_4->setValidator(new QRegExpValidator(rx6, this));
     ui->lineEdit_ref_2->setValidator(new QIntValidator(0,99999999,this));
     ui->lineEdit_nb_4->setValidator(new QIntValidator(0,99999999,this));
     ui->lineEdit_nb_7->setValidator(new QIntValidator(0,9999,this));
     QRegExp rx7("(|\"|/|\\.,|[A-Z,a-z]){30}");
         ui->lineEdit_nomP_2->setValidator(new QRegExpValidator(rx7, this));
         QRegExp rx8("(|\"|/|\\.,|[A-Z,a-z]){30}");
             ui->lineEdit_nb_2->setValidator(new QRegExpValidator(rx8, this));
             QRegExp rx9("(|\"|/|\\.,|[A-Z,a-z]){30}");
                 ui->lineEdit_nb_3->setValidator(new QRegExpValidator(rx9, this));
                 QRegExp rx0("(|\"|/|\\.,|[A-Z,a-z]){30}");
                     ui->lineEdit_nb_5->setValidator(new QRegExpValidator(rx0, this));

                     mysystem = new QSystemTrayIcon(this);
                     mysystem ->setIcon(QIcon(":/myappico.png"));
                     mysystem ->setVisible(true);


}

fenetre::~fenetre()
{
    delete ui;
}

void fenetre::on_pushButton_11_clicked()//commerciale
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

    ui->stackedWidget->setCurrentIndex(4);

}


/*void fenetre::on_pushButton_11_clicked() //commerciale
{

}
*/

void fenetre::on_pushButton_12_clicked() //client
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

     ui->stackedWidget->setCurrentIndex(1);
}

void fenetre::on_pushButton_4_clicked() //ajout client
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

ui->stackedWidget->setCurrentIndex(2);
}

void fenetre::on_pushButton_3_clicked() //afficher client
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

    ui->stackedWidget->setCurrentIndex(3);
}


void fenetre::on_pushButton_5_clicked() //back_client
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    ui->stackedWidget->setCurrentIndex(0);
}


void fenetre::on_pushButton_2_clicked() //back ajout client
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    ui->stackedWidget->setCurrentIndex(1);
}

void fenetre::on_pushButton_21_clicked()//back affiche client
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

    ui->stackedWidget->setCurrentIndex(1);
}


void fenetre::on_pushButton_33_clicked()//back  commerc
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    ui->stackedWidget->setCurrentIndex(0);
}

void fenetre::on_pushButton_clicked() //bouton ajouter citoyent
{player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

    int cin=ui->cx_idf->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString lieu=ui->lineEdit_lieu->text();
    int num_tlph=ui->lineEdit_telph->text().toInt();
    QString email=ui->lineEdit_mail->text();
    QString ville=ui->lineEdit_ville->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString profession=ui->lineEdit_profession->text();
    int code_postale=ui->lineEdit_codepostale->text().toInt();
    QString date = ui->dateEdit->date().toString();
    QString statut=" ";
    if (ui->femme->isChecked())
    {
        statut="femme";
        statut=ui->femme->text();
    }
    else
    {
        statut="homme";
        statut=ui->homme->text();
    }
    int age=ui->age->text().toInt();

    citoyent c(cin,age,num_tlph,code_postale,nom,prenom,date,lieu,statut,email,profession,ville,adresse);
    bool test=c.ajouter_citoyent();
    if (test)
    {
        ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout avec succée"), QMessageBox::Ok);
        ui->lineEdit_nom->clear();
        ui->cx_idf->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_lieu->clear();
        ui->lineEdit_telph->clear();
        ui->lineEdit_mail->clear();
        ui->lineEdit_ville->clear();
        ui->lineEdit_adresse->clear();
        ui->lineEdit_profession->clear();
        ui->lineEdit_codepostale->clear();
        ui->dateEdit->clear();


       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }


}

void fenetre::on_pushButton_40_clicked() // bouton supprimer citoyent
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

    int id=ui->lineEdit_ref_2->text().toUInt();
    citoyent c;
    bool test=c.supprimer_citoyent(id);
    if(test)
    {
        ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
        QMessageBox::information(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression avec succée"), QMessageBox::Ok);
        ui->lineEdit_ref_2->clear();
        ui->lineEdit_nomP_2->clear();
        ui->lineEdit_nb_2->clear();
        ui->lineEdit_nb_3->clear();
        ui->lineEdit_nb_4->clear();
        ui->lineEdit_mail->clear();
        ui->lineEdit_ville->clear();
        ui->lineEdit_nb_6->clear();
        ui->lineEdit_nb_5->clear();
        ui->lineEdit_nb_7->clear();
        ui->dateEdit->clear();
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }


}

void fenetre::on_pushButton_43_clicked() //Ajouter licence commercaile
{
     notification n;

    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

    int cin=ui->lineEdit_1->text().toInt();
    int cnss=ui->lineEdit_2->text().toInt();
    QString fiscale=ui->lineEdit_3->text();
    QString secteur=ui->lineEdit_4->text();


    commerciale c(cin,cnss,fiscale,secteur);
    bool test=c.ajouter_commerciale();
    if (test)
    {
        n.setPopupText("Certificat de decès a été supprimé");
                    n.show();
                    mysystem->showMessage(tr("Notification"),tr("Il y a une suppression d'un Certificat de decès"));
        ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout avec succée"), QMessageBox::Ok);
        ui->lineEdit_1->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }

}


void fenetre::on_pushButton_42_clicked() //supprimer licence commerciale
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();

    int id=ui->lineEdit_1->text().toUInt();
    bool test=tempcommerciale.supprimer_commerciale(id);
    if(test)
    {
        ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
        QMessageBox::information(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression avec succée"), QMessageBox::Ok);
        ui->lineEdit_1->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
        QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }
}

void fenetre::on_pushButton_44_clicked() //modifier licence commerciale
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    int id = ui->lineEdit_1->text().toInt();
    int cnss = ui->lineEdit_2->text().toInt();
     QString fiscale= ui->lineEdit_3->text();
     QString secteur= ui->lineEdit_4->text();


      commerciale a(id,cnss,fiscale,secteur);
      bool test=a.modifier_commerciale(id);
      if(test)
    {

          ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Modification avec succees.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void fenetre::on_pushButton_chercherP_2_clicked() //modifier citoyent
{

    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    int cin=ui->lineEdit_ref_2->text().toInt();
    QString nom=ui->lineEdit_nomP_2->text();
    QString prenom=ui->lineEdit_nb_2->text();
    QString lieu=ui->lineEdit_nb_3->text();
    int num_tlph=ui->lineEdit_nb_4->text().toInt();
    QString email=ui->lineEdit_mail->text();
    QString ville=ui->lineEdit_ville->text();
    QString adresse=ui->lineEdit_nb_6->text();
    QString profession=ui->lineEdit_nb_5->text();
    int code_postale=ui->lineEdit_nb_7->text().toInt();
    QString date = ui->dateEdit->date().toString();
    QString statut=" ";
    if (ui->femme->isChecked())
    {
        statut="femme";
        statut=ui->femme->text();
    }
    else
    {
        statut="homme";
        statut=ui->homme->text();
    }
    int age=ui->age->text().toInt();

      citoyent a(cin,age,num_tlph,code_postale,nom,prenom,date,lieu,statut,email,profession,ville,adresse);
      bool test=a.modifier_citoyent(cin);
      if(test)
    {

         ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Modification avec succees.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->lineEdit_ref_2->clear();
    ui->lineEdit_nomP_2->clear();
    ui->lineEdit_nb_2->clear();
    ui->lineEdit_nb_3->clear();
    ui->lineEdit_nb_4->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_ville->clear();
    ui->lineEdit_nb_6->clear();
    ui->lineEdit_nb_5->clear();
    ui->lineEdit_nb_7->clear();
    ui->dateEdit->clear();

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void fenetre::on_pushButton_35_clicked() //  imprimer commerciale
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    QString strStream;
              QTextStream out(&strStream);

              const int rowCount = ui->afficher_commerciale_1->model()->rowCount();
              const int columnCount = ui->afficher_commerciale_1->model()->columnCount();
              QString TT = QDate::currentDate().toString("yyyy/MM/dd");
              out <<"<html>\n"
                    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                  << "<title>ERP - COMmANDE LIST<title>\n "
                  << "</head>\n"
                  "<body bgcolor=#ffffff link=#5000A0>\n"
                  "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ****** "+TT+"</strong></h1>"
                  "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                    "</br> </br>";
              // headers
              out << "<thead><tr bgcolor=#d6e5ff>";
              for (int column = 0; column < columnCount; column++)
                  if (!ui->afficher_commerciale_1->isColumnHidden(column))
                      out << QString("<th>%1</th>").arg(ui->afficher_commerciale_1->model()->headerData(column, Qt::Horizontal).toString());
              out << "</tr></thead>\n";

              // data table
              for (int row = 0; row < rowCount; row++) {
                  out << "<tr>";
                  for (int column = 0; column < columnCount; column++) {
                      if (!ui->afficher_commerciale_1->isColumnHidden(column)) {
                          QString data =ui->afficher_commerciale_1->model()->data(ui->afficher_commerciale_1->model()->index(row, column)).toString().simplified();
                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                      }
                  }
                  out << "</tr>\n";
              }
              out <<  "</table>\n"
                  "</body>\n"
                  "</html>\n";

              QTextDocument *document = new QTextDocument();
              document->setHtml(strStream);

              QPrinter printer;

              QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
              if (dialog->exec() == QDialog::Accepted) {
                  document->print(&printer);
              }

              delete document;
}

void fenetre::on_pushButton_23_clicked() //imprimer citoyens
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    /*QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ; */

    QString strStream;
              QTextStream out(&strStream);

              const int rowCount = ui->tab_citoyent->model()->rowCount();
              const int columnCount = ui->tab_citoyent->model()->columnCount();
              QString TT = QDate::currentDate().toString("yyyy/MM/dd");
              out <<"<html>\n"
                    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                  << "<title>ERP - COMmANDE LIST<title>\n "
                  << "</head>\n"
                  "<body bgcolor=#ffffff link=#5000A0>\n"
                  "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  CITOYENS ****** "+TT+"</strong></h1>"
                  "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                    "</br> </br>";
              // headers
              out << "<thead><tr bgcolor=#d6e5ff>";
              for (int column = 0; column < columnCount; column++)
                  if (!ui->tab_citoyent->isColumnHidden(column))
                      out << QString("<th>%1</th>").arg(ui->tab_citoyent->model()->headerData(column, Qt::Horizontal).toString());
              out << "</tr></thead>\n";

              // data table
              for (int row = 0; row < rowCount; row++) {
                  out << "<tr>";
                  for (int column = 0; column < columnCount; column++) {
                      if (!ui->tab_citoyent->isColumnHidden(column)) {
                          QString data =ui->tab_citoyent->model()->data(ui->tab_citoyent->model()->index(row, column)).toString().simplified();
                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                      }
                  }
                  out << "</tr>\n";
              }
              out <<  "</table>\n"
                  "</body>\n"
                  "</html>\n";

              QTextDocument *document = new QTextDocument();
              document->setHtml(strStream);

              QPrinter printer;

              QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
              if (dialog->exec() == QDialog::Accepted) {
                  document->print(&printer);
              }

              delete document;
}

void fenetre::on_pushButton_24_clicked() //pdf CLIENT
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    QString strStream;
    strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(strStream).suffix().isEmpty()) { strStream.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(strStream);
     //   printer.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/logo.png"));


              QTextStream out(&strStream);

              const int rowCount = ui->tab_citoyent->model()->rowCount();
              const int columnCount = ui->tab_citoyent->model()->columnCount();
              QString TT = QDate::currentDate().toString("yyyy/MM/dd");
              out <<"<html>\n"
                    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                  << "<title>ERP - COMmANDE LIST<title>\n "
                  << "</head>\n"
                  "<body bgcolor=#ffffff link=#5000A0>\n"
                  "<h1 style=\"text-align: center;\"><strong> ******LISTE DES CITOYENS ****** "+TT+"</strong></h1>"
                 //   " <img src="logo.png" alt="Trulli" width="500" height="333">"
                  "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                    "</br> </br>";
              // headers
              out << "<thead><tr bgcolor=#d6e5ff>";
              for (int column = 0; column < columnCount; column++)
                  if (!ui->tab_citoyent->isColumnHidden(column))
                      out << QString("<th>%1</th>").arg(ui->tab_citoyent->model()->headerData(column, Qt::Horizontal).toString());
              out << "</tr></thead>\n";

              // data table
              for (int row = 0; row < rowCount; row++) {
                  out << "<tr>";
                  for (int column = 0; column < columnCount; column++) {
                      if (!ui->tab_citoyent->isColumnHidden(column)) {
                          QString data =ui->tab_citoyent->model()->data(ui->tab_citoyent->model()->index(row, column)).toString().simplified();
                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                      }
                  }
                  out << "</tr>\n";
              }
              out <<  "</table>\n"
                  "</body>\n"
                  "</html>\n";

              QTextDocument document;
              document.setHtml(strStream);
              document.print(&printer);
}

void fenetre::on_pushButton_36_clicked() // PDF COMMERCIALE
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    QString strStream;
    strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(strStream).suffix().isEmpty()) { strStream.append(".pdf"); }

        QPainter painter;
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(strStream);

              QTextStream out(&strStream);

              const int rowCount = ui->afficher_commerciale_1->model()->rowCount();
              const int columnCount = ui->afficher_commerciale_1->model()->columnCount();
              QString TT = QDate::currentDate().toString("yyyy/MM/dd");
              painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/logo.png"));

              out <<"<html>\n"
                    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                  << "<title>ERP - COMmANDE LIST<title>\n "
                  << "</head>\n"
                  "<body bgcolor=#ffffff link=#5000A0>\n"
                  "<h1 style=\"text-align: center;\"><strong> ******LISTE DES LICENCES COMMERCIALES ****** "+TT+"</strong></h1>"
                  "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                    "</br> </br>";
              // headers
              out << "<thead><tr bgcolor=#d6e5ff>";
              for (int column = 0; column < columnCount; column++)
                  if (!ui->tab_citoyent->isColumnHidden(column))
                      out << QString("<th>%1</th>").arg(ui->afficher_commerciale_1->model()->headerData(column, Qt::Horizontal).toString());
              out << "</tr></thead>\n";

              // data table
              for (int row = 0; row < rowCount; row++) {
                  out << "<tr>";
                  for (int column = 0; column < columnCount; column++) {
                      if (!ui->afficher_commerciale_1->isColumnHidden(column)) {
                          QString data =ui->afficher_commerciale_1->model()->data(ui->afficher_commerciale_1->model()->index(row, column)).toString().simplified();
                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                      }
                  }
                  out << "</tr>\n";
              }
              out <<  "</table>\n"
                  "</body>\n"
                  "</html>\n";

              QTextDocument document;
              document.setHtml(strStream);
              document.print(&printer);
}


void fenetre::on_radioButton_11_clicked()//trie mil kbirr li s5irr commerciale
{
     ui->afficher_commerciale_1->setModel(tempcommerciale.trierA());
}

void fenetre::on_radioButton_13_clicked()
{

    ui->afficher_commerciale_1->setModel(tempcommerciale.trierB());// trie commerciale
}
/*void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    ui->label_13->setText(time_text);

} */

/*void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    ui->showTime->setText(time_text);

}*/

void fenetre::on_pushButton_22_clicked() //recherche citoyen
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    QString cin =ui->cx_nomf_6->text();
     ui->tab_citoyent->setModel(temcitoyent.Recherche(cin));
}

void fenetre::on_radioButton_6_clicked()
{

     ui->tab_citoyent->setModel(temcitoyent.trierA());//trie citoyens
}

void fenetre::on_radioButton_5_clicked()
{
     ui->tab_citoyent->setModel(temcitoyent.trierB());//trie citoyens
}

void fenetre::on_tab_citoyent_activated(const QModelIndex &index) //faza ki tinzel 3atableau (citoyens)
{
    QString cin=ui->tab_citoyent->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select * from CITOYENT where Cin LIKE '"+cin+"%' or nom LIKE '"+cin+"%' or prenom LIKE '"+cin+"%' "); //or dateNaissance LIKE '"+cin+"%'
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_ref_2->setText(query.value(0).toString());
            ui->lineEdit_nomP_2->setText(query.value(1).toString());
            ui->lineEdit_nb_2->setText(query.value(2).toString());
            ui->lineEdit_nb_3->setText(query.value(4).toString());
            ui->lineEdit_nb_4->setText(query.value(7).toString());
            ui->lineEdit_nb_5->setText(query.value(9).toString());
            ui->lineEdit_nb_6->setText(query.value(11).toString());
            ui->lineEdit_nb_7->setText(query.value(12).toString());

        }
      }
        else
        {

          QMessageBox::critical(nullptr, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void fenetre::on_afficher_commerciale_1_activated(const QModelIndex &index)
{
    QString cin=ui->afficher_commerciale_1->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select * from COMMERCIALE where Cin LIKE '"+cin+"%' or CNSS LIKE '"+cin+"%' or fiscale LIKE '"+cin+"%' or secteur_dactivite LIKE '"+cin+"%'");
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_1->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());

        }
      }
        else
        {

          QMessageBox::critical(nullptr, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }
}



void fenetre::on_radioButton_3_clicked()//trie citoyens
{
     ui->tab_citoyent->setModel(temcitoyent.trierA_Z());
}

void fenetre::on_radioButton_4_clicked() //trie citoyens
{
     ui->tab_citoyent->setModel(temcitoyent.trierZ_A());
}

void fenetre::on_pushButton_34_clicked() //recherche commerciale
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    QString cin =ui->cx_nomf_13->text();
     ui->afficher_commerciale_1->setModel(tempcommerciale.Recherche(cin));
}


void fenetre::on_pushButton_37_clicked() //pdf commerciale
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/son/button20.WAV"));
    player->play();
    qDebug()<<player->errorString();
    QPdfWriter pdf("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/pdfcommerciales.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::blue);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"Liste Des licences commerciales");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/logo.png"));
                          painter.drawRect(0,3000,5500,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(600,3300,"CIN");
                          painter.drawText(1600,3300,"CNSS");
                          painter.drawText(2400,3300,"FISCALE");
                          painter.drawText(3700,3300,"SECTEUR_DACTIVITE");
                          painter.drawRect(0,3000,5500,9000);
                        //  painter.drawText(5300,3300,"LIEU");
                          //painter.drawText(7400,3300,"ETAT_MATRIMATIONALE");


                          QSqlQuery query;
                          query.prepare("select * from commerciale");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(400,i,query.value(0).toString());
                              painter.drawText(1600,i,query.value(1).toString());
                              painter.drawText(2400,i,query.value(2).toString());
                              painter.drawText(4000,i,query.value(3).toString());



                             i = i + 500;
}
}
