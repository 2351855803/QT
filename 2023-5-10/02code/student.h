#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include <QDebug>

class Student : public QWidget
{
    Q_OBJECT
public:
    explicit Student(QWidget *parent = 0);

signals:
    void treatOver(void);

public slots:
    void treat(void)
    {
        qDebug() << "学生请吃饭" << endl;
        //关闭窗口需要学生发出信号
        emit this->treatOver();
    }
};

#endif // STUDENT_H
