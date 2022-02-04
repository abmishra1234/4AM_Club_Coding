/*
	Invert the Position of Elements in an Array
	
	Definition
	Given an array, you have to reverse the position of array elements.
	
	Solution:
	Try to solve this using multiple approach
*/

#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>

struct InvertPosition {

	void reverse_iter(int arr[], int left, int right) {
		while (left < right) {
			swap(arr[left], arr[right]);
			++left;
			--right;
		}
	}

	void reverse(int arr[], int left, int right) {
		if (left >= right)
			return;
		else
		{
			swap(arr[left], arr[right]);
			reverse(arr, left + 1, right - 1);
		}
	}
};

//Driver function
int main()
{
	int array[5] = { 1,2,3,4,5 };//define the array
	int size = 5;//define the size of array
	InvertPosition ip;
	ip.reverse(array, 0, size - 1);//call the recursive function
	//reverseArray(array, 0, size - 1); //call the recursive function
	cout << "Reversed Array:";
	for (int i = 0; i < 5; i++)
		cout << array[i] << " ";//print the array
	cout << endl;
	return 0;
}




#endif // FORREF