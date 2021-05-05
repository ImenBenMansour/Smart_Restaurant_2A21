#include "login.h"
#include "ui_login.h"
#include "welcome.h"
#include <QMessageBox>
#include <QString>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);
      this->setWindowTitle("Login");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username= ui->lineEdit->text();
       QString password=ui->lineEdit_2->text();

       if (username == "esprit" && password == "esprit")
   {


           Welcome *w = new Welcome;
          hide();
          w->show();




       }
       else
       {
                  QMessageBox::information(this, "login", "login failed");
       }
}
