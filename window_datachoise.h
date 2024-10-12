#ifndef WINDOW_DATACHOISE_H
#define WINDOW_DATACHOISE_H

#include <QDialog>

namespace Ui {
class Window_DataChoise;
}

class Window_DataChoise : public QDialog
{
    Q_OBJECT

public:
    explicit Window_DataChoise(QWidget *parent = nullptr);
    ~Window_DataChoise();
    int get_answer();
    bool get_flag();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Window_DataChoise *ui;
    int answer;
    bool ok = false;
};

#endif // WINDOW_DATACHOISE_H
