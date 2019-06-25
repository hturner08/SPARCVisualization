#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <Q3DScatter>
namespace Ui {
class MainWindow;
}
#include <QDialog>
#include "properties.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QtDataVisualization::Q3DScatter *view;
    void color_graph();

private slots:
    void on_pushButton_clicked();
    void on_actionTFCoil_triggered();
    void on_actionOpen_triggered();
    void graph();

private:
    Ui::MainWindow *ui;
    Properties *property;
};

#endif // MAINWINDOW_H
