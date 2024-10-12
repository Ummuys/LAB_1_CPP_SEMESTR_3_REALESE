#pragma once
#include <QApplication>
#include <QWidget>
#include <QString>
#include <QIcon>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QColor>
#include <QFile>
#include <QLabel>
#include <QFontDatabase>
#include <QTimer>
#include <QFont>
#include <QLayout>
#include <QFileDialog>
#include <QtCore>
#include <QtCharts>

void style_button(QWidget * window, QPushButton *& btn, QString name, int x0, int y0, int w, int h);
void my_sorts(int ans, QString a_in, QString a_out, bool admin_file);

int msg_get_len(bool &ok);
int msg_get_choise(bool &ok);
int msg_get_choise_file(bool &ok);
void get_adress(QString &as);
void convert_qstr_to_c(QString str, char * c);
void do_all();
void mem_copy(long long * arr1, long long * arr2);
void mem_copy(char ** arr1, char ** ar2);
int test();
