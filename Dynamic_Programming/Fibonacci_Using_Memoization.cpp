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
#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

#define llint long long int 

struct Fibonacci {
	llint dp[100] = {0};
	/*
		Top-down approach
		This is called recursive and memoization in dp
	*/
	llint calcFibonacci_rec(llint n) {
		if (n <= 1)
			return n;
		else if (dp[n] != 0)
			return dp[n];
		else {
			dp[n] = (calcFibonacci_rec(n - 1) + calcFibonacci_rec(n - 2));
			return dp[n];
		}
	}

	/*
		Bottom-up approach
		This is called bottom-up or Tabulation
		here, you have to solve the sub problem first and their after by adding up 
		of these small problem's solution to find the solution of big problem.
	*/
	llint calcFibonacci_iter(llint n) {
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};

int main(int argc, char* argv[]) {
	Fibonacci* fib = new Fibonacci();
	cout << "5th Fibonacci is ---> " << fib->calcFibonacci_iter(5) << endl;
	cout << "6th Fibonacci is ---> " << fib->calcFibonacci_iter(6) << endl;
	cout << "40th Fibonacci is ---> " << fib->calcFibonacci_iter(40) << endl;

	delete fib;
}


#endif // FORREF

