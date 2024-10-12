#ifndef WINDOW_MERGESORT_H
#define WINDOW_MERGESORT_H

#include <QDialog>
#include <QMovie>
#include <QWidget>
#include <QLabel>

namespace Ui {
class Window_MergeSort;
}

class Window_MergeSort : public QDialog
{
    Q_OBJECT

public:
    explicit Window_MergeSort(QWidget *parent = nullptr);
    ~Window_MergeSort();
    QMovie * ms_movie;
    QString get_adress_f();
    QString get_adress_s();
    bool get_is_admin();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Window_MergeSort *ui;
    QString adress_f, adress_s;
    bool admin_file;
};

#endif // WINDOW_MERGESORT_H
