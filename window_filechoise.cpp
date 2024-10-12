#include "window_filechoise.h"
#include "ui_window_filechoise.h"
#include <QMessageBox>
Window_FileChoise::Window_FileChoise(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_FileChoise)
{
    ui->setupUi(this);
}

Window_FileChoise::~Window_FileChoise()
{
    delete ui;
}




void Window_FileChoise::on_pushButton_clicked()
{
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);

    if(ui->radioButton->isChecked()){
        answer = 0;
        ok = true;
        close();

    }

    else if(ui->radioButton_2->isChecked()){
        answer = 1;
        ok = true;
        close();

    }

    else{
        box.setText("Вам нужно выбрать один из вариантов!");
        box.exec();
        ok = false;
    }
}


int Window_FileChoise::get_answer(){
    return answer;
}
bool Window_FileChoise::get_flag(){
    return ok;
}
