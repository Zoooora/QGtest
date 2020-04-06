#include "LinkStack.hpp"
#include "linked.hpp"
#include "inputController.hpp"
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int map() {
	cout << endl << "~~~~~~~~~~~~~~~" << endl;
	cout << "���������˳��ջ�����˵�" << endl;
	cout << "������������������������������������������������������������" << endl;
	cout << "1.��ʼ��ջ" << endl;
	cout << "2.�ж�ջ�Ƿ�Ϊ��" << endl;
	cout << "3.���ջ��Ԫ��" << endl;
	cout << "4.���ջ" << endl;
	cout << "5.����ջ" << endl;
	cout << "6.���ջ�ĳ���" << endl;
	cout << "7.��ջ" << endl;
	cout << "8.��ջ" << endl;
	cout << "9.����������ջ" << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;
	cout << "����ѡ�";
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
				cout << "���" << endl;
			}
			break;
		case(2):
			isEmptyLStack(LinkStack_1);
			break;
		case(3):
			if (getTopLStack(LinkStack_1, &e1)) {
				cout << "��ջջ��Ԫ��Ϊ" << e1 << endl;
			}
			break;
		case(4):
			if (clearLStack(LinkStack_1)) {
				cout << "���" << endl;
			}
			break;
		case(5):
			if (destroyLStack(LinkStack_1)) {
				cout << "���" << endl;
				goto C;
			}
			break;
		case(6):
			if (LStackLength(LinkStack_1,&len)) {
				cout << "��ջ�ֳ���Ϊ" << len << endl;
			}
			break;
		case(7):
			cout << "���������ݣ�";
			data = input.is_unlimitted_digit();
			if (pushLStack(LinkStack_1, data)) {
				cout << "���" << endl;
			}
			break;
		case(8):
			if (popLStack(LinkStack_1, &back)) {
				cout << "���" << endl;
			}
			break;
		case(9):
			if (destroyLStack(LinkStack_1)) {
				cout << "���" << endl;
				return 0;
			}
		}
	}
	return 0;
}