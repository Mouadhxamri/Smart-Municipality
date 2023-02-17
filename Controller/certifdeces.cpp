#include "certifdeces.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>


Certifdeces::Certifdeces()
{
cin=0;
nom="";
prenom="";
datedeces="";
lieu="";
etatmatrim="";
}
Certifdeces::Certifdeces(int c,QString n,QString p,QString d,QString l,QString e)
{
    cin=c;
    nom=n;
    prenom=p;
    datedeces=d;
    lieu=l;
    etatmatrim=e;

}

bool Certifdeces::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from CERTIFDECES ");

  return query.exec();
}

bool Certifdeces::ajouter_certif()
{
    QSqlQuery query;
    QString cins=QString::number(cin);
    query.prepare("INSERT INTO CERTIFDECES(CIN_D, NOM, PRENOM, DATEDECES, LIEU, ETATMATRIM)"
                  "VALUES(:cin, :nom, :prenom, :datedeces, :lieu, :etatmatrim)");

    query.bindValue(":cin",cins);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":datedeces",datedeces);
    query.bindValue(":lieu",lieu);
    query.bindValue(":etatmatrim",etatmatrim);

    return query.exec();
}
QSqlQueryModel * Certifdeces::afficher_certif()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Certifdeces");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATE DECES"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("ETAT MATRIMONIALE"));
    return model;
}

 bool Certifdeces::supprimer_certif(int idc)
 {
     QSqlQuery query;
     QString res=QString::number(idc);
     query.prepare("delete from Certifdeces where CIN_D= :id");
     query.bindValue(":id",res);
     return query.exec();
 }

 bool Certifdeces::modifier_certif(int idd) //modifier certif
 {
     QSqlQuery query;
     QString res=QString::number(idd);
     query.prepare("Update certifdeces set CIN_D = :id , NOM = :nom , PRENOM = :prenom , DATEDECES = :datedeces , LIEU = :lieu , ETATMATRIM = :etatmatrim  where CIN_D = :id ");
     query.bindValue(":id", res);
     query.bindValue(":cin",cin);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":datedeces",datedeces);
     query.bindValue(":lieu",lieu);
     query.bindValue(":etatmatrim",etatmatrim);
     return query.exec();
 }

 QSqlQueryModel *Certifdeces::recherche(QString cin)
   {
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from CERTIFDECES where CIN_D LIKE '"+cin+"%' or nom LIKE '"+cin+"%' or prenom LIKE '"+cin+"%'");


       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

   return model;
       }
 QSqlQueryModel *Certifdeces::triercroi() //ml A-Z NOM
 {
     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM certifdeces order by NOM ASC");
            q->exec();
            model->setQuery(*q);
            return model;
      //ml kbir l sghir
        /*    QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM certifdeces order by codepostale DESC");
                   q->exec();
                   model->setQuery(*q);
                   return model;*/
 }
 QSqlQueryModel *Certifdeces::trierdec() //ml Z-A NOM
 {
     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM certifdeces order by NOM DESC");
            q->exec();
            model->setQuery(*q);
            return model;
      //ml kbir l sghir
        /*    QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM certifdeces order by codepostale DESC");
                   q->exec();
                   model->setQuery(*q);
                   return model;*/
 }
 void Certifdeces::CREATION_PDF()
 {
     QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

     QPrinter printer(QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);

     QTextDocument doc;
     QSqlQuery q;
     q.prepare("SELECT * FROM CERTIFDECES ");
     q.exec();
     QString pdf="<br> <h1  style='color:blue'>LISTE CERTIFICAT DE DECES  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th> PRENOM </th> <th> DATE DECES </th> <th> LIEU </th> <th> ETAT MATRIMONIALE </th> </tr>" ;


     while ( q.next()) {

         pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;

     }
     doc.setHtml(pdf);
     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
     doc.print(&printer);
 }
