#include "equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
equipement::equipement()
{


}
equipement::equipement (int ide ,QString nome ,int quantitee , QString etate )
{ this->ide=ide ;
    this->nome=nome ;
    this->quantitee=quantitee ;
this->etate=etate ;
}
int equipement::getide () {return ide ;}
QString equipement::getnome() {return nome ;}
int equipement::getquantitee() {return quantitee;}
QString equipement::getetate() {return etate;}
void equipement::setide(int ide){this->ide=ide;}
void equipement::setnome(QString nome){this->nome=nome;}
void equipement::setquantitee (int quantitee) {this->quantitee=quantitee;}
void equipement::setetate (QString etate) {this->etate=etate;}
bool equipement::ajoutere()

{

    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPEMENT (IDE, NOME, QUANTITEE , ETATE) "
                  "VALUES (:ide, :nome, :quantitee, :etate )");
    query.bindValue(":ide", ide);
    query.bindValue(":nome", nome);
    query.bindValue(":quantitee",quantitee);
    query.bindValue(":etate",etate);

    return query.exec();
}
bool equipement::supprimere(int ide)
{

    QSqlQuery query;
    query.prepare("Delete from EQUIPEMENT where ide=:ide");
    query.bindValue(":ide", ide);


    return query.exec();
}




QSqlQueryModel* equipement::affichere()
{
QSqlQueryModel* model=new QSqlQueryModel() ;
model->setQuery("SELECT* FROM EQUIPEMENT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ide"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nome"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantitee"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etate"));


       return model ;

}




bool equipement::modifiere(int ide, QString nome,int quantitee , QString etate )
{

    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENT set ide=:ide, nome=:nome, quantitee=:quantitee , etate=:etate  WHERE ide=:ide");
    query.bindValue(":ide",ide);
    query.bindValue(":nome",nome);
    query.bindValue(":quantitee",quantitee);
    query.bindValue(":etate",etate);


    return query.exec();
}
