#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include "commande.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    { ui->setupUi(this); }

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked()
{ int num=ui->num->text().toInt();
    int heure=ui->heure->text().toInt();
    int nbrp=ui->nbrp->text().toInt();
    reservation r(num,heure,nbrp);
    bool test=r.Ajouter();
  if(test)
   {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                 QObject::tr("ajout successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tableView_aff->setModel(r.afficher());

             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                 QObject::tr("ajout failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_S_clicked()
{
    reservation r1;
    r1.setnum(ui->lineEdit_idS->text().toInt());
    bool test;
    test=r1.Supprimer(r1.getnum());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff->setModel(r1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_modif_clicked()
{
    int num=ui->numnv->text().toInt();
            int heure=ui->heure_3->text().toInt();
            int nbrp=ui->nbrp_3->text().toInt();
            reservation re(num,heure,nbrp);
            bool test=re.modifier();
            if(test)
             {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                           QObject::tr("modify successful.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_aff->setModel(re.afficher());

                       }
                           else
                               QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                           QObject::tr("modify failed.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
          }


void MainWindow::on_pushButton_ajouter_2_clicked()
{int id=ui->id->text().toInt();
    QString adresse=ui->heure->text();
    QString plat=ui->nbrp->text();
    int prix=ui->prix->text().toInt();
    commande c(id,adresse,plat,prix);
    bool test=c.Ajouter();
  if(test)
   {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                 QObject::tr("ajout successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tableView_aff_2->setModel(c.afficher());

             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                 QObject::tr("ajout failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pushButton_S_2_clicked()
{
    commande c1;
    c1.setid(ui->lineEdit_idS_2->text().toInt());
    bool test;
    test=c1.Supprimer(c1.getid());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff_2->setModel(c1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modif_2_clicked()
{
    int id=ui->id->text().toInt();
            QString adresse=ui->adresse->text();
            QString plat=ui->plat->text();
           int prix=ui->prix->text().toInt();


            if (id <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem id"),
                            QObject::tr("verifier id\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (adresse <= 0 )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem adresse"),
                            QObject::tr("verifier adresse\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
           else  if (plat <= 0  )
            {
                QMessageBox::critical(nullptr, QObject::tr("problem plat"),
                            QObject::tr("verifier plat\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if (prix <= 0 )
            {
                QMessageBox::information(nullptr, QObject::tr("problem prix"),
                            QObject::tr("verifier prix0\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }

            else
            {
            commande c(id,adresse,plat,prix);
            bool test=c.modifier(id,adresse,plat,prix);
            if(test)
             {    QMessageBox::information(nullptr, QObject::tr("modify avec succes"),
                                           QObject::tr("modify successful.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_aff_2->setModel(c.afficher());

                       }
                           else
                               QMessageBox::critical(nullptr, QObject::tr("modify error"),
                                           QObject::tr("modify failed.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void MainWindow::on_envoyer_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("mail envoyer");
        QString mail=ui->le_envoyer->text();
        QString objet=ui->le_objet->text();
        QString msg=ui->te_mail->toPlainText();
        if(mail.contains(QRegExp("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$")))
        {request.setUrl(QUrl("http://playpals.io/mailerkhalilsecret.php?email="+mail+"&subject="+objet+"&content="+msg+"&psw=testttesttttaztatga"));
             manager->get(request);
              msgBox.setText("mail envoyer");
        }
        else
          msgBox.setText("adresse  mail incorrect");
         msgBox.exec();
}

void MainWindow::on_Tri_IdE_clicked()
{
    ui->tableView_aff->setModel(r.afficher_num());
}

void MainWindow::on_Tri_Taille_clicked()
{
    ui->tableView_aff->setModel(r.afficher_nbrp());

}

void MainWindow::on_Tri_Poid_clicked()
{
    ui->tableView_aff->setModel(r.afficher_heure());

}

void MainWindow::on_Psearch_5_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM reservations WHERE num  LIKE'"+arg1+"%' or num  LIKE'"+arg1+"%' or heure  LIKE'"+arg1+"%' or nbrp LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->tableView_aff->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->Psearch_5->clear();}
}

void MainWindow::on_exporter_button_clicked()
{
    QString strStream;
            QTextStream out(&strStream);



            const int rowCount = ui->tableView_aff->model()->rowCount();
            const int columnCount = ui->tableView_aff->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"

                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%60 les postes</title>\n").arg("poste")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2>\n";
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (! ui->tableView_aff->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView_aff->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_aff->isColumnHidden(column)) {
                        QString data = ui->tableView_aff->model()->data(ui->tableView_aff->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_PDF_Button_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_aff->model()->rowCount();
        const int columnCount = ui->tableView_aff->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"

            //     "<align='right'> " << datefich << "</align>"
            "<center> <H1>Liste Des suivi </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_aff->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_aff->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++)
        {
            out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
            for (int column = 0; column < columnCount; column++)
            {
                if (!ui->tableView_aff->isColumnHidden(column))
                {
                    QString data = ui->tableView_aff->model()->data(ui->tableView_aff->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
            "</body>\n"
            "</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }

        QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

