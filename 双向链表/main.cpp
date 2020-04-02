#include <iostream>
#include "qglist.hpp"
#include "linkedList.hpp"
#include "inputController.hpp"
using namespace std;

int map() {
	cout << endl << "~~~~~~~~~~~~~~~" << endl;
	cout << "双向链表操作菜单（瞎写的防灌水，希望师兄不要脸滚键盘了咚咚咚" << endl;
	cout << "——————————————————————————————" << endl;
	cout << "1.获取链表中第一个元素" << endl;
	cout << "2.获取链表中最后一个元素" << endl;
	cout << "3.在链表第一个元素前添加元素" << endl;
	cout << "4.删除链表第一个元素" << endl;
	cout << "5.在链表最后一个元素后添加元素" << endl;
	cout << "6.删除链表最后一个元素" << endl;
	cout << "7.在链表的第index + 1个元素前插入元素" << endl;
	cout << "8.删除第index + 1个元素" << endl;
	cout << "9.清空链表" << endl;
	cout << "10.查找元素" << endl;
	cout << "11.获取链表中元素的数量" << endl;
	cout << "12.遍历链表并输出全部元素" << endl;
	cout << "13.结束并销毁链表" << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;
	cout << "输入选项：";
	return 0;
}

void output(int& e) {
	cout << e << endl;
}

int main() {
	system("color F0");
	int i;
	cout << "正在创建链表...（瞎写的防灌水，希望师兄不要脸滚键盘了咚咚咚" << endl;
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
			cout << "链表中的第一个元素：" << List.front() << endl;
			break;
		case(2):
			cout << "链表的最后一个元素：" << List.back() << endl;
			break;
		case(3):
			cout << "请输入数据：";
			pushFront = input.is_unlimitted_digit();
			if (List.push_front(e1)) {
				cout << "完成" << endl;
			}
			break;
		case(4):
			if (List.pop_front()) {
				cout << "完成" << endl;
			}
			break;
		case(5):
			cout << "请输入数据：";
			pushBack = input.is_unlimitted_digit();
			if (List.push_back(e2)) {
				cout << "完成" << endl;
			}
			break;
		case(6):
			if (List.pop_back()) {
				cout << "完成" << endl;
			}
			break;
		case(7):
			cout << "index:"; index = input.is_limitted_digit();
			cout << "请输入数据："; insert = input.is_unlimitted_digit();
			if (List.insert(index, e3)) {
				cout << "完成" << endl;
			}
			break;
		case(8):
			cout << "index:"; index = input.is_limitted_digit();
			if (List.erase(index)) {
				cout << "完成" << endl;
			}
			break;
		case(9):
			if (List.clear()) {
				cout << "完成" << endl;
			}
			break;
		case(10):
			cout << "请输入数据："; contain = input.is_unlimitted_digit();
			List.contain(e4);
			break;
		case(11):
			size = List.size();
			cout << "该链表中元素数量为" << size << endl;
			break;
		case(12):
			if (List.traverse(output)) {
				cout << "输出完毕" << endl;
			}
			break;
		case(13):
			cout << "链表已被销毁" << endl;
			return 0;
		}
	}
}