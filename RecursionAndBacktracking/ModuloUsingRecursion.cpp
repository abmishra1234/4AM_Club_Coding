/*
	Base condition
	if(n/m == 0)
		return n;
	else
		f(n,m) = f(n/m, m)
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>


struct MyOperation {
	// Approach 01
	int Mod_01(int n, int m) {
		if (0 == n / m) {
			return n;
		}
		else {
			n -= ((n / m) * m);
			return Mod_01(n, m);
		}
	}

	// Approach 02
	int Mod_02(int n, int m) {
		if (m == 0) {
			return 0;
		}

		if (n < m) {
			return n;
		}
		else {
			return Mod_02(n - m, m);
		}
	}
};

int main() {
	int a = 12;
	int b = 5;
	MyOperation op;
	cout << a << " mod " << b << " = " << op.Mod_02(a, b);
	return 0;
}
#endif //FORREF 
