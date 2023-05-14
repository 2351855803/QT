#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QLineEdit>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->myForm = new Form;


    connect( ui->pushButton , &QPushButton::clicked , this ,  &Widget::judgeCode );

    connect( this->myForm , &Form::myBack , this , &Widget::back );



}

Widget::~Widget()
{
    delete ui;
}

void Widget::judgeCode()
{
    if( "root" == ui->lineEdit->text() && "123456" == ui->lineEdit_2->text() )
    {
        QMessageBox::information(this,"提示","登录成功！！");
        this->hide();
        myForm->show();
    }
    else
    {
        QMessageBox::critical(this,"警告","密码或者用户名错误");
    }
}

void Widget::back()
{
    this->show();
    myForm->hide();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}
