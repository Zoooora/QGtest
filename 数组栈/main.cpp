#include "SqStack.hpp"
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
			cout << "������ջ�Ĵ�С:";
			size = input.is_limitted_digit();
			if (initStack(Sqstack_1, size)) {
				cout << "�ɹ�������������Ĵ�СΪ" << size << "��ջ" << endl;
			}
			break;
		case(2):
			isEmptyStack(Sqstack_1);
			break;
		case(3):
			if (getTopStack(Sqstack_1, &e1)) {
				cout << "��ջջ��Ԫ��Ϊ" << e1 << endl;
			}
			break;
		case(4):
			if (clearStack(Sqstack_1)) {
				cout << "���" << endl;
			}
			break;
		case(5):
			if (destroyStack(Sqstack_1)) {
				cout << "���" << endl;
				goto C;
			}
			break;
		case(6):
			if (stackLength(Sqstack_1, &len)) {
				cout << "��ջ�ֳ���Ϊ" << len << endl;
			}
			break;
		case(7):
			cout << "���������ݣ�";
			data = input.is_unlimitted_digit();
			if (pushStack(Sqstack_1, data)) {
				cout << "���" << endl;
			}
			break;
		case(8):
			if (popStack(Sqstack_1, &back)) {
				cout << "���" << endl;
			}
			break;
		case(9):
			if (destroyStack(Sqstack_1)) {
				cout << "���" << endl;
				return 0;
			}
		}
	}
	return 0;
}