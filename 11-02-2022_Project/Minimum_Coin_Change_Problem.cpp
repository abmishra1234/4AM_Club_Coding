/*
	For any further interaction, you can reach to me on my below information
	Email - abmishra1234@gmail.com
*/

#define APP01 // for brute
//#define APP02 // for memo
//#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

typedef vector<int> Memo;

struct CoinChange {
	/*
		Bruteforce Approach
		coins -> is holding the list of coins (only input)
		sum -> is for target sum to produce by using the coin change	
	*/
	int minCoins_brut(vector<int> coins, int sum) {
		// you already reached to a target sum
		if (sum == 0) {
			return 0;
		}
		int min_coin_count = INT_MAX;
		for (size_t i = 0; i < coins.size(); ++i) {
			if (coins[i] <= sum) {
				min_coin_count = min(min_coin_count, 1 + minCoins_brut(coins, sum- coins[i]));
			}
		}
		
		return min_coin_count;
	}

	/*
		Now the time is to think some better way to implement this problem.
		Can we observe any duplicated recursion(overlapping sub structure?) call in this problem?
		Observation
		Let’s understand the overlapping sub structure using example,
		Input: coins[] = {9, 6, 5, 1}, N = 13
		Fn(13) =  several possibilities
		Picked 9 + Fn(4)
		Picked 6 , picked 1 thrice + Fn(4)
		Picked 5, picked 1 , 4 times + Fn(4)

		So, you will see that many times we end-up at Fn(4)  and this is the same we are trying to observe
		that does here overlapping sub structure exist or not? And Yes, it exist so it the candidate of memorization.
	*/
	int minCoins_Memo(vector<int> coins, int sum, Memo &memo) {
		if (memo[sum] != -1) {
			cout << "overlapping sub structure found!!!" << endl;
			return memo[sum];
		}

		if (sum == 0) {
			return 0;
		}

		int min_coin_count = INT_MAX;
		
		for (size_t i = 0; i < coins.size(); ++i) {
			if (coins[i] <= sum) {
				memo[sum] = min_coin_count = min(min_coin_count, 1 + minCoins_Memo(coins, sum - coins[i], memo));
			}
		}

		return min_coin_count;
	}
};

// Driver code
int main() {
	vector<int> coins = { 1,2,3,4,5 };
	int sum = 24;
	CoinChange cc;
#ifndef APP01
	cout << cc.minCoins_brut(coins, sum);
#endif // APP01
	//  basically you are puting negative value to indicate that this pertical value recursive call is already calculated?
#ifndef APP02
	Memo memo(sum + 1, -1); 
	cout << cc.minCoins_Memo(coins, sum, memo);
#endif // APP02
}

#endif // FORREF


