#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<event.h>
#include<partenaires.h>
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

    void on_pushButton_3_clicked();

    void on_events_activated(const QModelIndex &index);

    void on_partenaires_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Event e;
    Partenaires p;
};
#endif // MAINWINDOW_H
