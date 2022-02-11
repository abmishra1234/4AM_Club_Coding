/*
	My Contact :  abmishra1234@gmail.com
*/

#define APP01
#define APP02
#define FORREF
#ifndef FORREF

using namespace std;
#include<iostream>
#include<vector>

typedef vector<int> Memo;

struct Count {

	int minStep_brute(int n) {
		if (n == 1) {
			// this is your base condition
			return 0;
		}

		int step_one_cnt = INT_MAX, step_two_cnt = INT_MAX, step_three_cnt = INT_MAX;
	
		step_one_cnt = 1 + minStep_brute(n - 1);
		
		if (n % 2 == 0) {
			step_two_cnt = 1 + minStep_brute(n / 2);
		}

		if (n % 3 == 0) {
			step_three_cnt = 1 + minStep_brute(n / 3);
		}
		
		return min(step_one_cnt, min(step_two_cnt, step_three_cnt));
	}

	// Solution using Memoization
	int minStep_Memo(int n, Memo& memo) {
		if (n == 1) {
			return 0;
		}

		// you already calculated this value earlier, so no need to calculate again
		if (memo[n] != -1) {
//			cout << "Memoization hit here!!!" << endl;
			return memo[n];
		}

		int step_one_cnt = INT_MAX, step_two_cnt = INT_MAX, step_three_cnt = INT_MAX;

		step_one_cnt = 1 + minStep_Memo(n - 1, memo);

		if (n % 2 == 0) {
			step_two_cnt = 1 + minStep_Memo(n / 2, memo);
		}

		if (n % 3 == 0) {
			step_three_cnt = 1 + minStep_Memo(n / 3, memo);
		}

		memo[n] = min(step_one_cnt, min(step_two_cnt, step_three_cnt));

		return memo[n];
	}

	// Solution using Tabulization
	int minStep_Tabu(int n, Memo& memo) {
		memo[0] = 0;
		memo[1] = 0;

		for (int i = 2; i <= n; ++i) {
			memo[i] = 1 + memo[i - 1];
			if (i % 2 == 0) {
				memo[i] = min(memo[i], 1 + memo[i / 2]);
			}
			if (i % 3 == 0) {
				memo[i] = min(memo[i], 1 + memo[i / 3]);
			}
		}
		return memo[n];
	}
};


int main() {

	int n = 42;
	Count ct;
#ifndef APP01
	cout << ct.minStep_brute(n);
#endif // APP01
	Memo memo(n + 1, -1);
#ifndef APP02
	cout << ct.minStep_Memo(n, memo);
#endif // APP02
	cout << ct.minStep_Tabu(n, memo);
}

#endif // FORR