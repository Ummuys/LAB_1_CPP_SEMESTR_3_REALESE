#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "window_bubblesort.h"
#include "window_quicksort.h"
#include "window_insertionsort.h"
#include "window_heapsort.h"
#include "window_mergesort.h"
#include "window_selectionsort.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Window_BubbleSort wbs;
    Window_Quicksort qs;
    Window_InsertionSort ins;
    Window_HeapSort hs;
    Window_MergeSort ms;
    Window_SelectionSort ss;
};
#endif // MAINWINDOW_H
