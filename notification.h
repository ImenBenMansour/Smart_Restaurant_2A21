#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include<QString>
class Notification
{
public:
    Notification();
    void notification_ajoutProduit();
    void notification_ajoutEquipement();
    void notification_supprimerProduit();
    void notification_supprimerEquipement();
    void notification_modifierProduit();
    void notification_modifierEquipement();







};

#endif // NOTIFICATION_H
