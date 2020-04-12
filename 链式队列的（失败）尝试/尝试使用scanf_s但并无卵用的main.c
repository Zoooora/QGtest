#include "����ƥ��scanf_s��main���������õ�LQueue.h"
#include <stdio.h>

int map() {
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("��ʽ���в����˵�\n");
	printf("1.���\n");
	printf("2.����\n");
	printf("3.�����п�\n");
	printf("4.�鿴��ͷԪ��\n");
	printf("5.��ȡ���г���\n");
	printf("6.�������в����\n");
	printf("7.��ն���\n");
	printf("8.���ٶ��в��˳�\n");
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("������ѡ�");
	return 0;
}

int choice() {
	char type;
	printf("1.����\n2.���ַ�����ʵ����1~3���������벻�����õķ���ʵ�ֳ��ַ���������������\n");
	printf("�������������ͣ�");
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
			printf("��������ȷ��ѡ�");
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
			printf("���������ݣ�");
			scanf("%d", &data_i);
			if (EnLQueue(q, &data_i, 4)) {
				printf("���\n");
				goto C;
			}
		case(2):
			if (DeLQueue(q)) {
				printf("���\n");
				goto C;
			}
			printf("�ö���Ϊ��\n");
			goto C;
		case(3):
			if (IsEmptyLQueue(q)) {
				printf("�ö���Ϊ��\n");
				goto C;
			}
			printf("�ö��зǿ�\n");
			goto C;
		case(4):
			if (GetHeadLQueue(q, &head_i)) {
				printf("�ö���ͷԪ��Ϊ%d\n", head_i);
				goto C;
			}
			printf("�ö���Ϊ��\n");
			goto C;
		case(5):
			printf("�ö��г���Ϊ%d\n", LengthLQueue(q));
			goto C;
		case(6):
			if (TraverseLQueue(q, 4, LPrint)) {
				printf("���\n");
				goto C;
			}
			printf("�ö���Ϊ��\n");
			goto C;
		case(7):
			ClearLQueue(q);
			printf("���\n");
			goto C;
		case(8):
			DestoryLQueue(q);
			printf("���\n");
			return 0;
		}
	}
	else if (choi == 2) {
	D:map();
		scanf("%d", &n);
		switch (n) {
		case(1):
			printf("���������ݳ��ȣ�");
			scanf("%d", &len);
			if (len + 1 > 20) {
				printf("������Сһ�������\n");
				goto D;
			}
			printf("���������ݣ�");
			scanf_s("%s", data_c,len + 1);
			if (EnLQueue(q, data_c, len + 1)) {
				printf("���\n");
				goto D;
			}
		case(2):
			if (DeLQueue(q)) {
				printf("���\n");
				goto D;
			}
			printf("�ö���Ϊ��\n");
			goto D;
		case(3):
			if (IsEmptyLQueue(q)) {
				printf("�ö���Ϊ��\n");
				goto D;
			}
			printf("�ö��зǿ�\n");
			goto D;
		case(4):
			if (GetHeadLQueue(q, head_c)) {
				printf("�ö���ͷԪ��Ϊ%s\n", head_c);
				goto D;
			}
			printf("�ö���Ϊ��\n");
			goto D;
		case(5):
			printf("�ö��г���Ϊ%d\n", LengthLQueue(q));
			goto D;
		case(6):
			if (TraverseLQueue(q, len + 1, LPrint)) {
				printf("���\n");
				goto D;
			}
			printf("�ö���Ϊ��\n");
			goto D;
		case(7):
			ClearLQueue(q);
			printf("���\n");
			goto D;
		case(8):
			DestoryLQueue(q);
			printf("���\n");
			return 0;
		}
	}
	return 0;
}