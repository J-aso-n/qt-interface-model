#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDockWidget>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //删除中间窗口
    QWidget* p = takeCentralWidget();
    if(p)
        delete p;

    setDockNestingEnabled(true);//打开dock嵌套

    //左侧dock设置
    leftdock = new QDockWidget;
    leftdock->setObjectName("leftdock");

//    //删除标题栏
//    QWidget* lTitleBar = leftdock->titleBarWidget();
//    QWidget* lEmptyWidget = new QWidget();
//    leftdock->setTitleBarWidget(lEmptyWidget);
//    delete lTitleBar;

    //右侧dock设置
    rightdock = new QDockWidget;
    rightdock->setObjectName("rightdock");
    rightdock->setWindowTitle("编译结果");

    //添加dockwdget
    this->addDockWidget(Qt::LeftDockWidgetArea, leftdock);
    this->addDockWidget(Qt::RightDockWidgetArea, rightdock);
    splitDockWidget(leftdock,rightdock,Qt::Horizontal);

    myConnect();//连接槽函数

}

MainWindow::~MainWindow()
{
    delete ui;
    delete leftdock;
    delete rightdock;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    int width1 = int(this->width()*0.7);//左边的停靠窗宽是主界面的0.15倍
    int width2 = int(this->width()*0.3);//右边的停靠窗宽是主界面的0.85倍
    this->resizeDocks({leftdock,rightdock},{width1,width2},Qt::Horizontal);//设置左右水平布局
}

//连接信号和槽函数
void MainWindow::myConnect()
{
    QSize iconSize(50, 50);  // 设置图标的宽度和高度
    //工具栏添加图片
    QPushButton *portBtn_new = new QPushButton(this);
    portBtn_new->setIcon(QIcon("./icon/new.png"));	//按钮添加图片
    portBtn_new->setToolTip("新建");			//鼠标移动到按钮上时显示提示
    portBtn_new->setIconSize(iconSize);

    QPushButton *portBtn_open = new QPushButton(this);
    portBtn_open->setIcon(QIcon("./icon/open.png"));	//按钮添加图片
    portBtn_open->setToolTip("打开");			//鼠标移动到按钮上时显示提示
    portBtn_open->setIconSize(iconSize);

    QPushButton *portBtn_save = new QPushButton(this);
    portBtn_save->setIcon(QIcon("./icon/save.png"));	//按钮添加图片
    portBtn_save->setToolTip("保存");			//鼠标移动到按钮上时显示提示
    portBtn_save->setIconSize(iconSize);

    QPushButton *portBtn_save2 = new QPushButton(this);
    portBtn_save2->setIcon(QIcon("./icon/save2.png"));	//按钮添加图片
    portBtn_save2->setToolTip("另存为");			//鼠标移动到按钮上时显示提示
    portBtn_save2->setIconSize(iconSize);

    QPushButton *portBtn_quit = new QPushButton(this);
    portBtn_quit->setIcon(QIcon("./icon/quit.png"));	//按钮添加图片
    portBtn_quit->setToolTip("退出");			//鼠标移动到按钮上时显示提示
    portBtn_quit->setIconSize(iconSize);

    QPushButton *portBtn_help = new QPushButton(this);
    portBtn_help->setIcon(QIcon("./icon/help.png"));	//按钮添加图片
    portBtn_help->setToolTip("帮助");			//鼠标移动到按钮上时显示提示
    portBtn_help->setIconSize(iconSize);

    ui->mainToolBar->addWidget(portBtn_new);
    ui->mainToolBar->addWidget(portBtn_open);
    ui->mainToolBar->addSeparator(); //添加分 隔符
    ui->mainToolBar->addWidget(portBtn_save);
    ui->mainToolBar->addWidget(portBtn_save2);
    ui->mainToolBar->addSeparator(); //添加分 隔符
    ui->mainToolBar->addWidget(portBtn_quit);
    ui->mainToolBar->addWidget(portBtn_help);//根据工具栏添加方式选择添加按钮方式
    ui->mainToolBar->addSeparator(); //添加分 隔符

    connect(portBtn_quit, SIGNAL(clicked()), this, SLOT(on_actionClose_triggered()));
    connect(portBtn_help, SIGNAL(clicked()), this, SLOT(help()));
}

void MainWindow::help(){
    QMessageBox::aboutQt(this,tr("关于Qt"));
}

//打开文件槽函数
void MainWindow::on_actionOpen_triggered()
{

}

//新建文件槽函数
void MainWindow::on_actionNew_triggered()
{

}

//保存文件槽函数
void MainWindow::on_actionSave_triggered(){

}

//另存为文件槽函数
void MainWindow::on_actionSave2_triggered(){

}

//关于Qt槽函数
void MainWindow::on_actionQt_triggered()
{
    QMessageBox::aboutQt(this,tr("关于Qt"));
}

//工具栏槽函数
void MainWindow::on_actionTool_triggered(bool checked){
    if(checked)
    {
        ui->mainToolBar->show();
    }
    else
    {
        ui->mainToolBar->hide();
    }
}

//关于作者槽函数
void MainWindow::on_actionAuthor_triggered()
{
    QMessageBox box;
    box.setWindowTitle(tr("关于制作者"));
    box.setIcon(QMessageBox::Information);
    box.setText(tr("Author : TJ \n"
                   "Welcome to Computer Science \n"));
    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec() == QMessageBox::Accepted)
        box.close();
}

//动作关闭程序槽函数
void MainWindow::on_actionClose_triggered()
{
    close();
}
