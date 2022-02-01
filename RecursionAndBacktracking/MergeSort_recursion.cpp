/*
	Merge Sort
	Use Recursion to implement merge sort.
	Problem statement

	@Note :  This code is just for practice the recursion code
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct MergeSort {
	int* tarr;
	MergeSort(int n) :tarr(new int[n]) {
		cout << "Array data is initialized..." << endl;
	}

	void merge(int arr[], int left, int mid, int right) {
		int i = left;
		int j = mid + 1;
		int k = left;

		while (i <= mid && j <= right) {
			if (arr[i] <= arr[j]) {
				tarr[k++] = arr[i++];
			}
			else {
				tarr[k++] = arr[j++];
			}
		}

		while (i <= mid) {
			tarr[k++] = arr[i++];
		}

		while (j <= right) {
			tarr[k++] = arr[j++];
		}

		i = left; j = left;
		while (i < k) {
			arr[j++] = tarr[i++];
		}
	}

	void sort(int arr[], int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			sort(arr, left, mid);
			sort(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}

	~MergeSort() {
		delete[]tarr;
		tarr = nullptr;
	}

};

int main() {
	int arr[] = { 1,9,4,6,13,74,56,32,41,7,5 };
	int arrSize = sizeof(arr) / sizeof(int);
	MergeSort ms(arrSize);
	ms.sort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}

#endif // FORREF
