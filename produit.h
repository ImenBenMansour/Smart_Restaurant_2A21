#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class produit
{
public:
    produit();
  produit (int,QString,int,QDate);
  int getid () ;
  QString getnom() ;
  int getquantite () ;
  QDate getdate_exp () ;

  void setid(int) ;
  void setnom(QString) ;
  void setquantite (int) ;
  void setdate_exp (QDate) ;
  bool ajouter () ;
  QSqlQueryModel* afficher();
  bool supprimer (int) ;
  bool modifier(int,QString,int,QDate);
  QSqlQueryModel* trier_id();
  QSqlQueryModel* trier_nom();
  QSqlQueryModel* trier_date();


  QSqlQueryModel* afficher_four_id(QString);
  bool search_id(QString);

  QSqlQueryModel* afficher_four_nom(QString);
  bool search_nom(QString);




private:
  int id ;
  QString nom ;
  int quantite ;
  QDate date_exp ;
};

#endif // PRODUIT_H
