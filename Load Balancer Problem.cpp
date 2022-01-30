/*
	Load Balancer Problem
	Problem Statement:
	https://www.spoj.com/problems/BALIFE/
	
	Solution:
	Number of processors: n.
	Some observations:
	If the sum of the number of jobs of all processors is not divisible by n, the loads can’t be re balanced. Print -1;
	Else do the following:
	individual_load = sum/n
	ans=0
	for i (0,n-1)
	{
		difference_from_balanced=a[i] - individual_load
		jobs[ i+1 ] += difference_from_balance
		ans = max(ans , abs(difference_from_balanced)) // we have to find the max diff
	}
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<algorithm>
#include<numeric>

int max(int i, int j) {
	if (i > j)
		return i;
	return j;
}

int main()
{
	int arr[] = { 16, 17, 15, 0, 20, 1, 1, 2 };
	int arrSize = sizeof(arr) / sizeof(int);
	int load = accumulate(arr, arr + arrSize, 0);

	if (load % arrSize)
		return -1;

	// to find the avg load by load /= arrSize
	load /= arrSize;
	int max_load = 0, diff = 0;

	for (int i = 0; i < arrSize; ++i) {
		diff += arr[i] - load;

		if (diff < 0) {
			max_load = max(max_load, -1 * diff);
		}
		else {
			max_load = max(max_load, diff);
		}
	}
	cout << max_load << endl;
	return 0;
}

#endif // FORREF
