/*
	TBD --- Not complete yet
	LIS ( Longest Increasing Sequence)
	
	Status:
	Recursion Approach :  In progres
	Recursion with Memoization : TBD
	Solution with Tabulation : TBD

	LIS
	- length of the Lomgest Increasing Sequence
	- LIS sequence also



*/

//#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>

typedef vector<int> Memo;

struct LIS {

	/*
		1. Implement your solution using recursion without memoization

	
	*/
	int solve_rec(int arr[], int n) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}

		int maxlen = INT_MIN;

		if (arr[n - 2] < arr[n - 1]) {
			maxlen = max(1, 1 + solve_rec(arr, n - 1));
		}
		else
		{
			maxlen = 1; 
		}

		// This is the case when you are ignoring the current element
		maxlen = max(maxlen, max(1, solve_rec(arr, n - 1)));

		return maxlen;
	}

		int solve_memo(int arr[], int n, Memo &memo) {
		if (n == 0) {
			return memo[n] = 0;
		}
		else  if (n == 1) {
			return memo[n] = 1;
		}
		else {
			if (memo[n] != INT_MIN) {
				cout << "hiting the memo!!!" << endl;
				return memo[n];
			}

			if (arr[n - 2] < arr[n - 1]) {
				memo[n] = max(1, 1 + solve_memo(arr, n - 1, memo));
			}
			else
			{
				memo[n] = 1;
			}

			// this is for ignoring the current and movng from next
			memo[n] = max(memo[n], solve_memo(arr, n - 1, memo));

		}
		return memo[n];
	}

};






// driver code  
int main() {
	int arr[] = { 10,9,3,5,4,11,7,8 };
	int n = 8;

	//int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	LIS lis;
	cout << lis.solve_rec(arr, n) << endl;
	Memo memo(n + 1, INT_MIN);
	cout << "Memo = " << lis.solve_memo(arr, n, memo) << endl;


	return 0;
}



#endif // !FORREF


