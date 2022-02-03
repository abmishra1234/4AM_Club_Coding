/*
	Another Recursion Sample code
	- Base condition  ( n <= 1 :  return n )
	- recursive relationship (f(x) : x + f(x-1))
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>



struct SumOfN {
	int sum(int n) {
		if (n <= 1)
			return 1;
		else
			return n + sum(n - 1);
	}
};

int main() {

	int input = 5;
	SumOfN sn;
	// printing the answer
	cout << "The sum of first " << input << " numbers is " << sn.sum(input);
	return 0;
}
#endif // FORREF
