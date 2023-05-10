#ifndef TEACHER_H
#define TEACHER_H

#include <QWidget>
#include "QDebug"

class Teacher : public QWidget
{
    Q_OBJECT
public:
    explicit Teacher(QWidget *parent = 0);

signals:
    void hungry(void);

public slots:
    void classOver(void)
    {
        qDebug() << "下课" << endl;
        //需要触发teacher的信号
        emit this->hungry();
    }
};

#endif // TEACHER_H
