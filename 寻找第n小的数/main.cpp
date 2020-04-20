#include "sort.hpp"
#include "inputController.hpp"
#include <cstdlib>

inputController input;

int main() {
	system("color F0");
	int size, i, target, No;
	int* a;
	cout << "请输入数组大小：";
	size = input.is_limitted_digit();
	a = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		cout << "请输入第" << i + 1 << "号数据：";
		a[i] = input.is_unlimitted_digit();
	}
	cout << "请输入想寻找的第几小的数：";
	No = input.is_limitted_digit();
	target = sort(a, size, No);
	if (target != -114514) {
		cout << "该数组中第" << No << "小的数为：" << target << endl;
	}
	free(a);
	a = nullptr;
	return 0;
}