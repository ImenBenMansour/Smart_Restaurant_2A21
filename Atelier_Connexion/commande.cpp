#include "commande.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
commande::commande()
{
id=0;
adresse="";
plat="";
prix=0;
}
commande::commande(int id,QString adresse, QString plat,int prix)
{
    this->id=id; this->adresse=adresse;
    this->plat=plat; this->prix=prix;
}
int commande::getid()
{
    return id;
}
QString commande:: getadresse()
{
    return adresse;
}
QString commande::getplat()
{
    return plat;
}
int commande::getprix()
{
    return prix;
}
void commande::setid(int id)
{
    this->id=id;
}
void commande::setadresse(QString adresse)
{
    this-> adresse= adresse;
}
void commande::setplat(QString plat)
{
    this-> plat= plat;

}
void commande::setprix(int prix)
{
    this->prix=prix;
}
 bool commande::Ajouter()
 {

     QSqlQuery query;
     QString id_string=QString::number(id);

          query.prepare("INSERT INTO commandes (id,adresse,plat,prix) "
                        "VALUES (:id,:adresse,:plat,:prix)");
          query.bindValue(":id",id);
          query.bindValue(":adresse",adresse);
          query.bindValue(":plat",plat);
          query.bindValue(":prix",prix);
       return query.exec();

 }
 QSqlQueryModel *commande::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM commandes");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("plat"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
         return model;
}
bool commande::Supprimer(int id)
{
    QSqlQuery query;
         query.prepare("delete from commandes where id=:id");
         query.bindValue(0, id);
      return query.exec();
}

bool commande::modifier(int id,QString adresse,QString plat,int prix)
{

QSqlQuery query;

QString id_string=QString::number(id);

QString prix_string=QString::number(prix);

query.prepare("UPDATE suivi commandes id=:id,adresse=:adresse,plat=:plat,prix=:prix WHERE id=:id;");

query.bindValue(":id",id);
     query.bindValue(":adresse",adresse);
     query.bindValue(":plat",plat);
     query.bindValue(":prix",prix_string);

return    query.exec();
}


