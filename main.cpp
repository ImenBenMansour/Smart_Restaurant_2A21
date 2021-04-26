#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include<QFile>
#include <QTranslator>
#include<QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile("C:/Users/DELL/Downloads/Code_source_Atelier_Connexion/Atelier_Connexion/perstfic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);

  connection C;
  QTranslator t;
  QStringList languages;
  languages <<"French" <<"English" << "Arabe";

  const QString lang = QInputDialog::getItem(NULL,"Select language",
                                       "language", languages);

  if (lang == "English")
  {
      //t.load("C:/Qt/5.9.9/mingw53_32/translations/qtbase_en.qm");

      t.load(":/english.qm");

  }
  else if (lang == "Arabe" )
  {
      t.load(":/arabe.qm");
  }
  if(lang !="French"){
      a.installTranslator(&t);
  }
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
