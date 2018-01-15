#include "web.h"
#include "ui_web.h"

Web::Web(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Web)
{
    ui->setupUi(this);
}

Web::~Web()
{
    delete ui;
}

void Web::on_pushButton_clicked()
{

    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox::critical(this,tr("Erro"),tr("Insira um link válido!"));
    } else {
        QString link = ui->lineEdit->text();
        QDesktopServices::openUrl(QUrl(link));
    }
}
