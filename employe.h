#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<role.h>

class Employe
{
public:
    Employe();
    Employe(int,int,int,QString,QString,QDate,int);
    /***getter***/
    int getId();
    int getAge();
    int getSalaire();
    int getIdRole();
    QString getNom();
    QString getPrenom();
    QDate getDate();



    /***setter**/
    void setId(int);
    void setAge(int);
    void setSalaire(int);
    void setNom(QString);
    void setPrenom(QString);
    void setDate(QDate);
    void setIdRole(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString critere);
    QSqlQueryModel * trieAsc();
    QSqlQueryModel * trieDesc();
  QSqlQueryModel * trieAge();
    QSqlQueryModel * trieSalaire();
    void statistique();
        Employe afficherR(int);
        QList<Role> afficherRole();
    bool modifier();
    bool supprimer();
    void afficherStat();
private :
    int id,age,salaire,idRole;
    QString nom,prenom;
    QDate date_embauche;


};

#endif // EMPLOYE_H
