#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}

void Notification::notification_ajoutProduit() {

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire de stockage  "," produit ajoutée ",QSystemTrayIcon::Information,15000);
}
void Notification::notification_ajoutEquipement()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire de stockage  ","equipement ajoutée ",QSystemTrayIcon::Information,15000);
}
void Notification::notification_supprimerProduit(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire de stockage  ","produit Supprimé",QSystemTrayIcon::Information,15000);
}
void Notification::notification_supprimerEquipement(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire de stockage  ","equipement supprimé",QSystemTrayIcon::Information,15000);

}
void Notification::notification_modifierProduit(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire de stockage  "," produit modifié",QSystemTrayIcon::Information,15000);

}
void Notification::notification_modifierEquipement(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire de stockage  ","equipement modifié",QSystemTrayIcon::Information,15000);

}
