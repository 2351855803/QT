#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,600);

    //创建菜单栏
    QMenuBar *qm = new QMenuBar(this);
    //将菜单栏添加到主窗口特殊位置
    this->setMenuBar(qm);

    //创建菜单
    QMenu *file = new QMenu("文件",this);
    QMenu *set = new QMenu("设置",this);
    QMenu *close = new QMenu("关闭文件",this);



    //将菜单放到菜单栏
    qm->addMenu(file);
    qm->addMenu(set);
    qm->addMenu(close);



    //创建菜单项
    QAction *addfile = new QAction("添加文件",this);
    QAction *deletefile = new QAction("删除文件",this);

    QAction *closeM = new QAction("关闭文件",this);

    file->addAction(addfile);

    file->addSeparator();

    file->addAction(deletefile);

    close->addAction(closeM);



//    file->addActions(QList<QAction *>() << addfile << deletefile);

//    close->addActions(QList<QAction *>() << closeM);

    //file->addAction(addfile);

    //让菜单项动起来
    //使用lambda表达式
    connect( addfile , &QAction::triggered , [&](){
        qDebug() << "添加文件" << endl;
    } );
    connect( deletefile , &QAction::triggered , [&](){
        qDebug() << "删除文件" << endl;
    } );

    connect( closeM , &QAction::triggered , [&](){
        QMainWindow::close();
    });

    //设置菜单项的快捷方式
    addfile->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_N));
    deletefile->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_D));
    closeM->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_C));

    //创建工具栏
    QToolBar *qt1 = new QToolBar(this);
    //把窗口作为工具栏父对象
    this->addToolBar(qt1);
    //工具栏添加菜单项
    qt1->addAction(closeM);
    //设置不允许工具栏浮动
    qt1->setFloatable(false);
    //只允许工具栏停靠左右

    //    Constant
    //    Value
    //    Qt::LeftToolBarArea
    //    0x1
    //    Qt::RightToolBarArea
    //    0x2
    //    Qt::TopToolBarArea
    //    0x4
    //    Qt::BottomToolBarArea
    //    0x8
    //    Qt::AllToolBarAreas
    //    ToolBarArea_Mask
    //    Qt::NoToolBarArea
    //    0

    qt1->setAllowedAreas(Qt::TopToolBarArea);


    //添加状态栏
    QStatusBar *statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar);
    //添加标签
    QLabel *label = new QLabel("左侧信息",this);
    QLabel *label2 = new QLabel("右侧信息",this);
    //在状态栏上添加左侧信息
    statusBar->addWidget(label);
    //statusBar->addWidget(label2);
    statusBar->addPermanentWidget(label2);


    //添加中心部件
    //文本框作为中心部件
    QTextEdit *textEdit = new QTextEdit("这是文本框",this);
    this->setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}
