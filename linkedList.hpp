#include "qgforwardlist.hpp"
#include "inputController.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

inputController input;

QGForwardList::QGForwardList() {
	int n=0;
	Node* p1, * p2;
	QGForwardList::head = p1 = p2 = nullptr;
	p1 = (Node*)malloc(sizeof(Node));
	QGForwardList::head = p1;
	do {
		if (n != 0) p1 = p1->next;
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

QGForwardList::ElemType& QGForwardList::front() {
	return head->data;
}

QGForwardList::ElemType& QGForwardList::back() {
	QGForwardList::Node* phead = head;
	while (phead->next != nullptr) {
		phead = phead->next;
	}
	return phead->data;
}

bool QGForwardList::push_front(QGForwardList::ElemType& e) {
	QGForwardList::Node* p1 = head;
	QGForwardList::Node* phead = nullptr;
	phead = (Node*)malloc(sizeof(Node));
	phead->data = e;
	phead->next = p1;
	QGForwardList::head = phead;
	return 1;
}

bool QGForwardList::pop_front() {
	QGForwardList::Node* p1 = head;
	head = head->next;
	p1->next = nullptr;
	free(p1);
	return 1;
}

bool QGForwardList::push_back(QGForwardList::ElemType& e) {
	QGForwardList::Node* phead = head;
	QGForwardList::Node* p1 = nullptr;
	while (phead->next != nullptr) {
		phead = phead->next;
	}
	p1 = (Node*)malloc(sizeof(Node));
	phead->next = p1;
	p1->data = e;
	p1->next = nullptr;
	return 1;
}

bool QGForwardList::pop_back() {
	QGForwardList::Node* phead = head;
	while (phead->next->next != nullptr) {
		phead = phead->next;
	}
	free(phead->next);
	phead->next = nullptr;
	return 1;
}

bool QGForwardList::insert(unsigned int index, ElemType& e) {
	QGForwardList::Node* phead = head;
	QGForwardList::Node* p1 = nullptr;
	if (index == 0) QGForwardList::push_front(e);
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
		p1->data = e;
		phead->next = p1;
	}
	return 1;
}

bool QGForwardList::erase(unsigned int index) {
	QGForwardList::Node* phead = head;
	QGForwardList::Node* p1 = nullptr;
	if (index == 0) QGForwardList::pop_front();
	else {
		for (; index > 1; index--) {
			phead = phead->next;
			if (phead == nullptr) {
				cout << "链表过界" << endl;
				return 0;
			}
		}
		if (phead->next == nullptr) {
			QGForwardList::pop_back();
			return 1;
		}
		else {
			p1 = phead->next->next;
			free(phead->next);
			phead->next = p1;
		}
	}
	return 1;
}

bool QGForwardList::clear() {
	QGForwardList::Node* phead = head;
	while (phead != nullptr) {
		phead->data = 0;
		phead = phead->next;
	}
	return 1;
}

bool QGForwardList::contain(ElemType& e) {
	int n = 1;
	QGForwardList::Node* phead = head;
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

unsigned int QGForwardList::size(){
	int n = 0;
	QGForwardList::Node* phead = head;
	while (phead != nullptr) {
		n += 1;
		phead = phead->next;
	}
	return n;
}

bool QGForwardList::traverse(void (*visit)(ElemType& e)) {
	QGForwardList::Node* phead = head;
	while (phead != nullptr) {
		visit(phead->data);
		cout << "该数据所在地址：" << phead << endl;
		cout << "next:" << phead->next << endl << endl;
		phead = phead->next;
	}
	return 1;
}

bool QGForwardList::reverse() {
	QGForwardList::Node* phead = head;
	QGForwardList::Node* pnext = nullptr;
	QGForwardList::Node* pend = nullptr;
	if (QGForwardList::size() == 1) return 1;
	if (QGForwardList::size() == 2) {
		pnext = phead->next;
		pnext->next = phead;
		phead->next = nullptr;
		head = pnext;
		return 1;
	}
	if (QGForwardList::size() >= 3) {
		pnext = phead->next;
		pend = pnext->next;
		pnext->next = phead;
		phead->next = nullptr;
		phead = pnext;
		pnext = pend;
		while (pend->next != nullptr) {
			pend = pnext->next;
			pnext->next = phead;
			phead = pnext;
			pnext = pend;
		}
		pend->next = phead;
		head = pend;
		return 1;
	}
}

bool QGForwardList::isLoop() {
	QGForwardList::Node* p1 = head;
	QGForwardList::Node* p2 = head;
	int n;
	n = QGForwardList::size();
	if (n == 1) {
		cout << "该链表非环" << endl;
		return 0;
	}
	else if (n == 2) {
		if (p1->next->next == p2) {
			return 1;
		}
		else {
			cout << "该链表非环" << endl;
			return 0;
		}
	}
	else {
		if (n % 2 == 1) {
			while (p1->next != nullptr) {
				p1 = p1->next;
				p1 = p1->next;
				p2 = p2->next;
				if (p1 == p2) {
					return 1;
				}
			}
		}
		else {
			while (p1 != nullptr) {
				p1 = p1->next;
				p1 = p1->next;
				p2 = p2->next;
				if (p1 == p2) {
					return 1;
				}
			}
		}
		cout << "该链表非环" << endl;
		return 0;
	}
}

bool QGForwardList::reverseEven() {
	QGForwardList::Node* phead = head;
	QGForwardList::Node* p1 = phead->next;
	QGForwardList::Node* p2 = p1->next;
	int n,temp;
	int i = 0;//判断次数
	n = QGForwardList::size();
	if (n == 1) return 1;
	else if (n == 2) {
		QGForwardList::reverse();
		return 1;
	}
	else {
		if (n % 2 == 0) {
			while (p2 != nullptr) {
				if (i != 0) {
					phead = p2;
					p1 = phead->next;
					p2 = p1->next;
					if (p2 == nullptr) goto A;
				}
				phead->next = p2->next;
				p1->next = phead;
				if (i == 0) {
					head = p1;
				}
				i += 1;
			}
			A:phead->next = p2;
			p1->next = phead;
			return 1;
		}
		else {
			while (p1->next->next != nullptr) {
				if (i != 0) {
					phead = p2;
					p1 = phead->next;
					p2 = p1->next;
				}
				phead->next = phead->next->next->next;
				p1->next = phead;
				if (i == 0) {
					head = p1;
				}
				i += 1;				
			}
			phead->next = p2;
			p1->next = phead;
			return 1;
		}
	}
}

QGForwardList::ElemType& QGForwardList::middleElem() {
	QGForwardList::Node* p1 = head;
	QGForwardList::Node* p2 = head;
	int n;
	n = QGForwardList::size();
	if (n % 2 == 1) {
		while (p1->next != nullptr) {
			p1 = p1->next;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	else {
		while (p1 != nullptr) {
			p1 = p1->next;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return p2->data;
}

QGForwardList::~QGForwardList() {
	QGForwardList::Node* p1 = head;
	QGForwardList::Node* p2 = head;
	while (p2->next != nullptr) {
		p2 = p1->next;
		p1->next = nullptr;
		free(p1);
		p1 = p2;
	}
	free(p1);
	p1 = p2 = nullptr;
}

