/*
	Status : TBD

*/

//#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct Knapsack {
	
	int solve(int W, int n, int wt[], int val[], int cum_wt, int cum_item, int ind) {
		if (cum_wt > W) {
			return 0;
		}

		if (cum_item > n) {
			return 0;
		}

		if (ind >= n) {
			return 0;
		}

		int maxv = INT_MIN, v = INT_MIN, w = INT_MIN;
		if (wt[ind] <= W - cum_wt) {
			v = val[ind] + solve(W, n, wt, val, cum_wt + wt[ind], cum_item + 1, ind + 1);
		}
		
		w = solve(W, n, wt, val, cum_wt, cum_item, ind + 1);

		maxv = max(v, w);
		return maxv;
	}






};

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	Knapsack kp;
	cout << kp.solve(W, n,wt, val, 0,0,0);
	return 0;
}


#endif // FORREF