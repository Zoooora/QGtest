#include "LinkStack.hpp"
#include "linked.hpp"
#include "inputController.hpp"
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int map() {
	cout << endl << "~~~~~~~~~~~~~~~" << endl;
	cout << "基于链表的顺序栈操作菜单" << endl;
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
	C:LinkStack* LinkStack_1 = (LinkStack*)malloc(sizeof(LinkStack));
	LinkStack_1->count = 0;
	LinkStack_1->top = nullptr;
	int n, size, data;
	int e1;
	int len;
	int back;
	inputController input;
	while (true) {
		map();
		n = input.is_limitted_digit(9);
		switch (n) {
		case(1):
			if (initLStack(LinkStack_1)) {
				cout << "完成" << endl;
			}
			break;
		case(2):
			isEmptyLStack(LinkStack_1);
			break;
		case(3):
			if (getTopLStack(LinkStack_1, &e1)) {
				cout << "该栈栈顶元素为" << e1 << endl;
			}
			break;
		case(4):
			if (clearLStack(LinkStack_1)) {
				cout << "完成" << endl;
			}
			break;
		case(5):
			if (destroyLStack(LinkStack_1)) {
				cout << "完成" << endl;
				goto C;
			}
			break;
		case(6):
			if (LStackLength(LinkStack_1,&len)) {
				cout << "该栈现长度为" << len << endl;
			}
			break;
		case(7):
			cout << "请输入数据：";
			data = input.is_unlimitted_digit();
			if (pushLStack(LinkStack_1, data)) {
				cout << "完成" << endl;
			}
			break;
		case(8):
			if (popLStack(LinkStack_1, &back)) {
				cout << "完成" << endl;
			}
			break;
		case(9):
			if (destroyLStack(LinkStack_1)) {
				cout << "完成" << endl;
				return 0;
			}
		}
	}
	return 0;
}