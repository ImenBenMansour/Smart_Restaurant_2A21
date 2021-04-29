#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase> /* connexion a la base */
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
