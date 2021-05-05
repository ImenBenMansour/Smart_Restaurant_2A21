#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include "Plat_recette/recette.h"
#include "Plat_recette/plat.h"

namespace Ui {
class Welcome;
}

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();

private slots:
    void on_plat_recette_clicked();

    void on_commande_clicked();

    void on_produit_clicked();

    void on_fidelite_clicked();

    void on_RH_clicked();

    void on_events_clicked();

private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
