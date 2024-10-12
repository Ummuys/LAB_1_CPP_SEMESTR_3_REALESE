#pragma once
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <QString>
using namespace std;

int convert_char_to_int(const char* adress, long long*& nums, int len);
void fill_int_file(const char* adress, int len);
void fill_string_file(const char* adress, int len);
int work_with_string_and_file(const char* adress, char**& nums, int len);
int count_space(const char* adress);
bool is_empty_file(QString adress);
void get_name_of_sort(fstream& res, int ans);
void copy_file_to_file(char * into_adree, char * to_adress);

template <typename T, typename N>
void get_result(T* arr, int len, char * adress, int ans, N time) {
    fstream res(adress, ios::out);
    res << "||=========== INFO ===========||" << "\n";
    get_name_of_sort(res, ans);
    res << "Len of array: " << len << " elemnts" << "\n";
    if(ans)res << "Waste time: " << time.count() << " ms" << "\n";
    res << "||=========== INFO ===========||" << "\n" << '\n';

    res << "Sorted mass: " << "\n";
    for (int i = 0; i < len; i++) {
        res << arr[i];
        if (i + 1 < len) {
            if (i % 10 == 0 && i) {
                res << "\n";
            }
            else {
                res << ' ';
            }
        }
    }
    res.close();
}
