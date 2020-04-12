#include "AQueue.h"
#include <stdio.h>

int map() {
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("˳����в����˵�\n");
	printf("1.���\n");
	printf("2.����\n");
	printf("3.�����п�\n");
	printf("4.�ж϶����Ƿ�Ϊ��\n");
	printf("5.�鿴��ͷԪ��\n");
	printf("6.��ȡ���г���\n");
	printf("7.�������в����\n");
	printf("8.��ն���\n");
	printf("9.���ٶ��в��˳�\n");
	printf("~~~~~~~~~~~~~~~~~~~\n");
	printf("������ѡ�");
	return 0;
}

int choice() {
	char type;
	printf("1.����\n2.���ַ�\n");
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
			printf("���������ݣ�");
			scanf("%d", &data_i);
			if (EnAQueue(q, &data_i)) {
				printf("���\n");
				goto C;
			}
			printf("�ö�������\n");
			goto C;
		case(2):
			if (DeAQueue(q)) {
				printf("���\n");
				goto C;
			}
			printf("�ö���Ϊ��\n");
			goto C;
		case(3):
			if (IsEmptyAQueue(q)) {
				printf("�ö���Ϊ��\n");
				goto C;
			}
			printf("�ö��зǿ�\n");
			goto C;
		case(4):
			if (IsFullAQueue(q)) {
				printf("�ö�������\n");
				goto C;
			}
			printf("�ö���δ��\n");
			goto C;
		case(5):
			if (GetHeadAQueue(q,&head_i)) {
				printf("�ö���ͷԪ��Ϊ%d\n",head_i);
				goto C;
			}
			printf("�ö���Ϊ��\n");
			goto C;
		case(6):
			printf("�ö��г���Ϊ%d\n", LengthAQueue(q));
			goto C;
		case(7):
			if (TraverseAQueue(q, 4, &APrint)) {
				printf("���\n");
				goto C;
			}
			printf("�ö���Ϊ��\n");
			goto C;
		case(8):
			ClearAQueue(q);
			printf("���\n");
			goto C;
		case(9):
			DestoryAQueue(q);
			printf("���\n");
			return 0;
		}
	}
	else if (choi == 2) {
	D:map();
		scanf("%d", &n);
		getchar();
		switch (n) {
		case(1):
			printf("���������ݣ�");
			scanf("%c", &data_c);
			if (EnAQueue(q, &data_c)) {
				printf("���\n");
				goto D;
			}
			printf("�ö�������\n");
			goto D;
		case(2):
			if (DeAQueue(q)) {
				printf("���\n");
				goto D;
			}
			printf("�ö���Ϊ��\n");
			goto D;
		case(3):
			if (IsEmptyAQueue(q)) {
				printf("�ö���Ϊ��\n");
				goto D;
			}
			printf("�ö��зǿ�\n");
			goto D;
		case(4):
			if (IsFullAQueue(q)) {
				printf("�ö�������\n");
				goto D;
			}
			printf("�ö���δ��\n");
			goto D;
		case(5):
			if (GetHeadAQueue(q, &head_c)) {
				printf("�ö���ͷԪ��Ϊ%c\n", head_c);
				goto D;
			}
			printf("�ö���Ϊ��\n");
			goto D;
		case(6):
			printf("�ö��г���Ϊ%d\n", LengthAQueue(q));
			goto D;
		case(7):
			if (TraverseAQueue(q, 1, &APrint)) {
				printf("���\n");
				goto D;
			}
			printf("�ö���Ϊ��\n");
			goto D;
		case(8):
			ClearAQueue(q);
			printf("���\n");
			goto D;
		case(9):
			DestoryAQueue(q);
			printf("���\n");
			return 0;
		}
	}
	return 0;
}