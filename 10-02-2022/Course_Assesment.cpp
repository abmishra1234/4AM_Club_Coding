/*
	Gradding Assesment Problem
*/

#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>

bool check(int* arr, int n, int ind, int prev) {
	if (ind == n)
		return true;
	if (arr[ind] < prev)
		return false;

	return check(arr, n, ind + 1, arr[ind]);
}

bool isSorted(int* arr, int n) {
	if (n == 0)
		return false;
	if (n == 1)
		return true;

	return check(arr, n, 1, arr[0]);
}



int main() {
	int arr[] = { 1,3,5,23,56,58,67 };
	int n = sizeof(arr) / sizeof(int);
	cout << isSorted(arr, n);
}


#endif // FORREF
