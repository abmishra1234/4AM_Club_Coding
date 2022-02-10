/*
	First Solution is recursive ( non DP) 
	We’ll see this technique in our example of Fibonacci numbers. 

	Now, you must visualize that if you go for n = 40, than your program is taking substantial time
	in processing and this is making your code in-efficient. What we do than?

	So, one natural step should be here to track sown the recursive calls 
	fib(5) = fib(4)+fib(3)
	= 2*fib(3)+fib(2) and so on...
	so you might realized that in this small value we see many overlapping of call.
	so in bigger number we might have many overlapping call...

	OK, this seems to be resolved using memoization. that's what we learned sometime back.

	So, let's implement this through memoization
*/
//#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

#define llint long long int 
typedef vector<int> Vect;

struct Fibonacci {

	/*
		Top-down approach
		This is called recursive and memoization in dp
	*/
	llint calcFibonacci_rec(llint n, Vect &memo) {
		if (n <= 1)
			return n;
		else if (memo[n] != -1)
			return memo[n];
		else {
			memo[n] = (calcFibonacci_rec(n - 1, memo) + calcFibonacci_rec(n - 2, memo));
			return memo[n];
		}
	}

	/*
		Bottom-up approach
		This is called bottom-up or Tabulation
		here, you have to solve the sub problem first and their after by adding up 
		of these small problem's solution to find the solution of big problem.
	*/

	llint calcFibonacci_iter(llint n, Vect &memo) {
		memo[0] = 0;
		memo[1] = 1;
		for (int i = 2; i <= n; ++i) {
			memo[i] = memo[i - 1] + memo[i - 2];
		}
		return memo[n];
	}
};

int main(int argc, char* argv[]) {
	Fibonacci* fib = new Fibonacci();
	int n = 11;
	Vect  memo(n + 1, -1);
	cout << "5th Fibonacci is ---> " << fib->calcFibonacci_rec(5, memo) << endl;
	cout << "6th Fibonacci is ---> " << fib->calcFibonacci_rec(6, memo) << endl;
	cout << "40th Fibonacci is ---> " << fib->calcFibonacci_rec(11, memo) << endl;

	delete fib;
}
#endif // FORREF

