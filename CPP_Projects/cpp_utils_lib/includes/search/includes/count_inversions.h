//
// Created by Artiom GESP on 10/11/19.
//

#ifndef MY_UTILS_LIB_COUNT_INVERSIONS_H
#define MY_UTILS_LIB_COUNT_INVERSIONS_H


#include <iostream>

/*
 * Counting inversions in generic arrays using merge sort
 */


template<typename T>
void count(T *arr, T *tmp, int low, int mid, int high, unsigned long long &inversions) {
    int tmp_index = low;
    int tmp_low = low;
    int tmp_mid = mid;
    int prev = 0;

    while (low < tmp_mid && mid < high) {
        if (arr[low] <= arr[mid]) {
            tmp[tmp_index++] = arr[low++];
            inversions += prev;
        } else {
            tmp[tmp_index++] = arr[mid++];
            ++prev;

        }
    }
    while (low < tmp_mid) {
        tmp[tmp_index++] = arr[low++];
        inversions += prev;
    }
    while (mid < high)
        tmp[tmp_index++] = arr[mid++];
    for (int i = tmp_low; i < high; ++i)
        arr[i] = tmp[i];
}

template<typename T>
void _count_inversions(T *arr, T *tmp, int low, int mid, int high, unsigned long long &inversions) {
    int mid1;
    int mid2;
    if (low == mid) {
        return;
    }
    mid1 = (low + mid) / 2;
    mid2 = (mid + high) / 2;

    _count_inversions(arr, tmp, low, mid1, mid, inversions);
    _count_inversions(arr, tmp, mid, mid2, high, inversions);

    if (arr[mid - 1] > arr[mid])
        count(arr, tmp, low, mid, high, inversions);
}


template<typename T>
unsigned long long count_inversions(T *arr, size_t size) {
    T *tmp = new T[size];
    unsigned long long inversions = 0;
    _count_inversions(arr, tmp, 0, size / 2, size, inversions);
    delete[] tmp;
    return inversions;
}
#endif //MY_UTILS_LIB_COUNT_INVERSIONS_H
