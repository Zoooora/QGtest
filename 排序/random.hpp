#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

int ten_thousand[10000], fi_thousand[50000], two_hundred_thousand[200000], one_hundred[100];

class random_num {
public:
	void init_t_thousand() {
		srand(time(NULL));
		int i;
		for (i = 0; i < 10000; i++) {
			ten_thousand[i] = rand();
		}
		FILE* tfp = fopen("10000_data.txt", "w+");
		for (i = 0; i < 10000; i++) {
			fprintf(tfp, "%d ", ten_thousand[i]);
		}
		fclose(tfp);
	}

	void init_f_thousand() {
		srand(time(NULL));
		int i;
		for (i = 0; i < 50000; i++) {
			fi_thousand[i] = rand();
		}
		FILE* ffp = fopen("50000_data.txt", "w+");
		for (i = 0; i < 50000; i++) {
			fprintf(ffp, "%d ", fi_thousand[i]);
		}
		fclose(ffp);
	}

	void init_t_h_thousand() {
		srand(time(NULL));
		int i;
		for (i = 0; i < 200000; i++) {
			two_hundred_thousand[i] = rand();
		}
		FILE* t_h_fp = fopen("200000_data.txt", "w+");
		for (i = 0; i < 200000; i++) {
			fprintf(t_h_fp, "%d ", two_hundred_thousand[i]);
		}
		fclose(t_h_fp);
	}

	void init_one_hundred() {
		srand(time(NULL));
		int i;
		for (i = 0; i < 100; i++) {
			one_hundred[i] = rand();
		}
		FILE* t_h_fp = fopen("100_data.txt", "w+");
		for (i = 0; i < 100; i++) {
			fprintf(t_h_fp, "%d ", one_hundred[i]);
		}
		fclose(t_h_fp);
	}

	void get_t_thousand(int* a) {
		int i = 0;
		freopen("10000_data.txt", "r", stdin);
		for (i = 0; i < 10000; i++) {
			scanf("%d", &a[i]);
		}
		fclose(stdin);
	}

	void get_fi_thousand(int* a) {
		int i = 0;
		freopen("50000_data.txt", "r", stdin);
		for (i = 0; i < 50000; i++) {
			scanf("%d", &a[i]);
		}
		fclose(stdin);
	}

	void get_t_h_thousand(int* a) {
		int i = 0;
		freopen("200000_data.txt", "r", stdin);
		for (i = 0; i < 200000; i++) {
			scanf("%d", &a[i]);
		}
		fclose(stdin);
	}

	void get_one_hundred(int* a) {
		int i = 0;
		freopen("100_data.txt", "r", stdin);
		for (i = 0; i < 100; i++) {
			scanf("%d", &a[i]);
		}
		fclose(stdin);
	}
};
