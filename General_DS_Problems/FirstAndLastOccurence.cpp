/*
	First and Last Occurrence of an Element
	Use Binary Search to find the first and last occurrence of an element in an array.
	//========================
	Problem statement
	Given a sorted array with possibly duplicate elements, the task is to find indexes of 
	the first and last occurrences of an element x in the given array.

	Let's Evaluate the Performance of your code
	// Naive Approach -- Bruteforce solution
	Approach01 : Naive or Bruteforce approach
	Time Complexity - It's linear search, meaning you are checking all the 
	element in the given array, and so the time coplexity will be O(N)
	Space Complexity -  we don't need any additional memory in code, so ideally it will be O(1)
	Approach02 : Binary Search Approch, since the array is already sorted given in problem
	Time complexity - O(logn), Space Complexity - O(1)

	So visibly Approach 02 is better solution so let's implement it
//========================
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct Solution
{
	int first(int arr[], int left, int right, int target, int arrSize)
	{
		if (right >= left) {
			int mid = left + (right - left) / 2;
			if ((mid == 0 || target > arr[mid - 1]) && arr[mid] == target) {
				return mid;
			}
			else if (target > arr[mid]) {
				return first(arr, mid + 1, right, target, arrSize);
			}
			else
				return first(arr, left, mid - 1, target, arrSize);
		}
		return -1;
	}
	int last(int arr[], int left, int right, int target, int arrSize)
	{
		if (right >= left) {
			int mid = left + (right - left / 2);
			if (arr[mid] == target && (mid == arrSize - 1 || target < arr[mid + 1])) {
				return mid;
			}
			else if (arr[mid] > target) {
				return last(arr, left, mid - 1, target, arrSize);
			}
			else
				return last(arr, mid + 1, right, target, arrSize);
		}
		return -1;
	}
};

/*
	Just below driver code for testing the logic of implementation...
*/
int main()
{
	Solution sln; // it is just for calling the method of the solution class

	int arr[] = { 1, 2, 2, 2, 2, 3, 4,7,7, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(int);
	int x = 2;
	cout << "First Occurrence = " << sln.first(arr, 0, n - 1, x, n) << endl;
	cout << "Last Occurrence = " << sln.last(arr, 0, n - 1, x, n);

	return 0;
}
#endif // FORREF
