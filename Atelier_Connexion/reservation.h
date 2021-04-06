#ifndef reservation_H
#define reservation_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class reservation
{
public:
    reservation();
    reservation(int,int,int);
    int getnum();
    int getheure();
    int getnbrp();
    void setnum(int);
    void setheure(int);
    void setnbrp(int);
    bool Ajouter();
    QSqlQueryModel* afficher();
      QSqlQueryModel* afficher_num();
        QSqlQueryModel* afficher_nbrp();
          QSqlQueryModel* afficher_heure();
    bool Supprimer(int);
    bool modifier();
private:
    int num,heure,nbrp;

};

#endif // reservation_H
