#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    QString str;
    int n;
private slots:
    void read();
    void on_pushButton_clicked();
    void connected();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void disconnected();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

};

#endif // WIDGET_H
