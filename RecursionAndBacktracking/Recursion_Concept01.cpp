/*
	Multiplication Without Using * Operator
	Meaning you want to implement a*b without using operaot '*'

	Problem statement
	In this problem, we need to find the result of the 
	multiplication of two numbers, a and b but without using * operator.

	one catch here is you have to implement this using recursion only.
	Implementation:
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>


struct Multiplication
{
	int recAddition(int a, int b) {
		if (b == 0) {
			return 0;
		}
		else if (b == 1) {
			return a;
		}
		else if (b < 0) {
			b = -b;
			--b;
			return (-a + recAddition(a, -b));
		}
		else {
			return (a + recAddition(a, b - 1));
		}
	}
};

int main() {
	int a = -3, b = 5;
	Multiplication mul;
	cout << "answer = " << mul.recAddition(a, b) << endl;

}
#endif // !FORREF


