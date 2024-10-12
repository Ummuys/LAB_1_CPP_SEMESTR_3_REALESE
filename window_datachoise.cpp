#include "window_datachoise.h"
#include "ui_window_datachoise.h"
#include <QMessageBox>

Window_DataChoise::Window_DataChoise(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_DataChoise)
{
    ui->setupUi(this);
}

Window_DataChoise::~Window_DataChoise()
{
    delete ui;
}


int Window_DataChoise::get_answer(){
    return answer;
}

bool Window_DataChoise::get_flag(){
    return ok;
}

void Window_DataChoise::on_pushButton_clicked()
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

