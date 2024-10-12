#include "work_with_files.h"
#include <QMessageBox>
#include <QDateTime>
#include <QRandomGenerator>
const size_t MAX_LEN_STR = 256;
int convert_char_to_int(const char* adress, long long*& nums, int len) {
    fstream file_in(adress);
    bool is_neg = false;
    bool is_empty = true;
    bool empty_arr = true;
    char tmp;
    long long num_tmp;
    int i = 0;
    if(!len){
        len = 10;
    }
    nums = new long long[len];
    while (file_in) {
        tmp = file_in.get();
        if (tmp >= '0' && tmp <= '9') {

            if (is_empty) {
                num_tmp = (tmp - '0');
                is_empty = false;
            }
            else {
                num_tmp *= 10;
                num_tmp += (tmp - '0');
            }

        }

        else {
            if (tmp == '-')is_neg = true;
            else {
                if (!is_empty) {
                    if (is_neg)nums[i] = -num_tmp;
                    else nums[i] = num_tmp;
                    i++;
                    empty_arr = false;
                }
                is_neg = false;
                is_empty = true;
            }
        }
    }
    return !empty_arr ? i : 0;
}

void fill_int_file(const char * adress, int len) {
    QRandomGenerator generator;
    fstream file(adress, ios::out);
    srand(time(0));
    for (int i = 0; i < len; i++) {
        qint64 value = generator.generate() & std::numeric_limits<qint64>::max();
        if (i + 1 != len) {
            file << value << ' ';
        }
        else {
            file << value  << '\0';
        }
    }
    file.close();
}

void fill_string_file(const char* adress, int len) {
    fstream file(adress, ios::out);
    srand(time(0));
    char symb;
    int rand_len;
    bool big_letter = false;
    for (int i = 0; i < len; i++) {
        rand_len = 1 + rand() % 10;
        for (int i = 0; i < rand_len; i++) {
            if (big_letter) {
                symb = 'a' + rand() % ('z' - 'a');
                file << symb;
            }
            else {
                symb = 'A' + rand() % ('Z' - 'A');
                file << symb;
                big_letter = true;
            }
        }
        if (i + 1 != len) {
            file << ' ';
        }
        big_letter = false;
    }
    file << '\0';
    file.close();
}

int count_space(const char* adress) {
    int n = 1;
    fstream file_in(adress);
    char tmp_space = file_in.get();
    while (tmp_space != EOF) {
        if (tmp_space == ' ' || tmp_space == '\n') n++;
        tmp_space = file_in.get();
    }
    file_in.close();
    return n;
}

int work_with_string_and_file(const char* adress, char**& words, int len) {
    int i = 0;
    int symb_i = 0;
    bool empty_arr = true;
    bool fill_word = false;
    if (!len) {
        len = count_space(adress);
    }
    fstream file_in(adress);
    words = new char* [len];
    for (int i = 0; i < len; i++) {
        words[i] = new char[MAX_LEN_STR];
    }
    char tmp = file_in.get();
    while (tmp != EOF) {
        if (tmp == ' ' || tmp == '\n') {
            words[i][symb_i] = '\0';
            i++;
            symb_i = 0;
            fill_word = false;
        }
        else {
            words[i][symb_i] = tmp;
            symb_i++;
            empty_arr = false;
            fill_word = true;
        }
        tmp = file_in.get();
    }

    if (fill_word)i++;

    file_in.close();
    return !empty_arr ? i : 0;
}

bool is_empty_file(QString adress){
    char ads[256];
    strcpy(ads, adress.toLocal8Bit().constData());
    fstream file(ads);
    return file.peek() == EOF;
}

void get_name_of_sort(fstream& res, int ans){
    res << "Choise of sort: ";
    switch (ans) {
    case 0: {
        res << "all";
        break;
    }
    case 1: {
        res << "selection sort";
        break;
    }
    case 2: {
        res << "bubble sort";
        break;
    }
    case 3: {
        res << "insertion sort";
        break;
    }
    case 4: {
        res << "quick sort";
        break;
    }
    case 5: {
        res << "merge sort";
        break;
    }
    case 6: {
        res << "heap sort";
        break;
    }
    }
    res << '\n';
}

void copy_file_to_file(char * into_adress, char * to_adress){
    fstream into_file(into_adress);
    fstream to_file(to_adress);
    char tmp;
    while(into_file){
        tmp = into_file.get();
        to_file << tmp;
    }
    into_file.close();
    to_file.close();
}

