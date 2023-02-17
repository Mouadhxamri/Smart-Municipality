#include "departement.h"

departement::departement()
{
}
    departement::departement(int i,QString a,int b,int c)
    {
    id_dep=i;
    nom_dep=a;
    nbr_dep=b;
    budget=c;


    }

    bool departement::ajouter()
    {QSqlQuery query;
      QString id_deps=QString::number(id_dep);
      QString nbr_deps=QString::number(nbr_dep);
      QString budgets=QString::number(budget);
      query.prepare("insert into departement (id_dep,nom_dep,nbr_dep,budget) values (:id_dep,:nom_dep,:nbr_dep,:budget)");
      query.bindValue(":id_dep",id_deps);
      query.bindValue(":nom_dep",nom_dep);
      query.bindValue(":nbr_dep",nbr_deps);
      query.bindValue(":budget",budgets);

      return query.exec();
    }
    QSqlQueryModel * departement::afficher()
    { QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from departement");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id departement"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom departement"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbr departement"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("budget departement"));


        return model;

    }
    bool departement::supprimer(int idd)
    {
        QSqlQuery Query;

        QString id_deps=QString::number(idd);

        Query.prepare("Delete from departement where id_dep = :id_dep"  );
        Query.bindValue(":id_dep",id_deps);
        return Query.exec();


    }
    bool departement::supprimerTout()
    { QSqlQuery query;

       query.prepare("delete from departement ");

      return query.exec();
    }
    bool departement::modifier()
    {
        {

            QSqlQuery query ;

            QString id_deps=QString::number(id_dep);
            QString nbr_deps=QString::number(nbr_dep);
            QString budgets=QString::number(budget);

            query.prepare("update departement set nom_dep=:nom_dep,nbr_dep=:nbr_dep,budget=:budget where id_dep=:id_dep");
            query.bindValue(":id_dep",id_deps);
            query.bindValue(":nom_dep",nom_dep);
            query.bindValue(":nbr_dep",nbr_deps);
            query.bindValue(":budget",budgets);

           // query.addBindValue(id_depd);
            if(query.exec())
                return true;
            return false;
        }
    }




    void departement::rechercher(QString a,QTableView *g)
    { {QSqlQuery qry;
             QSqlQueryModel *m=new QSqlQueryModel();//initialisation
             qry.prepare("select * from departement where id_dep like'%"+a+"%' OR nom_dep like '%"+a+"%' OR nbr_dep like '%"+a+"%' OR budget like '%"+a+"%'");
                         qry.exec();
                     m->setQuery(qry);
             g->setModel(m);


         }}

    QSqlQueryModel * departement::afficherTriNOM()
    { QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from departement ORDER BY nom_dep ASC");// asc assendant dsc descendant

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id departement"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom departement"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbr departement"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("budget departement"));
        return model;

    }
