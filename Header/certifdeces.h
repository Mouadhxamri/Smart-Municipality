#ifndef CERTIFDECES_H
#define CERTIFDECES_H
#include <QString>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Certifdeces
{
public:
    Certifdeces();
    Certifdeces(int,QString,QString,QString,QString,QString);
    bool ajouter_certif();
    QSqlQueryModel * afficher_certif();
    bool supprimer_certif(int);
    bool modifier_certif(int);
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel * triercroi();
    QSqlQueryModel * trierdec();
    void CREATION_PDF();

        int getcin();
        QString getnom(){return nom;};
        QString getprenom(){return prenom;};
        QString getdatedeces(){return datedeces;};
        QString getlieu(){return lieu;};
        QString getetatmatrim(){return etatmatrim;};
        void setcin(int);
        void setnom(QString);
        void setprenom(QString);
        void setdatedeces(QString);
        void setlieu(QString);
        void setetatmatrim(QString);
        bool supprimerTout();

    private:
        int cin;
        QString nom,prenom,datedeces,lieu,etatmatrim;

};

#endif // CERTIFDECES_H
