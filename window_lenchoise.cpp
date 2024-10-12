#include "window_lenchoise.h"
#include "ui_window_lenchoise.h"

Window_LenChoise::Window_LenChoise(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_LenChoise)
{
    ui->setupUi(this);
}

Window_LenChoise::~Window_LenChoise()
{
    delete ui;
}

int Window_LenChoise::get_answer(){
    return answer;
}
bool Window_LenChoise::get_flag(){
    return ok;
}


void Window_LenChoise::on_pushButton_clicked()
{
    answer = ui->spinBox->value();
    ok = true;
    this->close();
}

