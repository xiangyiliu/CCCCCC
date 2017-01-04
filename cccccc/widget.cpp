#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::read()
{
    QString s = socket->readAll();
    str += s;
    ui->label->setText(s);
}

void Widget::on_pushButton_clicked()
{

    socket = new QTcpSocket;
    socket->connectToHost("192.168.1.22",1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(read()));
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    //socket->waitForReadyRead();
    //if (socket->ConnectedState==1)

}

void Widget::connected()
{
    ui->label->setText("1111111111");
}

void Widget::on_pushButton_2_clicked()
{
    n =socket->write("login|fljdslkj|fsdfsdf|");
    socket->waitForBytesWritten(100);
    socket->flush();

}

void Widget::on_pushButton_3_clicked()
{
    socket->write("chat|fljdslkj|liubing11111111|");
    socket->waitForBytesWritten(100);
    socket->flush();

}

void Widget::disconnected()
{
    ui->label->setText("已断开");
}

void Widget::on_pushButton_4_clicked()
{
    socket->close();
    socket->deleteLater();
}

void Widget::on_pushButton_5_clicked()
{
    n =socket->write("login|fljdslkj|fsdf|");
    socket->waitForBytesWritten(100);
    socket->flush();
}

void Widget::on_pushButton_6_clicked()
{
    socket->write("login|fljdslkj|fsdf|");
    socket->waitForBytesWritten(100);
    socket->flush();
}
