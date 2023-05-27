#include "colum.h"
#include "ui_colum.h"
#include <QBarSet>
#include <QtCharts/QBarSet>
#include <QVector>
#include <QDebug>

QVector<int> v1;
QVector<int> v2;
QVector<int> v3;
QVector<int> v4;

Colum::Colum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Colum)
{
    ui->setupUi(this);
    int i = 0;
    for(i = 0; i < 6; i++)
    {
        v1.push_front(0);
        v2.push_front(0);
        v3.push_front(0);
        v4.push_front(0);
    }

    QBarSet *set0 = new QBarSet("日光(min)");
    QBarSet *set1 = new QBarSet("UV(min)");
    QBarSet *set2 = new QBarSet("日光(month)");
    QBarSet *set3 = new QBarSet("UV(month)");

//        *set0 << 5 << 2 << 3 << 4 << 5 << 6;
//        *set1 << 7 << 0 << 0 << 4 << 0 << 7;
//        *set2 << 9 << 5 << 8 << 19<< 8 << 5;
//        *set3 << 5 << 6 << 7 << 3 << 4 << 5;

    connect( ui->pushButton , &QPushButton::clicked , [=](){
        v1.push_front( (ui->lineEdit_1->text()).toInt() );
        v2.push_front( (ui->lineEdit_2->text()).toInt() );
        v3.push_front( (ui->lineEdit_3->text()).toInt() );
        v4.push_front( (ui->lineEdit_4->text()).toInt() );


        QVector<int>::iterator it1 = v1.begin();
        QVector<int>::iterator it2 = v2.begin();
        QVector<int>::iterator it3 = v3.begin();
        QVector<int>::iterator it4 = v4.begin();

        *set0 << *it1;
        *set1 << *it2;
        *set2 << *it3;
        *set3 << *it4;

        it1++;
        it2++;
        it3++;
        it4++;

//        for(QVector<int>::iterator it4 = v4.begin(); it4 < v4.begin()+5 ; it4++ )
//        {

////            *set0 << *it1 << *(it1+1) << *(it1+2) << *(it1+3) << *(it1+4) << *(it1+5);
////            *set1 << *it2 << *(it2+1) << *(it2+2) << *(it2+3) << *(it2+4) << *(it2+5);
////            *set2 << *it3 << *(it3+1) << *(it3+2) << *(it3+3) << *(it3+4) << *(it3+5);
////            *set3 << *it4 << *(it4+1) << *(it4+2) << *(it4+3) << *(it4+4) << *(it4+5);

//            *set0 << *it1;
//            *set1 << *it2;
//            *set2 << *it3;
//            *set3 << *it4;

//            it1++;
//            it2++;
//            it3++;

//        }


        //按组划分
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);


//        ui->graphicsView->setChart(chart);
        ui->graphicsView->setChart(chart);


    } );
}

Colum::~Colum()
{
    delete ui;
}
