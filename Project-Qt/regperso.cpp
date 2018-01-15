#include "regperso.h"
#include "ui_regperso.h"

RegPerso::RegPerso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegPerso)
{
    ui->setupUi(this);
    ui->groupBox->hide();
}

RegPerso::~RegPerso()
{
    delete ui;
}

void RegPerso::on_pushButton_clicked()
{
    if(!(ui->lineEdit->text().isEmpty() || ui->lineEdit->text().isEmpty() || ui->lineEdit->text().isEmpty())) {
        QString nome = ui->lineEdit->text();
        QString classe = ui->lineEdit_2->text();
        int life = (ui->lineEdit_3->text()).toInt();
        person = new Personagem(life,nome,classe);
        // Confirma info
        ui->lineEdit_4->setText(person->getNome());
        ui->lineEdit_5->setText(person->getClasse());
        ui->lineEdit_6->setText(QStringLiteral("%1").arg(person->getLife()));
        ui->groupBox->show();
    } else {
        QMessageBox::critical(this,tr("Erro"),tr("Insira todas as informações para continuar"));
    }
}

void RegPerso::on_pushButton_2_clicked()
{
    QMessageBox msg;
    msg.setText("Dados salvos com sucesso!");
    msg.setWindowTitle("Salvo");
    msg.exec();
    close();
}
