#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <form.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void widgetBack(void);


private:
    Ui::Widget *ui;
    Form *myform;

};

#endif // WIDGET_H
