#include "partenaires.h"

Partenaires::Partenaires()
{

}

Partenaires::Partenaires(int id, QString nom, QString type_partenaire, QString type_partenariat,int idevent)
{this->id=id;
    this->nom=nom;
    this->type_partenaire=type_partenaire;
    this->type_partenariat=type_partenariat;
    this->idEvent=idevent;

}

int Partenaires::getId()
{return this->id;

}

int Partenaires::getIdevent()
{
    return this->idEvent;
}

QString Partenaires::getNom()
{
    return  this->nom;
}

void Partenaires::setIdevent(int idEvent)
{
    this->idEvent=idEvent;
}

QString Partenaires::getTypepartenaire()
{
    return this->type_partenaire;
}

QString Partenaires::getTypepartenariat()
{
    return this->type_partenariat;
}

void Partenaires::setId(int id)
{
    this->id=id;
}

void Partenaires::setNom(QString nom)
{
    this->nom=nom;
}

void Partenaires::setTypepartenaire(QString type_partenaire)
{
    this->type_partenaire=type_partenaire;
}

void Partenaires::setTypepartenariat(QString type_partenariat)
{
    this->type_partenariat=type_partenariat;
}

QSqlQueryModel *Partenaires::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();
       model->setQuery("select p.id,p.nom,p.type_partenaire,p.type_partenariat,c.nom from partenaires p inner join event c on p.idEvent=c.id");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_partenaire"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_partenariat"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("nom"));

       return model;


}

bool Partenaires::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id);
query.prepare("update partenaires set nom=:nom,type_partenaire=:type_partenaire,type_partenariat=:type_partenariat,idEvent=:idEvent where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":type_partenaire",type_partenaire);
    query.bindValue(":type_partenariat",type_partenariat);
    query.bindValue(":idEvent",idEvent);
return query.exec();
}

bool Partenaires::supprimer()
{ QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("Delete from partenaires where id =:id ");
    query.bindValue(":id",res);
    return  query.exec();

}

bool Partenaires::ajouter()
{


    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into partenaires (id,nom,type_partenaire,type_partenariat,idevent) values (:id,:nom,:type_partenaire,:type_partenariat,:idEvent)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":type_partenaire",type_partenaire);
    query.bindValue(":type_partenariat",type_partenariat);
    query.bindValue(":idEvent",idEvent);


    return query.exec();
}

Partenaires Partenaires::afficherR(int id)
{
    QSqlQuery query;
      Partenaires F;
       QString res = QString::number(id);
      query.prepare("select * from partenaires where id ='"+res+"'");
      if(query.exec())
       {if(query.first())
       { F.setId(query.value(0).toInt());
       F.setNom(query.value(1).toString());
       F.setTypepartenaire(query.value(2).toString());
       F.setTypepartenariat(query.value(3).toString());

          }}


      return F;
}

QList<Partenaires> Partenaires::afficherPartenaire()
{
    QList<Partenaires> f;
    QSqlQuery query;
        query.prepare("select p.id,p.nom,p.type_partenaire,p.type_partenariat from partenaires p  ");
        if(query.exec())
         {while(query.next())
            {
                Partenaires F;
          F.setId(query.value(0).toInt());
          F.setNom(query.value(1).toString());
          F.setTypepartenaire(query.value(2).toString());
          F.setTypepartenariat(query.value(3).toString());

          f.append(F);

         }}
        return f;
}

QSqlQueryModel *Partenaires::recherche(QString critere)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select p.id,p.nom,p.type_partenaire,p.type_partenariat,c.nom from partenaires p inner join event c on p.idEvent=c.id WHERE   p.id LIKE '%"+critere+"%' OR p.nom LIKE '%"+critere+"%' OR p.type_partenaire LIKE '%"+critere+"%' OR p.type_partenariat LIKE '%"+critere+"%' OR c.nom LIKE '%"+critere+"%'   ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_partenaire"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_partenariat"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nom"));


    return model;
}

