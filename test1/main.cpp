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
	cout << "请输入先序字符串[100]（空格及结尾用‘#’表示" << endl;
	scanf_s("%s", data, 100);
	InitBiTree(Tree);
	CreateBiTree(Tree, data, 0, &BITREE);
	cout << "先序遍历：";
	PreOrderTraverse(BITREE, visit);
	cout << endl;
	cout << "中序遍历：";
	InOrderTraverse(BITREE, visit);
	cout << endl;
	cout << "后序遍历：";
	PreOrderTraverse(BITREE, visit);
	cout << endl;
}