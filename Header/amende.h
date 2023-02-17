#ifndef AMENDE_H
#define AMENDE_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class amende
{
public:
    amende();
    amende(int,QString,QString,QString,QString,QString);
    int get_id(){return id;}
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_typeA(){return typeA;}
    QString get_montant(){return montant;}
    QString get_datea(){return datea;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel* rechercher(int);
    bool modifier(int);
    QSqlQueryModel * trierD();
    QSqlQueryModel * trierN();
    void CREATE_PDF();

private:
    int id;
    QString nom,prenom,typeA,montant,datea;
};

#endif // AMENDE_H

