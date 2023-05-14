#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>

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

void Widget::on_pushButton_clicked()
{
    ui->label->setText("新的信息");
}

void Widget::on_pushButton_2_clicked()
{
    static int flag = 0;
    flag++;
    flag%=2;
    QString imageAdd[2] = {":/image/temp.png",":/image/temp2.png"};
    ui->label_2->setPixmap(QPixmap(imageAdd[flag]));

}
