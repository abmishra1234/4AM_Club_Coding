/*
	For any further interaction, you can reach to me on my below information
	Email - abmishra1234@gmail.com
*/

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
	int minCoins(vector<int> coins, int sum) {
		// you already reached to a target sum
		if (sum == 0) {
			return 0;
		}
		int min_coin_count = INT_MAX;
		for (int i = 0; i < coins.size(); ++i) {
			if (coins[i] <= sum) {
				min_coin_count = min(min_coin_count, 1 + minCoins(coins, sum- coins[i]));
			}
		}
		
		return min_coin_count;
	}
};

int main() {
	vector<int> coins = { 1,2,3,4,5 };
	int sum = 24;
	CoinChange cc;
	cout << cc.minCoins(coins, sum);
}

#endif // FORREF


