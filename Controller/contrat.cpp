#include "contrat.h"

contrat::contrat()
{
    nomp="";
    nomm="";
    metierm="";
     metierp="";
     date="";
    cinm=0;
   cinp=0;


}

contrat::contrat(QString np,QString nm,QString mm,QString mp,QString d,int cm,int cp)
{
    nomp=np;
    nomm=nm;
    metierm=mm;
     metierp=mp;
     date=d;
    cinm=cm;
   cinp=cp;


}

bool contrat::ajouterContrat()
{
    QSqlQuery query;
    QString cinm1=QString::number(cinm);
    QString cinp1=QString::number(cinp);
    query.prepare("INSERT INTO TABLE1(cinm,nomprenomm,metierm,nomprenomp,metierp,cinp,datemariage) "
                  "VALUES(:cinm,:nomm,:metierm,:nomp,:metierp,:cinp,:date)");
    query.bindValue(":nomp",nomp);
    query.bindValue(":nomm",nomm);
    query.bindValue(":metierp",metierp);
     query.bindValue(":metierm",metierm);
      query.bindValue(":date",date);
    query.bindValue(":cinm",cinm);
    query.bindValue(":cinp",cinp);
    return query.exec();


}


QSqlQueryModel *contrat::afficherContrat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from TABLE1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cinm"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomm"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("metierm"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nomp"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("metierp"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("cinp"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date"));

       return model;


}


bool contrat::supprimerContrat(int cinm1)
{

    QSqlQuery query;
    QString CIN=QString::number(cinm1);
    query.prepare("Delete from TABLE1  where cinm=:cinm");
    query.bindValue(":cinm",cinm1);
    return query.exec();

}


bool contrat::modifierContrat(int cinm)
{

    QSqlQuery query;
    QString res=QString::number(cinm);
    QString cinp1=QString::number(cinp);
    query.prepare("UPDATE TABLE1 set cinm=:cinm,nomm=:nomprenomm,metierm=:metierm,nomp=:nomprenomp,metierp=:metierp,cinp=:cinp,date=:datemariage where cinm=:cinm ");
    query.bindValue(":nomp",nomp);
    query.bindValue(":nomm",nomm);
    query.bindValue(":metierp",metierp);
     query.bindValue(":metierm",metierm);
      query.bindValue(":date",date);
    query.bindValue(":cinm",cinm);
    query.bindValue(":cinp",cinp1);
      query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * contrat::chercherContrat(int cinm1){

QSqlQuery query;
QSqlQueryModel * model1=new QSqlQueryModel();
QString cinm=QString::number(cinm1);


    model1->setQuery("select * from TABLE1 where cinm LIKE '"+cinm+"' " );
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("cinm"));
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("nomm"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("metierm"));
     model1->setHeaderData(3,Qt::Horizontal,QObject::tr("nomp"));
      model1->setHeaderData(4,Qt::Horizontal,QObject::tr("metierp"));
    model1->setHeaderData(5,Qt::Horizontal,QObject::tr("cinp"));
    model1->setHeaderData(6,Qt::Horizontal,QObject::tr("date"));


    return model1;

}

