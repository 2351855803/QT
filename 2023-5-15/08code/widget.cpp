#include "widget.h"
#include "ui_widget.h"
#include <QRadioButton>
#include <QDebug>
#include <QCheckBox>
#include <QComboBox>
#include <QTreeWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    //可以读取checkbutton的对应文本内容
    //可以通过状态值勾选
    connect( ui->checkBox , &QCheckBox::stateChanged ,  [=](int state){
        if( 2 == state )
            qDebug() << ui->checkBox->text() << endl;

    } );
    connect( ui->checkBox_2 , &QCheckBox::stateChanged ,  [=](int state){
        if( 2 == state )
            qDebug() << ui->checkBox_2->text() << endl;

    } );
    connect( ui->checkBox_3 , &QCheckBox::stateChanged ,  [=](int state){
        if( 2 == state )
            qDebug() << ui->checkBox_3->text() << endl;

    } );
    connect( ui->checkBox_4 , &QCheckBox::stateChanged ,  [=](int state){
        if( 2 == state )
            qDebug() << ui->checkBox_4->text() << endl;

    } );
    //不管是勾选还是不勾选都会读取，无法使用
//    connect( ui->checkBox , &QCheckBox::clicked ,  [=](){
//        qDebug() << ui->checkBox->text() << endl;
//    } );


    //定义函数指针来接受
    void(QComboBox::*p)(const QString &text) = &QComboBox::currentIndexChanged;
    connect( ui->comboBox , p , [=](const QString &text){
        qDebug() << "选中的车型为" << text << endl;
    });

    connect( ui->treeWidget , &QTreeWidget::itemDoubleClicked , [=](QTreeWidgetItem *item, int column){
        qDebug() << "英雄为" << item->text(column);
    } );

    connect( ui->pushButton , &QPushButton::clicked , [=](){
        ui->widget->mySet(60);
    } );

}

Widget::~Widget()
{
    delete ui;
}


