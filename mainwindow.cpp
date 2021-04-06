#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include "equipement.h"
#include<QMessageBox>
#include  <QSqlQuery>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
     ui->le_ide->setValidator( new QIntValidator(0, 9999999, this));
     ui->le_quantitee->setValidator( new QIntValidator(0, 9999, this));
    ui->la_quantite->setValidator( new QIntValidator(0, 9999, this));
     ui->tab_produit->setModel(P.afficher());
     ui->tab_equipement->setModel(E.affichere());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    produit P(ui->le_id->text().toInt(),ui->le_nom->text(),ui->la_quantite->text().toInt(),ui->la_date->date());
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("produit ajoutée:\n"
         "click ok to exit"),QMessageBox::Ok);
              P.ajouter();
               ui->tab_produit->setModel(P.afficher());
}

void MainWindow::on_pb_supp_clicked()
{
    produit P1;
    P1.setid(ui->id_sup->text().toInt());
    bool test=P1.supprimer(P1.getid());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("suppression avec succes");
     ui->tab_produit->setModel(P.afficher());
    }
    else
        msgBox.setText("echec de la suppression");
    msgBox.exec();
}

void MainWindow::on_pb_mod_clicked()
{
    produit P2;
      P2.setid(ui->id_mod->text().toInt());
    P2.setnom(ui->nom_mod->text());
        P2.setquantite(ui->quantite_mod->text().toInt());
        P2.setdate_exp(ui->date_mod->date());



       P2.modifier(P2.getid(),P2.getnom(),P2.getquantite(),P2.getdate_exp());
       QMessageBox::information(nullptr, QObject::tr("database is open"),
               QObject::tr("produit modifier:\n"
    "click ok to exit"),QMessageBox::Ok);
       ui->tab_produit->setModel(P.afficher());

}

void MainWindow::on_radioButton_clicked()
{
     ui->tab_produit->setModel( P.trier_id());
}



void MainWindow::on_radioButton_2_clicked()
{
     ui->tab_produit->setModel( P.trier_nom());
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->tab_produit->setModel( P.trier_date());
}

void MainWindow::on_pushButton_clicked()
{



    equipement E(ui->le_ide->text().toInt(),ui->le_nome->text(),ui->le_quantitee->text().toInt(),ui->le_etate->text());
       int ide= ui->le_ide->text().toInt();
       QString nome= ui->le_nome->text();
    bool test=E.ajoutere();
         if(ide==0||nome=="")
         {
            QMessageBox::critical(nullptr, QObject::tr("vide"),
                                             QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

         }

           else if(test==true){
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("equipement ajoute:\n"
                 "click ok to exit"),QMessageBox::Ok);
            ui->tab_equipement->setModel(E.affichere());}
         else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("equipement existe deja:\n"
                            "click ok to exit"),QMessageBox::Ok);}

             E.ajoutere();



}

void MainWindow::on_pb_suppeq_clicked()
{

    equipement E1;
        E1.setide(ui->id_suppr->text().toInt());
        int ide= ui->id_suppr->text().toInt();
        bool test1=E1.supprimere(E1.getide());



       if(ide==0)
        {
           QMessageBox::information(nullptr, QObject::tr("vide"),
                                            QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

        }



        else if(test1==true)
           {QMessageBox::critical(nullptr,QObject::tr("datavase is open"),
                                     QObject::tr("Equipement supprimée:\n"
             "click ok to exit"),QMessageBox::Ok);
         ui->tab_equipement->setModel(E.affichere());
        }
           else
        {QMessageBox::critical(nullptr,QObject::tr("database is open"),
                                  QObject::tr("Erreur:\n"
               "click ok to exit"),QMessageBox::Ok);}
       E.supprimere(E.getide());
}


void MainWindow::on_pb_modifierequipement_clicked()
{
    equipement E2;
    E2.setide(ui->ide_mod->text().toInt());
        E2.setnome(ui->nom_mod_2->text());
        E2.setquantitee(ui->quantite_mod_2->text().toInt());
        E2.setetate(ui->etate_mod->text());

       E2.modifiere(E2.getide(),E2.getnome(),E2.getquantitee(),E2.getetate());
       int ide= ui->ide_mod->text().toInt();
       QString nome= ui->nom_mod_2->text();
       if(ide==0||nome=="")
            {
               QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

            }

       else {
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("reclamation modifier:\n"
        "click ok to exit"),QMessageBox::Ok);
           ui->tab_equipement->setModel(E.affichere());


}
}


void MainWindow::on_pb_rechid_clicked()
{
    QString id = ui->la_rechid->text();
    ui->tab_produit->setModel(P.afficher_four_id(id));
}

void MainWindow::on_pb_rechnom_clicked()
{
    QString nom = ui->la_rechnom->text();
    ui->tab_produit->setModel(P.afficher_four_nom(nom));
}
