#include "recette.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QString>


int Recette::getid_Re(){return id_Re;}
QString Recette::getnom_Re(){return nom_Re;}
QString Recette::getingredients(){return ingredients;}
QString Recette::getorigine(){return origine;}

void Recette::setid_Re(int id_Re){this->id_Re=id_Re;}
void Recette::setnom_Re(QString nom_Re){this->nom_Re=nom_Re;}
void Recette::setingredients(QString ingredients){this->ingredients=ingredients;}
void Recette::setorigine(QString origine){this->origine=origine;}
Recette::Recette()
{
}

Recette::Recette(int id_Re, QString nom_Re, QString ingredients, QString origine)
{ this->id_Re=id_Re; this->nom_Re=nom_Re; this->ingredients=ingredients; this->origine=origine;
}

bool Recette::ajouter()
{

        QSqlQuery query;
              query.prepare("INSERT INTO Recette (ID_RE, NOM_RE, INGREDIENTS, ORIGINE) "
                            "VALUES (:id_Re, :nom_Re, :ingredients, :origine)");
              query.bindValue(":id_Re", id_Re);
              query.bindValue(":nom_Re", nom_Re);
              query.bindValue(":ingredients", ingredients);
              query.bindValue(":origine", origine);

         return query.exec();

}
QSqlQueryModel* Recette::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM Recette");
         model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_Re"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_Re"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ingrédients"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Origine"));


    return model;
}
bool Recette::supprimer(int id_Re)
{
    QSqlQuery query;
          query.prepare("Delete from Recette where id_Re=:id_Re");
          query.bindValue(":id_Re", id_Re);
     return query.exec();
}
bool Recette::modifier(int id_Re,QString nom_Re,QString ingredients,QString origine)
{

    QSqlQuery query;
    query.prepare("UPDATE Recette set id_Re=:id_Re, nom_Re=:nom_Re, ingredients=:ingredients ,origine=:origine  WHERE id_Re=:id_Re");
    query.bindValue(":id_Re",id_Re);
    query.bindValue(":nom_Re",nom_Re);
    query.bindValue(":ingredients",ingredients);
    query.bindValue(":origine",origine);

    return query.exec();
}
