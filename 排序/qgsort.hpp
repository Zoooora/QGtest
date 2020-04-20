
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <cstdlib>

class SORT {
public:
    /**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
    void insertSort(int* a, int n) {
        int front, back, mark, min, temp;
        for (front = 0; front < n - 1; front++) {
            mark = -1;
            min = a[front];
            for (back = front + 1; back < n; back++) {
                if (a[back] < min) {
                    mark = back;
                    min = a[back];
                }
            }
            if (mark != -1) {
                temp = a[front];
                a[front] = a[mark];
                a[mark] = temp;
            }
        }
    }


    /**
     *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
     *  @description : 归并排序（合并数组）
     *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
     */
    void MergeArray(int* a, int begin, int mid, int end, int* temp) {
        int i, j, k;
        i = k = begin;
        j = mid + 1;
        while (i <= mid && j <= end) {
            if (a[i] < a[j]) {
                temp[k++] = a[i++];
            }
            else {
                temp[k++] = a[j++];
            }
        }
        while (i < mid + 1) {
            temp[k++] = a[i++];
        }
        while (j <= end) {
            temp[k++] = a[j++];
        }
        for (i = begin; i <= end; i++) {
            a[i] = temp[i];
        }
    }


    /**
     *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
     *  @description : 归并排序
     *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
     */
    void MergeSort(int* a, int begin, int end, int* temp) {
        if (begin < end) {
            int mid = (begin + end) / 2;
            MergeSort(a, begin, mid, temp);
            MergeSort(a, mid + 1, end, temp);
            MergeArray(a, begin, mid, end, temp);
        }
    }


    /**
     *  @name        : void QuickSort(int *a, int begin, int end);
     *  @description : 快速排序（递归版）
     *  @param       : 数组指针a，数组起点begin，数组终点end
     */
    void QuickSort_Recursion(int* a, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int i = begin;
        int j = end;
        int key = a[begin];
        while (i < j) {
            while (i < j && a[j] >= key) {
                j--;
            }
            a[i] = a[j];
            while (i < j && a[i] <= key) {
                i++;
            }
            a[j] = a[i];
        }
        a[i] = key;
        QuickSort_Recursion(a, begin, i - 1);
        QuickSort_Recursion(a, i + 1, end);
    }


    /**
     *  @name        : void QuickSort(int *a,int size)
     *  @description : 快速排序（非递归版）
     *  @param       : 数组指针a，数组长度size
     */
    void QuickSort(int* a, int size);


    /**
     *  @name        : void QuickSort(int *a, int begin, int end)
     *  @description : 快速排序（枢轴存放）
     *  @param       : 数组指针a，数组起点begin，数组终点end
     */
    int Partition(int* a, int begin, int end);


    /**
     *  @name        : void CountSort(int *a, int size , int max)
     *  @description : 计数排序
     *  @param       : 数组指针a，数组长度size，数组最大值max
     */
    void CountSort(int* a, int size, int max) {
        int *temp;
        int i, j, position;
        temp = (int*)malloc(sizeof(int) * size);
        for (i = 0; i < size; i++) {
            temp[i] = 0;
        }
        for (i = 0; i < size; i++) {
            position = 0;
            for (j = 0; j < size; j++) {
                if (a[j] < a[i]) {
                    position += 1;
                }
            }
            while (temp[position] != 0) {
                position += 1;
            }
            temp[position] = a[i];
        }
        for (i = 0; i < size; i++) {
            a[i] = temp[i];
        }
        free(temp);
    }


    /**
     *  @name        : void RadixCountSort(int *a,int size)
     *  @description : 基数计数排序
     *  @param       : 数组指针a，数组长度size
     */
    void RadixCountSort(int* a, int size) {
        int i, j, k, p = 10, digit = 1;
        for (i = 0; i < size; i++) {
            while (a[i] >= p) {
                digit += 1;
                p *= 10;
            }
        }//最高位digit
        int* temp1, count[10];
        int tens = 1;
        temp1 = (int*)malloc(sizeof(int) * size);
        for (i = 1; i <= digit; i++) {
            for (j = 0; j < 10; j++) {
                count[j] = 0;
            }
            for (j = 0; j < size; j++) {
                k = (a[j] / tens) % 10;
                count[k] += 1;
            }
            for (j = 1; j < 10; j++) {
                count[j] = count[j - 1] + count[j];
            }
            for (j = size - 1; j >= 0; j--) {
                k = (a[j] / tens) % 10;
                temp1[count[k] - 1] = a[j];
                count[k] -= 1;
            }
            for (j = 0; j < size; j++) {
                a[j] = temp1[j];
            }
            tens *= 10;
        }
        free(temp1);
    }


    /**
     *  @name        : void ColorSort(int *a,int size)
     *  @description : 颜色排序
     *  @param       : 数组指针a（只含0，1，2元素），数组长度size
     */
    void ColorSort(int* a, int size);


    /**
     *  @name        : 自拟
     *  @description : 在一个无序序列中找到第K大/小的数
     *  @param       : 数组指针a，数组长度size
     */
};


#endif // QUEUE_H_INCLUDED
