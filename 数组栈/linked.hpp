#pragma once
#include "SqStack.hpp"
#include <iostream>
#include <stack>
using namespace std;

Status initStack(SqStack* s, int sizes) {
	s->elem = (int*)malloc(sizes);
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack* s) {
	if (s->elem == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	else if (s->top == -1) {
		cout << "¸ÃË³ÐòÕ»Îª¿Õ" << endl;
		return ERROR;
	}
	else {
		cout << "¸ÃË³ÐòÕ»·Ç¿Õ" << endl;
	}
	return SUCCESS;
}

Status getTopStack(SqStack* s, ElemType* e) {
	if (s->elem == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	else if (s->top == -1) {
		cout << "¸ÃË³ÐòÕ»Îª¿Õ" << endl;
		return ERROR;
	}
	else {
		*e = s->elem[s->top];
		return SUCCESS;
	}
}

Status clearStack(SqStack* s) {
	if (s->elem == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack* s) {
	if (s->elem == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	delete[] s;
	return SUCCESS;
}

Status stackLength(SqStack* s, int* length) {
	if (s->elem == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	*length = (s->top) + 1;
	return SUCCESS;
}

Status pushStack(SqStack* s, ElemType data) {
	if (s->elem == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	else if (s->top == s->size - 1) {
		cout << "¸ÃË³ÐòÕ»ÒÑÂú" << endl;
		return ERROR;
	}
	else {
		(s->elem)[++s->top] = data;
		return SUCCESS;
	}
}

Status popStack(SqStack* s, ElemType* data) {
	if (s->elem == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	else if (s->top == -1) {
		cout << "¸ÃË³ÐòÕ»Îª¿Õ" << endl;
		return ERROR;
	}
	else {
		*data = s->elem[s->top];
		s->top -= 1;
		return SUCCESS;
	}
}
