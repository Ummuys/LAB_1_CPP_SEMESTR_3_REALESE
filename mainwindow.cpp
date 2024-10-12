#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "base_func.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sorts");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    qs.show();
}


void MainWindow::on_pushButton_clicked()
{
    wbs.show();
}

void MainWindow::on_pushButton_6_clicked()
{
    ins.show();
}


void MainWindow::on_pushButton_5_clicked()
{
    hs.show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ms.show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ss.show();
}


void MainWindow::on_pushButton_7_clicked()
{
    do_all();
}

