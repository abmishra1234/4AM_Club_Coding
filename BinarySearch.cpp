/*
	Binary Search
	Approach 01 : Recursive approach
	Approach 02 : Iterative approach

	@Note: It is general advice for all the coder, prefer iterative binary search instead recursion.
	but writing the recursion code sometime not easy and intutive so as per comfirtable level write your code
	but incase your code is recursive, always careful about the recursive stack.

	@copyright : Abinash Mishra, You can use for understanding the concept.
*/
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct BinarySearch
{
	int BinarySearch_rec(int arr[], int left, int right, int target)
	{
		// base condition
		if (left >= right)
		{
			if (left == right && arr[left] == target) {
				return left;
			}
			return -1;
		}

		int mid = left + (right - left) / 2;
		int res = -1;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] < target)
		{
			// check right half
			res = BinarySearch_rec(arr, mid + 1, right, target);

		}
		else
		{
			// check the left half
			res = BinarySearch_rec(arr, left, mid - 1, target);
		}

		return res;
	}
	int BinarySearch_iter(int arr[], int left, int right, int target)
	{
		// there is no base condition, you have to iterate and start grow until the point you are looking
		while (left <= right) {
			if (left == right)
			{
				if (arr[left] == target)
				{
					return left;
				}
				return -1;
			}

			int mid = left + (right - left) / 2;
			if (arr[mid] == target)
			{
				return mid;
			}
			else if (arr[mid] < target)
			{
				left = mid + 1;
			}
			else
				right = mid - 1;
		}

		return -1;
	}
};

int main()
{
	int arr[] = { 2, 3, 4, 10, 40, 41 };
	int x = 32;
	int n = sizeof(arr) / sizeof(arr[0]);
	BinarySearch bs;
	int result = bs.BinarySearch_iter(arr, 0, n - 1, x);
	if (result == -1)
		cout << "Element is not present in array";
	else
		cout << "Element is present at index " << result;

	return 0;
}
#endif // FORREF

