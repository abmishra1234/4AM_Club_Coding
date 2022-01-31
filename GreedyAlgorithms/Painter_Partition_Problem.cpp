/*
	Painter's Partition Problem
	
	Problem statement
	We have to paint n boards of length {A1, A2, A3,...,An}. There are k painters available and 
	each takes 1 unit of time to paint 1 unit of board. The Problem is to find the minimum time to
	get this job done under the constraints that any painter will only paint continuous sections of boards,
	say board {2,3,4} or only board {1} or nothing but not board {2, 4, 5}.

	Let us look at some examples:
	- We have input k=2, A = {10, 10, 10, 10}, The output is 20. 
	  Here, we can divide the boards into 2 equal-sized partitions, 
	  so each painter gets 20 units of the board and the total time taken is 20.

	- We have input k=2, A={10,20,30,40}. The output is 60. 
	  Here, we can divide the first 3 boards for one painter and 
	  the last board for the second painter.

	  We can describe the problem as:
	  <<<
		  Given an array A of non-negative integers and a positive integer k, 
		  we have to divide A into k of fewer partitions such that 
		  the maximum sum of the elements in a partition, 
		  overall partitions is minimized.
	  >>>

	  This problem is little tricky for binary search thinking. Incase you 
	  know to form problem into binary search than it might strike you while pressure situation
	  otherwise it is better to go with some average solution first and than go for optimisation.

	  This problem is revision candidate for getting quick hint

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

int getMaxfromArray(int arr[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int getSumfromArray(int arr[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total += arr[i];
	return total;
}

int numberOfPainters(int arr[], int n, int maxLen)
{
	int total = 0, numPainters = 1;

	for (int i = 0; i < n; i++) {
		total += arr[i];

		if (total > maxLen) {
			total = arr[i];
			numPainters++;
		}
	}

	return numPainters;
}

int partition(int arr[], int n, int k)
{
	int low = getMaxfromArray(arr, n);
	int high = getSumfromArray(arr, n);

	while (low < high) {
		int mid = low + (high - low) / 2;
		int requiredPainters = numberOfPainters(arr, n, mid);
		cout << "Low: " << low << " High: " << high << " Mid: " << mid <<
			" Required Painters: " << requiredPainters << endl;

		if (requiredPainters <= k)
			high = mid;

		else
			low = mid + 1;
	}

	return low;
}

int main()
{
	int arr[] = { 10, 20, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << "Minimum time: " << partition(arr, n, k) << endl;
	return 0;
}

#endif //FORREF 
