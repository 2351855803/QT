#include "home.h"
#include "ui_home.h"
#include <QDateTime>
#include <QDebug>
#include <QPushButton>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QDateTime * sys_time = new QDateTime;
    ui->label->setText(sys_time->currentDateTime().toString("yyyy.MM.dd \n hh:mm:ss"));



    //界面1
    connect( ui->pushButton , &QPushButton::clicked , [=](){
        ui->stackedWidget->setCurrentIndex(0);
    } );
    connect( ui->pushButton_2 , &QPushButton::clicked , [=](){
        ui->stackedWidget->setCurrentIndex(1);
    } );

    //退出
    connect( ui->pushButton_4 , &QPushButton::clicked , this , &Home::close );


}

Home::~Home()
{
    delete ui;
}
