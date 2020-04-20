
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <cstdlib>

class SORT {
public:
    /**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
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
     *  @description : �鲢���򣨺ϲ����飩
     *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
     *  @description : �鲢����
     *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
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
     *  @description : �������򣨵ݹ�棩
     *  @param       : ����ָ��a���������begin�������յ�end
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
     *  @description : �������򣨷ǵݹ�棩
     *  @param       : ����ָ��a�����鳤��size
     */
    void QuickSort(int* a, int size);


    /**
     *  @name        : void QuickSort(int *a, int begin, int end)
     *  @description : �������������ţ�
     *  @param       : ����ָ��a���������begin�������յ�end
     */
    int Partition(int* a, int begin, int end);


    /**
     *  @name        : void CountSort(int *a, int size , int max)
     *  @description : ��������
     *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
     *  @description : ������������
     *  @param       : ����ָ��a�����鳤��size
     */
    void RadixCountSort(int* a, int size) {
        int i, j, k, p = 10, digit = 1;
        for (i = 0; i < size; i++) {
            while (a[i] >= p) {
                digit += 1;
                p *= 10;
            }
        }//���λdigit
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
     *  @description : ��ɫ����
     *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
     */
    void ColorSort(int* a, int size);


    /**
     *  @name        : ����
     *  @description : ��һ�������������ҵ���K��/С����
     *  @param       : ����ָ��a�����鳤��size
     */
};


#endif // QUEUE_H_INCLUDED
