#include "AQueue.h"
#include <stdio.h>

int map() {
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("顺序队列操作菜单\n");
	printf("1.入队\n");
	printf("2.出队\n");
	printf("3.队列判空\n");
	printf("4.判断队列是否为满\n");
	printf("5.查看队头元素\n");
	printf("6.获取队列长度\n");
	printf("7.遍历队列并输出\n");
	printf("8.清空队列\n");
	printf("9.销毁队列并退出\n");
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("请输入选项：");
	return 0;
}

int choice() {
	char type;
	printf("1.数字\n2.单字符\n");
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
	system("color F0");
	int n, data_i, head_i, choi;
	char data_c, head_c;
	AQueue* q = (AQueue*)malloc(sizeof(AQueue));
	InitAQueue(q);
	choi = choice();
	if (choi == 1) {
		C:map();
		scanf("%d", &n);
		switch (n) {
		case(1):
			printf("请输入数据：");
			scanf("%d", &data_i);
			if (EnAQueue(q, &data_i)) {
				printf("完成\n");
				goto C;
			}
			printf("该队列已满\n");
			goto C;
		case(2):
			if (DeAQueue(q)) {
				printf("完成\n");
				goto C;
			}
			printf("该队列为空\n");
			goto C;
		case(3):
			if (IsEmptyAQueue(q)) {
				printf("该队列为空\n");
				goto C;
			}
			printf("该队列非空\n");
			goto C;
		case(4):
			if (IsFullAQueue(q)) {
				printf("该队列已满\n");
				goto C;
			}
			printf("该队列未满\n");
			goto C;
		case(5):
			if (GetHeadAQueue(q,&head_i)) {
				printf("该队列头元素为%d\n",head_i);
				goto C;
			}
			printf("该队列为空\n");
			goto C;
		case(6):
			printf("该队列长度为%d\n", LengthAQueue(q));
			goto C;
		case(7):
			if (TraverseAQueue(q, 4, &APrint)) {
				printf("完成\n");
				goto C;
			}
			printf("该队列为空\n");
			goto C;
		case(8):
			ClearAQueue(q);
			printf("完成\n");
			goto C;
		case(9):
			DestoryAQueue(q);
			printf("完成\n");
			return 0;
		}
	}
	else if (choi == 2) {
	D:map();
		scanf("%d", &n);
		getchar();
		switch (n) {
		case(1):
			printf("请输入数据：");
			scanf("%c", &data_c);
			if (EnAQueue(q, &data_c)) {
				printf("完成\n");
				goto D;
			}
			printf("该队列已满\n");
			goto D;
		case(2):
			if (DeAQueue(q)) {
				printf("完成\n");
				goto D;
			}
			printf("该队列为空\n");
			goto D;
		case(3):
			if (IsEmptyAQueue(q)) {
				printf("该队列为空\n");
				goto D;
			}
			printf("该队列非空\n");
			goto D;
		case(4):
			if (IsFullAQueue(q)) {
				printf("该队列已满\n");
				goto D;
			}
			printf("该队列未满\n");
			goto D;
		case(5):
			if (GetHeadAQueue(q, &head_c)) {
				printf("该队列头元素为%c\n", head_c);
				goto D;
			}
			printf("该队列为空\n");
			goto D;
		case(6):
			printf("该队列长度为%d\n", LengthAQueue(q));
			goto D;
		case(7):
			if (TraverseAQueue(q, 1, &APrint)) {
				printf("完成\n");
				goto D;
			}
			printf("该队列为空\n");
			goto D;
		case(8):
			ClearAQueue(q);
			printf("完成\n");
			goto D;
		case(9):
			DestoryAQueue(q);
			printf("完成\n");
			return 0;
		}
	}
	return 0;
}