#pragma once
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class inputController {
public:
	//�޶���������ʱֻ���������������
	int is_unlimitted_digit();

	//�޶���������ʱֻ�����벻������������
	int is_limitted_digit();
	int is_limitted_digit(int max_num);
};

int inputController::is_unlimitted_digit() {
	char input[10000];
	int len,n,output=0;
	bool loop = true;
	while (loop) {
		C:n = 0;
		scanf("%s", input);
		len = strlen(input);
		if (input[0] != '-') {
			for (; n < len; n++) {
				if (input[n] < 48 || input[n] > 57) {
					cout << "���������֣�";
					goto C;
				}
			}
			for (n = 0,len -= 1; n <= len; n++) {
				output += ((input[n]-48) * pow(10, len - n));
			}
			return output;
		}
		else if(input[0] == '-') {
			n = 1;
			for (; n < len; n++) {
				if (input[n] < 48 || input[n] > 57) {
					cout << "���������֣�";
					goto C;
				}
			}
			for (n = 1,len -= 1; n <= len; n++) {
				output += (input[n]-48) * pow(10, len - n);
			}
			return -1 * output;
		}
	}	
}

int inputController::is_limitted_digit() {
	char input[100];
	int len, n, output = 0;
	bool loop = true;
	while (loop) {
		C:n = 0;
		scanf("%s", input);
		len = strlen(input);
		for (; n < len; n++) {
			if (input[n] == '-') {
				cout << "��������������";
				goto C;
			}
			if (input[n] < 48 || input[n] > 57) {
				cout << "��������������";
				goto C;
			}
		}
		for (n = 0, len -= 1; n <= len; n++) {
			output += ((input[n] - 48) * pow(10, len - n));
		}
		return output;
	}
}

//override
int inputController::is_limitted_digit(int max_num) {
	char input[10];
	int len, n, output;
	bool loop = true;
	while (loop) {
		C:n = 0;
		output = 0;
		scanf("%s", input);
		len = strlen(input);
		for (; n < len; n++) {
			if (input[n] == '-') {
				cout << "��������������";
				goto C;
			}
			if (input[n] < 48 || input[n] > 57) {
				cout << "��������������";
				goto C;
			}
		}
		for (n = 0, len -= 1; n <= len; n++) {
			output += ((input[n] - 48) * pow(10, len - n));
		}
		if (output > max_num) {
			cout << "������1~" << max_num << "��������:";
			goto C;
		}
		return output;
	}
}