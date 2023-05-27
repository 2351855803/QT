#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDebug>
#include <QPushButton>
#include <stdio.h>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //第一个界面退出
    connect( ui->pushButton_3 , &QPushButton::clicked , this , &Widget::close );


    //创建注册界面
    this->reg = new Register();
    connect( ui->pushButton_2 , &QPushButton::clicked , reg , &Register::show );

    //登录界面
    connect( ui->pushButton , &QPushButton::clicked , [=](){

        FILE *file;
        if( NULL == (file = fopen("D:/Qt/QT/GUI/Acc.txt","r")) )
        {
            perror("OpenError");
        }
        QString acc = ui->lineEdit->text();
        QString pwd = ui->lineEdit_2->text();
        char temp[300] = {0};

        while( NULL != fgets(temp,300,file) )
        {



            QString acc_read = (QString)strtok(temp,":");

            QString pwd_read = (QString)strtok(NULL,":");

//            qDebug() << "输入账户名" << acc << endl;
//            qDebug() << "输入密码" << pwd << endl;
//            qDebug() << "账户名" << acc_read << endl;
//            qDebug() << "密码" << pwd_read << endl;

            if( acc == acc_read && pwd == pwd_read )
            {
                //qDebug() << temp << endl;
                QMessageBox::information(this,"提示","登录成功");
                this->home = new Home;
                this->hide();
                this->home->show();

                return;
            }

        }
        QMessageBox::critical(this,"警告","用户名或密码错误");

    } );


}

Widget::~Widget()
{
    delete ui;
}
