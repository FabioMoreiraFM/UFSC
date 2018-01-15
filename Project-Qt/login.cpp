#include "login.h"
#include "ui_login.h"
#include <QMainWindow>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    close();
}

void Login::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if (username != "fabio" || password != "123") {
        QMessageBox::critical(this,tr("Erro"),tr("Usuário ou senha incorreto"));
    } else {
        MainWindow *w = new MainWindow();
        w->setWindowModality(Qt::ApplicationModal);
        w->show();
        this->close();
    }
}
