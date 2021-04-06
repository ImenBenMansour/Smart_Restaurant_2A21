#ifndef PLAT_H
#define PLAT_H
#include <QString>
#include <QSqlQueryModel>
#include <QApplication>

class Plat
{
public:
    Plat();
    Plat(int id_Pl, QString nom_Pl, QString type, int nb_calories, int prix);

    int getid_Pl();
    QString getnom_Pl();
    QString gettype();
    int getnb_calories();
    int getprix();

    void setid_Pl(int);
    void setnom_Pl(QString);
    void settype(QString);
    void setnb_calories(int);
    void setprix(int);

    bool ajouter1();
    QSqlQueryModel* afficher1();
    bool supprimer1(int);
    bool modifier1(int,QString,QString,int,int);

         QSqlQueryModel* trier_id_Pl();
         QSqlQueryModel* trier_nom_Pl();
         QSqlQueryModel* trier_type();

          QSqlQueryModel* afficher_id_Pl(QString);
           bool search_id_Pl(QString);

           QSqlQueryModel* afficher_nom_Pl(QString);
           bool search_nom_Pl(QString);

           QSqlQueryModel* afficher_type(QString);
           bool search_type(QString);

private:
    int id_Pl;
    QString nom_Pl, type;
    int nb_calories, prix ;
};

#endif // PLAT_H
