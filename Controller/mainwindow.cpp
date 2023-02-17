#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include "lumiere.h"
#include "ui_lumiere.h"

#include "certifdeces.h"
#include "permisconstr.h"
#include "commerciale.h"
#include "citoyent.h"
#include "contrat.h"
#include "fourriere.h"
#include"vehicule.h"
#include"amende.h"
#include"excel.h"

#include "server.h"
#include "client.h"

#include "arduno_temp.h"
#include "temp.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>

#include <QSystemTrayIcon>
#include "notification.h"

#include <QIntValidator>
#include <QValidator>

#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
     ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
     ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
     ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
     // ui->tableView->setModel(tempfourriere.afficherfourriere());
      ui->tabView_vehicule->setModel(tempfourriere.afficherfourriere());
      //  ui->tab_afficher->setModel(tempcontrat.afficherContrat());
      ui->afficher_client_3->setModel(tempVehicule.trierD());
      ui->tabView_amende->setModel(temAmende.afficher());
      ui->tableView_deces->setModel(tempcert.afficher_certif());
      ui->tableView_permis->setModel(temppermis.afficher_permis());
      ui->tableView_employes->setModel(z.afficher());
      ui->tableView_depart->setModel(d.afficher());

      mysystem = new QSystemTrayIcon(this);
      mysystem ->setIcon(QIcon(":/iconn.png"));
      mysystem ->setVisible(true);

      click = new QMediaPlayer();
      click->setMedia(QUrl::fromLocalFile("C:\\Users\\Ahmed.A.Hsouna\\Documents\\Smart_Municipality_2A2\\click.mp3"));

      son=new QSound("C:\\Users\\Ahmed.A.Hsouna\\Documents\\Smart_Municipality_2A2\\click.MP3");
      ui->lineEdit_cindeces->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_cincitoyencommerciale->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_cinm1->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_cinp1->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_cinpermis->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_14->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_8->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_cinsr->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_ref_2->setValidator(new QIntValidator(0,99999999,this));
      ui->cx_idf->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_postalepermis->setValidator(new QIntValidator(0,9999,this));
      ui->lineEdit_telph->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_codepostale->setValidator(new QIntValidator(0,9999,this));
      ui->lineEdit_nb_3->setValidator(new QIntValidator(0,99,this));
      ui->lineEdit_nb_4->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_nb_7->setValidator(new QIntValidator(0,9999,this));
      ui->lineEdit_numero->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_budget_2->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_nbrdesemployes_2->setValidator(new QIntValidator(0,9999,this));
      ui->lineEdit_12->setValidator(new QIntValidator(0,9999,this));
      ui->lineEdit_fiscale->setValidator(new QIntValidator(0,9999,this));
      ui->lineEdit_cnss->setValidator(new QIntValidator(0,9999,this));













}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_commerciale_clicked()
{
    click->play();
    //son->play();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_citoyen_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_certifdeces_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_permisconstr_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_lesamendes_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_lesvehicules_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_3_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_14_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_backdeces_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_backpermis_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_backcitoyen0_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_bkaf_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_bkaf2_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_34_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_36_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_37_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_33_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_ajouterciyoyenacceuil_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_affichercitoyenacceuil_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_backcitoyen1_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_backaffichagecitoyen_clicked()
{
    click->play();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_ajoutercitoyen_clicked() //ajout citoyent
{
    click->play();
    notification n;
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
        n.setPopupText("Citoyen a été Ajouté");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un Ajout d'un Citoyen"));
        ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
        QMessageBox::information(this, QObject::tr("Ajout"),
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
        n.setPopupText("il y'a un probleme");
       n.show();
        QMessageBox::critical(this, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }

}



void MainWindow::on_pushButton_supprimercitoyen_clicked()
{
    click->play();
    notification n;
    int id=ui->lineEdit_ref_2->text().toUInt();
    citoyent c;
    bool test=c.supprimer_citoyent(id);
    if (ui->lineEdit_ref_2->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Supprimer"),
                           QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

    }
   else if(test)
    {
        n.setPopupText("Citoyen a été supprimé");
                    n.show();
                    mysystem->showMessage(tr("Notification"),tr("Il y a une suppression d'un Citoyen"));
        ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
        QMessageBox::information(this, QObject::tr("Supprimer"),
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
        n.setPopupText("il y'a un probleme");
       n.show();
        QMessageBox::critical(this, QObject::tr("Supprimer"),
        QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }
}

void MainWindow::on_pushButton_chercherP_2_clicked()
{
    click->play();
    notification n;
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
          n.setPopupText("Citoyen a été modifié");
                      n.show();
                      mysystem->showMessage(tr("Notification"),tr("Il y a une modification d'un Citoyen"));

         ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());//refresh
    QMessageBox::information(this, QObject::tr("Modifier"),
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
      {
          n.setPopupText("il y'a un probleme");
         n.show();
          QMessageBox::critical(this, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_pushButton_ajoutercommerciale_clicked()
{
    click->play();
    notification n;
    int cin=ui->lineEdit_cincitoyencommerciale->text().toInt();
    int cnss=ui->lineEdit_cnss->text().toInt();
    QString fiscale=ui->lineEdit_fiscale->text();
    QString secteur=ui->lineEdit_secteuractivite->text();


    commerciale c(cin,cnss,fiscale,secteur);
    bool test=c.ajouter_commerciale();
    if (test)
    {
        n.setPopupText("Licence commerciale a été Ajouté");
        n.show();


        mysystem->showMessage(tr("Notification"),tr("Il y a un Ajout d'un licence commerciale"));
        ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());


        QMessageBox::information(this, QObject::tr("Ajout"),
        QObject::tr("Ajout avec succée"), QMessageBox::Ok);
        ui->lineEdit_cincitoyencommerciale->clear();
        ui->lineEdit_cnss->clear();
        ui->lineEdit_fiscale->clear();
        ui->lineEdit_secteuractivite->clear();
       // hide();
    }
    else
    {
        n.setPopupText("il y'a un probleme");
       n.show();
        QMessageBox::critical(this, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }
}

void MainWindow::on_pushButton_supprimercommerciale_clicked()
{
    click->play();
    notification n;
    int id=ui->lineEdit_cincitoyencommerciale->text().toUInt();
    QString res=QString::number(id);
    bool test=tempcommerciale.supprimer_commerciale(id);
    if (ui->lineEdit_cincitoyencommerciale->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Supprimer"),
                           QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

    }
   else if(test)
    {
        n.setPopupText("Licence commerciale a été supprimé");
                    n.show();
                    mysystem->showMessage(tr("Notification"),tr("Il y a une suppression d'un Licence commerciale"));
        ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
        QMessageBox::information(this, QObject::tr("Supprimer"),
        QObject::tr("Suppression avec succée"), QMessageBox::Ok);

        ui->lineEdit_cincitoyencommerciale->clear();
        ui->lineEdit_cnss->clear();
        ui->lineEdit_fiscale->clear();
        ui->lineEdit_secteuractivite->clear();
    }
       // hide();

    else
    {
        n.setPopupText("il y'a un probleme");
        n.show();
        QMessageBox::critical(this, QObject::tr("Supprimer"),
        QObject::tr("Suppression echoués"), QMessageBox::Ok);
    }
}

void MainWindow::on_pushButton_modifiercommerciale_clicked()
{
    click->play();
    notification n;
    int id = ui->lineEdit_cincitoyencommerciale->text().toInt();
    int cnss = ui->lineEdit_cnss->text().toInt();
     QString fiscale= ui->lineEdit_fiscale->text();
     QString secteur= ui->lineEdit_secteuractivite->text();


      commerciale a(id,cnss,fiscale,secteur);
      bool test=a.modifier_commerciale(id);
      if(test)
    {
          n.setPopupText("Licence commerciale a été modifié");
                      n.show();
                      mysystem->showMessage(tr("Notification"),tr("Il y a une modification d'un Licence commerciale"));

          ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());//refresh
    QMessageBox::information(this, QObject::tr("Modifier"),
                      QObject::tr("Modification avec succees.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEdit_cincitoyencommerciale->clear();
    ui->lineEdit_cnss->clear();
    ui->lineEdit_fiscale->clear();
    ui->lineEdit_secteuractivite->clear();

    }
      else
      {
          n.setPopupText("il y'a un probleme");
          n.show();
          QMessageBox::critical(this, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_imprimercommerciale_clicked() //imprime( commerciale
{
    /*click->play();
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("PRINT LICENSES COMMERCIALES");
    d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (d.exec() != QDialog::Accepted)
        return ; */
   click->play();
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




void MainWindow::on_pushButton_imprimercitoyen_clicked() //imprimer citoyens
{
    click->play();
  /* click->play();
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("PRINT CITOYENS");
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

void MainWindow::on_pushButton_pdfcitoyen_clicked()
{
    click->play();
    QString strStream;
    strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(strStream).suffix().isEmpty()) { strStream.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(strStream);
     //   printer.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:\\Users\\Ahmed.A.Hsouna\\Documents\\Smart_Municipality_2A2\\logo.png"));


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

void MainWindow::on_pdfcommerciale_clicked()
{
    click->play();
    QPdfWriter pdf("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\pdfcommerciales.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::blue);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"Liste Des licences commerciales");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png"));
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
                          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                      QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_radioButton_11_clicked()
{
    click->play();
    ui->afficher_commerciale_1->setModel(tempcommerciale.trierA());
}

void MainWindow::on_radioButton_13_clicked()
{
    click->play();
    ui->afficher_commerciale_1->setModel(tempcommerciale.trierB());
}

void MainWindow::on_pushButton_recherchecitoyen_clicked()
{
    click->play();
    QString cin =ui->cx_nomf_6->text();
     ui->tab_citoyent->setModel(temcitoyent.Recherche(cin));
}

void MainWindow::on_radioButton_6_clicked()
{
    click->play();
    ui->tab_citoyent->setModel(temcitoyent.trierA());//trie citoyens
}

void MainWindow::on_radioButton_5_clicked()
{
    click->play();
     ui->tab_citoyent->setModel(temcitoyent.trierB());//trie citoyens
}

void MainWindow::on_radioButton_3_clicked()
{
    click->play();
    ui->tab_citoyent->setModel(temcitoyent.trierA_Z());

}

void MainWindow::on_radioButton_4_clicked()
{
    click->play();
     ui->tab_citoyent->setModel(temcitoyent.trierZ_A());
}

void MainWindow::on_tab_citoyent_activated(const QModelIndex &index)
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

          QMessageBox::critical(this, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_afficher_commerciale_1_activated(const QModelIndex &index)
{
    QString cin=ui->afficher_commerciale_1->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select * from COMMERCIALE where CIN_CO LIKE '"+cin+"%' or CNSS LIKE '"+cin+"%' or fiscale LIKE '"+cin+"%' or secteur_dactivite LIKE '"+cin+"%'");
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_cincitoyencommerciale->setText(query.value(0).toString());
            ui->lineEdit_cnss->setText(query.value(1).toString());
            ui->lineEdit_fiscale->setText(query.value(2).toString());
            ui->lineEdit_secteuractivite->setText(query.value(3).toString());

        }
      }
        else
        {

          QMessageBox::critical(this, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_pushButton_recherchecomm_clicked()
{
    click->play();
    QString cin =ui->cx_nomf_13->text();
     ui->afficher_commerciale_1->setModel(tempcommerciale.Recherche(cin));
}

void MainWindow::on_pushButton_chercherP_6_clicked() //ajouter une contrat
{
    notification n;
    click->play();
    QString metierm=ui->lineEdit_metierm1->text();
        QString metierp=ui->lineEdit_metierp_1->text();
        QString nomm=ui->lineEdit_nomm1->text();
        QString nomp=ui->lineEdit_13->text();
        QString date=ui->lineEdit_date1->text();
        int cinp=ui->lineEdit_cinp1->text().toInt();
        int cinm=ui->lineEdit_cinm1->text().toInt();
        contrat c(nomp,nomm,metierp,metierm,date,cinm,cinp);
        bool test ;
        test=c.ajouterContrat();

        if(test)
     {
            n.setPopupText("Contrat a été ajouté");
            n.show();
            mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un contrat"));
           // ui->tab_afficher->setModel(tempcontrat.afficherContrat());
             ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
            QMessageBox::information(this, QObject::tr("Ajout contrat"),
                        QObject::tr("Ajout avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
        { n.setPopupText("il y'a un probleme");
            n.show();
            QMessageBox::critical(this, QObject::tr("Ajout contrat"),
                        QObject::tr("Ajout impossible.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_43_clicked() //supprimer contrat
{
    click->play();
    notification n;
    int cinm=ui->lineEdit_14->text().toInt();
   bool test;
   test=tempcontrat.supprimerContrat(cinm);
   if (ui->lineEdit_14->text()=="")
   {
       QMessageBox::critical(this, QObject::tr("Supprimer"),
                          QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

   }
  else if(test)
   {
       n.setPopupText("Contrat a été supprimé");
       n.show();
       mysystem->showMessage(tr("Notification"),tr("Il y a un supprission d'un contrat"));
   // ui->tab_afficher->setModel(tempcontrat.afficherContrat());
     ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
       QMessageBox::information(this, QObject::tr("supprimer contrat"),
                   QObject::tr("supprission avec succés.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else{
       n.setPopupText("il y'a un probleme");
                   n.show();
       QMessageBox::critical(this, QObject::tr("supprimer contrat"),
                   QObject::tr("supprision échoué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_chercherP_5_clicked() //modifier contrat
{
    click->play();
    notification n;
    QString nomp=ui->lineEdit_1->text();
    QString date=ui->lineEdit_date1->text();
    QString metierp=ui->lineEdit_metierp_1->text();
    QString metierm=ui->lineEdit_metierm1->text();
    QString nomm=ui->lineEdit_nomm1->text();
int cinp=ui->lineEdit_cinp1->text().toInt();
    int cinm=ui->lineEdit_cinm1->text().toInt();
    contrat c(nomp,nomm,metierp,metierm,date,cinp,cinm);
    bool test ;
    test=c.modifierContrat(cinm);


    if(test)
 {
        n.setPopupText("Contrat a été modifié");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un modification d'un contrat"));
        //ui->tab_afficher->setModel(tempcontrat.afficherContrat());
         ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
        QMessageBox::information(this, QObject::tr("modifier contrat"),
                    QObject::tr("modifier avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }

 else{ n.setPopupText("il y'a un probleme");
        n.show();
        QMessageBox::critical(this, QObject::tr("modifier contrat"),
                    QObject::tr("modifier impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_4_clicked() //ajout fourriere
{
    click->play();
     notification n;
    QString matricule=ui->lineEdit_1->text();
    QString type=ui->lineEdit_2->text();
    QString couleur=ui->lineEdit_3->text();

        fourriere f (matricule,type,couleur);
        bool test ;
        test=f.ajouterfourriere();

        if(test)
     {
            n.setPopupText("un Fourriere a été ajouté");
            n.show();
            mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un fourriere"));
           // ui->tableView->setModel(tempfourriere.afficherfourriere());
             ui->tabView_vehicule->setModel(tempfourriere.afficherfourriere());
            QMessageBox::information(this, QObject::tr("Ajout fourriere"),
                        QObject::tr("Ajout avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else{ n.setPopupText("il y'a un probleme");
            n.show();
            QMessageBox::critical(this, QObject::tr("Ajout fourriere"),
                        QObject::tr("Ajout impossible.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_supp_clicked() //supprimer fourriere
{
    click->play();
    notification n;
    QString matricule=ui->lineEdit_surema->text();
    bool test;
    test=tempfourriere.supprimerfourriere(matricule);
    if (ui->lineEdit_surema->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Supprimer"),
                           QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

    }
  else  if(test)
    {
        n.setPopupText("Fourriere a été supprimé");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un supprission d'un fourriere"));
        //ui->tableView->setModel(tempfourriere.afficherfourriere());
         ui->tabView_vehicule->setModel(tempfourriere.afficherfourriere());
        QMessageBox::information(this, QObject::tr("supprimer fourriere"),
                    QObject::tr("supprission avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{ n.setPopupText("il y'a un probleme");
        n.show();
        QMessageBox::critical(this, QObject::tr("supprimer fourriere"),
                    QObject::tr("supprision échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_modi_clicked() //modifier fourriere
{
    click->play();
    notification n;
    QString matricule=ui->lineEdit_1->text();
    QString type=ui->lineEdit_2->text();
    QString couleur=ui->lineEdit_3->text();

       fourriere f(matricule,type,couleur);
    bool test ;
    test=f.modifierfourriere();

    if(test)
 {
        n.setPopupText("fourriere a été modifié");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un modification d'un fourriere"));
       // ui->tableView->setModel(tempfourriere.afficherfourriere());
         ui->tabView_vehicule->setModel(tempfourriere.afficherfourriere());
        QMessageBox::information(this, QObject::tr("modifier fourrier"),
                    QObject::tr("modifier avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else{ n.setPopupText("il y'a un probleme");
        n.show();
           QMessageBox::critical(this, QObject::tr("modifier fourriere"),
                       QObject::tr("modifier impossible.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_6_clicked()
{
    click->play();
    QSqlDatabase db;
                    QTableView table_commande;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM TABLE1 ");
                     qry.exec();
                     Modal->setQuery(qry);
                     table_commande.setModel(Modal);



                     db.close();


                     QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = table_commande.model()->rowCount();
                     const int columnCount =  table_commande.model()->columnCount();


                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des commandes")
                        <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!table_commande.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(table_commande.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!table_commande.isColumnHidden(column)) {
                                 QString data = table_commande.model()->data(table_commande.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                           //  "<< QString("<p><img src="C:\\Users\\Ahmed.A.Hsouna\\Documents\\Smart_Municipality_2A2\\logo.png"; width="200"; height="200";\">%1</p>\n")"
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted) {

                         QLabel lab;
                          QPixmap pixmap("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         //QPrinter printer(QPrinter::PrinterResolution);

                         //pixmap.load("aze.png");
                         //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                         //painter.drawPixmap(10,10,50,50, pixmap);

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\rendezvous.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}


void MainWindow::on_pushButton_39_clicked() //recherche contrat
{
    click->play();
    int cinm=ui->lineEdit->text().toInt();
            ui->afficher_client_4->setModel(tempcontrat.chercherContrat(cinm));

            QMessageBox::information(this, QObject::tr("chercher"),
                        QObject::tr("ok"), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_impr_clicked()
{
  /*  click->play();
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("PRINT CERTIFICAT DE DECES");
    d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (d.exec() != QDialog::Accepted)
        return ; */
    click->play();
    QSqlDatabase db;
                            QTableView TableView_Commande;
                            QSqlQueryModel * Modal=new  QSqlQueryModel();

                            QSqlQuery qry;
                             qry.prepare("SELECT * FROM table2 ");
                             qry.exec();
                             Modal->setQuery(qry);
                             TableView_Commande.setModel(Modal);



                             db.close();


                             QString strStream;
                             QTextStream out(&strStream);

                             const int rowCount = TableView_Commande.model()->rowCount();
                             const int columnCount =  TableView_Commande.model()->columnCount();


                             const QString strTitle ="Document";


                             out <<  "<html>\n"
                                 "<head>\n"
                                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 <<  QString("<title>%1</title>\n").arg(strTitle)
                                 <<  "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"
                                << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("gestion  fourriere")
                                <<"<br>"
                                 <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                             out << "<thead><tr bgcolor=#f0f0f0>";
                             for (int column = 0; column < columnCount; column++)
                                 if (!TableView_Commande.isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(TableView_Commande.model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!TableView_Commande.isColumnHidden(column)) {
                                         QString data = TableView_Commande.model()->data(TableView_Commande.model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";
                             }
                             out <<  "</table>\n"
                                     "<br><br>"

                                     "<p align='center'> <img src='C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png' alt='logologo'></p>"

                                  <<"<br>"
                                     <<"<table border=1 cellspacing=0 cellpadding=2 >\n";


                                 out << "<thead><tr bgcolor=#f0f0f0>";

                                     out <<  "</table >\n"

                                 "</body>\n"

                                 "</html>\n";

                             QTextDocument *document = new QTextDocument();
                             document->setHtml(strStream);

                             QPrinter printer;
                             QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                             if (dialog->exec() == QDialog::Accepted) {

                                QLabel lab;
                                  QPixmap pixmap("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png");
                                 lab.setPixmap(pixmap);
                                 QPainter painter(&lab);
                                 QPrinter printer(QPrinter::PrinterResolution);


                                 document->print(&printer);

                             }

                             printer.setOutputFormat(QPrinter::PdfFormat);
                             printer.setPaperSize(QPrinter::A4);
                             printer.setOutputFileName("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\table2.pdf");
                             printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                             delete document;
}

void MainWindow::on_pushButton_38_clicked() // trie fourriere
{
    click->play();
    if(ui->radioButton->isChecked())
    {
        ui->tabView_vehicule->setModel(tempfourriere.trier(1));
    }
    else if(ui->radioButton_2->isChecked())
    {
        ui->tabView_vehicule->setModel(tempfourriere.trier(2));

    }
    else if(ui->radioButton_3->isChecked())
    {
        ui->tabView_vehicule->setModel(tempfourriere.trier(3));

    }
    else
    {
        QMessageBox::critical(this, QObject::tr("tri"),
                    QObject::tr("selectionner une bouton.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherP_7_clicked() // ajout vehecule
{
    click->play();
    notification n;
    QString type= ui->lineEdit_type->text();
    QString marque= ui->lineEdit_marque->text();
    QString matricule= ui->lineEdit_matricule->text();
    QString puissance= ui->lineEdit_puissance->text();
    QString energie= ui->lineEdit_energie->text();
    QString dateS= ui->lineEdit_date->text();
    vehicule v(type,marque,matricule,puissance,energie,dateS);
    bool test=v.ajouter();
    if(test)
    {
        n.setPopupText("véhicule a été ajouté");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un véhicule"));
        ui->afficher_client_3->setModel(tempVehicule.afficher());
        QMessageBox::information(this, QObject::tr("ajout"),
                 QObject::tr("ajout succès.\n""Click canal to exit"),QMessageBox::Cancel);
     }
    else { n.setPopupText("il y'a un probleme");
        n.show();
        QMessageBox::critical(this, QObject::tr("ajout"),
                QObject::tr("ajout echoué.\n""Click canal to exit"),QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_supp_2_clicked() //supprimer vehecule
{
    click->play();
    notification n;
    QString matricule = ui->lineEdit_surema_2->text();
    bool test=tempVehicule.supprimer(matricule);
    if (ui->lineEdit_surema_2->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Supprimer"),
                           QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

    }
  else  if(test)
    {
        n.setPopupText("véhicule a été supprimé");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un supprission d'un véhicule"));
      ui->afficher_client_3->setModel(tempVehicule.afficher());
      QMessageBox::information(this, QObject::tr("suppression"),
               QObject::tr("suppression avec succès.\n""Click canal to exit"),QMessageBox::Cancel);
    }
    else
    {
        n.setPopupText("il y'a un probleme");
       n.show();
       QMessageBox::critical(this, QObject::tr("suppression"),
                            QObject::tr("suppression avec echoué.\n""Click canal to exit"),QMessageBox::Cancel);}
}


void MainWindow::on_pushButton_chercherP_4_clicked() //modifier vehecule
{
    click->play();
    notification n;
    QString type= ui->lineEdit_type->text();
    QString marque= ui->lineEdit_marque->text();
    QString matricule= ui->lineEdit_matricule->text();
    QString puissance= ui->lineEdit_puissance->text();
    QString energie= ui->lineEdit_energie->text();
    QString dateS= ui->lineEdit_date->text();
    vehicule v(type,marque,matricule,puissance,energie,dateS);
            bool test=v.modifier(matricule);
            if(test)
            {
                n.setPopupText("véhicule a été modifié");
                n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a un modification d'un véhicule"));
               ui->afficher_client_3->setModel(tempVehicule.afficher());
                QMessageBox::information(this, QObject::tr("modifié"),
                            QObject::tr("modifié avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else { n.setPopupText("il y'a un probleme");
                n.show();

                QMessageBox::critical(this, QObject::tr("modifié"),
                            QObject::tr("modifié échoué.\n""Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_rech_2_clicked() //recherche vehecule
{
    click->play();
    QString matricule = ui->lineEdit_surema_2->text();
            ui->afficher_client_3->setModel(tempVehicule.rechercher(matricule));
}


void MainWindow::on_radioButton_mat_2_clicked() //trie vehecule (matricule)
{
    click->play();
    ui->afficher_client_3->setModel(tempVehicule.trierM());
}

void MainWindow::on_radioButton_date_2_clicked() //trie vehecule date
{
    click->play();
    ui->afficher_client_3->setModel(tempVehicule.trierD());
}

void MainWindow::on_pushButton_5_clicked() //ajout amande
{
    click->play();
    notification n;
    int id= ui->lineEdit_8->text().toInt();
    QString nom= ui->lineEdit_9->text();
    QString prenom= ui->lineEdit_10->text();
    QString typeA= ui->lineEdit_11->text();
    QString montant= ui->lineEdit_12->text();
    QString datea= ui->lineEdit_7->text();
    amende v(id,nom,prenom,typeA,montant,datea);
    bool test=v.ajouter();
    if(test)
    {
        n.setPopupText("Amande a été ajouté");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un amnde"));
        ui->tabView_amende->setModel(temAmende.afficher());
        QMessageBox::information(this, QObject::tr("ajout"),
                 QObject::tr("ajout succès.\n""Click canal to exit"),QMessageBox::Cancel);
     }
    else {
        n.setPopupText("il y'a un probleme");
       n.show();
        QMessageBox::critical(this, QObject::tr("ajout"),
                QObject::tr("ajout echoué.\n""Click canal to exit"),QMessageBox::Cancel); }
}

void MainWindow::on_pushButton_suppr_clicked() //supprimer amande
{
    click->play();
    notification n;
    int id= ui->lineEdit_cinsr->text().toInt();
    bool test=temAmende.supprimer(id);
    if (ui->lineEdit_cinsr->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Supprimer"),
                           QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

    }
  else  if(test)
    {
        n.setPopupText("Amande a été supprimé");
        n.show();
        mysystem->showMessage(tr("Notification"),tr("Il y a un supprission d'un amande"));
      ui->tabView_amende->setModel(temAmende.afficher());
      QMessageBox::information(this, QObject::tr("suppression"),
               QObject::tr("suppression avec succès.\n""Click canal to exit"),QMessageBox::Cancel);
    }
    else {
        n.setPopupText("il y'a un probleme");
       n.show();
     QMessageBox::critical(this, QObject::tr("suppression"),
                            QObject::tr("suppression avec echoué.\n""Click canal to exit"),QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_mod_clicked() // modifier amande
{
    click->play();
    notification n;
    int id= ui->lineEdit_8->text().toInt();
    QString nom= ui->lineEdit_9->text();
    QString prenom= ui->lineEdit_10->text();
    QString typeA= ui->lineEdit_11->text();
    QString montant= ui->lineEdit_12->text();
    QString datea= ui->lineEdit_7->text();
    amende a(id,nom,prenom,typeA,montant,datea);

            bool test=a.modifier(id);
            if(test)
            {
                n.setPopupText("Amande a été modifié");
                n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a un modification d'un amande"));
               ui->tabView_amende->setModel(temAmende.afficher());
                QMessageBox::information(this, QObject::tr("modifié"),
                            QObject::tr("modifié avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else{
                n.setPopupText("il y'a un probleme");
               n.show();

                QMessageBox::critical(this, QObject::tr("modifié"),
                            QObject::tr("modifié échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_reche_clicked() //recherche amande
{
    click->play();

    int id=ui->lineEdit_cinsr->text().toInt();
            ui->tabView_amende->setModel(temAmende.rechercher(id));
}



void MainWindow::on_pushButton_imp_clicked()
{
    click->play();
    amende a;
     a.CREATE_PDF();

}

void MainWindow::on_radioButton_dat_clicked()
{
    click->play();
     ui->tabView_amende->setModel(temAmende.trierD());
}

void MainWindow::on_radioButton_nom_clicked()
{
    click->play();
     ui->tabView_amende->setModel(temAmende.trierN());
}

void MainWindow::on_pushButton_ajouterdeces_clicked() //ajout deces
{
    click->play();
    notification n;
    int cin=ui->lineEdit_cindeces->text().toInt();
    QString nom=ui->lineEdit_nomdeces->text();
    QString prenom=ui->lineEdit_prenomdeces->text();
    QString datedeces=ui->dateEdit_deces->date().toString();
    QString lieu=ui->lineEdit_lieudeces->text();
    QString statut=" ";
        if (ui->radioButton_celibatairedeces->isChecked())
        {
            statut="Celibataire";
            statut=ui->radioButton_celibatairedeces->text();
        }
        else if (ui->radioButton_divorcedeces->isChecked())
        {
            statut="Divorce";
            statut=ui->radioButton_divorcedeces->text();
        }
        else if (ui->radioButton_mariedeces->isChecked())
        {
            statut="Marie";
            statut=ui->radioButton_mariedeces->text();
        }
        else
        {
            statut="Voeuf";
            statut=ui->radioButton_voeufdeces->text();
        }

        Certifdeces c(cin,nom,prenom,datedeces,lieu,statut);
        bool test=c.ajouter_certif();
        if(test)
        {
            n.setPopupText("Certificat de decès a été ajouté");
            n.show();
            mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un Certificat de decès"));
            ui->tableView_deces->setModel(tempcert.afficher_certif());
            QMessageBox::information(this, QObject::tr("Ajout"),
                        QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
         else
        {
            n.setPopupText("il y'a un probleme");
            n.show();
            QMessageBox::critical(this, QObject::tr("Ajout"),
                        QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_supprimerdeces_clicked() //supprimer deces
{
    click->play();
    notification n;
        int id=ui->lineEdit_cindeces->text().toUInt();
            bool test=tempcert.supprimer_certif(id);
            if (ui->lineEdit_cindeces->text()=="")
            {
                QMessageBox::critical(this, QObject::tr("Supprimer"),
                                   QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

            }
          else  if(test)
            {
                n.setPopupText("Certificat de decès a été supprimé");
                n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a une suppression d'un Certificat de decès"));
                ui->tableView_deces->setModel(tempcert.afficher_certif());
                QMessageBox::information(this, QObject::tr("Supprimer"),
                QObject::tr("Suppression avec succée"), QMessageBox::Ok);
               // hide();
            }
            else
            {
                n.setPopupText("il y'a un probleme");
                n.show();
                QMessageBox::critical(this, QObject::tr("Supprimer"),
                QObject::tr("Suppression echoués"), QMessageBox::Ok);
            }
}

void MainWindow::on_pushButton_modifierdeces_clicked() //modifier deces
{
    click->play();
    notification n;
    int cin=ui->lineEdit_cindeces->text().toInt();
    QString nom=ui->lineEdit_nomdeces->text();
    QString prenom=ui->lineEdit_prenomdeces->text();
    QString datedeces=ui->dateEdit_deces->date().toString();
    QString lieu=ui->lineEdit_lieudeces->text();
    QString statut=" ";
        if (ui->radioButton_celibatairedeces->isChecked())
        {
            statut="Celibataire";
            statut=ui->radioButton_celibatairedeces->text();
        }
        else if (ui->radioButton_divorcedeces->isChecked())
        {
            statut="Divorce";
            statut=ui->radioButton_divorcedeces->text();
        }
        else if (ui->radioButton_mariedeces->isChecked())
        {
            statut="Marie";
            statut=ui->radioButton_mariedeces->text();
        }
        else
        {
            statut="Voeuf";
            statut=ui->radioButton_voeufdeces->text();
        }

            Certifdeces c(cin,nom,prenom,datedeces,lieu,statut);
            bool test=c.modifier_certif(cin);
            if(test)
            {   n.setPopupText("Certificat de Decès a été modifié");
                n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a une modification d'un Certificat de decès"));
                ui->tableView_deces->setModel(tempcert.afficher_certif());
                QMessageBox::information(this, QObject::tr("Modification"),
                            QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else
            {
                n.setPopupText("il y'a un probleme");
               n.show();
                QMessageBox::critical(this, QObject::tr("Modification"),
                            QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_imprimerdeces_clicked()
{
    click->play();
    QString strStream;
                  QTextStream out(&strStream);

                  const int rowCount = ui->tableView_deces->model()->rowCount();
                  const int columnCount = ui->tableView_deces->model()->columnCount();
                  out <<"<html>\n"
                        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      << "<title>ERP - COMmANDE LIST<title>\n "
                      << "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"
                      "<h1 style=\"text-align: center;\"><strong> LISTE CERTIFICAT DECES  ""</strong></h1>"
                      "<table style=\"text-align: center; font-size: 13px;\" border=1>\n "
                        "</br> </br>";
                  // headers
                  out << "<thead><tr bgcolor=#56089A>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->tableView_deces->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->tableView_deces->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->tableView_deces->isColumnHidden(column)) {
                              QString data =ui->tableView_deces->model()->data(ui->tableView_deces->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_rechdeces_clicked()
{
    click->play();
    QString cin =ui->lineEdit_rechdeces->text();
    ui->tableView_deces->setModel(tempcert.recherche(cin));
}


void MainWindow::on_pushButton_pdfdeces_clicked()
{
    click->play();
    QPdfWriter pdf("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\pdfdeces.pdf");
                  QPainter painter(&pdf);
                 int i = 4000;
                      painter.setPen(Qt::blue);
                      painter.setFont(QFont("Arial", 25));
                      painter.drawText(950,1100,"Liste Des certificats de deces");
                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Arial", 15));
                     // painter.drawText(1100,2000,afficheDC);
                      painter.drawRect(100,100,7300,2600);
                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png"));
                      painter.drawRect(0,3000,9600,500);
                      painter.setFont(QFont("Arial", 9));
                      painter.drawText(200,3300,"CIN");
                      painter.drawText(1600,3300,"NOM");
                      painter.drawText(2100,3300,"PRENOM");
                      painter.drawText(3200,3300,"DATE_DECES");
                      painter.drawText(5300,3300,"LIEU");
                      painter.drawText(7400,3300,"ETAT_MATRIMATIONALE");


                      QSqlQuery query;
                      query.prepare("select * from CERTIFDECES");
                      query.exec();
                      while (query.next())
                      {
                          painter.drawText(200,i,query.value(0).toString());
                          painter.drawText(1300,i,query.value(1).toString());
                          painter.drawText(2100,i,query.value(2).toString());
                          painter.drawText(3200,i,query.value(3).toString());
                          painter.drawText(5300,i,query.value(4).toString());
                          painter.drawText(7400,i,query.value(5).toString());


                         i = i + 500;
                      }
                      QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_TriAZdeces_clicked()
{
    click->play();
     ui->tableView_deces->setModel(tempcert.triercroi());
}

void MainWindow::on_pushButton_TriZAdeces_clicked()
{
    click->play();
    ui->tableView_deces->setModel(tempcert.trierdec());
}

void MainWindow::on_tableView_deces_activated(const QModelIndex &index)
{
    Certifdeces c;
    QString cin=ui->tableView_deces->model()->data(index).toString();
      QSqlQuery query;
QString status="";
      query.prepare("select * from CERTIFDECES where cin_d LIKE '"+cin+"%' or nom LIKE '"+cin+"%' or prenom LIKE '"+cin+"%'");
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_cindeces->setText(query.value(0).toString());
            ui->lineEdit_nomdeces->setText(query.value(1).toString());
            ui->lineEdit_prenomdeces->setText(query.value(2).toString());
            ui->lineEdit_lieudeces->setText(query.value(4).toString());
           // status= c.getetatmatrim();
          //  model->setHeaderData(0,Qt::Horizontal, QObject::tr("CIN Citoyen"));
         /*   if (status=="Celibataire")
            {
                ui->radioButton_celibataire->setChecked(1);
            }
           else if (status=="Marie")
            {
                ui->radioButton_marie->setChecked(1);
            }
         else   if (status=="Divorce")
            {
                ui->radioButton_divorce->setChecked(1);
            }
            else if (status=="Voeuf")
            {
                ui->radioButton_voeuf->setChecked(1);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("error"),
                            QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
            }*/
      }
      }
        else
        {

            //QMessageBox::critical(this,tr("error::"),query.lastError().text());
          QMessageBox::critical(this, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_pushButton_ajouterpermis_clicked() // ajout permi
{
    click->play();
    notification n;
        int cin=ui->lineEdit_cinpermis->text().toInt();
        QString lieu=ui->lineEdit_lieupermis->text();
        int codepostale=ui->lineEdit_postalepermis->text().toInt();

            permisconstr p(cin,lieu,codepostale);
            bool test=p.ajouter_permis();
            if(test)
            {
                n.setPopupText("Permis de Construction a été Ajouté");
                n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a un Ajout d'un Permis de construction"));
               ui->tableView_permis->setModel(temppermis.afficher_permis());
                QMessageBox::information(this, QObject::tr("Ajout"),
                            QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else
            {
                n.setPopupText("il y'a un probleme");
               n.show();
                QMessageBox::critical(this, QObject::tr("Ajout"),
                            QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
            }

}


void MainWindow::on_pushButton_supprimerpermis_clicked()
{
    click->play();
    notification n;
        int id=ui->lineEdit_cinpermis->text().toUInt();
            bool test=temppermis.supprimer_permis(id);
            if (ui->lineEdit_cinpermis->text()=="")
            {
                QMessageBox::critical(this, QObject::tr("Supprimer"),
                                   QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

            }
        else    if(test)
            {
                n.setPopupText("Permis de Construction a été Supprimé");
                n.show();
                mysystem->showMessage(tr("Notification"),tr("Il y a une suppression d'un Permis de construction"));
                ui->tableView_permis->setModel(temppermis.afficher_permis());
                QMessageBox::information(this, QObject::tr("Supprimer"),
                QObject::tr("Suppression avec succée"), QMessageBox::Ok);
               // hide();
            }
            else
            {
                n.setPopupText("il y'a un probleme");
                n.show();
                QMessageBox::critical(this, QObject::tr("Supprimer"),
                QObject::tr("Suppression echoués"), QMessageBox::Ok);
            }
}

void MainWindow::on_pushButton_modifierpermis_clicked()
{
    click->play();
    notification n;
    int cin=ui->lineEdit_cinpermis->text().toInt();
    QString lieu=ui->lineEdit_lieupermis->text();
    int codepostale=ui->lineEdit_postalepermis->text().toInt();

            permisconstr p(cin,lieu,codepostale);
            bool test=p.modifier_permis(cin);
            if(test)
            {  n.setPopupText("Permis de construction a été modifié");
               n.show();
            mysystem->showMessage(tr("Notification"),tr("Il y a une modification d'une Permis de Construction"));
               ui->tableView_permis->setModel(temppermis.afficher_permis());
                QMessageBox::information(this, QObject::tr("Modification"),
                            QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else
            {
                n.setPopupText("il y'a un probleme");
               n.show();
                QMessageBox::critical(this, QObject::tr("Modification"),
                            QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void MainWindow::on_pushButton_recherchepermis_clicked() //recherche permis
{
    click->play();
    QString cin =ui->lineEdit_recherchepermis->text();
    ui->tableView_permis->setModel(temppermis.recherche(cin));
}

void MainWindow::on_pushButton_lieuazpermis_clicked()
{
    click->play();
     ui->tableView_permis->setModel(temppermis.triercroi());
}

void MainWindow::on_pushButton_lieuzapermis_clicked()
{
    click->play();
    ui->tableView_permis->setModel(temppermis.trierdec());
}

void MainWindow::on_pushButton_tripostalecroipermis_clicked()
{
    click->play();
    ui->tableView_permis->setModel(temppermis.triercodecroi());

}

void MainWindow::on_pushButton_tripostaledecpermis_clicked()
{
    click->play();
     ui->tableView_permis->setModel(temppermis.triercodedec());
}

void MainWindow::on_pushButton_pdfpermis_clicked() // pdf permis
{
    click->play();
    QPdfWriter pdf("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\pdfconstruction.pdf");
                  QPainter painter(&pdf);
                 int i = 4000;
                      painter.setPen(Qt::red);
                      painter.setFont(QFont("Arial", 25));
                      painter.drawText(950,1100,"Liste Des Permis Constructions");
                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Arial", 15));
                     // painter.drawText(1100,2000,afficheDC);
                      painter.drawRect(100,100,7300,2600);
                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png"));
                      painter.drawRect(0,3000,9600,500);
                      painter.setFont(QFont("Arial", 9));
                      painter.drawText(200,3300,"CIN");
                      painter.drawText(1600,3300,"LIEU");
                      painter.drawText(2100,3300,"CODE_POSTALE");

                      QSqlQuery query;
                      query.prepare("select * from PERMISCONSTRUCTIONN");
                      query.exec();
                      while (query.next())
                      {
                          painter.drawText(200,i,query.value(0).toString());
                          painter.drawText(1300,i,query.value(1).toString());
                          painter.drawText(2100,i,query.value(2).toString());

                         i = i + 500;
                      }
                      QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_imprimerpermis_clicked() //imprimer permis
{
    click->play();
    QString strStream;
                  QTextStream out(&strStream);

                  const int rowCount = ui->tableView_permis->model()->rowCount();
                  const int columnCount = ui->tableView_permis->model()->columnCount();
                  out <<"<html>\n"
                        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      << "<title>ERP - COMmANDE LIST<title>\n "
                      << "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"
                      "<h1 style=\"text-align: center;\"><strong> LISTE PERMIS CONSTRUCTION  ""</strong></h1>"
                      "<table style=\"text-align: center; font-size: 13px;\" border=1>\n "
                        "</br> </br>";
                  // headers
                  out << "<thead><tr bgcolor=#56089A>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->tableView_permis->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->tableView_permis->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->tableView_permis->isColumnHidden(column)) {
                              QString data =ui->tableView_permis->model()->data(ui->tableView_permis->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_imagepermis_clicked() //importation image
{
    click->play();
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.jpeg *jpg *.png *.bmp *.gif *.mp4)"));

        if (QString::compare(filename, QString()) !=0)
        {
            QImage image;
            bool valid = image.load(filename);
            if (valid)
            {
            image = image.scaledToWidth(ui->label_63->width(), Qt::SmoothTransformation);
            ui->label_63->setPixmap(QPixmap::fromImage(image));
            }
            else
            {
                ///error handling
            }
            }
}

void MainWindow::on_tableView_permis_activated(const QModelIndex &index)
{
    QString cin=ui->tableView_permis->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select * from PERMISCONSTRUCTIONN where cin_p LIKE '"+cin+"%' or lieu LIKE '"+cin+"%' or codepostale LIKE '"+cin+"%'");
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_cinpermis->setText(query.value(0).toString());
            ui->lineEdit_lieupermis->setText(query.value(1).toString());
            ui->lineEdit_postalepermis->setText(query.value(2).toString());
        }
      }
        else
        {

            //QMessageBox::critical(this,tr("error::"),query.lastError().text());
          QMessageBox::critical(this, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_pushButton_ajouteremploye_clicked() //ajout employee
{notification n;
    click->play();
    int CIN = ui->lineEdit_CIN->text().toInt();

        QString nom=ui->lineEdit_nom_2->text();
        QString prenom = ui->lineEdit_prenom_2->text();
        int num = ui->lineEdit_numero->text().toInt();
        QString adresse = ui->lineEdit_adresse_2->text();

        employe z (CIN,nom,prenom,num,adresse);
        bool test = z.ajouter();
        if(test)
        { n.setPopupText("Un employé a ete ajouté");
            n.show();
         mysystem->showMessage(tr("Notification"),tr("Un employé a ete ajouté"));
            ui->tableView_employes->setModel(z.afficher());

        QMessageBox::information(this,QObject::tr("ajouter un employé"),QObject::tr("employé ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
        }
        ui->lineEdit_CIN->clear();
        ui->lineEdit_nom_2->clear();
        ui->lineEdit_prenom_2->clear();
        ui->lineEdit_numero->clear();
        ui->lineEdit_adresse_2->clear();

}

void MainWindow::on_pushButton_24_clicked()
{
    click->play();
    int CINe= ui->lineEdit_CIN->text().toInt();
    bool test=z.supprimer(CINe);
    if (ui->lineEdit_CIN->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Supprimer"),
                           QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

    }
     else   if(test){
           ui->tableView_employes->setModel(z.afficher());
           QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                       QObject::tr("employe a ete supprimé avec succés.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


         }
         else
             QMessageBox::critical(this, QObject::tr("problem supprimer"),
                         QObject::tr("connection failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

int MainWindow::getselectedEmploye()
{
int s=ui->tableView_employes->selectionModel()->currentIndex().row();
QModelIndex index =ui->tableView_employes->model()->index(s, 0,QModelIndex());
int aff=ui->tableView_employes->model()->data(index).toString().toInt();
return aff;
}
int MainWindow::getselectedDepartement()
{
int s=ui->tableView_depart->selectionModel()->currentIndex().row();
QModelIndex index =ui->tableView_depart->model()->index(s, 0,QModelIndex());
int aff=ui->tableView_depart->model()->data(index).toString().toInt();
return aff;
}


void MainWindow::on_pushButton_10_clicked() //modifier employee
{
    click->play();
    employe c(ui->lineEdit_CIN->text().toInt(),ui->lineEdit_nom_2->text(),ui->lineEdit_prenom_2->text(),ui->lineEdit_numero->text().toInt(),ui->lineEdit_adresse_2->text());
        c.modifier(getselectedEmploye());
         ui->tableView_employes->setModel(z.afficher());
        ui->lineEdit_CIN->setText("");
         ui->lineEdit_nom->setText("");
         ui->lineEdit_prenom->setText("");
         ui->lineEdit_numero->setText("");
         ui->lineEdit_adresse->setText("");
}

void MainWindow::on_pushButton_12_clicked() //supprimer tous les employes
{
    click->play();
    bool test=z.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes){
    if(test){
         ui->tableView_employes->setModel(z.afficher());

        QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   }
}

void MainWindow::on_pushButton_7_clicked() //pdf employee
{
    click->play();
    int CIN= ui ->lineEdit_CIN->text().toInt() ;
    QString nom= ui ->lineEdit_nom_2->text() ;
    QString prenom= ui ->lineEdit_prenom_2->text() ;
    int num= ui->lineEdit_numero->text().toInt();
    QString adresse=ui->lineEdit_adresse_2->text();

    QString CINs=QString::number(CIN);
    QString nums=QString::number(num);

    QString pdf_name= "employe_"+nom+"_"+prenom+".pdf";
    QPdfWriter pdf(pdf_name);
    QPainter painter(&pdf);

    painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png"));
                          painter.drawRect(0,3000,9600,500);

    painter.setPen(Qt::blue);
    painter.drawText(3000,1500,"DEV SPACE");

    painter.setPen(Qt::black);
    painter.drawText(100,2600,"CIN : ");
    painter.setPen(Qt::blue);
    painter.drawText(2000,2600,CINs);
    painter.setPen(Qt::blue);
    painter.drawText(100,2300,"Nom : ");
    painter.setPen(Qt::blue);
    painter.drawText(2000,2300,nom);
    painter.drawText(100,2900,"Prenom : ");
    painter.setPen(Qt::blue);
    painter.drawText(2000,2900,prenom);
    painter.setPen(Qt::blue);

    painter.setPen(Qt::blue);
    painter.drawText(100,3200,"numero : ");
    painter.setPen(Qt::black);
    painter.drawText(2000,3200,nums);
    painter.setPen(Qt::blue);
    painter.drawText(100,3500,"Adresse : ");
    painter.setPen(Qt::black);
    painter.drawText(2000,3500,adresse);

    painter.end();
}

void MainWindow::on_pushButton_8_clicked() //recherche employee
{
    click->play();
    int  CIN = ui->lineEdit_CIN->text().toInt();
     QString nom = ui->lineEdit_nom_2->text();
     QString prenom = ui->lineEdit_prenom_2->text();
     int num = ui->lineEdit_numero->text().toInt();
     QString adresse = ui->lineEdit_adresse_2->text();
         if(nom==""&&prenom==""&&adresse==""&&num==0){
         QString txt=ui->lineEdit_CIN->text();
         ui->tableView_employes->setModel(z.recherche_CIN_employe(txt));
         }
         else    if(CIN==0&&prenom==""&&adresse==""&&num==0){
             QString txt=ui->lineEdit_nom->text();
            ui->tableView_employes->setModel(z.recherche_nom_employe(txt));}
         else    if(CIN==0&&nom==""&&adresse==""&&num==0){
             QString txt=ui->lineEdit_prenom->text();
            ui->tableView_employes->setModel(z.recherche_prenom_employe(txt));}
         else    if(CIN==0&&nom==""&&prenom==""&&num==0){
             QString txt=ui->lineEdit_adresse->text();
            ui->tableView_employes->setModel(z.recherche_adresse_employe(txt));}
}

void MainWindow::on_pushButton_13_clicked() // trie employee
{
    click->play();
    QString tri=ui->comboBox->currentText();

        if(tri=="CIN")
      ui->tableView_employes->setModel(z.ordre_CIN_employe());
        else if(tri=="Nom")
            ui->tableView_employes->setModel(z.ordre_nom_employe());
        else if(tri=="Prenom")
 ui->tableView_employes->setModel(z.ordre_prenom_employe());
}


void MainWindow::on_pushButton_22_clicked() //ajout departement
{
    click->play();
    int id = ui->id_dep_2->text().toInt();
     int nbre = ui->lineEdit_nbrdesemployes_2->text().toInt();
      int bud = ui->lineEdit_budget_2->text().toInt();
        QString nomd=ui->lineEdit_nomdep_2->text();




        departement d (id ,nomd,nbre,bud);
        bool test = d.ajouter();
        if(test)
        {
            ui->tableView_depart->setModel(d.afficher());

        QMessageBox::information(this,QObject::tr("ajouter un departement"),QObject::tr("departement ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
        }
        ui->id_dep_2->clear();
        ui->lineEdit_nbrdesemployes_2->clear();
        ui->lineEdit_budget_2->clear();
        ui->lineEdit_nomdep_2->clear();

}

void MainWindow::on_pushButton_26_clicked()
{
    click->play();
    int id_dep= ui->id_dep_2->text().toInt();
    bool test=d.supprimer(id_dep);
    if (ui->id_dep_2->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Supprimer"),
                           QObject::tr("Veuillez remplir tous le champs"), QMessageBox::Ok);

    }

     else   if(test){
           ui->tableView_depart->setModel(d.afficher());
           QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                       QObject::tr("departement a ete supprimé avec succés.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


         }
         else
             QMessageBox::critical(this, QObject::tr("problem supprimer"),
                         QObject::tr("connection failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_30_clicked()
{
    click->play();
    departement d(ui->id_dep_2->text().toInt(),ui->lineEdit_nomdep_2->text(),ui->lineEdit_nbrdesemployes_2->text().toInt(),ui->lineEdit_budget_2->text().toInt());
    d.modifier();
     ui->tableView_depart->setModel(d.afficher());
    ui->id_dep_2->setText("");
     ui->lineEdit_nomdep_2->setText("");
     ui->lineEdit_nbrdesemployes_2->setText("");
     ui->lineEdit_budget_2->setText("");
}

void MainWindow::on_pushButton_9_clicked() //supprimer tous departement
{
    click->play();
    bool test=d.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
    if(test)
    {
         ui->tableView_depart->setModel(d.afficher());
        QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   }

}

void MainWindow::on_pushButton_11_clicked()
{
    click->play();
     ui->tableView_depart->setModel(d.afficherTriNOM());
}

void MainWindow::on_pushButton_15_clicked() //chatt
{
    click->play();
    serverdialog = new Server(this);
    serverdialog->show();
    clientdialog = new Client(this);
    clientdialog->show();
}

void MainWindow::on_pushButton_16_clicked() //chatt commerciale
{
    click->play();
    clientdialog = new Client(this);
    clientdialog->show();
}

void MainWindow::on_pushButton_18_clicked() //chatt employee
{
    click->play();
    serverdialog = new Server(this);
    serverdialog->show();
}

void MainWindow::on_pushButton_23_clicked() //supprimer tous les commerciales
{
    click->play();
    bool test=tempcommerciale.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
    if(test)
    {
         ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
        QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   }
}

void MainWindow::on_pushButton_21_clicked()//supprimer tous les citoyens
{
    click->play();
    bool test=temcitoyent.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
    if(test)
    {
         ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
        QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_20_clicked()//supprimertous permis
{
    click->play();
    bool test=temppermis.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
    if(test)
    {
         ui->tableView_permis->setModel(temppermis.afficher_permis());
        QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_19_clicked() //supprimer tous certif deces
{
    click->play();
    bool test=tempcert.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
    if(test)
    {
         ui->tableView_deces->setModel(tempcert.afficher_certif());
        QMessageBox::information(this, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_25_clicked() // exel citoyens
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->tab_citoyent);

           obj.addField(0, "colum1", "char(20)");
           obj.addField(1, "colum2", "char(20)");
           obj.addField(2, "colum3", "char(20)");
           obj.addField(3, "colum4", "char(20)");
           obj.addField(4, "colum5", "char(20)");
           obj.addField(5, "colum6", "char(20)");
           obj.addField(6, "colum7", "char(20)");
           obj.addField(7, "colum8", "char(20)");
           obj.addField(8, "colum9", "char(20)");
           obj.addField(9, "colum10", "char(20)");
           obj.addField(10, "colum11", "char(20)");
           obj.addField(11, "colum12", "char(20)");
           obj.addField(12, "colum13", "char(20)");

           int retVal = obj.export2Excel();

           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}

void MainWindow::on_pushButton_27_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->tableView_deces);

           obj.addField(0, "colum1", "char(20)");
           obj.addField(1, "colum2", "char(20)");
           obj.addField(2, "colum3", "char(20)");
           obj.addField(3, "colum4", "char(20)");
           obj.addField(4, "colum5", "char(20)");

           int retVal = obj.export2Excel();

           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}

void MainWindow::on_pushButton_28_clicked()//temperature
{
    click->play();
    tempe = new temp(this);
    tempe->show();
}

void MainWindow::on_pushButton_29_clicked() // capteur de mouvement
{
    click->play();
    mouv = new lumiere(this);
    mouv->show();
}

void MainWindow::on_pushButton_35_clicked()
{

}
