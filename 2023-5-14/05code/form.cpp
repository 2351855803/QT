#include "form.h"
#include "ui_form.h"
#include "widget.h"
#include <QPushButton>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
#if 0
    //给主窗口发送回退信号
    connect( ui->pushButton_return , &QPushButton::clicked , [&](){
        emit this->myBack();

    } );
#else
    //给主窗口发送回退信号，不使用lambda表达式
    connect( ui->pushButton_return , &QPushButton::clicked , this , &Form::myBack );
#endif
}

Form::~Form()
{
    delete ui;
}
