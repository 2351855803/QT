#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSpinBox>
#include <QSlider>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //改变数字让进度条也发生变化
    //因为信号发生了函数重载，所以需要定义一个函数指针
    void(QSpinBox::*p)(int i) = &QSpinBox::valueChanged;
    connect( ui->spinBox , p , ui->horizontalSlider , &QSlider::setValue );

    //改变进度条让数字发生变化
    connect( ui->horizontalSlider , &QSlider::sliderMoved , ui->spinBox , &QSpinBox::setValue );


}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::mySet(int val)
{
    ui->horizontalSlider->setValue(val);
    ui->spinBox->setValue(val);
}
