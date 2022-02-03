/*
	Fibonacci Sequence
	1. Base or termination condition
	if n == 0 || n == 1
		return n;
	else
		return fx(n-1) + fx(n-2);
*/


#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>


struct MyOperation {
	// Approach 01
	int Fib(int n) {
		if (0 == n || 1 == n) {
			return n;
		}
		else {
			return Fib(n - 1) + Fib(n - 2);
		}
	}
};

int main() {
	int n = 23;
	MyOperation op;
	cout << op.Fib(n);
	return 0;
}
#endif //FORREF 
