/*
	Bubble Sort
	Requirement :  Use Recursion to implement bubble sort.
	Problem statement Given an array arr, you need to sort the elements.
	Implementation:
*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct BubbleSort {
	void sort(int arr[], int arrSize) {
		// so my base condition will be , when we left out with only one element
		// than that element is at righe place so exit the recursion
		if (arrSize == 1)
			return;
		for (int i = 1; i < arrSize; ++i) {
			// assuming that we have to sort array in increasing order
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
			}
		}
		sort(arr, arrSize - 1);
	}
};

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort bs;
	bs.sort(arr, n);
	cout << "Sorted array : \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
#endif
