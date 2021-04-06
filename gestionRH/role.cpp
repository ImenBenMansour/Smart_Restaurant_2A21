#include "role.h"

Role::Role()
{

}
Role::Role(int id,QString description,QString departement)
{this->id=id;
    this->description=description;
    this->departement=departement;

}
int Role::getId(){return this->id;}
QString Role::getDescription(){return this->description;}
QString Role::getDepartement(){return this->departement;}
void Role::setId(int id){this->id=id;}
void Role::setDescription(QString description){this->description=description;}
void Role::setDepartement(QString departement){this->departement=departement;}
/**crud**/
bool Role::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into role (id,description,departement) values (:id,:description,:departement)");
    query.bindValue(":id",res);
    query.bindValue(":description",description);
    query.bindValue(":departement",departement);

    return query.exec();
}

bool Role::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id);
query.prepare("update role set description=:description,departement=:departement where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":description",description);
    query.bindValue(":departement",departement);

    return query.exec();

}
bool Role::supprimer()
{    QSqlQuery query;
     QString res = QString::number(id);

     query.prepare("Delete from role where id =:id ");
     query.bindValue(":id",res);
     return  query.exec();
}

  QSqlQueryModel * Role::afficher()
  {
      QSqlQueryModel * model =new QSqlQueryModel();
      model->setQuery("select * from role");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("description"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("departement"));

      return model;

  }
Role Role::afficherR(int id)
{
    QSqlQuery query;
      Role F;
       QString res = QString::number(id);
      query.prepare("select * from role where id ='"+res+"'");
      if(query.exec())
       {if(query.first())
        F.setId(query.value(0).toInt());
       F.setDescription(query.value(1).toString());
       F.setDepartement(query.value(2).toString());

       }


     return F;
}
int Role::recupererID(QString nom)
{
    QSqlQuery query;
        int id=0;
        query.prepare("select * from role where description='"+nom+"'");
        if(query.exec())
         {if(query.first())
            {id=query.value(0).toInt();

         }}
        return id;

}
