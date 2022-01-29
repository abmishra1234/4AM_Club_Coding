/*
	Binary Search
	Approach 01 : Recursive approach
	Approach 02 : Iterative approach
	Approach 03 : Any Improvements possible?
	@copyright : Abinash Mishra, You can use for understanding the concept.
*/

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
			res = BinarySearch_rec(arr, left, mid-1, target);
		}

		return res;
	}

	int BinarySearch_iter(int arr[], int left, int right) 
	{


		return -1;
	}
};

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	BinarySearch bs;
	int result = bs.BinarySearch_rec(arr, 0, n - 1, x);
	if (result == -1)
		cout << "Element is not present in array";
	else
		cout << "Element is present at index " << result;

	return 0;
}