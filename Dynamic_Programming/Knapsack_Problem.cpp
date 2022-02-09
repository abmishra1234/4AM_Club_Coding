/*
	0/1 Knapsack
	Introduction
	Given the weights and profits of ‘N’ items, we are asked 
	to put these items in a knapsack that has a capacity ‘C’. 
	The goal is to get the maximum profit from the items in the knapsack.

	So, there are constraint of, Each item can only be selected once, 
	as we don’t have multiple quantities of any item.

	Let’s take Merry’s example, who wants to carry some fruits in the 
	knapsack to get maximum profit.Here are the weights and 
	profits of the fruits:

	Items: { Apple, Orange, Banana, Melon }
	Weights: { 2, 3, 1, 4 }
	Profits: { 4, 5, 3, 7 }
	Knapsack capacity(W): 5

	So, according to the constraint given, let's discuss, how to proceed?
	
	case 01 - Apple & Orange = 4+5 = 09 ( profit)
	case 02 - Banana & Melon = 3+7 = 10 ( profit )
	case 03 - Orange & banana = 5+3 = 08 (profit )
	case 04 - Apple & banana = 4+3 = 07 (profit )

	So with this exercise , we found that case 02 is givint the optimal profit

*/

//#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

struct Knapsack {
	typedef vector<vector<int>> Memo;

	/*
		Approach 01 :  Brute Force Approach
		Time Complexity : O(2^n) // where n is the number of item to be picked
		Space complexity : O(1) // const space

		Can we do better?
	*/
	int Knapsack_rec(const vector<int>& profits, const vector<int>& weights, 
		const int capacity, size_t ind, int accuWeight) {
		if (ind >= profits.size()) {
			return 0;
		}
		else
		{
			int profit1 = 0, profit2 = 0;
			if (accuWeight + weights[ind] <= capacity) {
				profit1 = profits[ind] + Knapsack_rec(profits, weights, capacity,
					ind + 1, accuWeight + weights[ind]);
			}

			profit2 = Knapsack_rec(profits, weights, capacity, ind + 1, accuWeight);
			return max(profit1, profit2);
		}
	}

	/*
		Top-down Dynamic Programming with Memoization
		What is the time and space complexity of the below solution?

		Since our memoization array dp[profits.length][capacity+1] 
		stores the results for all the subproblems, we can conclude 
		that we will not have more than N*C subproblems 
		(where ‘N’ is the number of items and ‘C’ is the knapsack capacity).

		That means our time complexity is not more than O(N*C)

		And same goes for the space also , it's order is not more than O(N*C)
	*/
	int Knapsack_Memo(const vector<int>& profits, const vector<int>& weights,
		const int capacity, size_t ind, int accuWeight, vector<vector<int>>&memo) {
		if (ind >= profits.size()) {
			return 0;
		}

		if (memo[ind][capacity - accuWeight] != -1) {
			return memo[ind][capacity - accuWeight];
		}

		int profit1 = 0, profit2 = 0;
		if (accuWeight + weights[ind] <= capacity) {
			profit1 = profits[ind] + Knapsack_Memo(profits, weights, capacity,
				ind + 1, accuWeight + weights[ind], memo);
		}

		profit2 = Knapsack_Memo(profits, weights, capacity, ind + 1, accuWeight, memo);
		memo[ind][capacity - accuWeight] = max(profit1, profit2);
		return memo[ind][capacity - accuWeight];
	}

	/*
		Bottom-up Dynamic Programming or Tabulizaton Approach
		
		Let’s try to populate our dp[][] array working in a bottom-up fashion.

		Essentially we want to find the maximum profit, for every sub array and for every possible capacity.

		This means, dp[i][c] will represent the maximum knapsack profit for capacity c, calculated from the 
		first i items. 

		Now, let's focus , what are the possibilities for the i'th item and "c" capacity.
		so, in general there are two possibilities here, one is to pick the element and another is to discard the element
		(so, yes only two case with item). And so the maximum out of these two steps will be included into the solution step.

		So, dp[i][c] = max of { profit[i] + dp[i-1][c-wi], dp[i-1][c] } // first is to add the ith item and 2nd is for ignore 
		So, you reach at your dp relationship and now you need to populate your dp table using this formula.
			
	*/

	int Knapsack_Tabu(const vector<int>& profits, const vector<int>& weights,
		const size_t capacity) {
		int size = profits.size();
		Memo memo(size, vector<int>(capacity + 1, -1));

		for (int i = 0; i < size; ++i) {
			memo[i][0] = 0;
		}

		for (int i = 0; i < size; ++i) {
			memo[i][1] = 1;
		}

		for (int i = 1; i <= capacity; ++i) {
			memo[0][i] = profits[0];
		}

		for (int i = 1; i < size; ++i) {
			for (int j = 1; j <= capacity; ++j) {
				int profit1 = memo[i - 1][j];
				int profit2 = (weights[i] <= j) ? (profits[i] + memo[i - 1][j - weights[i]]) : 0;
				memo[i][j] = max(profit1, profit2);
			}
		}

		return memo[size - 1][capacity];
	}

	int solveKnapsack(const vector<int>& profits, const vector<int>& weights, int capacity) {
		// This below line code is for dynamic two dimensional array
		Memo memo(profits.size(), vector<int>(capacity + 1, -1));
		//return Knapsack_Memo(profits, weights, capacity,0, 0, memo);
		return Knapsack_Tabu(profits, weights, capacity);
	}
};

int main(int argc, char* argv[]) {
	Knapsack ks;
	vector<int> profits = { 1, 6, 10, 16 };
	vector<int> weights = { 1, 2, 3, 5 };
	int maxProfit = ks.solveKnapsack(profits, weights, 7);
	cout << "Total knapsack profit ---> " << maxProfit << endl;
	maxProfit = ks.solveKnapsack(profits, weights, 6);
	cout << "Total knapsack profit ---> " << maxProfit << endl;
}

#endif // FORREF