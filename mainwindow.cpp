#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include "equipement.h"
#include<QMessageBox>
#include  <QSqlQuery>
#include<QIntValidator>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QtCharts>
#include <QPieSeries>
#include <QPieSlice>
#include <QPixmap>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




     ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
    ui->id_mod->setValidator( new QIntValidator(0, 9999999, this));
     ui->id_sup->setValidator( new QIntValidator(0, 9999999, this));
     ui->ide_mod->setValidator( new QIntValidator(0, 9999999, this));
     ui->id_suppr->setValidator( new QIntValidator(0, 9999999, this));
     ui->le_ide->setValidator( new QIntValidator(0, 9999999, this));
     ui->ide_mod->setValidator( new QIntValidator(0, 9999999, this));
     ui->le_quantitee->setValidator( new QIntValidator(0, 9999, this));
    ui->la_quantite->setValidator( new QIntValidator(0, 9999, this));
         ui->quantite_mod->setValidator( new QIntValidator(0, 9999, this));
         ui->quantite_mod_2->setValidator( new QIntValidator(0, 9999, this));

    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->nom_mod->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
      ui->nom_mod_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->le_nome->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->le_etate->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->nom_mod->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->etate_mod->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
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
            QMessageBox::information(nullptr, QObject::tr("la database est ouverte"),
                    QObject::tr("produit ajoutée:\n"
         "click ok to exit"),QMessageBox::Ok);
            N.notification_ajoutProduit();
            P.ajouter();
               ui->tab_produit->setModel(P.afficher());
}

void MainWindow::on_pb_supp_clicked()
{
    produit P1;
    P1.setid(ui->id_sup->text().toInt());
    N.notification_supprimerProduit();
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
       N.notification_modifierProduit();
       QMessageBox::information(nullptr, QObject::tr("la database est ouverte"),
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
            QMessageBox::information(nullptr, QObject::tr("la database est ouverte"),
                            QObject::tr("equipement ajoute:\n"
                 "click ok to exit"),QMessageBox::Ok);
            ui->tab_equipement->setModel(E.affichere());}
         else{QMessageBox::information(nullptr, QObject::tr("la database est ouverte"),
                                       QObject::tr("equipement existe deja:\n"
                            "click ok to exit"),QMessageBox::Ok);}
         N.notification_ajoutEquipement();

             E.ajoutere();



}

void MainWindow::on_pb_suppeq_clicked()
{

    equipement E1;
        E1.setide(ui->id_suppr->text().toInt());
        int ide= ui->id_suppr->text().toInt();
        N.notification_supprimerEquipement();
        bool test1=E1.supprimere(E1.getide());



       if(ide==0)
        {
           QMessageBox::information(nullptr, QObject::tr("vide"),
                                            QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

        }



        else if(test1==true)
           {QMessageBox::information(nullptr,QObject::tr("la database est ouverte"),
                                     QObject::tr("Equipement supprimée:\n"
             "click ok to exit"),QMessageBox::Ok);
         ui->tab_equipement->setModel(E.affichere());
        }
           else
        {QMessageBox::critical(nullptr,QObject::tr("la database est ouverte"),
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
       N.notification_modifierEquipement();
       if(ide==0||nome=="")
            {
               QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

            }

       else {
           QMessageBox::information(nullptr, QObject::tr("la database est ouverte"),
                   QObject::tr("equipement modifier:\n"
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



/*void MainWindow::on_id_sup_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM PRODUIT  WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or QUANTITE LIKE'"+arg1+"%' or DAT_EXP LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->id_sup->clear();}
}

void MainWindow::on_id_mod_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM EQUIPEMENT  WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or QUANTITE LIKE'"+arg1+"%' or DAT_EXP LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->id_mod->clear();}

}

void MainWindow::on_id_suppr_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM equipement  WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or QUANTITE LIKE'"+arg1+"%' or ETATE LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->id_suppr->clear();}
}

void MainWindow::on_ide_mod_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM equipement  WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or QUANTITE LIKE'"+arg1+"%' or ETATE LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->ide_mod->clear();}

}*/

void MainWindow::on_pb_rechdate_clicked()
{
    QString quantite = ui->larech_date->text();
    ui->tab_produit->setModel(P.afficher_four_quantite(quantite));
}

void MainWindow::on_pb_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/21658/OneDrive/Bureau/Atelier_Connexion/DesktopPdfAbonnes.pdf");
                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Produits");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(300,3300,"ID");
                              painter.drawText(2300,3300,"NOM");
                              painter.drawText(4300,3300,"QUANTITE");
                              painter.drawText(6300,3300,"DATE_EXP");




                              QSqlQuery query;
                              query.prepare("select * from PRODUIT");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(300,i,query.value(0).toString());
                                  painter.drawText(2300,i,query.value(1).toString());
                                  painter.drawText(4300,i,query.value(2).toString());
                                  painter.drawText(6300,i,query.value(3).toString());




                                 i = i +500;
                              }
                              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/21658/OneDrive/Bureau/Atelier_Connexion/DesktopPdfAbonnes.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}

/*void MainWindow::on_pb_retoureq_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
} */
/*

void MainWindow::on_pushButton_2_clicked()
{
    QPieSeries *series = new QPieSeries();
                QChart *chart = new QChart();

            QSqlQuery query;
            QPieSlice *slice;

            query.prepare("SELECT ca.cin ,ca.point,ca.id_carte ,cl.nom , cl.prenom  FROM  cartefid ca ,clientfid cl where ca.cin=cl.cin ");
            if(query.exec())
            {int i=0;
            while(query.next())
            {

               series->append(query.value(1).toString(), query.value(0).toInt());
            slice = series->slices().at(i);
               slice->setExploded();
                slice->setLabelVisible();
                slice->setPen(QPen(Qt::darkGreen, 2));

                slice->setBrush(Qt::green);
                i++;

            }}

            //![1]

            //![2]
              /*
               slice1->setExploded();
                 slice1->setLabelVisible();
                 slice1->setPen(QPen(Qt::darkGreen, 2));
                 slice1->setBrush(Qt::green);
            //![2]

            //![3]
                chart->addSeries(series);
                chart->setTitle("Statisque ");



            QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                                 chartView->show();
}
*/

void MainWindow::on_pb_imprimerprod_clicked()
{
    QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tab_produit->model()->rowCount();
                const int columnCount = ui->tab_produit->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tab_produit->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_produit->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_produit->isColumnHidden(column)) {
                            QString data = ui->tab_produit->model()->data(ui->tab_produit->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}
