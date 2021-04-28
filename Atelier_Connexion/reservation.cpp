#include "reservation.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>

reservation::reservation()
{
num=0;
heure=0;
nbrp=0;
}
reservation::reservation(int num,int heure,int nbrp)
{
    this->num=num; this->heure=heure;
    this->nbrp=nbrp;
}
int reservation::getnum()
{
    return num;
}
int reservation:: getheure()
{
    return heure;
}
int reservation::getnbrp()
{
    return nbrp;
}
void reservation::setnum(int num)
{
    this->num=num;
}
void reservation::setheure(int heure)
{
    this->heure=heure;
}
void reservation::setnbrp(int nbrp)
{
    this->nbrp=nbrp;

}
 bool reservation::Ajouter()
 {

     QSqlQuery query;
     QString num_string=QString::number(num);
          query.prepare("INSERT INTO reservations (num,heure, nbrp) "
                        "VALUES (:num,:heure,:nbrp)");
          query.bindValue(":num",num);
          query.bindValue(":heure",heure);
          query.bindValue(":nbrp", nbrp);
       return query.exec();

 }
 QSqlQueryModel *reservation::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM reservations");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("heure"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbrp"));
         return model;
 }
bool reservation::Supprimer(int num)
{
    QSqlQuery query;
         query.prepare("delete from reservations where num=:num");
         query.bindValue(0, num);
      return query.exec();
}


bool reservation::modifier()
{

QSqlQuery query;

QString num_string=QString::number(num);
QString heure_string=QString::number(heure);
QString nbrp_string=QString::number(nbrp);


query.prepare("UPDATE set reservations heure=12,nbrp=14 WHERE num=2");

query.bindValue(":num",num_string);
     query.bindValue(":heure",heure_string);
     query.bindValue(":nbrp",nbrp_string);

return    query.exec();
}
QSqlQueryModel *reservation::afficher_num()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM reservations ORDER BY num");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("heure"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbrp"));
        return model;
}
QSqlQueryModel *reservation::afficher_nbrp()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM reservations ORDER BY nbrp");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("heure"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbrp"));
        return model;
}
QSqlQueryModel *reservation::afficher_heure()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM reservations ORDER BY heure");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("heure"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbrp"));
        return model;
}
