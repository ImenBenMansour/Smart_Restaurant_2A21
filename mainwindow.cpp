#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <event.h>
#include<QMessageBox>
#include <QtWidgets>
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


/***************/

    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->nom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
     ui->type->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
     ui->id_2->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->nom_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
     ui->partenaire->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
     ui->partenariat->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->events->setModel(e.afficher());
    ui->partenaires->setModel(p.afficher());
ui->comboBox->addItem("type");
ui->comboBox->addItem("nom");
ui->comboBox->addItem("id");
    /****************/

        /****************************/
    QList<Event> fi=e.afficherRole();
    QStringList l;

    for(int i=0;i<fi.size();i++)
    {
  Event fo;
       fo=fi.at(i);
       l.append(fo.getNom());
    }ui->event->addItem("");
    ui->event->addItems(l);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
if(ui->id->text()=="" || ui->nom->text()=="" || ui->type->text()=="")
{
    QMessageBox::critical(nullptr, QObject::tr("Ajout event"),
                                   QObject::tr("erreur.\n"
                                               "Veuillez remplir tous les champs"), QMessageBox::Cancel);}

else
{
    Event event(ui->id->text().toInt(),ui->nom->text(),ui->type->text());
            if(event.ajouter())
              {  QMessageBox::information(nullptr, QObject::tr("Ajout event"),
                                                            QObject::tr("add successful.\n"

                                                                        "Click OK to exit."), QMessageBox::Cancel);
                ui->events->setModel(e.afficher());
                ui->id->setText("");
                ui->nom->setText("");
                ui->type->setText("");

                QList<Event> fi=e.afficherRole();
                QStringList l;
            ui->event->clear();
                for(int i=0;i<fi.size();i++)
                {
              Event fo;
                   fo=fi.at(i);
                   l.append(fo.getNom());
                }ui->event->addItem("");
                ui->event->addItems(l);

            }
            else
                                   QMessageBox::critical(nullptr, QObject::tr("Ajout event"),
                                                      QObject::tr("add failed.\n"
                                                                  "Click OK to exit."), QMessageBox::Cancel);



}
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->id->text()=="" || ui->nom->text()=="" || ui->type->text()=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier event"),
                                       QObject::tr("erreur.\n"
                                                   "Veuillez remplir tous les champs"), QMessageBox::Cancel);
        ui->events->setModel(e.afficher());
        QList<Event> fi=e.afficherRole();
        QStringList l;
    ui->event->clear();
        for(int i=0;i<fi.size();i++)
        {
      Event fo;
           fo=fi.at(i);
           l.append(fo.getNom());
        }ui->event->addItem("");
        ui->event->addItems(l);

    }

    else
    {
        Event event(ui->id->text().toInt(),ui->nom->text(),ui->type->text());
                if(event.modifier())
                 {   QMessageBox::information(nullptr, QObject::tr("modifier event"),
                                                                QObject::tr("add successful.\n"

                                                                            "Click OK to exit."), QMessageBox::Cancel);
                    ui->events->setModel(e.afficher());
                    ui->id->setText("");
                    ui->nom->setText("");
                    ui->type->setText("");
                    QList<Event> fi=e.afficherRole();
                    QStringList l;
                ui->event->clear();
                    for(int i=0;i<fi.size();i++)
                    {
                  Event fo;
                       fo=fi.at(i);
                       l.append(fo.getNom());
                    }ui->event->addItem("");
                    ui->event->addItems(l);


                }
                else
                                       QMessageBox::critical(nullptr, QObject::tr("modifier event"),
                                                          QObject::tr("add failed.\n"
                                                                      "Click OK to exit."), QMessageBox::Cancel);



    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int idi=ui->id->text().toInt();
    Event ev=e.afficherR(idi);
    if(ev.supprimer())
    {QMessageBox::information(nullptr, QObject::tr("supprimer event"),
                                        QObject::tr("delete successful.\n"
                                                    "Click OK to exit."), QMessageBox::Cancel);
        ui->events->setModel(e.afficher());
        ui->id->setText("");
        ui->nom->setText("");
        ui->type->setText("");
        QList<Event> fi=e.afficherRole();
        QStringList l;
    ui->event->clear();
        for(int i=0;i<fi.size();i++)
        {
      Event fo;
           fo=fi.at(i);
           l.append(fo.getNom());
        }ui->event->addItem("");
        ui->event->addItems(l);

    }
    else {


        QMessageBox::critical(nullptr, QObject::tr("supprimer event"),
                           QObject::tr("delete failed.\n"
                                       "Click OK to exit."), QMessageBox::Cancel);

    }

}

void MainWindow::on_events_activated(const QModelIndex &index)
{
    int id =ui->events->model()->data(index).toInt();
    Event ev=e.afficherR(id);
    ui->id->setText(QString::number(ev.getId()));
    ui->nom->setText(ev.getNom());
    ui->type->setText(ev.getType());

}

