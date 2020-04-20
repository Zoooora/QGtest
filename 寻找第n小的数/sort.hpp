#pragma once
#include <iostream>
using namespace std;

void QuickSort_Recursion(int* a, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int i = begin;
    int j = end + 1;
    int key = a[begin];
    int temp;
    while (true) {
        while (a[++i] < key) {
            if (i == end) {
                break;
            }
        }
        while (a[--j] > key) {
            if (j == begin) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    temp = a[begin];
    a[begin] = a[j];
    a[j] = temp;
    QuickSort_Recursion(a, begin, j - 1);
    QuickSort_Recursion(a, j + 1, end);
}

int sort(int* a, int end, int No) {
    int i = 1, n = 1;
    QuickSort_Recursion(a, 0, end - 1);
    while (n < end) {
        if (a[n] != a[n - 1]) {
            i += 1;
            if (i == No) {
                break;
            }
        }
        n += 1;
    }
    if (i < No) {
        cout << "该数组没有第" << No << "小的数" << endl;
        return -114514;
    }
    return a[n];
}