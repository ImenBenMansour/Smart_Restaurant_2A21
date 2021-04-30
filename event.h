#ifndef EVENT_H
#define EVENT_H
#include  <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Event
{
public:
    Event();
    Event(int,QString,QString);
    int getId();
    QString getNom();
    QString getType();
    void setId(int);
    void setNom(QString);
    void setType(QString);
    QSqlQueryModel * afficher();
    bool modifier();
    bool supprimer();
    bool ajouter();
    Event afficherR(int);
    QList<Event> afficherRole();
    int recupererID(QString);
    QSqlQueryModel * trieAsc(QString critere);
    QSqlQueryModel * trieDesc(QString critere);


private :
    int id;
    QString nom,type;

};

#endif // EVENT_H
