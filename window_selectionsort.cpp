#include "window_selectionsort.h"
#include "ui_window_selectionsort.h"
#include <QPixmap>
#include <QFileDialog>
#include "base_func.h"
#include "work_with_files.h"
#include <QMessageBox>
#include <QDesktopServices>

Window_SelectionSort::Window_SelectionSort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Window_SelectionSort)
{
    ui->setupUi(this);
    QPixmap pm = QPixmap(1,1);
    pm.fill(QColor(0,0,0,0));
    this->setWindowIcon(QIcon(pm));
    ss_movie = new QMovie("C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\selectionsort.gif");
    ui->label_2->setMovie(ss_movie);
    ui->label_2->setStyleSheet("QLabel {"
                               "border-style: solid;"
                               "border-width: 3px;"
                               "border-color: #696969; "
                               "}");
    ss_movie->start();
}

Window_SelectionSort::~Window_SelectionSort()
{
    delete ui;
}

QString Window_SelectionSort::get_adress_f(){
    return adress_f;
}
QString Window_SelectionSort::get_adress_s(){
    return adress_s;
}
bool Window_SelectionSort::get_is_admin(){
    return admin_file;
}


void Window_SelectionSort::on_pushButton_1_clicked()
{
    bool ok;
    int choose = msg_get_choise_file(ok);
    if(ok && !choose){
        adress_f = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        ui->pushButton_1->setText(adress_f);
        admin_file = true;
    }

    else if(ok && choose){
        get_adress(adress_f);
        if(!adress_f.isEmpty()){

            if(is_empty_file(adress_f)){
                QDesktopServices::openUrl(QUrl(adress_f));
            }

            ui->pushButton_1->setText(adress_f);
            admin_file = false;
        }
        else{
            ui->pushButton_1->setText("Файл не выбран");
        }
    }
    else{
        ui->pushButton_1->setText("Файл не выбран");
    }

}


void Window_SelectionSort::on_pushButton_2_clicked()
{
    get_adress(adress_s);
    if(!adress_s.isEmpty()){
        ui->pushButton_2->setText(adress_s);
    }
    else{
        ui->pushButton_2->setText("Файл не выбран");
    }
}


void Window_SelectionSort::on_pushButton_3_clicked(){
    QMessageBox box;
    box.setWindowTitle("Error");
    box.setWindowFlag(Qt::Tool);
    if(!adress_s.isEmpty() && !adress_f.isEmpty()){my_sorts(1,adress_f,adress_s, admin_file);}
    else if(!adress_s.isEmpty() && adress_f.isEmpty()){
        box.setText("Вы не выбрали файл ввода!");
        box.exec();
    }

    else if(adress_s.isEmpty() && !adress_f.isEmpty()){
        box.setText("Вы не выбрали файл вывода!");
        box.exec();
    }
    else{
        box.setText("Вы не выбрали оба файла!");
        box.exec();
    }
}
