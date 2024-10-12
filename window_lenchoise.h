#ifndef WINDOW_LENCHOISE_H
#define WINDOW_LENCHOISE_H

#include <QDialog>

namespace Ui {
class Window_LenChoise;
}

class Window_LenChoise : public QDialog
{
    Q_OBJECT

public:
    explicit Window_LenChoise(QWidget *parent = nullptr);
    ~Window_LenChoise();
    int get_answer();
    bool get_flag();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Window_LenChoise *ui;
    int answer;
    bool ok = false;
};

#endif // WINDOW_LENCHOISE_H
