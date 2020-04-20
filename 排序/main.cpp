#include "qgsort.hpp"
#include "random.hpp"
#include "link.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    system("color F0");
    NUM.init_t_thousand();
    NUM.init_f_thousand();
    NUM.init_t_h_thousand();
    int i;
    cout << "插入排序" << endl;
    cout << "10000数据：" << insert_10000_data() << "ms" << endl;
    cout << "50000数据：" << insert_50000_data() << "ms" << endl;
    cout << "200000数据：" << insert_200000_data() << "ms" << endl;
    cout << "100k*100数据：" << insert_100_data() << "ms" << endl << endl;
    cout << "归并排序" << endl;
    cout << "10000数据：" << merge_10000_data() << "ms" << endl;
    cout << "50000数据：" << merge_50000_data() << "ms" << endl;
    cout << "200000数据：" << merge_200000_data() << "ms" << endl;
    cout << "100k*100数据：" << merge_100_data() << "ms" << endl << endl;
    cout << "快速排序（递归版" << endl;
    cout << "10000数据：" << quick_R_10000_data() << "ms" << endl;
    cout << "50000数据：" << quick_R_50000_data() << "ms" << endl;
    cout << "200000数据：" << quick_R_200000_data() << "ms" << endl;
    cout << "100k*100数据：" << quick_R_100_data() << "ms" << endl << endl;
    cout << "计数排序" << endl;
    cout << "10000数据：" << count_10000_data() << "ms" << endl;
    cout << "50000数据：" << count_50000_data() << "ms" << endl;
    cout << "200000数据：" << count_200000_data() << "ms" << endl;
    cout << "100k*100数据：" << count_100_data() << "ms" << endl << endl;
    cout << "基数排序" << endl;
    cout << "10000数据：" << radix_10000_data() << "ms" << endl;
    cout << "50000数据：" << radix_50000_data() << "ms" << endl;
    cout << "200000数据：" << radix_200000_data() << "ms" << endl;
    cout << "100k*100数据：" << radix_100_data() << "ms" << endl << endl;
    cout << "随机数据和排序后数据在目录下" << endl;
    return 0;
}

