#include "link.hpp"
#include "inputController.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
inputController input;

int main() {
	system("color F0");
	srand(time(NULL));
	int size, i;
	int* a;
	cout << "�����������С��";
	size = input.is_limitted_digit();
	a = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		a[i] = rand() % 3;
	}
	FILE* p = fopen("color.txt", "w+");
	for (int k = 0; k < size; k++) {
		fprintf(p, "%d ", a[k]);
	}
	fclose(p);
	ColorSort(a, size);
	FILE* tp = fopen("sort.txt", "w+");
	for (int k = 0; k < size; k++) {
		fprintf(tp, "%d ", a[k]);
	}
	fclose(tp);
	cout << "�ļ������Ŀ¼��";
	return 0;
}