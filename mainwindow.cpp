#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "recette.h"
#include <QMessageBox>
#include <QIntValidator>
#include "plat.h"
#include <QApplication>
#include <QSqlQuery>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent)
 :QMainWindow(parent),
   ui(new Ui::MainWindow)

{ ui->setupUi(this);
ui->tabrecette->setModel(R.afficher());
ui->tabplat->setModel(P.afficher1());
ui->le_id_Pl->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_nom_Pl->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->le_type->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->le_nb_calories->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_prix->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_id_sup_Pl->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_nom_modif_Pl->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->le_id_modif_Pl->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_nb_calories_modif->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_prix_modif->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_type_modif->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->le_id_Re->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_nom_Re->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->les_ingredients_Re->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->la_origine_Re->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->le_id_sup_Re->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_id_modif_Re->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
ui->le_nom_modif_Re->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->les_ingredients_modiff->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
ui->la_origine_modiff->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
}
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
                       QObject::tr("recette modifiée:\n"
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

void MainWindow::on_rb_tid_clicked()
{
    ui->tabplat->setModel( P.trier_id_Pl());
}

void MainWindow::on_rb_tn_clicked()
{
  ui->tabplat->setModel( P.trier_nom_Pl());
}


void MainWindow::on_rb_tt_clicked()
{
    ui->tabplat->setModel( P.trier_type());
}

void MainWindow::on_pb_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/DELL/Downloads/Code_source_Atelier_Connexion/plat.pdf");
                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::blue);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Plats");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/DELL/Downloads/Code_source_Atelier_Connexion/Atelier_Connexion/logo.png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawRect(0,3000,9600,500);
                              painter.drawText(300,3300,"ID_PL");
                             painter.drawRect(0,3000,9600,500);
                              painter.drawText(2300,3300,"NOM_PL");
                              painter.drawRect(0,3000,9600,500);
                              painter.drawText(4300,3300,"TYPE");
                              painter.drawRect(0,3000,9600,500);
                              painter.drawText(6300,3300,"NB_CALORIES");
                              painter.drawRect(0,3000,9600,500);
                              painter.drawText(8000,3300,"PRIX");



                              QSqlQuery query;
                              query.prepare("select * from PLAT");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(300,i,query.value(0).toString());
                                  painter.drawText(2300,i,query.value(1).toString());
                                  painter.drawText(4300,i,query.value(2).toString());
                                  painter.drawText(6300,i,query.value(3).toString());
                                  painter.drawText(8000,i,query.value(4).toString());



                                 i = i +500;
                              }
                              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/DELL/Downloads/Code_source_Atelier_Connexion/plat.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}

void MainWindow::on_le_id_sup_Re_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM recette  WHERE ID_RE  LIKE'"+arg1+"%' or NOM_RE  LIKE'"+arg1+"%' or INGREDIENTS LIKE'"+arg1+"%' or ORIGINE LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->le_id_sup_Re->clear();}
}

void MainWindow::on_le_id_modif_Re_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM recette  WHERE ID_RE  LIKE'"+arg1+"%' or NOM_RE  LIKE'"+arg1+"%' or INGREDIENTS LIKE'"+arg1+"%' or ORIGINE LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->le_id_modif_Re->clear();}
}

/*void MainWindow::on_le_id_sup_Pl_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM OLAT  WHERE ID_PL  LIKE'"+arg1+"%' or NB_CALORIES  LIKE'"+arg1+"%' or PRIX LIKE'"+arg1+"%' or NOM_PL LIKE'"+arg1+"%'or TYPE LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->le_id_sup_Pl->clear();}
}

void MainWindow::on_le_id_modif_Pl_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM OLAT  WHERE ID_PL  LIKE'"+arg1+"%' or NB_CALORIES  LIKE'"+arg1+"%' or PRIX LIKE'"+arg1+"%' or NOM_PL LIKE'"+arg1+"%'or TYPE LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->le_id_modif_Pl->clear();}
}*/

void MainWindow::on_pb_rid_clicked()
{
    QString id_Pl = ui->le_id_Plr->text();
       ui->tabplat->setModel(P.afficher_id_Pl(id_Pl));
   }


void MainWindow::on_pb_rn_clicked()
{
    QString nom_Pl = ui->le_nom_plr->text();
       ui->tabplat->setModel(P.afficher_nom_Pl(nom_Pl));

}

void MainWindow::on_pb_rt_clicked()
{
    QString type = ui->le_typer->text();
       ui->tabplat->setModel(P.afficher_type(type));

}
