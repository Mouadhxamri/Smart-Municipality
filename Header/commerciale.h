#ifndef COMMERCIALE_H
#define COMMERCIALE_H
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

class commerciale
{
public:
    commerciale();
    commerciale(int,int,QString,QString);

    bool ajouter_commerciale();
    QSqlQueryModel * afficher_commerciale();
    bool supprimer_commerciale(int);
    bool modifier_commerciale(int);
    QSqlQueryModel* Recherche(QString);
    QSqlQueryModel * trierA();
    QSqlQueryModel * trierB();
    QString get_fiscale();
    QString get_secteur_activite();
    bool supprimerTout();
    bool rechcin(QString);

private:
    int Cin_co,CNSS;
    QString fiscale,secteur_activite;
};

#endif // COMMERCIALE_H