void MainWindow::on_partenaires_activated(const QModelIndex &index)
{

    int ids =ui->partenaires->model()->data(index).toInt();
    Partenaires evi=p.afficherR(ids);

    ui->id_2->setText(QString::number(evi.getId()));
    ui->nom_2->setText(evi.getNom());
ui->partenaire->setText(evi.getTypepartenaire());
ui->partenariat->setText(evi.getTypepartenariat());
}

void MainWindow::on_pushButton_4_clicked()
{

    if(ui->id_2->text()=="" || ui->nom_2->text()=="" || ui->partenaire->text()=="" || ui->partenariat->text()=="" )
    {


        QMessageBox::critical(nullptr, QObject::tr("ajout partenaire"),
                           QObject::tr("add failed.\n"
                                       "Click OK to exit."), QMessageBox::Cancel);
    } else
    {

        Partenaires part(ui->id_2->text().toInt(),ui->nom_2->text(),ui->partenaire->text(),ui->partenariat->text(),e.recupererID(ui->event->currentText()));
        if(part.ajouter())
        {QMessageBox::information(nullptr, QObject::tr("ajouter partenaires"),
                                  QObject::tr("add successful.\n"
                                              "Click OK to exit."), QMessageBox::Cancel);
            ui->partenaires->setModel(p.afficher());


        } else
            QMessageBox::critical(nullptr, QObject::tr("ajout partenaire"),
                               QObject::tr("ass failed.\n"
                                           "Click OK to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->id_2->text()=="" || ui->nom_2->text()=="" || ui->partenaire->text()=="" || ui->partenariat->text()=="" )
    {


        QMessageBox::critical(nullptr, QObject::tr("ajout partenaire"),
                           QObject::tr("add failed.\n"
                                       "Click OK to exit."), QMessageBox::Cancel);
    } else
    {

        Partenaires part(ui->id_2->text().toInt(),ui->nom_2->text(),ui->partenaire->text(),ui->partenariat->text(),e.recupererID(ui->event->currentText()));
        if(part.modifier())
        {QMessageBox::information(nullptr, QObject::tr("ajouter partenaires"),
                                  QObject::tr("add successful.\n"
                                              "Click OK to exit."), QMessageBox::Cancel);
            ui->partenaires->setModel(p.afficher());


        } else
            QMessageBox::critical(nullptr, QObject::tr("ajout partenaire"),
                               QObject::tr("ass failed.\n"
                                           "Click OK to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_6_clicked()

{int idi=ui->id_2->text().toInt();
    p.setId(idi);
    Event ev=e.afficherR(idi);
    if(p.supprimer())
    {QMessageBox::information(nullptr, QObject::tr("supprimer partenaire"),
                                        QObject::tr("delete successful.\n"
                                                    "Click OK to exit."), QMessageBox::Cancel);
        ui->partenaires->setModel(p.afficher());
        ui->id_2->setText("");
        ui->nom_2->setText("");
        ui->partenaire->setText("");
        ui->partenariat->setText("");


    }
    else {


        QMessageBox::critical(nullptr, QObject::tr("supprimer event"),
                           QObject::tr("delete failed.\n"
                                       "Click OK to exit."), QMessageBox::Cancel);

    }

}

void MainWindow::on_pushButton_7_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
      if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
      QPrinter printer(QPrinter::PrinterResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setPaperSize(QPrinter::A4);
      printer.setOutputFileName(fileName);
      QTextDocument doc;
      QList<Partenaires> fi=p.afficherPartenaire();
      QString message="<h1 style='margin-left:100px;margin-bottom:100px;'>liste partenaire</h1><table border='1'><tr><th>id</th> <th>Nom</th><th>type partenaire</th> <th>type partenariat</th> </tr> ";
      for(int i=0;i<fi.size();i++)
      {Partenaires ei=fi.at(i);
          message.append("<tr><td>");
          message.append(QString::number(ei.getId()));
          message.append("</td>");
          message.append("<td>");
          message.append(ei.getNom());
          message.append("</td>");
          message.append("<td>");
          message.append(ei.getTypepartenaire());
          message.append("</td>");
          message.append("<td>");
          message.append(ei.getTypepartenariat());
          message.append("</td></tr>");
      }
      message.append("</table>");
   doc.setHtml(message);

      doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
      doc.print(&printer);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->partenaires->setModel(p.recherche(ui->lineEdit->text()));

}

void MainWindow::on_radioButton_clicked()
{
    ui->events->setModel(e.trieAsc(ui->comboBox->currentText()));

}

void MainWindow::on_radioButton_2_clicked()
{
    ui->events->setModel(e.trieDesc(ui->comboBox->currentText()));

}




