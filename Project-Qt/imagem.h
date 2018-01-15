#ifndef IMAGEM_H
#define IMAGEM_H
#include <QFileDialog>
#include <QDialog>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class Imagem;
}

class Imagem : public QDialog
{
    Q_OBJECT

public:
    explicit Imagem(QWidget *parent = 0);
    ~Imagem();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Imagem *ui;
};

#endif // IMAGEM_H
