#ifndef DATA_H
#define DATA_H

#include <QDialog>

namespace Ui {
class Data;
}

class Data : public QDialog
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = 0);
    ~Data();

private:
    Ui::Data *ui;

private slots:
    void showTime();
};

#endif // DATA_H
