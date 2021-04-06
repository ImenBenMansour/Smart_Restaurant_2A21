#include "connection.h"
#include "QSqlDatabase"
connection::connection()
{}
bool connection::createConnection(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
    db.setUserName("feriel");
    db.setPassword("feriel");


    if(db.open())
        test=true;
    return test;



}
