/*
	Is this given Array a Palindrome?

	Problem Statement
	Write a function palindrome that takes an integer 
	array and returns true if the array is a palindrome 
	else it returns false.

	Lets solve this problem from different approaches.
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<string>

struct Palindrome {
	// Iterative Approach
	bool isPalindrom_iter(int array[], int left, int right) {
		while (left < right) {
			if (array[left] != array[right]) {
				return false;
			}
			++left;
			--right;
		}

		return true;
	}

	// Recursive Approach
	bool isPalindrom(int array[], int left, int right) {
		bool res = false;

		if (left >= right) {
			return true;
		}
		else
		{
			if (array[left] != array[right]) {
				return false;
			}
			return isPalindrom(array, left + 1, right - 1);
		}
	}
};

// Driver code 
int main()
{
	int array[] = { 1, 2, 2, 2, 1 };//declare an array
	int n = sizeof(array) / sizeof(array[0]);//calculate the size of the array
	int startIndex = 0;//define the starting index
	int endIndex = n - 1;//define the ending index
	Palindrome pa;
	if (pa.isPalindrom(array, startIndex, endIndex) == 1) //call recursive function
		cout << "Array is a Palindrome";
	else
		cout << "Array is not Palindrome";

	return 0;
}

#endif // FORREF


