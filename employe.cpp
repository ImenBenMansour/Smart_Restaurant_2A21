#include "employe.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE
Employe::Employe()
{

}
Employe::Employe(int id,int age,int salaire,QString nom,QString prenom,QDate date,int idRole)
{
    this->id=id;
    this->age=age;
    this->salaire=salaire;
    this->nom=nom;
    this->prenom=prenom;
    this->date_embauche=date;
    this->idRole=idRole;
}
int Employe:: getId(){return this->id;}
int Employe:: getAge(){return this->age;}
int Employe::getSalaire(){return this->salaire;}
QString Employe::getNom(){return this->nom;}
QString Employe::getPrenom(){return this->prenom;}
QDate Employe::getDate(){return this->date_embauche;}

int Employe::getIdRole(){return this->idRole;}
void Employe::setId(int id){this->id=id;}
void Employe::setAge(int age){this->age=age;}
void Employe::setNom(QString nom){this->nom=nom;}
void Employe::setPrenom(QString prenom){this->prenom=prenom;}
void Employe::setSalaire(int salaire){this->salaire=salaire;}
void Employe::setDate(QDate date){this->date_embauche=date;}
void Employe::setIdRole(int idRole){this->idRole=idRole
                                   ;}
bool Employe::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into employe (id,nom,prenom,age,salaire,date_embauche,idRole) values (:id,:nom,:prenom,:age,:salaire,:date,:idRole)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":age",age);

    query.bindValue(":prenom",prenom);
    query.bindValue(":salaire",salaire);
    query.bindValue(":date",date_embauche);
    query.bindValue(":idRole",idRole);


    return query.exec();
}
bool Employe::modifier()
{  QSqlQuery query;
    QString res = QString::number(id);
query.prepare("update employe set nom=:nom,prenom=:prenom,age=:age,salaire=:salaire,date_embauche=:date,idRole=:idRole where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":age",age);

    query.bindValue(":prenom",prenom);
    query.bindValue(":salaire",salaire);
    query.bindValue(":date",date_embauche);
    query.bindValue(":idRole",idRole);

    return query.exec();


}

bool Employe::supprimer()
{
    QSqlQuery query;
       QString res = QString::number(id);

       query.prepare("Delete from employe where id =:id ");
       query.bindValue(":id",res);
       return  query.exec();
}

void Employe::afficherStat()
{                QPieSeries *series = new QPieSeries();
                 QChart *chart = new QChart();

    QSqlQuery query;
        int id=0;
        query.prepare("select count(e.id) ,r.departement from employe e inner join role r on e.idRole=r.id group by r.departement ");
        if(query.exec())
         {while(query.next())
            {
                 series->append("Jane", 1);
                 series->append("Joe", 2);
                 series->append("Andy", 3);
                 series->append("Barbara", 4);
                 series->append("Axel", 5);
             //![1]

             //![2]
                 QPieSlice *slice = series->slices().at(1);
                 slice->setExploded();
                 slice->setLabelVisible();
                 slice->setPen(QPen(Qt::darkGreen, 2));
                 slice->setBrush(Qt::green);
             //![2]

             //![3]
                 chart->addSeries(series);
                 chart->setTitle("Simple piechart example");
                 chart->legend()->hide();
             //![3]

             //![4]

             //![4]

             //![5]



}
} QChartView *chartView = new QChartView(chart);
                     chartView->setRenderHint(QPainter::Antialiasing);
                                  chartView->show();
}

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select c.id,c.nom,c.prenom,c.age,c.salaire,c.date_embauche,r.description from employe c inner join role r on c.idRole=r.id");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_embauche"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("description"));

    return model;

}
Employe Employe::afficherR(int id)
{

    QSqlQuery query;
      Employe F;
       QString res = QString::number(id);
      query.prepare("select * from employe where id ='"+res+"'");
      if(query.exec())
       {if(query.first())
        F.setId(query.value(0).toInt());
       F.setNom(query.value(1).toString());
       F.setPrenom(query.value(2).toString());
       F.setAge(query.value(3).toInt());
       F.setSalaire(query.value(4).toInt());
       F.setDate(query.value(5).toDate());
       F.setIdRole(query.value(6).toInt());

       }
     return F;
}

QList<Role> Employe::afficherRole()
{
    QList<Role> f;
    QSqlQuery query;
        query.prepare("select id,description from role ");
        if(query.exec())
         {while(query.next())
            {
                Role F;
          F.setId(query.value(0).toInt());
          F.setDescription(query.value(1).toString());
          f.append(F);

         }}
        return f;


}
QSqlQueryModel * Employe::recherche(QString critere)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("select c.id,c.nom,c.prenom,c.age,c.salaire,c.date_embauche,r.description from employe c inner join role r on c.idRole=r.id WHERE  r.description LIKE '%"+critere+"%' OR c.date_embauche LIKE '%"+critere+"%' OR c.nom LIKE '%"+critere+"%' OR prenom LIKE '%"+critere+"%' OR salaire LIKE '%"+critere+"%' OR age LIKE '%"+critere+"%'  ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_embauche"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("description"));

    return model;

}
QSqlQueryModel * Employe::trieAsc( )
{
    QSqlQueryModel * model =new QSqlQueryModel();
        model->setQuery("select c.id,c.nom,c.prenom,c.age,c.salaire,c.date_embauche,r.description from employe c inner join role r on c.idRole=r.id  order by date_embauche asc ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_embauche"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("description"));

        return model;
}
QSqlQueryModel * Employe::trieDesc( )
{
    QSqlQueryModel * model =new QSqlQueryModel();
        model->setQuery("select c.id,c.nom,c.prenom,c.age,c.salaire,c.date_embauche,r.description from employe c inner join role r on c.idRole=r.id  order by date_embauche desc ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_embauche"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("description"));

        return model;
}

QSqlQueryModel *Employe::trieAge()
{
    QSqlQueryModel * model =new QSqlQueryModel();
        model->setQuery("select c.id,c.nom,c.prenom,c.age,c.salaire,c.date_embauche,r.description from employe c inner join role r on c.idRole=r.id  order by age desc ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_embauche"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("description"));

        return model;
}

QSqlQueryModel *Employe::trieSalaire()
{
    QSqlQueryModel * model =new QSqlQueryModel();
        model->setQuery("select c.id,c.nom,c.prenom,c.age,c.salaire,c.date_embauche,r.description from employe c inner join role r on c.idRole=r.id  order by salaire desc ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_embauche"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("description"));

        return model;
}

void Employe::statistique()
{
    QPieSeries *series = new QPieSeries();
              QChart *chart = new QChart();

 QSqlQuery query;
     int id=0;
    /* query.prepare("select count(e.id) ,r.departement from employe e inner join role r on e.idRole=r.id group by r.departement ");
     if(query.exec())
      {while(query.next())
         {*/
              series->append("Jane", 1);
              series->append("Joe", 2);
              series->append("Andy", 3);
              series->append("Barbara", 4);
              series->append("Axel", 5);
          //![1]

          //![2]
              QPieSlice *slice = series->slices().at(1);
              slice->setExploded();
              slice->setLabelVisible();
              slice->setPen(QPen(Qt::darkGreen, 2));
              slice->setBrush(Qt::green);
          //![2]

          //![3]
              chart->addSeries(series);
              chart->setTitle("Simple piechart example");
              chart->legend()->hide();
          //![3]

          //![4]

          //![4]

          //![5]



/*}
} */QChartView *chartView = new QChartView(chart);
                  chartView->setRenderHint(QPainter::Antialiasing);
                               chartView->show();
}
