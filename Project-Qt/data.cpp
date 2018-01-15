#include "data.h"
#include "ui_data.h"
#include <QTimer>
#include <QDateTime>

Data::Data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

Data::~Data()
{
    delete ui;
}

void Data::showTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_2->setText(time_text);
}
