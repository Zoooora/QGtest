#include <iostream>
#include "qglist.hpp"
#include "linkedList.hpp"
#include "inputController.hpp"
using namespace std;

int map() {
	cout << endl << "~~~~~~~~~~~~~~~" << endl;
	cout << "˫����������˵���Ϲд�ķ���ˮ��ϣ��ʦ�ֲ�Ҫ����������������" << endl;
	cout << "������������������������������������������������������������" << endl;
	cout << "1.��ȡ�����е�һ��Ԫ��" << endl;
	cout << "2.��ȡ���������һ��Ԫ��" << endl;
	cout << "3.�������һ��Ԫ��ǰ���Ԫ��" << endl;
	cout << "4.ɾ�������һ��Ԫ��" << endl;
	cout << "5.���������һ��Ԫ�غ����Ԫ��" << endl;
	cout << "6.ɾ���������һ��Ԫ��" << endl;
	cout << "7.������ĵ�index + 1��Ԫ��ǰ����Ԫ��" << endl;
	cout << "8.ɾ����index + 1��Ԫ��" << endl;
	cout << "9.�������" << endl;
	cout << "10.����Ԫ��" << endl;
	cout << "11.��ȡ������Ԫ�ص�����" << endl;
	cout << "12.�����������ȫ��Ԫ��" << endl;
	cout << "13.��������������" << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;
	cout << "����ѡ�";
	return 0;
}

void output(int& e) {
	cout << e << endl;
}

int main() {
	system("color F0");
	int i;
	cout << "���ڴ�������...��Ϲд�ķ���ˮ��ϣ��ʦ�ֲ�Ҫ����������������" << endl;
	inputController input;
	QGList List;
	int pushFront, pushBack, insert, contain;
	unsigned int index, size;
	QGList::ElemType& e1 = pushFront;
	QGList::ElemType& e2 = pushBack;
	QGList::ElemType& e3 = insert;
	QGList::ElemType& e4 = contain;
	while (true) {
		map();
		i = input.is_limitted_digit(13);
		switch (i) {
		case(1):
			cout << "�����еĵ�һ��Ԫ�أ�" << List.front() << endl;
			break;
		case(2):
			cout << "��������һ��Ԫ�أ�" << List.back() << endl;
			break;
		case(3):
			cout << "���������ݣ�";
			pushFront = input.is_unlimitted_digit();
			if (List.push_front(e1)) {
				cout << "���" << endl;
			}
			break;
		case(4):
			if (List.pop_front()) {
				cout << "���" << endl;
			}
			break;
		case(5):
			cout << "���������ݣ�";
			pushBack = input.is_unlimitted_digit();
			if (List.push_back(e2)) {
				cout << "���" << endl;
			}
			break;
		case(6):
			if (List.pop_back()) {
				cout << "���" << endl;
			}
			break;
		case(7):
			cout << "index:"; index = input.is_limitted_digit();
			cout << "���������ݣ�"; insert = input.is_unlimitted_digit();
			if (List.insert(index, e3)) {
				cout << "���" << endl;
			}
			break;
		case(8):
			cout << "index:"; index = input.is_limitted_digit();
			if (List.erase(index)) {
				cout << "���" << endl;
			}
			break;
		case(9):
			if (List.clear()) {
				cout << "���" << endl;
			}
			break;
		case(10):
			cout << "���������ݣ�"; contain = input.is_unlimitted_digit();
			List.contain(e4);
			break;
		case(11):
			size = List.size();
			cout << "��������Ԫ������Ϊ" << size << endl;
			break;
		case(12):
			if (List.traverse(output)) {
				cout << "������" << endl;
			}
			break;
		case(13):
			cout << "�����ѱ�����" << endl;
			return 0;
		}
	}
}