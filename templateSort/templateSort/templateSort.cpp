#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
template <class T>

void selectionSort(T array[], unsigned long size) {
	for (unsigned long index_i = 0; index_i < size - 1; ++index_i) {
		unsigned long min_index = index_i;

		for (unsigned long index_j = index_i + 1; index_j < size; ++index_j) {
			if (array[index_j] < array[min_index]) {
				min_index = index_j;
			}
		}

		if (min_index != index_i) {
			swap(array[index_i], array[min_index]);
		}
	}
}
template <class T>
void Print(T array[], unsigned long size) {
	for (unsigned long i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
}


int main()
{
	char A[3] = { 'a','y','c' };
	unsigned long size = sizeof A / sizeof(A[0]);
	cout << size << endl;
	selectionSort(A, size);
	Print(A, size);
	return 0;
}

