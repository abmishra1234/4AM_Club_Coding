/*
	Find the First Occurrence of a Number in an Array
	
	Given an array, find the first occurrence of a given number 
	in that array and return the index of that number.

	Lets discuss different approaches below

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct FirstOccurence {
	
	// Iterative solution
	int get_Iter(int array[], int nElement, int index, int target) {
		for (int i = index; i < nElement; ++i) {
			if (array[i] == target)
				return i;
		}

		return -1;
	}

	// recursive solution
	int get(int array[], int nElement, int index, int target) {
		if (index >= nElement)
			return -1;
		else
		{
			if (array[index] == target) {
				return index;
			}
			else
				return get(array, nElement, index + 1, target);
		}
	}

};

int main() {
	int array[] = { 2,3,4,1,7,8,3 };//define an array
	int x = 3;//define the number whose first occurence is to be found
	int size = 7;//define size of array
	
	FirstOccurence fc;

	cout << "First Occurence of the number " << x << " is at index:";
	cout << fc.get(array, size, 0, x);

	return 0;
}



#endif // FORREF