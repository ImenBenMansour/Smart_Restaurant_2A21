#ifndef commande_H
#define  commande_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

class  commande
{
public:
     commande();
     commande(int,QString,QString,int);
    int getid();
    QString getadresse();
    QString getplat();
    int getprix();
    void setid(int);
    void setadresse(QString);
    void setplat(QString);
    void setprix(int);
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprimer(int);
    bool modifier(int,QString,QString,int);
private:
    int id,prix;
    QString adresse,plat;

};

#endif //  commande_H
