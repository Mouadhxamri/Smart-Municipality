#include "mainwindow.h"
#include "login.h"
//#include <fenetre.h>
#include <connexion.h>
#include <QMessageBox>

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login l;
    connexion c;
    bool test=c.ouvrirconnexion();
      if(test)
        {
          //l.show();
          w.show();

          QMessageBox::information(nullptr, QObject::tr("database is open"),
                 QObject::tr("connection successful.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
        }

      else
       QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                 QObject::tr("connection failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
