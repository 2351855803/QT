#include "widget.h"
#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(500,500);

    QPushButton *q1 = new QPushButton("Close",this);

    connect(q1,&QPushButton::clicked,this,&Widget::close);
    //connect(q1,SIGNAL(clicked()),this,SLOT(close()));
}

Widget::~Widget()
{

}
