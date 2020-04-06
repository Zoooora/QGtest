#include "SqStack.hpp"
#include "linked.hpp"
#include "inputController.hpp"
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int map() {
	cout << endl << "~~~~~~~~~~~~~~~" << endl;
	cout << "基于数组的顺序栈操作菜单" << endl;
	cout << "——————————————————————————————" << endl;
	cout << "1.初始化栈" << endl;
	cout << "2.判断栈是否为空" << endl;
	cout << "3.获得栈顶元素" << endl;
	cout << "4.清空栈" << endl;
	cout << "5.销毁栈" << endl;
	cout << "6.获得栈的长度" << endl;
	cout << "7.入栈" << endl;
	cout << "8.出栈" << endl;
	cout << "9.结束并销毁栈" << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;
	cout << "输入选项：";
	return 0;
}

int main() {
	system("color F0");
	C:SqStack* Sqstack_1 = (SqStack*)malloc(sizeof(SqStack));
	Sqstack_1->top = -1;
	Sqstack_1->elem = nullptr;
	int n,size,data;
	int e1;
	int len;
	int back;
	inputController input;
	while (true) {
		map();
		n = input.is_limitted_digit(9);
		switch (n) {
		case(1):
			cout << "请输入栈的大小:";
			size = input.is_limitted_digit();
			if (initStack(Sqstack_1, size)) {
				cout << "成功建立基于数组的大小为" << size << "的栈" << endl;
			}
			break;
		case(2):
			isEmptyStack(Sqstack_1);
			break;
		case(3):
			if (getTopStack(Sqstack_1, &e1)) {
				cout << "该栈栈顶元素为" << e1 << endl;
			}
			break;
		case(4):
			if (clearStack(Sqstack_1)) {
				cout << "完成" << endl;
			}
			break;
		case(5):
			if (destroyStack(Sqstack_1)) {
				cout << "完成" << endl;
				goto C;
			}
			break;
		case(6):
			if (stackLength(Sqstack_1, &len)) {
				cout << "该栈现长度为" << len << endl;
			}
			break;
		case(7):
			cout << "请输入数据：";
			data = input.is_unlimitted_digit();
			if (pushStack(Sqstack_1, data)) {
				cout << "完成" << endl;
			}
			break;
		case(8):
			if (popStack(Sqstack_1, &back)) {
				cout << "完成" << endl;
			}
			break;
		case(9):
			if (destroyStack(Sqstack_1)) {
				cout << "完成" << endl;
				return 0;
			}
		}
	}
	return 0;
}