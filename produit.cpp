#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
produit::produit()
{

}

produit::produit (int id ,QString nom ,int quantite , QDate date_exp )
{ this->id=id ;
    this->nom=nom ;
    this->quantite=quantite ;
this->date_exp=date_exp ;
}
int produit::getid () {return id ;}
QString produit::getnom() {return nom ;}
int produit::getquantite() {return quantite;}
QDate produit::getdate_exp() {return date_exp;}
void produit::setid(int id){this->id=id;}
void produit::setnom(QString nom){this->nom=nom;}
void produit::setquantite (int quantite) {this->quantite=quantite;}
void produit::setdate_exp (QDate date_exp) {this->date_exp=date_exp;}
bool produit::ajouter()

{



    QSqlQuery query;
    query.prepare("INSERT INTO PRODUIT (ID, NOM, QUANTITE , DATE_EXP) "
                  "VALUES (:id, :nom, :quantite, :date_exp )");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite",quantite);
    query.bindValue(":date_exp",date_exp);

    return query.exec();
}
bool produit::supprimer(int id)
{

    QSqlQuery query;
    query.prepare("Delete from PRODUIT where id=:id");
    query.bindValue(":id", id);


    return query.exec();
}





QSqlQueryModel* produit::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel() ;
model->setQuery("SELECT* FROM PRODUIT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date D'expiration"));


       return model ;

}

bool produit::modifier(int id,QString nom,int quantite , QDate date_exp)
{

    QSqlQuery query;
    query.prepare("UPDATE PRODUIT set id=:id, nom=:nom, quantite=:quantite , date_exp=:date_exp  WHERE id=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":quantite",quantite);
    query.bindValue(":date_exp",date_exp);


    return query.exec();
}

QSqlQueryModel* produit::trier_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PRODUIT ORDER BY id");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

        model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXP"));

        return model ;
}

QSqlQueryModel* produit::trier_nom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PRODUIT ORDER BY nom");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

        model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXP"));


        return model ;
}

QSqlQueryModel* produit::trier_date()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * from PRODUIT ORDER BY date_exp");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXP"));



        return model ;
}
QSqlQueryModel* produit::afficher_four_id(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUIT WHERE ID=:id ");
    query.bindValue(":id", id);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXP"));
    return model;
}

bool produit::search_id(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT ID FROM PRODUIT WHERE ID=:id");
    query.bindValue(":id", id);
    query.exec();

    if(query.size()!=id){return false;}
    else return true;
}





// recherhe par nom
QSqlQueryModel* produit::afficher_four_nom(QString nom)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUIT WHERE NOM=:nom ");
    query.bindValue(":nom", nom);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_EXP"));

    return model;
}

bool produit::search_nom(QString nom)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM PRODUIT WHERE NOM=:nom");
    query.bindValue(":nom", nom);
    query.exec();

    if(query.size()!=nom){return false;}
    else return true;
}




