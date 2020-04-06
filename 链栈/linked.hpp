#pragma once
#include "LinkStack.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

Status initLStack(LinkStack* s) {
	s->top = (StackNode*)malloc(sizeof(StackNode));
	s->top->next = nullptr;
	s->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack* s) {
	if (s->top == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	else if (s->count != 0) {
		cout << "¸ÃÕ»²»Îª¿Õ" << endl;
		return SUCCESS;
	}
	else {
		cout << "¸ÃÕ»Îª¿Õ" << endl;
		return SUCCESS;
	}
}

Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	else if (s->count == 0) {
		cout << "¸ÃË³ÐòÕ»Îª¿Õ" << endl;
		return ERROR;
	}
	else {
		*e = s->top->data;
		return SUCCESS;
	}
}

Status clearLStack(LinkStack* s) {
	if (s->top == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	s->count = 0;
	StackNode* ph=nullptr;
	while (s->top->next != nullptr) {
		ph = s->top->next;
		free(s->top);
		s->top = ph;
	}
	s->top->data = 0;
	return SUCCESS;
}

Status destroyLStack(LinkStack* s) {
	if (s->top == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	s->count = 0;
	StackNode* ph = nullptr;
	while (s->top->next != nullptr) {
		ph = s->top->next;
		free(s->top);
		s->top = ph;
	}
	free(s->top);
	return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length) {
	if (s->top == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack* s, ElemType data) {
	if (s->top == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	StackNode* ph = nullptr;
	ph = (StackNode*)malloc(sizeof(StackNode));
	ph->next = s->top;
	ph->data = data;
	s->top = ph;
	s->count += 1;
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data) {
	if (s->top == nullptr) {
		cout << "¸ÃË³ÐòÕ»ÉÐÎ´³õÊ¼»¯" << endl;
		return ERROR;
	}
	StackNode* ph = nullptr;
	ph = s->top->next;
	free(s->top);
	s->top = ph;
	s->count -= 1;
	return SUCCESS;
}