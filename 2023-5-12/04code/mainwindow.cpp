#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox::StandardButton state;
    connect( ui->pushButton_login , &QPushButton::clicked ,[&](){

        state = QMessageBox::question(this,"询问","是否保存",QMessageBox::Save|QMessageBox::Cancel);
        if( QMessageBox::Yes == state )
        {
            qDebug() << "保存成功" << endl;
        }
        else if( QMessageBox::No == state )
        {
            qDebug() << "保存失败" << endl;
        }
    });




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"文件","./","*.cpp");
    qDebug() << fileName << endl;
}


void MainWindow::on_actionColor_triggered()
{
    QColor color =  QColorDialog::getColor(Qt::white,this,"color");
    qDebug() << color.blue() << " " << color.red() << " " << color.green() << endl;

}

void MainWindow::on_actionFont_triggered()
{
    bool yes = true;
    QFont qf = QFontDialog::getFont(&yes,QFont(),this,"字体");
    qDebug() << qf.family() << " " << qf.pointSize() << endl;
}
