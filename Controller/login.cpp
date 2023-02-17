#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if (username == "" && password == "") {
               QMessageBox::information(this, "Login", "Username and password are correct");
               hide();
          secdialog = new MainWindow(this);
          secdialog->show();

           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }
}
