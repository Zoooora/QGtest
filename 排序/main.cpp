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
    cout << "��������" << endl;
    cout << "10000���ݣ�" << insert_10000_data() << "ms" << endl;
    cout << "50000���ݣ�" << insert_50000_data() << "ms" << endl;
    cout << "200000���ݣ�" << insert_200000_data() << "ms" << endl;
    cout << "100k*100���ݣ�" << insert_100_data() << "ms" << endl << endl;
    cout << "�鲢����" << endl;
    cout << "10000���ݣ�" << merge_10000_data() << "ms" << endl;
    cout << "50000���ݣ�" << merge_50000_data() << "ms" << endl;
    cout << "200000���ݣ�" << merge_200000_data() << "ms" << endl;
    cout << "100k*100���ݣ�" << merge_100_data() << "ms" << endl << endl;
    cout << "�������򣨵ݹ��" << endl;
    cout << "10000���ݣ�" << quick_R_10000_data() << "ms" << endl;
    cout << "50000���ݣ�" << quick_R_50000_data() << "ms" << endl;
    cout << "200000���ݣ�" << quick_R_200000_data() << "ms" << endl;
    cout << "100k*100���ݣ�" << quick_R_100_data() << "ms" << endl << endl;
    cout << "��������" << endl;
    cout << "10000���ݣ�" << count_10000_data() << "ms" << endl;
    cout << "50000���ݣ�" << count_50000_data() << "ms" << endl;
    cout << "200000���ݣ�" << count_200000_data() << "ms" << endl;
    cout << "100k*100���ݣ�" << count_100_data() << "ms" << endl << endl;
    cout << "��������" << endl;
    cout << "10000���ݣ�" << radix_10000_data() << "ms" << endl;
    cout << "50000���ݣ�" << radix_50000_data() << "ms" << endl;
    cout << "200000���ݣ�" << radix_200000_data() << "ms" << endl;
    cout << "100k*100���ݣ�" << radix_100_data() << "ms" << endl << endl;
    cout << "������ݺ������������Ŀ¼��" << endl;
    return 0;
}

