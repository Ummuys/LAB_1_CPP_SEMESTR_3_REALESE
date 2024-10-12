#ifndef WINDOW_QUICKSORT_H
#define WINDOW_QUICKSORT_H

#include <QDialog>
#include <QMovie>
#include <QWidget>
#include <QLabel>

namespace Ui {
class Window_Quicksort;
}

class Window_Quicksort : public QDialog
{
    Q_OBJECT

public:
    explicit Window_Quicksort(QWidget *parent = nullptr);
    ~Window_Quicksort();
    QMovie * qs_movie;
    QString get_adress_f();
    QString get_adress_s();
    bool get_is_admin();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Window_Quicksort *ui;
    QString adress_f, adress_s;
    bool admin_file;
};

#endif // WINDOW_QUICKSORT_H
