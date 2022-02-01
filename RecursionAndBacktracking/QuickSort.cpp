/*
	Quick Sort
	Use Recursion to implement Quick Sort.

	Problem statement 
	Quick Sort is a Divide and Conquer algorithm. 
	It is the third sorting algorithm that we are going to discuss 
	to perform sorting of an array of numbers.

	Solution: Recursive approach
	
	This sorting algorithm picks an element as a pivot 
	and partitions the given array around the picked pivot.

	There are many different versions of Quick Sort 
	that pick the pivot in different ways such as:

	- Always picking the first element as the pivot element
	- Always picking the last element as the pivot element(implemented below )
	- Picking a random element as pivot
	- Picking the median as pivot

	The main focus of this approach is partition process.
	The goal of the partition process is that when given an array and an element x
	of the array as the pivot , it should put x is at correct position in a sorted array
	and put all smaller elements, smaller than x , before x and all number greater than x , right
	of the pivot element. All of this is done in linear time. 
	For this implementation we put the pivot as last element of the array. 

	To achieve this process, following process is followed
	1. A pointer is fixed at pivot element. The pivot element is compared with the elements beginning from the first index.
	If the element greater than the pivot element is reached, a second pointer is set for that element.
	2. Now, the pivot element is compared with the other elements (a third pointer).If an element smaller 
	than the pivot element is reached, the smaller element is swapped with the greater element found earlier.
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

/*
	These are some logical steps to achieve the Quick Sorting.
	1. Repeat the porcess until every element placed at right position.
	2. Select the pivot element
	3. Put all element smaller than pivot element to the left
	   and all greater element to the right
*/
struct QuickSort {

	int Partition(int arr[], int left, int right, int pivot) {
		int li = left;
		int ri = right;

		while (true) {
			while (arr[li] < pivot) {
				li++;
			}

			while (ri > 0 && arr[ri] > pivot) {
				ri--;
			}

			if (li >= ri)
				break;
			else
			{
				// interchange
				swap(arr[li], arr[ri]);
			}
		}

		// finally positioning the pivot element
		swap(arr[li], arr[ri]);
		return li;
	}

	void quickSort(int arr[], int left, int right) {
		if (left < right) {
			int pivot = arr[right];
			int pivot_point = Partition(arr, left, right, pivot);
			quickSort(arr, left, pivot_point - 1);
			quickSort(arr, pivot_point + 1, right);
		}
	}
};

int main() {
	int arr[7] = { 4,6,3,2,1,9,7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSort qs;
	qs.quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
#endif // FORREF
