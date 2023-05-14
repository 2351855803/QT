#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLineEdit>
#include <Qdebug.h>
#include <QString>
#include <QmessageBox>
#include <form.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    //实例化一个form窗口
    this->myform = new Form();

    ui->setupUi(this);
    ui->lineEdit_Code->setEchoMode(QLineEdit::Password);

    //连接按钮
    connect( ui->pushButton_Cancel , &QPushButton::clicked , this , &Widget::close );
    connect( ui->pushButton_Login , &QPushButton::clicked , [&](){

//        qDebug() << "账号为" << ui->lineEdit_User->text() << endl;
//        qDebug() << "密码为" << ui->lineEdit_Code->text() << endl;
        QString user = ui->lineEdit_User->text();
        QString code = ui->lineEdit_Code->text();


        //判断密码
        if( user == "root" && code == "mycode" )
        {
            QMessageBox::information(this,"提示","登录成功！");
            this->hide();
            myform->show();
        }
        else
        {
            QMessageBox::critical(this,"错误","账户或者密码错误");
        }

    });

    //监听新窗口的回退信号myBack
    connect( this->myform , &Form::myBack , this , &Widget::widgetBack );


}

Widget::~Widget()
{
    delete ui;
}

void Widget::widgetBack()
{
    this->show();
    myform->hide();
}
