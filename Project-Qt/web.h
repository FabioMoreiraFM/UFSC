#ifndef WEB_H
#define WEB_H

#include <QDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class Web;
}

class Web : public QDialog
{
    Q_OBJECT

public:
    explicit Web(QWidget *parent = 0);
    ~Web();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Web *ui;
};

#endif // WEB_H
