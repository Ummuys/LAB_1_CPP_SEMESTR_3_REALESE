#pragma once

template <typename T>
void my_swap(T& obj1, T& obj2) {
    T tmp = obj1;
    obj1 = obj2;
    obj2 = tmp;
}

template <typename T>
int comp(T * obj1, T * obj2) {
    int is_bigger = 0;
    bool first_came = true;
    while (*obj1 && *obj2) {
        if (first_came) {
            if (*obj1 > *obj2) {
                is_bigger = 1;
                first_came = false;
            }

            else if (*obj1 < *obj2) {
                is_bigger = 0;
                first_came = false;
            }
        }
        obj1++;
        obj2++;
    }
    if (!(*obj2) && (*obj1))return 1;
    else if (!(*obj1) && (*obj2))return 0;
    else return is_bigger;;
}
template <typename T>
int comp(T obj1, T obj2) {
    return obj1 > obj2 ? 1 : 0;
}


template <typename T>
void selection_sort(T* arr, int len) {
    for (int i = 0; i < len; i++) {
        int min_i = i;
        for (int j = i + 1; j < len; j++) {
            if (comp(arr[min_i], arr[j])) min_i = j;
        }
        if (min_i != i) my_swap(arr[i], arr[min_i]);
    }
}

template <typename T>
void bubble_sort(T* arr, int len) {

    for (int i = 1; i < len; i++) {
        for (int j = 0; j < len - i; j++) {

            if (comp(arr[j], arr[j + 1]))my_swap(arr[j], arr[j + 1]);
        }
    }
}

template <typename T>
void insertion_sort(T* arr, int len) {

    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && comp(arr[j-1], arr[j]); j--) {
            my_swap(arr[j-1], arr[j]);
        }
    }
}

template <typename T>
void quick_sort(T* arr, int start, int end) {
    if (start > end) {
        return;
    }
    T mid = arr[(start + end) / 2];
    int i = start;
    int j = end;
    while (i <= j) {
        while (comp(mid,arr[i])) i++;
        while (comp(arr[j], mid)) j--;
        if (i <= j) {
            my_swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, start, j);
    quick_sort(arr, i, end);
}

template <typename T>
void merge_sort(T* arr, int start, int end) {
    if (end - start < 2) {
        return;
    }
    if (end - start == 2 && comp(arr[start+1], arr[start])) {
        my_swap(arr[start], arr[start + 1]);
    }

    merge_sort(arr, start, start + (end - start) / 2);
    merge_sort(arr, start + (end - start) / 2, end);

    T* merge_tmp = new T[end + 1];

    int s_m = start;
    int m_m = start + (end - start) / 2;
    int e_m = m_m;
    int merge_size = 0;

    while (merge_size < end - start) {
        if (s_m >= m_m || (e_m < end && comp(arr[s_m], arr[e_m]))) {
            merge_tmp[merge_size] = arr[e_m];
            e_m++;
            merge_size++;
        }
        else {
            merge_tmp[merge_size] = arr[s_m];
            s_m++;
            merge_size++;
        }
    }

    for (int i = start; i < end; i++) {
        arr[i] = merge_tmp[i - start];
    }

    delete[] merge_tmp;
}

// HEAP SORT
template <typename T>
void sift_up(T* arr, int i) {
    while (i > 0) {
        int j = (i - 1) / 2;
        if (comp(arr[i], arr[j]))
            my_swap(arr[i], arr[j]);
        else
            break;
        i = j;
    }
}

template <typename T>
void sift_down(T* arr, int i, int last_index) {
    while (1) {
        int left_j = 2 * i + 1;
        int right_j = 2 * i + 2;
        int j = i;
        if (left_j < last_index && comp(arr[left_j], arr[j])) {
            j = left_j;
        }
        if (right_j < last_index && comp(arr[right_j], arr[j])) {
            j = right_j;
        }
        if (j != i) {
            my_swap(arr[i], arr[j]);
            i = j;
        }
        else {
            break;
        }
    }
}

template <typename T>
void heapify(T* arr, int len) {
    for (int i = 0; i < len; i++) {
        sift_up(arr, i);
    }
}

template <typename T>
void heap_sort(T* arr, int len) {

    heapify(arr, len);
    for (int last_index = len - 1; last_index > 0; last_index--) {
        my_swap(arr[0], arr[last_index]);
        sift_down(arr, 0, last_index);
    }
}


template <typename T>
void call_sort(T* arr, int len, int choose) {
    switch (choose) {
    case 1: {
        selection_sort(arr, len);
        break;
    }
    case 2: {
        bubble_sort(arr, len);
        break;
    }
    case 3: {
        insertion_sort(arr, len);
        break;
    }
    case 4: {
        quick_sort(arr, 0, len - 1);
        break;
    }
    case 5: {
        merge_sort(arr, 0, len - 1);
        break;
    }
    case 6: {
        heap_sort(arr, len);
        break;
    }
    }
}
// HEAP SORT
