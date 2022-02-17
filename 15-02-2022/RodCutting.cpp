/*
	Rod Cutting Problem
	Problem statement#
	You are given a rod of size n > 1, it can be cut into any number of pieces k. 
	The price for each piece of size i is represented as price(i) 
	and the maximum revenue from a rod of size i is r(i) 
	(could be split into multiple pieces). 
	
	Find r(n){total maximum revenue} for the rod of size n.

	- Memoization : completed 
	- Tabulization :  : Completed
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include <iostream>
#include<vector>
#include<string>

typedef vector<int> Memo;


struct CuttingRod {

	// price is the price list of cut, and n is the total length of rod
	int cutRod(int price[], int n, Memo &memo) {
		if (memo[n] != -1) {
			cout << "hit the bull!!" << endl;
			return memo[n];
		}
		
		if (n <= 0) {
			return 0;
		}
		else
		{
			for (int i = 1; i <= n; ++i)
				memo[n] = max(memo[n], price[i] + cutRod(price, n-i, memo));
		}
		return memo[n];
	}

	// implement the code with tabulization of dp
	int cutRoad_dp(int price[], int n) {
		Memo dp(n + 1, -1);
		
		// rod length is 0 means no rod
		dp[0] = price[0];
		//rod length from l=1 to l=n
		for (int i = 1; i <= n; ++i) {
			int best_price = INT_MIN;
			// cut possible on road
			for (int j = 1; j <= i; ++j) {
				best_price = max(best_price, price[j] + dp[i - j]);
			}
			dp[i] = best_price;
		}

		return dp[n];
	}

};

int main() {
	int n = 6; // length of rod is given as 6
	
	/*
		cut    : 0, 1, 2, 3, 4, 5, 6
		profit : 0, 2, 5, 8, 9, 10, 11
	*/
	int price[] = { 0, 2,5,8,9,10,11 };
	CuttingRod cr;
	Memo memo(n + 1, -1);
	int answer = cr.cutRod(price, n, memo);
	cout << "Your maximum revanue from length n = " << n << " , after cutting is : " << answer << endl;

	answer = cr.cutRoad_dp(price, n);
	cout << "dp with Tab ---> Your maximum revanue from length n = " << n << " , after cutting is : " << answer << endl;

}









#endif // FORREF

