#include "commerciale.h"

commerciale::commerciale()
{
    Cin_co=0;
    CNSS=0;
    fiscale=" ";
    secteur_activite=" ";
}

commerciale::commerciale(int c,int cn,QString f,QString s)
{
    this->Cin_co=c;
    this->CNSS=cn;
    this->fiscale=f;
    this->secteur_activite=s;
}

bool commerciale ::ajouter_commerciale()
{
    QSqlQuery query;
    QString CINS= QString::number(Cin_co);
    query.prepare("INSERT INTO COMMERCIALE(CIN_CO,CNSS,FISCALE,SECTEUR_DACTIVITE) "
                  "VALUES (:Cin_co, :CNSS,:fiscale,:secteur_dactivite)");
    query.bindValue(":Cin_co", CINS);
    query.bindValue(":CNSS", CNSS);
    query.bindValue(":fiscale", fiscale);
    query.bindValue(":secteur_dactivite", secteur_activite);

    return    query.exec();
}

bool commerciale::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from COMMERCIALE ");

  return query.exec();
}

QSqlQueryModel * commerciale ::afficher_commerciale()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from commerciale");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_CO"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CNSS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("FISCALE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SECTEUR_DACTIVITE"));

    return model;
}


bool commerciale :: supprimer_commerciale(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);


            query.prepare("Delete from commerciale where CIN_CO = :id");
            query.bindValue(":id",res);
            return query.exec();




}

bool commerciale::modifier_commerciale(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Update commerciale set CIN_CO = :Cin_co , CNSS = :cnss , FISCALE = :fiscale , SECTEUR_DACTIVITE = :secteur_dactivite   where CIN_CO = :Cin_co ");
query.bindValue(":id", res);
query.bindValue(":Cin_co", Cin_co);
query.bindValue(":cnss", CNSS);
query.bindValue(":fiscale", fiscale);
query.bindValue(":secteur_dactivite", secteur_activite);

return    query.exec();
}

QString commerciale :: get_fiscale() { return fiscale; }
QString commerciale :: get_secteur_activite() { return secteur_activite; }

QSqlQueryModel* commerciale::Recherche(QString cin)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from COMMERCIALE where Cin_co LIKE '"+cin+"%' or CNSS LIKE '"+cin+"%' or fiscale LIKE '"+cin+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_CO"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("CNSS"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("FISCALE"));

 return model;
}

QSqlQueryModel *commerciale::trierA() // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM commerciale order by Cin_co ");
           q->exec();
           model->setQuery(*q);
           return model;

}

QSqlQueryModel *commerciale::trierB() // m sghir lel kbir
{ QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from commerciale order by Cin_co desc");
                  return model;
}
bool commerciale::rechcin(QString idd)
{
    Recherche(idd);
}
