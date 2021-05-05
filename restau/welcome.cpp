#include "welcome.h"
#include "ui_welcome.h"
#include "Plat_recette/recette.h"
#include <QMessageBox>
#include <QIntValidator>
#include "Plat_recette/plat.h"
#include <QApplication>
#include <QSqlQuery>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include "Plat_recette/palt_recette.h"
#include "Reservation/reservation_commande.h"
#include "Produit_equipement/produit_equipement.h"
#include "Fidelite/abonne.h"
#include "RH/rh.h"
#include "Event/gestionevent.h"
#include <QMediaPlayer>
Welcome::Welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Welcome)
{


    ui->setupUi(this);
        this->setWindowTitle("Accueil");
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_plat_recette_clicked()
{

    Palt_recette *w = new Palt_recette;

   hide();
   w->show();
}

void Welcome::on_commande_clicked()
{
    Reservation_commande *w = new Reservation_commande;
   hide();
   w->show();
}

void Welcome::on_produit_clicked()
{
    Produit_equipement *w = new Produit_equipement;
   hide();
   w->show();
}

void Welcome::on_fidelite_clicked()
{
    abonne *w = new abonne;
   hide();
   w->show();
}

void Welcome::on_RH_clicked()
{
    RH *w = new RH;
   hide();
   w->show();
}

void Welcome::on_events_clicked()
{
    GestionEvent *w = new GestionEvent;
   hide();
   w->show();
}
