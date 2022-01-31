/*
	GCD :  Greatest Common Divisor
	gcd(A, B) = gcd(B, A % B) // recurrence for GCD
	gcd(A, 0) = A // base case

	Explanation:

	The above function, gcd(), accepts two numbers as input and provides the output. 
	As we are using the % operator, the number of recursive calls required to reach 
	the final result would be less than n, where n = max(a,b).

	Euclid’s GCD algorithm runs in O(log(N)), where N = max(a,b).
*/

using namespace std;
#include<iostream>

#define FORREF
#ifndef FORREF

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main() {
	cout << gcd(14, 4) << endl;
}

#endif // !FORREF

