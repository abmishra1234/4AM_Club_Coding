
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
