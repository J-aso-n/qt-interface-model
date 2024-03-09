#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void help();

    //打开文件槽函数
    void on_actionOpen_triggered();
    //新建文件槽函数
    void on_actionNew_triggered();
    //保存文件槽函数
    void on_actionSave_triggered();
    //另存为文件槽函数
    void on_actionSave2_triggered();
    //工具栏槽函数
    void on_actionTool_triggered(bool checked);
    //关于Qt槽函数
    void on_actionQt_triggered();
    //关于作者槽函数
    void on_actionAuthor_triggered();
    //关闭程序槽函数
    void on_actionClose_triggered();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    QDockWidget *leftdock,*rightdock;
    //连接信号和槽函数
    void myConnect();
};
#endif // MAINWINDOW_H
