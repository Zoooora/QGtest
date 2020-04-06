#include "inputController.hpp"
#include "linked.hpp"
#include "LinkStack.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool check(char formular[]) {
	int len,brackets=0;
	for (len = 0; len < strlen(formular); len++) {
		if (formular[len] < 48 && formular[len]>57 && formular[len] != '+' && formular[len] != '-' && formular[len] != '*' && formular[len] != '/' && formular[len] != '(' && formular[len] != ')') {
			cout << "请输入正确的式子" << endl;
			return 0;
		}//判断非法字符
		if (formular[len] == '/' && formular[len + 1] == 48) {
			cout << "除数不能为零" << endl;
			return 0;
		}//判断x/0
		if (formular[len] == '(') {
			brackets += 1;
		}
		if (formular[len] == ')') {
			brackets -= 1;
		}//判断括号
		if (len < strlen(formular) - 3) {
			if (formular[len] < 48 && formular[len]>57 && formular[len] != '(' && formular[len] != ')') {
				if (formular[len + 1] < 48 && formular[len + 1]>57 && formular[len + 1] != '(' && formular[len + 1] != ')') {
					if (formular[len + 2] < 48 && formular[len + 2]>57 && formular[len + 2] != '(' && formular[len + 2] != ')') {
						cout << "请输入正确的式子" << endl;
						return 0;
					}
				}
			}
		}//判断连续三位非数字非括号	
	}
	if (brackets != 0) {
		cout << brackets;
		cout << "括号不对称" << endl;
		return 0;
	}
	for (len = 0; len < strlen(formular);len++) {
		if (formular[len] == '-') {
			if (len == 0 || formular[len - 1] == '(') {
				int n = strlen(formular);
				formular[strlen(formular) + 1] = '\0';
				for (; n > len; n--) {
					formular[n] = formular[n - 1];
				}
				formular[n] = '0';
			}
		}//第一位负号和(-前面加0
	}
	return 1;
}

int transform(char formular[], char back[]) {//中缀表达式转换后缀表达式
	LinkStack* LinkStack_3 = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(LinkStack_3);
	int len, nback, nfor, e;
	len = strlen(formular);
	for (nfor = 0, nback = 0; nfor < len; nfor++,nback++) {
		if (formular[nfor] == '(' || formular[nfor] == '*' || formular[nfor] == '/') {
			pushLStack(LinkStack_3, formular[nfor]);
			back[nback] = ' ';
			continue;
		}
		else if (formular[nfor] == '+' || formular[nfor] == '-') {
			if (LinkStack_3->count != 0) {
				getTopLStack(LinkStack_3, &e);
				if (e == '(' || e == '+' || e == '-') {
					pushLStack(LinkStack_3, formular[nfor]);
					back[nback] = ' ';
					continue;
				}
				else if (e == '*' || e == '/') {
					back[nback] = e;
					nback += 1;
					back[nback] = ' ';
					popLStack(LinkStack_3, &e);
					pushLStack(LinkStack_3, formular[nfor]);
					continue;
				}
			}
			else {
				pushLStack(LinkStack_3, formular[nfor]);
				back[nback] = ' ';
				continue;
			}
		}
		else if (formular[nfor] == ')') {
			while (LinkStack_3->top->data != '(') {
				getTopLStack(LinkStack_3, &e);
				back[nback] = e;
				popLStack(LinkStack_3, &e);			
			}
			popLStack(LinkStack_3, &e);
			continue;
		}
		else {
			back[nback] = formular[nfor];
		}
	}
	while (LinkStack_3->count >= 1) {
		getTopLStack(LinkStack_3, &e);
		back[nback] = e;
		nback += 1;
		popLStack(LinkStack_3, &e);		
	}
	/*getTopLStack(LinkStack_3, &e);
	back[nback] = e;
	nback += 1;*/
	back[nback] = '\0';
	clearLStack(LinkStack_3);
	return 1;
}

int calculator(char back[]) {
	int m1 = 0, n;
	int result, d, e;
	char strresult[10];
	LinkStack* LinkStack_4 = (LinkStack*)malloc(sizeof(LinkStack));
	initLStack(LinkStack_4);
	while (back[m1]) {
		if (m1 == 0) {
			pushLStack(LinkStack_4, (int)atof(&back[m1]));
		}
		else {
			if (back[m1] >= 48 && back[m1] <= 57) {
				pushLStack(LinkStack_4, (int)atof(&back[m1]));
			}
		}
		if (back[m1] < 48 && back[m1] != 32) {
			switch (back[m1]) {
			case('+'):
				popLStack(LinkStack_4, &d);
				popLStack(LinkStack_4, &e);
				result = e + d;
				pushLStack(LinkStack_4, result);
				break;
			case('-'):
				popLStack(LinkStack_4, &d);
				popLStack(LinkStack_4, &e);
				result = e - d;
				pushLStack(LinkStack_4, result);
				break;
			case('*'):
				popLStack(LinkStack_4, &d);
				popLStack(LinkStack_4, &e);
				result = e * d;
				pushLStack(LinkStack_4, result);
				break;
			case('/'):
				popLStack(LinkStack_4, &d);
				popLStack(LinkStack_4, &e);
				result = e / d;
				pushLStack(LinkStack_4, result);
				break;
			}
		}
		m1 += 1;
		

	}
	getTopLStack(LinkStack_4, &result);
	return result;
}

int main() {
	system("color F0");
	char formular[100];
	char back[100];
	int n = 0;
	int result;
	while (true) {
		cout << "请输入式子（请正确使用括号，包括对称的左右括号，表示负数时使用括号等，同时大概只支持个位数的运算。。。）"<<endl;
		scanf("%s", formular);
		if (check(formular)) {
			transform(formular, back);
			cout << "后缀表达式" << endl;
			printf("%s\n", back);
			result = calculator(back);
			cout << "计算结果" << endl << result << endl;
			cout << "输入 @ 结束或者其他任意键继续：";
			getchar();
			if (getchar() == '@') {
				return 0;
			}
		}
		else continue;
	}
}

