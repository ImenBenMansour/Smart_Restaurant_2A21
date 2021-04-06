#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "equipement.h"
#include <QMainWindow>
#include<QApplication>
#include"produit.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_mod_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

    void on_pb_suppeq_clicked();

    void on_pushButton_2_clicked();

    void on_pb_modifierequipement_clicked();

    void on_pb_rechid_clicked();

    void on_pb_rechnom_clicked();

private:
    Ui::MainWindow *ui;
     produit P ;
     equipement E ;
};
#endif // MAINWINDOW_H
