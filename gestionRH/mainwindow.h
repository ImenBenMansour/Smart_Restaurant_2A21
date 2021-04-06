#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <role.h>
#include<employe.h>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_roles_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_ajouter_clicked();

    void on_role_currentIndexChanged(int index);

    void on_modifier_clicked();

    void on_employes_activated(const QModelIndex &index);

    void on_supprimer_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_trie_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_stat_clicked();

    void on_pushButto_clicked(bool checked);

    void on_pushButto_clicked();

    void on_statistqie_clicked();

private:
    Ui::MainWindow *ui;
    Role r;
    int idRole;
    QString dep;
    Employe e;
};
#endif // MAINWINDOW_H
