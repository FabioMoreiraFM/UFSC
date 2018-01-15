#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagem.h"
#include "regperso.h"
#include "web.h"
#include "data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionRegistrar_Personagem_triggered();

    void on_actionVisualizar_Imagem_triggered();

    void on_actionAbrir_Site_triggered();

    void on_actionData_Atual_triggered();

    void on_actionSair_triggered();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    RegPerso *rp;
    Imagem *imagem;
    Web *web;
    Data *data;
};

#endif // MAINWINDOW_H
