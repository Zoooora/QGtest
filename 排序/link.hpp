#pragma once
#include "qgsort.hpp"
#include "random.hpp"
#include <ctime>

SORT qgsort;
random_num NUM;

int tenthousand[10000], fithousand[50000], twohundred_thousand[200000], onehundred[100];
int temp1[10000], temp2[50000], temp3[200000], temp4[100];

int insert_10000_data() {
	NUM.get_t_thousand(tenthousand);
	clock_t begin = clock();
	qgsort.insertSort(tenthousand, 10000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_insert_10000.txt", "w+");
	for (int i = 0; i < 10000; i++) {
		fprintf(p, "%d ", tenthousand[i]);
	}
	fclose(p);
	return end;
}

int insert_50000_data() {
	NUM.get_fi_thousand(fithousand);
	clock_t begin = clock();
	qgsort.insertSort(fithousand, 50000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_insert_50000.txt", "w+");
	for (int i = 0; i < 50000; i++) {
		fprintf(p, "%d ", fithousand[i]);
	}
	fclose(p);
	return end;
}

int insert_200000_data() {
	NUM.get_t_h_thousand(twohundred_thousand);
	clock_t begin = clock();
	qgsort.insertSort(twohundred_thousand, 200000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_insert_200000.txt", "w+");
	for (int i = 0; i < 200000; i++) {
		fprintf(p, "%d ", twohundred_thousand[i]);
	}
	fclose(p);
	return end;
}

int insert_100_data() {
	int i;
	clock_t begin = clock();
	for (i = 0; i < 100000; i++) {
		NUM.get_one_hundred(onehundred);
		qgsort.insertSort(onehundred, 100);
	}
	clock_t end = clock() - begin;
	FILE* p = fopen("after_insert_100.txt", "w+");
	for (i = 0; i < 100; i++) {
		fprintf(p, "%d", onehundred[i]);
	}
	fclose(p);
	return end;
}

int merge_10000_data() {
	NUM.get_t_thousand(tenthousand);
	clock_t begin = clock();
	qgsort.MergeSort(tenthousand, 0, 10000, temp1);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_merge_10000.txt", "w+");
	for (int i = 0; i < 10000; i++) {
		fprintf(p, "%d ", tenthousand[i]);
	}
	fclose(p);
	return end;
}

int merge_50000_data() {
	NUM.get_fi_thousand(fithousand);
	clock_t begin = clock();
	qgsort.MergeSort(fithousand, 0, 50000, temp2);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_merge_50000.txt", "w+");
	for (int i = 0; i < 50000; i++) {
		fprintf(p, "%d ", fithousand[i]);
	}
	fclose(p);
	return end;
}

int merge_200000_data() {
	NUM.get_t_h_thousand(twohundred_thousand);
	clock_t begin = clock();
	qgsort.MergeSort(twohundred_thousand, 0, 200000, temp3);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_merge_200000.txt", "w+");
	for (int i = 0; i < 200000; i++) {
		fprintf(p, "%d ", twohundred_thousand[i]);
	}
	fclose(p);
	return end;
}

int merge_100_data() {
	int i;
	clock_t begin = clock();
	for (i = 0; i < 100000; i++) {
		NUM.get_one_hundred(onehundred);
		qgsort.MergeSort(onehundred, 0, 100, temp4);
	}
	clock_t end = clock() - begin;
	FILE* p = fopen("after_merge_100.txt", "w+");
	for (i = 0; i < 100; i++) {
		fprintf(p, "%d", onehundred[i]);
	}
	fclose(p);
	return end;
}

int quick_R_10000_data() {
	NUM.get_t_thousand(tenthousand);
	clock_t begin = clock();
	qgsort.QuickSort_Recursion(tenthousand, 0, 10000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_quick_R_10000.txt", "w+");
	for (int i = 0; i < 10000; i++) {
		fprintf(p, "%d ", tenthousand[i]);
	}
	fclose(p);
	return end;
}

int quick_R_50000_data() {
	NUM.get_fi_thousand(fithousand);
	clock_t begin = clock();
	qgsort.QuickSort_Recursion(fithousand, 0, 50000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_quick_R_50000.txt", "w+");
	for (int i = 0; i < 50000; i++) {
		fprintf(p, "%d ", fithousand[i]);
	}
	fclose(p);
	return end;
}

int quick_R_200000_data() {
	NUM.get_t_h_thousand(twohundred_thousand);
	clock_t begin = clock();
	qgsort.QuickSort_Recursion(twohundred_thousand, 0, 200000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_quick_R_200000.txt", "w+");
	for (int i = 0; i < 200000; i++) {
		fprintf(p, "%d ", twohundred_thousand[i]);
	}
	fclose(p);
	return end;
}

int quick_R_100_data() {
	int i;
	clock_t begin = clock();
	for (i = 0; i < 100000; i++) {
		NUM.get_one_hundred(onehundred);
		qgsort.QuickSort_Recursion(onehundred, 0, 100);
	}
	clock_t end = clock() - begin;
	FILE* p = fopen("after_quick_R_100.txt", "w+");
	for (i = 0; i < 100; i++) {
		fprintf(p, "%d", onehundred[i]);
	}
	fclose(p);
	return end;
}

int count_10000_data() {
	NUM.get_t_thousand(tenthousand);
	clock_t begin = clock();
	qgsort.CountSort(tenthousand, 10000, 1);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_count_10000.txt", "w+");
	for (int i = 0; i < 10000; i++) {
		fprintf(p, "%d ", tenthousand[i]);
	}
	fclose(p);
	return end;
}

int count_50000_data() {
	NUM.get_fi_thousand(fithousand);
	clock_t begin = clock();
	qgsort.CountSort(fithousand, 50000, 1);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_count_50000.txt", "w+");
	for (int i = 0; i < 50000; i++) {
		fprintf(p, "%d ", fithousand[i]);
	}
	fclose(p);
	return end;
}

int count_200000_data() {
	NUM.get_t_h_thousand(twohundred_thousand);
	clock_t begin = clock();
	qgsort.CountSort(twohundred_thousand, 200000, 1);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_count_200000.txt", "w+");
	for (int i = 0; i < 200000; i++) {
		fprintf(p, "%d ", twohundred_thousand[i]);
	}
	fclose(p);
	return end;
}

int count_100_data() {
	int i;
	clock_t begin = clock();
	for (i = 0; i < 100000; i++) {
		NUM.get_one_hundred(onehundred);
		qgsort.CountSort(onehundred, 100, 1);
	}
	clock_t end = clock() - begin;
	FILE* p = fopen("after_count_100.txt", "w+");
	for (i = 0; i < 100; i++) {
		fprintf(p, "%d", onehundred[i]);
	}
	fclose(p);
	return end;
}

int radix_10000_data() {
	NUM.get_t_thousand(tenthousand);
	clock_t begin = clock();
	qgsort.RadixCountSort(tenthousand, 10000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_radix_10000.txt", "w+");
	for (int i = 0; i < 10000; i++) {
		fprintf(p, "%d ", tenthousand[i]);
	}
	fclose(p);
	return end;
}

int radix_50000_data() {
	NUM.get_fi_thousand(fithousand);
	clock_t begin = clock();
	qgsort.RadixCountSort(fithousand, 50000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_radix_50000.txt", "w+");
	for (int i = 0; i < 50000; i++) {
		fprintf(p, "%d ", fithousand[i]);
	}
	fclose(p);
	return end;
}

int radix_200000_data() {
	NUM.get_t_h_thousand(twohundred_thousand);
	clock_t begin = clock();
	qgsort.RadixCountSort(twohundred_thousand, 200000);
	clock_t end = clock() - begin;
	FILE* p = fopen("after_radix_200000.txt", "w+");
	for (int i = 0; i < 200000; i++) {
		fprintf(p, "%d ", twohundred_thousand[i]);
	}
	fclose(p);
	return end;
}

int radix_100_data() {
	int i;
	clock_t begin = clock();
	for (i = 0; i < 100000; i++) {
		NUM.get_one_hundred(onehundred);
		qgsort.RadixCountSort(onehundred, 100);
	}
	clock_t end = clock() - begin;
	FILE* p = fopen("after_radix_100.txt", "w+");
	for (i = 0; i < 100; i++) {
		fprintf(p, "%d", onehundred[i]);
	}
	fclose(p);
	return end;
}