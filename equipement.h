#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
class equipement
{
public:
    equipement();
  equipement (int,QString,int,QString);
  int getide () ;
  QString getnome() ;
  int getquantitee () ;
  QString getetate () ;

  void setide(int) ;
  void setnome(QString) ;
  void setquantitee (int) ;
  void setetate (QString) ;
  bool ajoutere () ;
  QSqlQueryModel* affichere();
  bool supprimere (int) ;
  bool modifiere(int,QString,int,QString);


private:
  int ide ;
  QString nome ;
  int quantitee ;
  QString etate ;
};

#endif
