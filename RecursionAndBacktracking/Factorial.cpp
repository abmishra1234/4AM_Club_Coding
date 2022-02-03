#define FORREF

using namespace std;
#include<iostream>

#ifndef FORREF

struct Factorial {
	// Better is to write this code iterative but written recursive to just demonstratr the recursion
	double doFactorial(int n) {
		// base or terminiting condition
		if (n == 0 || n == 1)
			return 1;
		else
			return n * doFactorial(n - 1);
	}
};

int main()
{
	// defining the input
	int input = 6;
	// calling the function and printing the output
	Factorial f;
	double result = f.doFactorial(input);
	cout << input << "! = " << result;
}

#endif // FORREF