#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "form.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Form *myForm;
public slots:
    void judgeCode(void);
    void back(void);
};

#endif // WIDGET_H
