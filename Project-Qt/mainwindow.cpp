#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    rp = new RegPerso();
    rp->setModal(true);
    rp->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    web = new Web();
    web->setModal(true);
    web->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    imagem = new Imagem();
    imagem->setModal(true);
    imagem->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    data = new Data();
    data->setModal(true);
    data->show();
}

void MainWindow::on_actionRegistrar_Personagem_triggered()
{
    ui->pushButton->click();
}

void MainWindow::on_actionAbrir_Site_triggered()
{
    ui->pushButton_2->click();
}

void MainWindow::on_actionVisualizar_Imagem_triggered()
{
    ui->pushButton_3->click();
}

void MainWindow::on_actionData_Atual_triggered()
{
     ui->pushButton_4->click();
}

void MainWindow::on_actionSair_triggered()
{
    close();
}

void MainWindow::on_pushButton_5_clicked()
{
    close();
}
