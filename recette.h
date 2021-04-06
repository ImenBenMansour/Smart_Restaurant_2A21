#ifndef RECETTE_H
#define RECETTE_H
#include <QString>
#include <QSqlQueryModel>
#include <QApplication>


class Recette
{
public:
    Recette ();
    Recette(int id_Re, QString nom_Re, QString ingredients, QString origine);

    int getid_Re();
    QString getnom_Re();
    QString getingredients();
    QString getorigine();

    void setid_Re(int);
    void setnom_Re(QString);
    void setingredients(QString);
    void setorigine(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString);



private:
    int id_Re;
    QString nom_Re, ingredients, origine;

};

#endif // RECETTE_H
