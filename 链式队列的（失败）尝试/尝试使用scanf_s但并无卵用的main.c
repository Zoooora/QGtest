#include "尝试匹配scanf_s的main但并无卵用的LQueue.h"
#include <stdio.h>

int map() {
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("链式队列操作菜单\n");
	printf("1.入队\n");
	printf("2.出队\n");
	printf("3.队列判空\n");
	printf("4.查看队头元素\n");
	printf("5.获取队列长度\n");
	printf("6.遍历队列并输出\n");
	printf("7.清空队列\n");
	printf("8.销毁队列并退出\n");
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("请输入选项：");
	return 0;
}

int choice() {
	char type;
	printf("1.数字\n2.单字符（其实可以1~3，但是我想不到更好的方法实现长字符串的输入和输出）\n");
	printf("请输入数据类型：");
	while (TRUE) {
		scanf("%c", &type);
		getchar();
		if (type == '1') {
			return 1;
		}
		else if (type == '2') {
			return 2;
		}
		else {
			printf("请输入正确的选项：");
		}
	}
}

int main() {
	int n, len, choi, data_i, head_i;
	char data_c[20], head_c[20];
	system("color F0");
	LQueue* q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(q);
	choi = choice();
	if (choi == 1) {
		C:map();
		scanf("%d", &n);
		switch (n) {
		case(1):
			printf("请输入数据：");
			scanf("%d", &data_i);
			if (EnLQueue(q, &data_i, 4)) {
				printf("完成\n");
				goto C;
			}
		case(2):
			if (DeLQueue(q)) {
				printf("完成\n");
				goto C;
			}
			printf("该队列为空\n");
			goto C;
		case(3):
			if (IsEmptyLQueue(q)) {
				printf("该队列为空\n");
				goto C;
			}
			printf("该队列非空\n");
			goto C;
		case(4):
			if (GetHeadLQueue(q, &head_i)) {
				printf("该队列头元素为%d\n", head_i);
				goto C;
			}
			printf("该队列为空\n");
			goto C;
		case(5):
			printf("该队列长度为%d\n", LengthLQueue(q));
			goto C;
		case(6):
			if (TraverseLQueue(q, 4, LPrint)) {
				printf("完成\n");
				goto C;
			}
			printf("该队列为空\n");
			goto C;
		case(7):
			ClearLQueue(q);
			printf("完成\n");
			goto C;
		case(8):
			DestoryLQueue(q);
			printf("完成\n");
			return 0;
		}
	}
	else if (choi == 2) {
	D:map();
		scanf("%d", &n);
		switch (n) {
		case(1):
			printf("请输入数据长度：");
			scanf("%d", &len);
			if (len + 1 > 20) {
				printf("请输入小一点的数据\n");
				goto D;
			}
			printf("请输入数据：");
			scanf_s("%s", data_c,len + 1);
			if (EnLQueue(q, data_c, len + 1)) {
				printf("完成\n");
				goto D;
			}
		case(2):
			if (DeLQueue(q)) {
				printf("完成\n");
				goto D;
			}
			printf("该队列为空\n");
			goto D;
		case(3):
			if (IsEmptyLQueue(q)) {
				printf("该队列为空\n");
				goto D;
			}
			printf("该队列非空\n");
			goto D;
		case(4):
			if (GetHeadLQueue(q, head_c)) {
				printf("该队列头元素为%s\n", head_c);
				goto D;
			}
			printf("该队列为空\n");
			goto D;
		case(5):
			printf("该队列长度为%d\n", LengthLQueue(q));
			goto D;
		case(6):
			if (TraverseLQueue(q, len + 1, LPrint)) {
				printf("完成\n");
				goto D;
			}
			printf("该队列为空\n");
			goto D;
		case(7):
			ClearLQueue(q);
			printf("完成\n");
			goto D;
		case(8):
			DestoryLQueue(q);
			printf("完成\n");
			return 0;
		}
	}
	return 0;
}