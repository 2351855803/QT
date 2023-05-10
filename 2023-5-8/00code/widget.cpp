#include "widget.h"
#include <QString>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置标题
    this->setWindowTitle("FirstQT");
    //设置窗口大小
    this->resize(400,400);
    //固定窗口大小
    //this->setFixedSize(600,600);


    QPushButton *q1 = new QPushButton("Close",this);

    connect(q1,&QPushButton::clicked,this,&Widget::close);








//    //创建按键控件
//    QPushButton *q1 = new QPushButton;
//    //给按钮设置文本
//    q1->setText("FirstButton");
//    q1->setParent(this);

//    QPushButton *q2 = new QPushButton("第二个按钮" , this);

//    //移动按钮
//    q2->move(100,100);
}

Widget::~Widget()
{

}
