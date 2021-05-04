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

    void on_rb_tid_clicked();

    void on_rb_tn_clicked();

    void on_rb_tt_clicked();

    void on_pb_pdf_clicked();

    void on_le_id_sup_Re_textChanged(const QString &arg1);

    void on_le_id_modif_Re_textChanged(const QString &arg1);

    void on_le_id_sup_Pl_textChanged(const QString &arg1);

    void on_le_id_modif_Pl_textChanged(const QString &arg1);

    void on_pb_rid_clicked();

    void on_pb_rn_clicked();

    void on_pb_rt_clicked();

private:
    Ui::MainWindow *ui;
    Recette R;
    Plat P;
};

#endif // MAINWINDOW_H
