/*
	Status : Completed
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

// This is for handling the Memoization table
typedef vector<vector<int>> Memo;

struct Knapsack {
	/*
		This is the simplest way to do the knapsack problem
		Recursion without memoization
	*/
	int solve(int wt[], int val[], int W, int ind/* start from last index*/) {

		if (W <= 0) {
			return 0;
		}

		if (ind < 0) {
			return 0;
		}

		int maxv = INT_MIN, u = INT_MIN, v = INT_MIN;
		if (wt[ind] <= W) {
			u = val[ind] + solve(wt, val, W-wt[ind], ind - 1);
		}
		v = solve(wt, val, W, ind - 1);
		maxv = max(u, v);
		return maxv;
	}

	/*
	This is the simplest way to do the knapsack problem
	Recursion with memoization
*/
	int solve_memo(int wt[], int val[], int W, int ind/* start from last index*/, Memo &memo) {
		if (W <= 0) {
			return 0;
		}

		if (ind < 0) {
			return 0;
		}

		if (memo[W][ind] != -1) {
			cout << "hit the memo, wow!!!" << endl;
			return memo[W][ind];
		}

		int u = INT_MIN, v = INT_MIN;
		if (wt[ind] <= W) {
			memo[W][ind] = max(memo[W][ind], val[ind] + solve_memo(wt, val, W - wt[ind], ind - 1, memo));
		}
		memo[W][ind] = max(memo[W][ind], solve_memo(wt, val, W, ind - 1, memo));

		return memo[W][ind];
	}

	/*
		DP based on tabulation
	*/
	int solve_dp(int wt[], int val[], int W/* knapsack capacity */, int nItems) {
		Memo dp(nItems+1, vector<int>(W+1, 0));
		
		for (int i = 0; i <= nItems; ++i) {
			for (int j = 0; j <= W; ++j) {
				// this is the case when there is no item to pick or no capacity left inot knapsack?
				if (i == 0 || j == 0) {
					dp[i][j] = 0;
				}
				else if (wt[i-1] <= j) {
					dp[i][j] = max(val[i-1] + dp[i - 1][j-wt[i-1]], dp[i - 1][j]);
				}
				else if(wt[i] > j)
					dp[i][j] = dp[i - 1][j];
			}
		}

		return dp[nItems][W];
	}
};

int main()
{
	int val[] = { 60, 100, 120, 456 };
	int wt[] = { 10, 20, 30, 50 };
	int W = 80;
	int n = sizeof(val) / sizeof(val[0]);
	Knapsack kp;
	cout << kp.solve(wt, val, W, n-1) << endl;
	// next is how to implement memo in knapsack
	Memo memo(W + 1, vector<int>(n, -1));
	cout << "Memo : " << kp.solve_memo(wt, val, W, n - 1, memo) << endl;
	cout << "Tabulation : " << kp.solve_dp(wt, val, W, n);
	return 0;
}


#endif // FORREF