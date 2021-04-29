#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include<QDebug>
#include <QMessageBox>
#include<QFile>
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{QApplication a(argc, argv);
    QTranslator T ;
    QStringList langs ;
    langs << "French" << "English" ;
    const QString lang =QInputDialog::getItem(NULL,"language","select a language", langs );

    if (lang=="English")
    {T.load(":/ingles.qm");}
    if(lang!="French")
    {a.installTranslator(&T); }
    QFile styleSheetFile("C:/Users/21658/OneDrive/Bureau/Atelier_Connexion/Perstfic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);


    Connection c;
    bool test=c.createconnect();
     MainWindow w;




     if(test) QMessageBox::information(nullptr, QObject::tr("database is open"),QObject::tr("connexion reussite\n" "click OK to exist"),
                                       QMessageBox::Ok);
         //qDebug() <<"connexion reussite";


     else
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connexion failed\n" "click Cancel to exist"),
                                                QMessageBox::Cancel);
         //qDebug() <<"erreur de connexion";
     w.show();
    return a.exec();
}

