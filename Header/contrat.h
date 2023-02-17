#ifndef CONTRAT_H
#define CONTRAT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class contrat
{
public:
    contrat();
    contrat(QString,QString,QString,QString,QString,int,int);
    QString getNomp(){return nomp;}
    QString getNomm(){return nomm;}
    QString getMetierm(){return metierm;}
    QString getMetierp(){return metierp;}
    QString getDate(){return date;}
    int getCinm(){return cinm;}
    int getCinp(){return cinp;}
    bool ajouterContrat();
    QSqlQueryModel * afficherContrat();
     QSqlQueryModel * chercherContrat(int);
    bool supprimerContrat(int);
    bool modifierContrat(int);

private:
QString nomp,nomm,metierm,metierp,date;
int cinm,cinp,cinp1,cinp2;
};

#endif // CONTRAT_H

