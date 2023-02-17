#include "citoyent.h"
#include <QDebug>


citoyent::citoyent()
{
    Cin=0;
    age=0;
    numTelph=0;
    codePostale=0;
    nom=" ";
    prenom=" ";
    dateNaissance=" ";
    lieu=" ";
    sexe=" ";
    mail=" ";
    profession=" ";
    ville=" ";
    adresse=" ";
}

bool citoyent::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from CITOYENT ");

  return query.exec();
}

citoyent::citoyent(int c,int a,int nT,int cP,QString n,QString p,QString dN,QString l,QString s,QString m,QString pr,QString v,QString Adr)
{
    this->Cin=c;
    this->age=a;
    this->numTelph=nT;
    this->codePostale=cP;
    this->nom=n;
    this->prenom=p;
    this->dateNaissance=dN;
    this->lieu=l;
    this->sexe=s;
    this->mail=m;
    this->profession=pr;
    this->ville=v;
    this->adresse=Adr;

}

bool citoyent ::ajouter_citoyent()
{
    QSqlQuery query;
    QString CINS= QString::number(Cin);
    query.prepare("INSERT INTO CITOYENT(CIN,NOM,PRENOM,DATE_NAISSANCE,LIEU,AGE,SEXE,NUM_TELPH,MAIL,PROFESSION,VILLE,ADRESSE,CODE_POSTALE) "
                  "VALUES (:Cin, :nom,:prenom,:dateNaissance,:lieu,:age,:sexe,:numTelph,:mail,:profession,:ville,:adresse,:codePostale)");
    query.bindValue(":Cin", CINS);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateNaissance", dateNaissance);
    query.bindValue(":lieu", lieu);
    query.bindValue(":age", age);
    query.bindValue(":sexe", sexe);
    query.bindValue(":numTelph", numTelph);
    query.bindValue(":mail", mail);
    query.bindValue(":profession", profession);
    query.bindValue(":ville", ville);
    query.bindValue(":adresse", adresse);
    query.bindValue(":codePostale", codePostale);
    return    query.exec();
}

QSqlQueryModel * citoyent ::afficher_citoyent()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from citoyent");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("NUM_TELPH"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("PROFESSION"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("VILLE"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("CODE_POSTALE"));

    return model;
}

bool citoyent :: supprimer_citoyent(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from citoyent where CIN = :id");
    query.bindValue(":id",res);
    return query.exec();

}

bool citoyent::modifier_citoyent(int Cin)
{
    QSqlQuery query;
    QString CINS= QString::number(Cin);
    query.prepare("Update citoyent set CIN =:Cin , NOM = :nom , PRENOM = :prenom , DATE_NAISSANCE = :dateNaissance , LIEU = :lieu , AGE = :age , SEXE = :sexe , NUM_TELPH = :numTelph , MAIL = :mail , PROFESSION = :profession , VILLE = :ville , ADRESSE = :adresse , CODE_POSTALE = :codePostale  where CIN = :Cin ");


    //query.prepare("Update commerciale set CIN = :cin , NOM = :cnss , FISCALE = :fiscale , SECTEUR_DACTIVITE = :secteur_dactivite    ");

    query.bindValue(":id", CINS);
    query.bindValue(":Cin", Cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateNaissance", dateNaissance);
    query.bindValue(":lieu", lieu);
    query.bindValue(":age", age);
    query.bindValue(":sexe", sexe);
    query.bindValue(":numTelph", numTelph);
    query.bindValue(":mail", mail);
    query.bindValue(":profession", profession);
    query.bindValue(":ville", ville);
    query.bindValue(":adresse", adresse);
    query.bindValue(":codePostale", codePostale);

    return    query.exec();
}

QSqlQueryModel* citoyent::Recherche(QString cin)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from citoyent where Cin LIKE '"+cin+"%' or nom LIKE '"+cin+"%' or prenom LIKE '"+cin+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

 return model;
}

QSqlQueryModel *citoyent::trierA() // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM citoyent order by age ASC");
           q->exec();
           model->setQuery(*q);
           return model;

}

QSqlQueryModel *citoyent::trierB() // m sghir lel kbir
{
           QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM citoyent order by age DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;
}
QSqlQueryModel *citoyent::trierA_Z() // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM citoyent order by nom ");
           q->exec();
           model->setQuery(*q);
           return model;

}

QSqlQueryModel *citoyent::trierZ_A() // m sghir lel kbir
{
           QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM citoyent order by nom DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;
}

QString citoyent :: get_nom() { return nom; }
QString citoyent :: get_prenom() { return prenom; }
QString citoyent :: get_dateNaissance() { return dateNaissance; }
QString citoyent :: get_lieu() { return lieu; }
QString citoyent :: get_sexe() { return sexe; }
QString citoyent :: get_mail() { return mail; }
QString citoyent :: get_profession() { return profession; }
QString citoyent :: get_ville() { return ville; }
QString citoyent :: get_adresse() { return adresse; }

