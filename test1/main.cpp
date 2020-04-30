#include "LinkBiTree.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

BiTNode* Tree = nullptr;
BiTNode* BITREE = nullptr;

Status visit(TElemType e) {
	cout << e << " ";
	return SUCCESS;
}

int main() {
	system("color F0");
	char data[101];
	cout << "�����������ַ���[100]���ո񼰽�β�á�#����ʾ" << endl;
	scanf_s("%s", data, 100);
	InitBiTree(Tree);
	CreateBiTree(Tree, data, 0, &BITREE);
	cout << "���������";
	PreOrderTraverse(BITREE, visit);
	cout << endl;
	cout << "���������";
	InOrderTraverse(BITREE, visit);
	cout << endl;
	cout << "���������";
	PreOrderTraverse(BITREE, visit);
	cout << endl;
}