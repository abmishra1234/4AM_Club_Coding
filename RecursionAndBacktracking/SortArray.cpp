/*
	Sort an Array
	
*/

#define FORREF
#ifndef FORREF
#include<iostream>
using namespace std;

//Recursive function to sort the array
void SortArray(int arr[], int startIndex, int size)
{
	// find the minimum element in the unsorted subarray[i..n-1]
	  // and swap it with arr[startIndex]
	int min = startIndex;
	for (int j = startIndex + 1; j < size; j++)
	{
		// if arr[j] element is less, then it is the new minimum
		if (arr[j] < arr[min])
			min = j;	// update index of min element
	}

	//swap values at two indices in the array
	int Swap = arr[startIndex];
	arr[startIndex] = arr[min];
	arr[min] = Swap;

	// base case
	if (startIndex + 1 < size) { //if one element is left to be sorted
		SortArray(arr, startIndex + 1, size); // recursive case
	}
}

void printSortArray(int* numbers, int size)
{
	SortArray(numbers, 0, size);//call the recursive function
	for (int i = 0; i < size; i++)//print elements of the array
		cout << numbers[i] << ' ';
}
//Driver function
int main()
{
	int array[] = { 3, 2, 9, 1, 8 };// define an array
	int size = 5;//define the size of array
	cout << "Sorted Array:\n";
	printSortArray(array, size);//call the print function
	return 0;
}
#endif // FORREF

