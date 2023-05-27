#include "register.h"
#include "ui_register.h"
#include <QPushButton>
#include <stdio.h>
#include <QDebug>
#include <QByteArray>
#include <string>
#include <QMessageBox>
#include <QByteArray>


Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    //注册界面退出
    connect( ui->pushButton_2 , &QPushButton::clicked , this , &Register::close );

    connect( ui->pushButton , &QPushButton::clicked , [=](){
        FILE *file;
        if( NULL == (file = fopen("D:/Qt/QT/GUI/Acc.txt","r")) )
        {
            perror("Open Error");
        }

        char temp[300] = {0};
        while( fgets(temp,300,file) != NULL )
        {

            //qDebug() << strtok(temp,":") << endl;
            QString tempName = (QString)strtok(temp,":");
            if( ui->lineEdit->text() == tempName )
            {
                QMessageBox::critical(this,"警告","用户名存在");
                return;
            }
        }
        fclose(file);

        //输入的用户名为空
        if( ui->lineEdit->text() == NULL || ui->lineEdit_2->text() == NULL )
        {
            QMessageBox::critical(this,"警告","用户名或密码为空");
            return;
        }
        else if( ui->lineEdit_2->text() != ui->lineEdit_3->text()  )
        {
            QMessageBox::critical(this,"警告","两次密码不一致");
            return;
        }
        else
        {
            //存储注册信息
            FILE *file2;
            if( NULL == (file2 = fopen("D:/Qt/QT/GUI/Acc.txt","a+")) )
            {
                perror("Open Error");
            }
            QByteArray tn = ui->lineEdit->text().toLatin1();    //用户名
            QByteArray tc = ui->lineEdit_2->text().toLatin1();    //密码
            tn.data();
            tc.data();
            fputs(tn,file2);
            fputs(":",file2);
            fputs(tc,file2);
            fputs(":",file2);
            fputs("\n",file2);
            fclose(file2);
            QMessageBox::information(this,"提示","注册成功");
            this->hide();
        }



    } );

}

Register::~Register()
{
    delete ui;
}
