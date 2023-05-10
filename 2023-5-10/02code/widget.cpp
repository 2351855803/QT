#include "widget.h"
#include "teacher.h"
#include "student.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Teacher *te = new Teacher(this);
    Student *stu = new Student(this);

    this->resize(400,400);

    //建立老师和学生的关系
    //需要自定义老师以及学生类的槽函数以及信号
    //在类的定义中写
    connect(te, &Teacher::hungry , stu , &Student::treat );

    //定义一个按键来连接与老师的关系
    QPushButton *q1 = new QPushButton("下课",this);
    connect( q1 , &QPushButton::clicked , te , &Teacher::classOver );

    //当学生说请吃饭后，关闭窗口，则需要建立学生与窗口的连接
    connect( stu , &Student::treatOver , this , &QWidget::close );
}

Widget::~Widget()
{

}
