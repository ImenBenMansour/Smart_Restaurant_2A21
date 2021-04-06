#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include<QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile("C:/Users/DELL/Downloads/Code_source_Atelier_Connexion/Atelier_Connexion/perstfic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);

  connection C;
  bool  test=C.createConnection();
   MainWindow w;
  if(test)
      QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("Connexion successfull:\n"
"click ok to exit"),QMessageBox::Ok);


   //qDebug() << "connexion reussite";

  else
     // qDebug() <<"erreur de connexion";
     QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("Connexion failed:\n"
"click cancel to exit"),QMessageBox::Cancel);

  w.show();
    return a.exec();
}
