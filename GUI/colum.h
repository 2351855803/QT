#ifndef COLUM_H
#define COLUM_H

#include <QWidget>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Colum;
}

class Colum : public QWidget
{
    Q_OBJECT

public:
    explicit Colum(QWidget *parent = 0);
    ~Colum();

private:
    Ui::Colum *ui;
};

#endif // COLUM_H
