#include "base_func.h"
#include "sort.h"
#include "work_with_files.h"
#include <QPixmap>
#include <QDesktopServices>
#include <QRadioButton>
#include "window_filechoise.h"
#include "window_datachoise.h"
#include "window_lenchoise.h"

int msg_get_choise_file(bool& ok){
    Window_FileChoise win;
    win.exec();
    int ans = win.get_answer();
    ok = win.get_flag();
    return ans;
}

void style_button(QWidget * window, QPushButton *& btn, QString name, int x0, int y0, int w, int h){
    btn = new QPushButton(name, window);
    btn->setGeometry(x0,y0,w,h);
}

int msg_get_len(bool& ok){
    Window_LenChoise win;
    win.exec();
    int ans = win.get_answer();
    ok = win.get_flag();
    return ans;
}

int msg_get_choise(bool& ok){
    Window_DataChoise win;
    win.exec();
    int ans = win.get_answer();
    ok = win.get_flag();
    return ans;
}

void my_sorts(int ans, QString a_in, QString a_out, bool admin_file){
    bool ok = true;
    QMessageBox box;
    box.setWindowTitle("Result");
    box.setWindowFlag(Qt::Tool);

    char adress_in[256];
    char adress_out[256];
    strcpy(adress_in, a_in.toLocal8Bit().constData());
    strcpy(adress_out, a_out.toLocal8Bit().constData());

    int len;
    if(admin_file){
        len = msg_get_len(ok);
    }
    else len = 0;

    if(ok){
        int choise = msg_get_choise(ok);
        if(!choise && ok){
            long long* arr;
            if(admin_file)fill_int_file(adress_in, len);
            len = convert_char_to_int(adress_in, arr, len);
            auto start = chrono::steady_clock::now();
            call_sort(arr, len, ans);
            auto end = chrono::steady_clock::now();
            auto result = chrono::duration_cast<chrono::milliseconds>(end - start);
            get_result(arr, len, adress_out, ans, result);
            delete[] arr;
            box.setText("Время выполнения сортировки -> " + QString::number(result.count()) + "ms");
            box.exec();
            QMessageBox * res = new QMessageBox(QMessageBox::Question,"Result","Сортировка выполнена успешно, хотите открыть файл с отсортированными данными?",
                                               QMessageBox::Yes| QMessageBox::Cancel);
            res->setWindowFlag(Qt::Tool);
            if(res->exec() == QMessageBox::Yes){
                QDesktopServices::openUrl(QUrl(a_out));
            }
            delete res;
        }
        else if(choise && ok){
            char** arr;
            if(admin_file)fill_string_file(adress_in, len);
            len = work_with_string_and_file(adress_in, arr, len);
            auto start = chrono::steady_clock::now();
            call_sort(arr, len, ans);
            auto end = chrono::steady_clock::now();
            auto result = chrono::duration_cast<chrono::milliseconds>(end - start);
            get_result(arr, len, adress_out, ans, result);
            for (int i = 0; i < len; i++) {
                delete[] arr[i];
            }
            delete[] arr;
            box.setText("Время выполнения сортировки -> " + QString::number(result.count()) + "ms");
            box.exec();
            QMessageBox * res = new QMessageBox(QMessageBox::Information,"Result","Сортировка выполнена успешно, хотите открыть файл с отсортированными данными?",
                                               QMessageBox::Yes| QMessageBox::No);
            if(res->exec() == QMessageBox::Yes){
                QDesktopServices::openUrl(QUrl(a_out));

            }
            delete res;
        }
    }
}


void get_adress(QString &ad){
    ad = QFileDialog::getOpenFileName(0, "Открыть", "", "*.txt");
}


void mem_copy(long long * from, long long * to, int len){
    for(int i = 0; i < len; i++){
        to[i] = from[i];
    }
}
void mem_copy(char ** from, char ** to, int len){
    for(int i = 0; i < len; i++){
        int j = 0;
        for(;from[i][j]; j++){
            to[i][j] = from[i][j];
        }
    }
}


