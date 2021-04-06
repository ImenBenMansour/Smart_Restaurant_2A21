#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reservation.h"
#include "commande.h"
#include <QMainWindow>
#include <QDialog>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QNetworkAccessManager>
#include <QNetworkReply>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_S_clicked();

    void on_pushButton_modif_clicked();

    void on_pushButton2_ajouter_clicked();

    void on_pushButton_S2_clicked();

    void on_pushButton_modif2_clicked();


    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_S_2_clicked();

    void on_pushButton_modif_2_clicked();

    void on_envoyer_clicked();

    void on_Tri_IdE_clicked();

    void on_Tri_Taille_clicked();

    void on_Tri_Poid_clicked();

    void on_Psearch_5_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    reservation r;
    commande c;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
};

#endif // MAINWINDOW_H
