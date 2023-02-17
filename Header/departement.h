#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTableView>

class departement
{
public:
    departement();

    departement(int,QString,int,int);
    int getid_dep(){return id_dep;}
     QString getnom_dep(){return nom_dep;}
      int getnbr_dep(){return nbr_dep;}
      int getbudget(){return budget;}
          bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier();
        bool supprimerTout();
         void rechercher(QString a,QTableView *g);
         QSqlQueryModel * afficherTriNOM();

    private:
    int id_dep,nbr_dep,budget;
    QString nom_dep;
};

#endif // DEPARTEMENT_H

