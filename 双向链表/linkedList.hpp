#pragma once
#include "qglist.hpp"
#include "inputController.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

inputController input;

QGList::QGList() {
	int n = 0;
	Node* p1, * p2;
	QGList::head = p1 = p2 = nullptr;
	p1 = (Node*)malloc(sizeof(Node));
	head = p1;
	p1->prior = nullptr;
	do {
		if (n != 0) {
			p1->next->prior = p1;
			p1 = p1->next;
		}
		cout << "请输入第" << (n + 1) << "个数据:";
		p1->data = input.is_unlimitted_digit();
		cout << "输入 y 继续或者其他任意键退出:";
		p2 = (Node*)malloc(sizeof(Node));
		p1->next = p2;
		n += 1;
		getchar();
	} while (getchar() == 'y');
	p1->next = nullptr;
	free(p2);
}

QGList::~QGList() {
	QGList::Node* p1 = head;
	QGList::Node* p2 = head;
	while (p2->next != nullptr) {
		p2 = p1->next;
		p1->next = nullptr;
		free(p1);
		p1 = p2;
	}
	free(p1);
	p1 = p2 = nullptr;
}

QGList::ElemType& QGList::front() {
	return head->data;
}

QGList::ElemType& QGList::back() {
	QGList::Node* phead = head;
	while (phead->next != nullptr) {
		phead = phead->next;
	}
	return phead->data;
}

bool QGList::push_front(QGList::ElemType& e) {
	QGList::Node* p1 = head;
	QGList::Node* phead = nullptr;
	phead = (Node*)malloc(sizeof(Node));
	phead->prior = nullptr;
	phead->data = e;
	phead->next = p1;
	p1->prior = phead;
	head = phead;
	return 1;
}

bool QGList::pop_front() {
	QGList::Node* p1 = head;
	head = head->next;
	head->prior = nullptr;
	p1->next = nullptr;
	free(p1);
	return 1;
}

bool QGList::push_back(QGList::ElemType& e) {
	QGList::Node* phead = head;
	QGList::Node* p1 = nullptr;
	while (phead->next != nullptr) {
		phead = phead->next;
	}
	p1 = (Node*)malloc(sizeof(Node));
	phead->next = p1;
	p1->prior = phead;
	p1->data = e;
	p1->next = nullptr;
	return 1;
}

bool QGList::pop_back() {
	QGList::Node* phead = head;
	while (phead->next->next != nullptr) {
		phead = phead->next;
	}
	phead->next->prior = nullptr;
	free(phead->next);
	phead->next = nullptr;
	return 1;
}

bool QGList::insert(unsigned int index, QGList::ElemType& e) {
	QGList::Node* phead = head;
	QGList::Node* p1 = nullptr;
	if (index == 0) QGList::push_front(e);
	else {
		for (; index > 1; index--) {
			phead = phead->next;
			if (phead == nullptr) {
				cout << "链表过界" << endl;
				return 0;
			}
		}
		p1 = (Node*)malloc(sizeof(Node));
		p1->next = phead->next;
		phead->next->prior = p1;
		p1->prior = phead;
		p1->data = e;
		phead->next = p1;
	}
	return 1;
}

bool QGList::erase(unsigned int index) {
	QGList::Node* phead = head;
	QGList::Node* p1 = nullptr;
	if (index == 0) QGList::pop_front();
	else {
		for (; index > 1; index--) {
			phead = phead->next;
			if (phead == nullptr) {
				cout << "链表过界" << endl;
				return 0;
			}
		}
		if (phead->next == nullptr) {
			QGList::pop_back();
			return 1;
		}
		else {
			p1 = phead->next->next;
			p1->prior = phead;
			free(phead->next);
			phead->next = p1;
		}
	}
	return 1;
}

bool QGList::clear() {
	QGList::Node* phead = head;
	while (phead != nullptr) {
		phead->data = 0;
		phead = phead->next;
	}
	return 1;
}

bool QGList::contain(QGList::ElemType& e) {
	int n = 1;
	QGList::Node* phead = head;
	while (phead != nullptr) {
		if (e == phead->data) {
			cout << "第" << n << "号元素是" << e << endl;
			return 1;
		}
		else {
			phead = phead->next;
			n += 1;
		}
	}
	cout << "该链表中不存在元素" << e << endl;
	return 1;
}

unsigned int QGList::size() {
	int n = 0;
	QGList::Node* phead = head;
	while (phead != nullptr) {
		n += 1;
		phead = phead->next;
	}
	return n;
}

bool QGList::traverse(void(*visit)(QGList::ElemType& e)) {
	QGList::Node* phead = head;
	while (phead != nullptr) {
		visit(phead->data);
		cout << "prior:" << phead->prior << endl;
		cout << "该数据所在地址：" << phead << endl;
		cout << "next:" <<phead->next << endl << endl;
		phead = phead->next;
	}
	return 1;
}