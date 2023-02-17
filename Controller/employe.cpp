#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


employe::employe()
{
    CIN_E=0;
    nom="";
    prenom="";
    nume=0;
    adresse="";

}
employe::employe(int i,QString a,QString b,int c,QString d)
{
CIN_E=i;
nom=a;
prenom=b;
nume=c;
adresse=d;

}

bool employe::ajouter()
{QSqlQuery query;
  QString CINs=QString::number(CIN_E);
  QString nums=QString::number(nume);
  query.prepare("insert into employee (CIN_E,nom,prenom,nume,adresse) values (:CIN_E,:nom,:prenom,:nume,:adresse)");
  query.bindValue(":CIN_E",CINs);
  query.bindValue(":nume",nums);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":adresse",adresse);
  return query.exec();
}
QSqlQueryModel * employe::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nume"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

    return model;

}
bool employe::supprimer(int CINe)
{
    QSqlQuery Query;
    QString CINs=QString::number(CINe);
    Query.prepare("Delete from employee where CIN_E = :CIN_E"  );
    Query.bindValue(":CIN_E",CINs);
    return Query.exec();


}
bool employe::modifier(int CINd)
{
    {
        QSqlQuery query ;
        query.prepare("update employee set CIN_E=? ,nom=?,prenom=?,nume=?,adresse=? where CIN_E=?");
        query.addBindValue(CIN_E);
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(nume);
        query.addBindValue(adresse);
        query.addBindValue(CINd);
        if(query.exec())
            return true;
        return false;
    }
}
bool employe::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from employee ");

  return query.exec();
}


/*void employe::rechercher(QString a,QTableView *g)
{ {QSqlQuery qry;
         QSqlQueryModel *m=new QSqlQueryModel();//initialisation
         qry.prepare("select * from employee where CIN_E like'%"+a+"%' OR nom like '%"+a+"%' OR prenom like '%"+a+"%' OR nume like '%"+a+"%' OR adresse like '%"+a+"%'");
                     qry.exec();
                 m->setQuery(qry);
         g->setModel(m);*/
    QSqlQueryModel *employe::recherche_CIN_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employee where CIN_E LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));


          return model;
      }
      QSqlQueryModel *employe::recherche_nom_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employee where nom LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }
      QSqlQueryModel *employe::recherche_prenom_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employee where prenom LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }
     /* QSqlQueryModel *employe::recherche_num_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employee where num LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }*/
      QSqlQueryModel *employe::recherche_adresse_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employee where adresse LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }





QSqlQueryModel * employe::afficherTriNOM()
{ QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee ORDER BY nom ASC");// asc assendant dsc descendant
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nume"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

    return model;

}

QSqlQueryModel *employe::ordre_CIN_employe()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from employee  order by CIN_E" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));



         return model;
     }

QSqlQueryModel *employe::ordre_nom_employe()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from employee  order by nom" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));



         return model;
     }
QSqlQueryModel *employe::ordre_prenom_employe()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from employee  order by prenom" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_E"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));



         return model;
     }
