#ifndef PERMISCONSTR_H
#define PERMISCONSTR_H
#include <QString>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>


class permisconstr
{
public:
    permisconstr();
    permisconstr(int,QString,int);
    bool ajouter_permis();
    QSqlQueryModel * afficher_permis();
    bool supprimer_permis(int);
    bool modifier_permis(int);
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel * triercroi();
    QSqlQueryModel * trierdec();
    QSqlQueryModel * triercodecroi();
    QSqlQueryModel * triercodedec();
    bool supprimerTout();

    void CREATION_PDF();

    int getcin();
    QString getlieu(){return lieu;};
    int getcodepostale(){return codepostale;};

        void setcin(int);
        void setlieu(QString);
        void setcodepostale(int);

    private:
        int cin_p,codepostale;
        QString lieu;
};

#endif // PERMISCONSTR_H

