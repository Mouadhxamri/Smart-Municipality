#ifndef CITOYENT_H
#define CITOYENT_H
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>



class citoyent
{
public:
    citoyent();
    citoyent(int,int,int,int,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    bool ajouter_citoyent();
    QSqlQueryModel * afficher_citoyent();
    bool supprimer_citoyent(int);
    bool modifier_citoyent(int);
    QSqlQueryModel* Recherche(QString);
    QSqlQueryModel * trierA();
    QSqlQueryModel * trierB();
    QSqlQueryModel * trierA_Z();
    QSqlQueryModel * trierZ_A();

    QString get_nom();
    QString get_prenom();
    QString get_dateNaissance();
    QString get_lieu();
    QString get_sexe();
    QString get_mail();
    QString get_profession();
    QString get_ville();
    QString get_adresse();
    bool supprimerTout();


private:
    int Cin,age,numTelph,codePostale;
    QString nom,prenom,dateNaissance,lieu,sexe,mail,profession,ville,adresse;

};

#endif // CITOYENT_H

