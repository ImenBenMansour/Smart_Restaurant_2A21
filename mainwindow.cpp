#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "recette.h"
#include <QMessageBox>
#include <QIntValidator>
#include "plat.h"

MainWindow::MainWindow(QWidget *parent)
 :QMainWindow(parent),
   ui(new Ui::MainWindow)

{ ui->setupUi(this);
ui->tabrecette->setModel(R.afficher());
ui->le_id_Re->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->tabplat->setModel(P.afficher1());
ui->le_id_Pl->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));}
MainWindow::~MainWindow()

{ delete ui; }


void MainWindow::on_pb_ajouter_Re_clicked()
{    Recette R(ui->le_id_Re->text().toInt(),ui->le_nom_Re->text(),ui->les_ingredients_Re->text(),ui->la_origine_Re->text());
    int id_Re=ui->le_id_Re->text().toInt();
  QString nom_Re=ui->le_nom_Re->text();
  QString ingredients=ui->les_ingredients_Re->text();
  QString origine=ui->la_origine_Re->text();
   bool test=R.ajouter();
          if(id_Re==0 ||nom_Re==""||ingredients==""||origine=="")
          { QMessageBox::critical(nullptr, QObject::tr("vide"),
                                           QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
          }
          else if (test==true){
              QMessageBox::information(nullptr,QObject::tr("database is open"),
                                       QObject::tr("recette ajouté: \n" "click ok to exit"), QMessageBox::Ok);
              ui->tabrecette->setModel(R.afficher());

          }

          else{

       QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("recette existe déjà:\n"
            "click ok to exit"),QMessageBox::Ok);}

            R.ajouter();
}

void MainWindow::on_pb_sup_Re_clicked()
{
    Recette R1;
         R1.setid_Re(ui->le_id_sup_Re->text().toInt());
         int id_Re=ui->le_id_sup_Re->text().toInt();
         bool test1=R1.supprimer(R1.getid_Re());

         if (id_Re==0)
            {
             QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                     QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

                 }



                 else if(test1==true)
                    {QMessageBox::information(nullptr,QObject::tr("datavase is open"),
                                              QObject::tr("recette supprimée:\n"
                      "click ok to exit"),QMessageBox::Ok);
                  ui->tabrecette->setModel(R.afficher());
                 }
                    else
                 {QMessageBox::critical(nullptr,QObject::tr("database is open"),
                                           QObject::tr("recette non supprimée:\n"
                        "click ok to exit"),QMessageBox::Ok);}
                R.supprimer(R.getid_Re());

}

void MainWindow::on_pb_modifier_Re_clicked()
{
    Recette R2;
        R2.setid_Re(ui->le_id_modif_Re->text().toInt());
            R2.setnom_Re(ui->le_nom_modif_Re->text());
            R2.setingredients(ui->les_ingredients_modiff->text());
            R2.setorigine(ui->la_origine_modiff->text());

           R2.modifier(R2.getid_Re(),R2.getnom_Re(),R2.getingredients(),R2.getorigine());
           int id_Re= ui->le_id_modif_Re->text().toInt();
           QString nom_Re= ui->le_nom_modif_Re->text();
           if(id_Re==0||nom_Re=="")
                {
                   QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                    QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

                }

           else {
               QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("recette modifié:\n"
            "click ok to exit"),QMessageBox::Ok);
               ui->tabrecette->setModel(R.afficher());

           }
}


void MainWindow::on_pb_ajouter_Pl_clicked()
{

    Plat P(ui->le_id_Pl->text().toInt(),ui->le_nom_Pl->text(),ui->le_type->text(),ui->le_nb_calories->text().toInt(),ui->le_prix->text().toInt());
        int id_Pl=ui->le_id_Pl->text().toInt();
      QString nom_Pl=ui->le_nom_Pl->text();
      QString type=ui->le_type->text();
      int nb_calories=ui->le_nb_calories->text().toInt();
      int prix=ui->le_prix->text().toInt();
       bool test=P.ajouter1();
              if(id_Pl==0 ||nom_Pl==""||type==""||nb_calories==0||prix==0)
              { QMessageBox::critical(nullptr, QObject::tr("vide"),
                                               QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
              }
              else if (test==true){
                  QMessageBox::information(nullptr,QObject::tr("database is open"),
                                           QObject::tr("plat ajouté: \n" "click ok to exit"), QMessageBox::Ok);
                  ui->tabplat->setModel(P.afficher1());
              }

              else{

           QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("plat existe déjà:\n"
                "click ok to exit"),QMessageBox::Ok);}

                P.ajouter1();
}

void MainWindow::on_pb_sup_Pl_clicked()
{
    Plat P1;
         P1.setid_Pl(ui->le_id_sup_Pl->text().toInt());
         int id_Pl=ui->le_id_sup_Pl->text().toInt();
         bool test1=P1.supprimer1(P1.getid_Pl());

         if (id_Pl==0)
            {
             QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                     QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

                 }



                 else if(test1==true)
                    {QMessageBox::information(nullptr,QObject::tr("datavase is open"),
                                              QObject::tr("plat supprimée:\n"
                      "click ok to exit"),QMessageBox::Ok);
                  ui->tabplat->setModel(P.afficher1());
                 }
                    else
                 {QMessageBox::critical(nullptr,QObject::tr("database is open"),
                                           QObject::tr("plat non supprimée:\n"
                        "click ok to exit"),QMessageBox::Ok);}
                P.supprimer1(P.getid_Pl());

}

void MainWindow::on_pb_modif_Pl_clicked()
{
    Plat P2;
        P2.setid_Pl(ui->le_id_modif_Pl->text().toInt());
            P2.setnom_Pl(ui->le_nom_modif_Pl->text());
            P2.settype(ui->le_type_modif->text());
            P2.setnb_calories(ui->le_nb_calories_modif->text().toInt());
            P2.setprix(ui->le_prix_modif->text().toInt());


           P2.modifier1(P2.getid_Pl(),P2.getnom_Pl(),P2.gettype(),P2.getnb_calories(),P2.getprix());
           int id_Pl=ui->le_id_modif_Pl->text().toInt();
           QString nom_Pl=ui->le_nom_modif_Pl->text();
           if(id_Pl==0||nom_Pl=="")
                {
                   QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                    QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

                }

           else {
               QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("plat modifié:\n"
            "click ok to exit"),QMessageBox::Ok);
               ui->tabplat->setModel(P.afficher1());

           }
}
