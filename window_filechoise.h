#ifndef WINDOW_FILECHOISE_H
#define WINDOW_FILECHOISE_H

#include <QDialog>

namespace Ui {
class Window_FileChoise;
}

class Window_FileChoise : public QDialog
{
    Q_OBJECT


public:
    explicit Window_FileChoise(QWidget *parent = nullptr);
    ~Window_FileChoise();
    int get_answer();
    bool get_flag();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Window_FileChoise *ui;
    int answer;
    bool ok = false;
};

#endif // WINDOW_FILECHOISE_H
