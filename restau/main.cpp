#include "welcome.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include<QFile>
#include <QTranslator>
#include<QInputDialog>
#include "login.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile(":/Perstfic.qss");
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
   Login w;

  if(test)
  {
   w.show();

      QMediaPlaylist *playlist = new QMediaPlaylist();
      playlist->addMedia(QUrl("qrc:/sound.mp3"));
      playlist->setPlaybackMode(QMediaPlaylist::Loop);

      QMediaPlayer *music = new QMediaPlayer();
      music->setPlaylist(playlist);
      music->play();


}

   //qDebug() << "connexion reussite";

  else
  {
     // qDebug() <<"erreur de connexion";
     QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("Connexion failed:\n"
"click cancel to exit"),QMessageBox::Cancel);
}

    return a.exec();
}
