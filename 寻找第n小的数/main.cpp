#include "sort.hpp"
#include "inputController.hpp"
#include <cstdlib>

inputController input;

int main() {
	system("color F0");
	int size, i, target, No;
	int* a;
	cout << "�����������С��";
	size = input.is_limitted_digit();
	a = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		cout << "�������" << i + 1 << "�����ݣ�";
		a[i] = input.is_unlimitted_digit();
	}
	cout << "��������Ѱ�ҵĵڼ�С������";
	No = input.is_limitted_digit();
	target = sort(a, size, No);
	if (target != -114514) {
		cout << "�������е�" << No << "С����Ϊ��" << target << endl;
	}
	free(a);
	a = nullptr;
	return 0;
}