#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <role.h>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QDateTime>

#include "qrcode.h"

#include <QPainter>
#include <QDebug>

using namespace std;
using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;





QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->nom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
     ui->prenom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
     ui->id->setValidator(new QIntValidator(0, 65, this)) ;
     ui->salaire->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->age->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->idE->setValidator(new QIntValidator(0, 100000, this)) ;
     ui->departement->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));

    ui->roles->setModel(r.afficher());
    ui->employes->setModel(e.afficher());
    /************/

    QList<Role> fi=e.afficherRole();
    QStringList l;

    for(int i=0;i<fi.size();i++)
    {
  Role fo;
       fo=fi.at(i);
       l.append(fo.getDescription());
    }ui->role->addItem("");
    ui->role->addItems(l);
ui->trie->addItem("plus récents");
ui->trie->addItem("plus anciens");
ui->trie->addItem("par age");
ui->trie->addItem("par salaire");

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*gestion roles*****/
//ajout
void MainWindow::on_pushButton_clicked()
{

    if(ui->id->text()=="" || ui->departement->text()=="" || ui->description->toPlainText()=="")
    {QMessageBox::critical(nullptr, QObject::tr("Ajout Role"),
                               QObject::tr("erreur.\n"
                                           "Veuillez remplir tous les champs"), QMessageBox::Cancel);}

    else
    {
        Role role(ui->id->text().toInt(),ui->description->toPlainText(),ui->departement->text());
                if(role.ajouter())
                {QMessageBox::information(nullptr, QObject::tr("Ajout role"),
                                            QObject::tr("add successful.\n"

                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->roles->setModel(r.afficher());
                    ui->id->setText("");
                     ui->description->setPlainText("");
                      ui->departement->setText("");


                      QList<Role> fi=e.afficherRole();
                      QStringList l;
                  ui->role->clear();
                      for(int i=0;i<fi.size();i++)
                      {
                    Role fo;
                         fo=fi.at(i);
                         l.append(fo.getDescription());
                      }ui->role->addItem("");
                      ui->role->addItems(l);



                }  else
                        QMessageBox::critical(nullptr, QObject::tr("Ajout role"),
                                           QObject::tr("add failed.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

//modifier

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->id->text()=="" || ui->departement->text()=="" || ui->description->toPlainText()=="")
        {QMessageBox::critical(nullptr, QObject::tr("Ajout Role"),
                                   QObject::tr("erreur.\n"
                                               "Veuillez remplir tous les champs"), QMessageBox::Cancel);}

        else
        {
            Role role(ui->id->text().toInt(),ui->description->toPlainText(),ui->departement->text());
                    if(role.modifier())
                       { QMessageBox::information(nullptr, QObject::tr("modifier role"),
                                                QObject::tr("Update successful.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
                        ui->roles->setModel(r.afficher());
                        ui->id->setText("");
                         ui->description->setPlainText("");
                          ui->departement->setText("");
                          QList<Role> fi=e.afficherRole();
                          QStringList l;
                          ui->role->clear();
                              for(int i=0;i<fi.size();i++)
                              {
                            Role fo;
                                 fo=fi.at(i);
                                 l.append(fo.getDescription());
                              }ui->role->addItem("");
                              ui->role->addItems(l);

                    }
                        else
                            QMessageBox::critical(nullptr, QObject::tr("modifier role"),
                                               QObject::tr("Update failed.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void MainWindow::on_roles_activated(const QModelIndex &index)
{    int id =ui->roles->model()->data(index).toInt();

    Role role=r.afficherR(id);
     ui->id->setText(QString::number(role.getId()));
      ui->description->setPlainText(role.getDescription());
       ui->departement->setText(role.getDepartement());

}

void MainWindow::on_pushButton_3_clicked()
{
    int id =ui->id->text().toInt();
    Role role=r.afficherR(id);
    if(role.supprimer())
       { QMessageBox::information(nullptr, QObject::tr("supprimer role"),
                                QObject::tr("delete successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        ui->roles->setModel(r.afficher());
        ui->id->setText("");
         ui->description->setPlainText("");
          ui->departement->setText("");
          ui->roles->setModel(r.afficher());
          QList<Role> fi=e.afficherRole();
          QStringList l;
          ui->role->clear();
              for(int i=0;i<fi.size();i++)
              {
            Role fo;
                 fo=fi.at(i);
                 l.append(fo.getDescription());
              }ui->role->addItem("");
              ui->role->addItems(l);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer role"),
                           QObject::tr("delete failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_role_currentIndexChanged(int index)
{
    idRole=r.recupererID(ui->role->itemText(index));
    dep=ui->role->itemText(index);
}

void MainWindow::on_ajouter_clicked()
{QString sDate = QDateTime::currentDateTime().toString(" dd/MM/yyyy");
    if(ui->idE->text()=="" || ui->nom->text()=="" || ui->prenom->text()=="" || ui->age->text()=="" || ui->salaire->text()==""|| ui->date->text()=="" || dep=="")
        QMessageBox::critical(nullptr, QObject::tr("ajouter employe"),
                           QObject::tr("add failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);


    else
    {
Employe emp(ui->idE->text().toInt(),ui->age->text().toInt(),ui->salaire->text().toInt(),ui->nom->text(),ui->prenom->text(),ui->date->date(),r.recupererID(ui->role->currentText()));
if(emp.ajouter())
{QMessageBox::information(nullptr, QObject::tr("Ajout employe"),
                            QObject::tr("add successful.\n"

                                        "Click Cancel to exit."), QMessageBox::Cancel);
    ui->employes->setModel(e.afficher());
    ui->idE->setText("");
    ui->nom->setText("");
    ui->prenom->setText("");
    ui->age->setText("");
ui->salaire->setText("");
  }  else
        QMessageBox::critical(nullptr, QObject::tr("Ajout employe"),
                           QObject::tr("add failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_modifier_clicked()
{QString sDate = QDateTime::currentDateTime().toString(" dd/MM/yyyy");
    if(ui->idE->text()=="" || ui->nom->text()=="" || ui->prenom->text()=="" || ui->age->text()=="" || ui->salaire->text()==""|| ui->date->text()=="" || dep=="")
        QMessageBox::critical(nullptr, QObject::tr("modifier employe"),
                           QObject::tr("add failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

    else
    {
Employe emp(ui->idE->text().toInt(),ui->age->text().toInt(),ui->salaire->text().toInt(),ui->nom->text(),ui->prenom->text(),ui->date->date(),r.recupererID(ui->role->currentText()));
if(emp.modifier())
{QMessageBox::information(nullptr, QObject::tr("modifier employe"),
                            QObject::tr("update successful.\n"

                                        "Click Cancel to exit."), QMessageBox::Cancel);
    ui->employes->setModel(e.afficher());
    ui->idE->setText("");
    ui->nom->setText("");
    ui->prenom->setText("");
    ui->age->setText("");
ui->salaire->setText("");
  }  else
        QMessageBox::critical(nullptr, QObject::tr("Modifier employe"),
                           QObject::tr("update failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_employes_activated(const QModelIndex &index)
{int id =ui->employes->model()->data(index).toInt();
Employe em=e.afficherR(id);
ui->idE->setText(QString::number(em.getId()));
ui->nom->setText(em.getNom());
ui->prenom->setText(em.getPrenom());
ui->age->setText(QString::number(em.getId()));
ui->salaire->setText(QString::number(em.getSalaire()));
ui->date->setDate(em.getDate());
QString ri=r.afficherR(em.getId()).getDepartement();
}

void MainWindow::on_supprimer_clicked()
{
    int id =ui->idE->text().toInt();
    Employe em=e.afficherR(id);
    if(em.supprimer())
       { QMessageBox::information(nullptr, QObject::tr("supprimer employe"),
                                QObject::tr("delete successful.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        ui->employes->setModel(e.afficher());
        ui->idE->setText("");
        ui->nom->setText("");
        ui->prenom->setText("");
        ui->age->setText("");
    ui->salaire->setText("");;

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer employe"),
                           QObject::tr("delete failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_search_textChanged(const QString &arg1)
{
    ui->employes->setModel(e.recherche(ui->search->text()));

}

void MainWindow::on_trie_currentIndexChanged(int index)
{if(ui->trie->currentText()=="plus récents")
        ui->employes->setModel(e.trieDesc());
     else if(ui->trie->currentText()=="plus aciens")
         ui->employes->setModel(e.trieAsc());
    else if (ui->trie->currentText()=="par age")
        ui->employes->setModel(e.trieAge());
    else if (ui->trie->currentText()=="par salaire")
        ui->employes->setModel(e.trieSalaire());


}



void MainWindow::on_statistqie_clicked()
{ QPieSeries *series = new QPieSeries();
    QChart *chart = new QChart();

QSqlQuery query;
QPieSlice *slice;
int id=0;
query.prepare("select count(e.id) as nombre ,r.description from employe e inner join role r on e.idRole=r.id group by r.description ");
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
     slice1->setBrush(Qt::green);*/
//![2]

//![3]
    chart->addSeries(series);
    chart->setTitle("Statisque : nombre d'employés par département");



QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
                     chartView->show();


}




void MainWindow::paintQR(QPainter &painter, const QSize sz, const QString &data, QColor fg)
{
    // NOTE: At this point you will use the API to get the encoding and format you want, instead of my hardcoded stuff:
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(data.toUtf8().constData(), qrcodegen::QrCode::Ecc::LOW);
    const int s=qr.getSize()>0?qr.getSize():1;
    const double w=sz.width();
    const double h=sz.height();
    const double aspect=w/h;
    const double size=((aspect>1.0)?h:w);
    const double scale=size/(s+2);
    // NOTE: For performance reasons my implementation only draws the foreground parts in supplied color.
    // It expects background to be prepared already (in white or whatever is preferred).
    painter.setPen(Qt::NoPen);
    painter.setBrush(fg);
    for(int y=0; y<s; y++) {
        for(int x=0; x<s; x++) {
            const int color=qr.getModule(x, y);  // 0 for white, 1 for black
            if(0!=color) {
                const double rx1=(x+1)*scale, ry1=(y+1)*scale;
                QRectF r(rx1, ry1, scale, scale);
                painter.drawRects(&r,1);
            }
        }
    }
}
void MainWindow::on_departement_textEdited(const QString &arg1)
{

    ui->QRCODE->setQRData(arg1);
}
