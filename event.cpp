#include "event.h"

Event::Event()
{

}

Event::Event(int id, QString nom , QString type)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
}

int Event::getId()
{
    return this->id;
}

QString Event::getNom()
{
    return this->nom;
}

QString Event::getType()
{
    return this->type;
}

void Event::setId(int id)
{
    this->id=id;
}

void Event::setNom(QString nom)
{
    this->nom=nom;
}

void Event::setType(QString type)
{this->type=type;

}

QSqlQueryModel *Event::afficher()
{   QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select * from event");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));

    return model;

}

bool Event::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id);
query.prepare("update event set nom=:nom,type=:type where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":nom",nom);

    return query.exec();
}

bool Event::supprimer()
{ QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("Delete from event where id =:id ");
    query.bindValue(":id",res);
    return  query.exec();

}

bool Event::ajouter()
{


    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into event (id,nom,type) values (:id,:nom,:type)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);

    return query.exec();
}

Event Event::afficherR(int id)
{
    QSqlQuery query;
      Event F;
       QString res = QString::number(id);
      query.prepare("select * from event where id ='"+res+"'");
      if(query.exec())
       {if(query.first())
        F.setId(query.value(0).toInt());
       F.setNom(query.value(1).toString());
       F.setType(query.value(2).toString());

       }


      return F;
}



QList<Event> Event::afficherRole()
{
    QList<Event> f;
    QSqlQuery query;
        query.prepare("select id,nom from event ");
        if(query.exec())
         {while(query.next())
            {
                Event F;
          F.setId(query.value(0).toInt());
          F.setNom(query.value(1).toString());
          f.append(F);

         }}
        return f;

}

int Event::recupererID(QString nom)
{  QSqlQuery query;
    int id=0;
    query.prepare("select * from event where nom='"+nom+"'");
    if(query.exec())
     {if(query.first())
        {id=query.value(0).toInt();

     }}
    return id;


}

QSqlQueryModel *Event::trieAsc(QString critere)
{  QSqlQueryModel * model =new QSqlQueryModel();
    if(critere=="type")
    {
      model->setQuery("select * from event order by type asc");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
}
    else if(critere=="nom")
    {  model->setQuery("select * from event order by nom asc");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));}
    else
    {  model->setQuery("select * from event order by id asc");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));}

    return model;

}

QSqlQueryModel *Event::trieDesc(QString critere)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    if(critere=="type")
    {
      model->setQuery("select * from event order by type desc");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
}
    else if(critere=="nom")
    {  model->setQuery("select * from event order by nom desc");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));}
    else    {  model->setQuery("select * from event order by id desc");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));}
      return model;
}

