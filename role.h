#ifndef ROLE_H
#define ROLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Role
{
public:
    Role();
    Role(int,QString,QString);
    /**************/
    int getId();
    QString getDescription();
    QString getDepartement();
    void setId(int);
    void setDescription(QString);
    void setDepartement(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer();
    Role afficherR(int);
    int recupererID(QString);
 private:
    int id;
    QString description,departement;

};

#endif // ROLE_H
