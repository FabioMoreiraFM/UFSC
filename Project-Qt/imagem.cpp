#include "imagem.h"
#include "ui_imagem.h"

Imagem::Imagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Imagem)
{
    ui->setupUi(this);
}

Imagem::~Imagem()
{
    delete ui;
}

void Imagem::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "Image File (*.jpg)");
    QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
}
