#ifndef PARTENAIRES_H
#define PARTENAIRES_H
#include  <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Partenaires
{
public:
    Partenaires();
    Partenaires(int,QString,QString,QString,int);
    int getId();
    int getIdevent();
    QString getNom();
    void setIdevent(int);
    QString getTypepartenaire();
    QString getTypepartenariat();
    void setId(int);
    void setNom(QString);
    void setTypepartenaire(QString);
    void setTypepartenariat(QString);
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer();
    bool ajouter();
    Partenaires afficherR(int);
    QList<Partenaires> afficherPartenaire();
    QSqlQueryModel * recherche(QString critere);

private :
    int id,idEvent;
    QString nom,type_partenaire,type_partenariat;
};

#endif // PARTENAIRES_H
