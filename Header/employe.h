#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTableView>
class employe
{
public:
    employe();
    employe(int,QString,QString,int,QString);
    int getcin(){return CIN_E;}
     QString getnom(){return nom;}
      QString getprenom(){return prenom;}
      int getnum(){return nume;}
          QString getadresse(){return adresse;}
bool ajouter();
QSqlQueryModel * recherche_CIN_employe(QString);
QSqlQueryModel * recherche_nom_employe(QString);
QSqlQueryModel * recherche_prenom_employe(QString);
//QSqlQueryModel * recherche_num_employe(QString);
QSqlQueryModel * recherche_adresse_employe(QString);
QSqlQueryModel * ordre_CIN_employe();
QSqlQueryModel * ordre_nom_employe();
QSqlQueryModel * ordre_prenom_employe();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int);

        bool supprimerTout();
         void rechercher(QString a,QTableView *g);
            QSqlQueryModel * afficherTriNOM();
    private:
    int CIN_E,nume;
    QString nom,prenom,adresse;



};

#endif // EMPLOYE_H