void do_all(){
    QString adress_in;
    bool admin_file;
    bool set_in_file;
    int my_or_basic = msg_get_choise_file(set_in_file);
    // Выбрать свой файл или с рандомными данными
    if(!set_in_file)return;
    if(!my_or_basic){
        adress_in = "C:\\Users\\Ummuys\\Desktop\\Labs\\CPP\\Lab_1_Realese\\basic_txt.txt";
        admin_file = true;
    }
    else{
        get_adress(adress_in);
        if(!adress_in.isEmpty()){
            if(is_empty_file(adress_in)){
                QDesktopServices::openUrl(QUrl(adress_in));
            }
            admin_file = false;
        }
        else return;
    }

    //Выбор файла на вывод
    QMessageBox box;
    box.setText(QString("Выберите, пожалуйста, файл для вывода данных"));
    box.setWindowTitle("Sorts");
    box.setWindowFlag(Qt::Tool);
    box.exec();
    QString adress_out;
    get_adress(adress_out);
    if(adress_out.isEmpty())return;

    // Если выбрали не свой файл, то получаем длину
    int len = 0;
    if(admin_file){
        bool set_len;
        len = msg_get_len(set_len);
        if(!set_len)return;
    }
    //Узнаем что мы будем заполнять
    bool set_data;
    int int_or_str = msg_get_choise(set_data);
    if(!set_data)return;

    //Получаем заветный адресс
    char adress_ch_in[256];
    strcpy(adress_ch_in, adress_in.toLocal8Bit().constData());

    char adress_ch_out[256];
    strcpy(adress_ch_out, adress_out.toLocal8Bit().constData());

    chrono::milliseconds arr_time[6];

    if(!int_or_str){
        long long* arr;
        if(admin_file)fill_int_file(adress_ch_in, len);
        len = convert_char_to_int(adress_ch_in, arr, len);
        long long * arr_copy = new long long[len];
        for(int k = 0; k < 6; k++){
            mem_copy(arr, arr_copy, len);
            auto start = chrono::steady_clock::now();
            call_sort(arr_copy, len, k+1);
            auto end = chrono::steady_clock::now();
            arr_time[k] = chrono::duration_cast<chrono::milliseconds>(end - start);
        }

        get_result(arr_copy, len, adress_ch_out, 0, arr_time[0]);
    }

    else{
        char** arr;
        if(admin_file)fill_string_file(adress_ch_in, len);
        len = work_with_string_and_file(adress_ch_in, arr, len);
        char ** arr_copy = new char*[len];

        for(int i = 0; i < len; i++){
            arr_copy[i] = new char[256];
        }

        for(int k = 0; k < 6; k++){
            mem_copy(arr, arr_copy, len);
            auto start = chrono::steady_clock::now();
            call_sort(arr_copy, len, k+1);
            auto end = chrono::steady_clock::now();
            arr_time[k] = chrono::duration_cast<chrono::milliseconds>(end - start);
        }

        get_result(arr_copy, len, adress_ch_out, 0, arr_time[0]);

        for (int i = 0; i < len; i++) {
            delete[] arr_copy[i];
        }
        delete[] arr_copy;

        for (int i = 0; i < len; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    int max_value_slow = 0;
    for(int i = 0; i < 3; i++){
        if(max_value_slow < arr_time[i].count())max_value_slow = arr_time[i].count();
    }

    int max_value_quick = 0;
    for(int i = 3; i < 6; i++){
        if(max_value_quick < arr_time[i].count())max_value_quick = arr_time[i].count();
    }

    QBarSeries * slow_series = new QBarSeries();
    QBarSeries * quick_series = new QBarSeries();

    QBarSet * slow_set = new QBarSet("ms");
    QBarSet * quick_set = new QBarSet("ms");

    for(int i = 0; i < 3; i++){
        slow_set->append(arr_time[i].count());
    }

    for(int i = 3; i < 6; i++){
        quick_set->append(arr_time[i].count());
    }

    quick_series->append(quick_set);
    slow_series->append(slow_set);


    QChart * slow_chart = new QChart();
    slow_chart->addSeries(slow_series);
    slow_chart->setTitle("Result 1");
    slow_chart->setAnimationOptions(QChart::SeriesAnimations);

    QChart * quick_chart = new QChart();
    quick_chart->addSeries(quick_series);
    quick_chart->setTitle("Result 2");
    quick_chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList slow_sorts;
    slow_sorts.append("SelectionSort");
    slow_sorts.append("BubbleSort");
    slow_sorts.append("InsertionSort");

    QStringList quick_sorts;
    quick_sorts.append("QuickSort");
    quick_sorts.append("MergeSort");
    quick_sorts.append("HeapSort");

    QBarCategoryAxis * slow_axisX = new QBarCategoryAxis();
    slow_axisX->append(slow_sorts);
    slow_chart->addAxis(slow_axisX, Qt::AlignBottom);
    slow_series->attachAxis(slow_axisX);

    QBarCategoryAxis * quick_axisX = new QBarCategoryAxis();
    quick_axisX->append(quick_sorts);
    quick_chart->addAxis(quick_axisX, Qt::AlignBottom);
    quick_series->attachAxis(quick_axisX);

    QValueAxis * slow_axisY = new QValueAxis();
    slow_axisY->setRange(0, max_value_slow);
    slow_chart->addAxis(slow_axisY, Qt::AlignLeft);
    slow_series->attachAxis(slow_axisY);

    QValueAxis * quick_axisY = new QValueAxis();
    quick_axisY->setRange(0, max_value_quick);
    quick_chart->addAxis(quick_axisY, Qt::AlignLeft);
    quick_series->attachAxis(quick_axisY);

    slow_chart->legend()->setVisible(true);
    slow_chart->legend()->setAlignment(Qt::AlignBottom);
    slow_chart->setVisible(true);

    quick_chart->legend()->setVisible(true);
    quick_chart->legend()->setAlignment(Qt::AlignBottom);
    quick_chart->setVisible(true);

    QChartView * slow_chartview = new QChartView(slow_chart);
    slow_chartview->setWindowTitle("Slow sorts");
    slow_chartview->move(960,200);
    slow_chartview->setMinimumHeight(400);
    slow_chartview->setMinimumWidth(800);
    slow_chartview->setRenderHint(QPainter::Antialiasing);
    slow_chartview->setVisible(true);

    QChartView * quick_chartview = new QChartView(quick_chart);
    quick_chartview->setWindowTitle("Quick sorts");
    quick_chartview->move(0,200);
    quick_chartview->setMinimumHeight(400);
    quick_chartview->setMinimumWidth(800);
    quick_chartview->setRenderHint(QPainter::Antialiasing);
    quick_chartview->setVisible(true);


    if(!(slow_chartview->isVisible())){
        delete slow_series;
        delete slow_set;
        delete slow_chart;
        delete slow_axisX;
        delete slow_axisY;
        delete slow_chartview;
    }


    if(!(quick_chartview->isVisible())){
        delete quick_series;
        delete quick_set;
        delete quick_chart;
        delete quick_axisX;
        delete quick_axisY;
        delete quick_chartview;
    }


}
