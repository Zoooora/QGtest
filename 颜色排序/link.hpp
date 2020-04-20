#pragma once

void ColorSort(int* a, int size) {
	int i = 0, n = 0;
	int temp;
	for (; i < size - 1; i++) {
		if (a[i] > a[i + 1]) {
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
		if (i + 2 == size) {
			i = -1;
			size -= 1;
		}
	}
}

