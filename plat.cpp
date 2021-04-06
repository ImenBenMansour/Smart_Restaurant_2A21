#include "plat.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QString>

int Plat::getid_Pl(){return id_Pl;}
QString Plat::getnom_Pl(){return nom_Pl;}
QString Plat::gettype(){return type;}
int Plat::getnb_calories(){return nb_calories;}
int Plat::getprix(){return prix;}


void Plat::setid_Pl(int id_Pl){this->id_Pl=id_Pl;}
void Plat::setnom_Pl(QString nom_Pl){this->nom_Pl=nom_Pl;}
void Plat::settype(QString type){this->type=type;}
void Plat::setnb_calories(int nb_calories){this->nb_calories=nb_calories;}
void Plat::setprix(int prix){this->prix=prix;}
Plat::Plat()
{
}

Plat::Plat(int id_Pl, QString nom_Pl, QString type, int nb_calories, int prix)
{ this->id_Pl=id_Pl; this->nom_Pl=nom_Pl; this->type=type; this->nb_calories=nb_calories; this->prix=prix;
}

bool Plat::ajouter1()
{

        QSqlQuery query;
              query.prepare("INSERT INTO Plat (ID_PL, NOM_PL, TYPE, NB_CALORIES, PRIX) "
                            "VALUES (:id_Pl, :nom_Pl, :type, :nb_calories, :prix)");
              query.bindValue(":id_Pl", id_Pl);
              query.bindValue(":nom_Pl", nom_Pl);
              query.bindValue(":type", type);
              query.bindValue(":nb_calories", nb_calories);
              query.bindValue(":prix", prix);

         return query.exec();

}
QSqlQueryModel* Plat::afficher1()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM Plat");
         model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_Pl"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_Pl"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_calories"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
bool Plat::supprimer1(int id_Pl)
{
    QSqlQuery query;
          query.prepare("Delete from Plat where id_Pl=:id_Pl");
          query.bindValue(":id_Pl", id_Pl);
     return query.exec();
}
bool Plat::modifier1(int id_Pl,QString nom_Pl,QString type,int nb_calories,int prix)
{

    QSqlQuery query;
    query.prepare("UPDATE Plat set id_Pl=:id_Pl, nom_Pl=:nom_Pl, type=:type ,nb_calories=:nb_calories, prix=:prix  WHERE id_Pl=:id_Pl");
    query.bindValue(":id_Pl",id_Pl);
    query.bindValue(":nom_Pl",nom_Pl);
    query.bindValue(":type",type);
    query.bindValue(":nb_calories",nb_calories);
    query.bindValue(":prix",prix);

    return query.exec();
}
QSqlQueryModel* Plat::trier_id_Pl()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from Plat ORDER BY id_Pl");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Pl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_Pl"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_calories"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

        return model ;
}

QSqlQueryModel* Plat::trier_nom_Pl()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from Plat ORDER BY nom_Pl");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Pl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_Pl"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_calories"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
        return model ;
}

QSqlQueryModel* Plat::trier_type()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from Plat ORDER BY type");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_Pl"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_Pl"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_calories"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

        return model ;
}
