#ifndef FOURRIERE_H
#define FOURRIERE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fourriere
{
public:
    fourriere();
    fourriere(QString,QString,QString);
    QString getmatricule(){return matricule;}
    QString gettype(){return type;}
    QString getcouleur(){return couleur;}
    bool ajouterfourriere();
    QSqlQueryModel * afficherfourriere();
    bool supprimerfourriere(QString);
    bool modifierfourriere();
  QSqlQueryModel * trier(int n);

private:
QString matricule,type,couleur;
};

#endif // FOURRIERE_H

