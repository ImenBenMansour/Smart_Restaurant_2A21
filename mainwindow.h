#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "recette.h"
#include "plat.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pb_ajouter_Re_clicked();

    void on_pb_ajouter_Pl_clicked();

    void on_pb_sup_Re_clicked();

    void on_pb_modifier_Re_clicked();

    void on_pb_sup_Pl_clicked();

    void on_pb_modif_Pl_clicked();

private:
    Ui::MainWindow *ui;
    Recette R;
    Plat P;
};

#endif // MAINWINDOW_H
