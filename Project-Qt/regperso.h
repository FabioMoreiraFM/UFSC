#ifndef REGPERSO_H
#define REGPERSO_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "personagem.h"

namespace Ui {
class RegPerso;
}

class RegPerso : public QDialog
{
    Q_OBJECT

public:
    explicit RegPerso(QWidget *parent = 0);
    ~RegPerso();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RegPerso *ui;
    Personagem *person;
};

#endif // REGPERSO_H
