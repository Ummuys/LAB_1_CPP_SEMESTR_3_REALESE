#ifndef WINDOW_BUBBLESORT_H
#define WINDOW_BUBBLESORT_H

#include <QDialog>
#include <QMovie>
#include <QWidget>
#include <QLabel>

namespace Ui {
class Window_BubbleSort;
}

class Window_BubbleSort : public QDialog
{
    Q_OBJECT

public:
    explicit Window_BubbleSort(QWidget *parent = nullptr);
    ~Window_BubbleSort();
    QMovie * bs_movie;
    QString get_adress_f();
    QString get_adress_s();
    bool get_is_admin();


private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Window_BubbleSort *ui;
    QString adress_f, adress_s;
    bool admin_file;
};

#endif // WINDOW_BUBBLESORT_H
