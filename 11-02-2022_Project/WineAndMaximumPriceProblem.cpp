/*
	Wine and Maximum Price Problem
	Problem statement:
	Imagine you have a collection of N wines placed next to each other on a shelf.
	For simplicity, let us number the wines from left to right as they are standing on the shelf with integers from 1 to N, respectively.
	The price of the ith wine is pi(price of different wines can be different). Because the wines get better every year, supposing today is the year 1, on
	the year 'y' , the price of the ith wine will be y*pi , i.e, y times of the current year value.
	
	Next, you want to sell all the wines you have, but you want to sell exactly one wine per year, starting this year. One more constraint is that each year you are
	allowed to sell only either the leftmost or the rightmost wine on the shelf 
	and you are not allowed to reorder the wines on the self(i.e., they must stay in the same order as they were in the beginning). 

	You want to find the maximum profit you can get if you sell the wines in optimal order. 

	Let's try to see with example
	Now let’s take a look at why this is not a Greedy problem. If we were assuming this to be a greedy problem, we could sell the cheaper wine 
	from the two (leftmost and rightmost) available wines every year.

	Let the prices of 5 wines be: 2, 3, 5, 1, 4.

	At year = 1: {2,3,5,1,4} sell p1 = 2 to get cost = 2
	At year = 2: {3,5,1,4} sell p2 = 3 to get cost = 2 + 2*3 = 8
	At year = 3: {5,1,4} sell p5 = 4 to get cost = 8 + 4*3 = 20
	At year = 4: {5,1} sell p4 = 1 to get cost = 20 + 1*4 = 24
	At year = 5: {5} sell p3 = 5 to get cost = 24 + 5*5 = 49
	The Greedy approach gives an optimal answer of 49, but if we sell in the order of p1, p5, p4, p2, p3 for a total profit 2 * 1 + 4 * 2 + 1 * 3 + 3 * 4 + 5 * 5 = 50, it would mean that the Greedy approach fails.

	Lets focus on 03 different approaches of your problem
	01 - Bruteforce recursive solution
	02 - Recursive DP solution
	03 - Iterative DP Solution

*/

#define FORREF
//#define APP01
//#define APP02

#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>

// 03 dimension to handle this problem
/* start position, end position, Year, */ 
typedef vector<vector<vector<int>>> Memo;

struct WinePrice {
	
	/*
		price - list of price of wines,
		start - start index for your wine price list
		end - end index for your wine price list

		Time : 2^n // where n = end-start+1
		Space : O(m) // where m is the depth of recursion stack
	*/
	int maxPrice_brut(vector<int> price, int start, int end, int year) {
		
		// base condition
		if (start > end) {
			return 0;
		}

		// suppose you picked from left
		int incStart = year * price[start] + maxPrice_brut(price, start+1, end, year+1);
		int incEnd = year * price[end] + maxPrice_brut(price, start, end-1, year+1);

		return max(incStart, incEnd);
	}

/*
	price - list of price of wines,
	start - start index for your wine price list
	end - end index for your wine price list
	Time :  O(n^3) // Exponential to degree of 3
	Space : O(n^3) // in additional space also ( Some recursive stack space + memo table space )
*/
	int maxPrice_memo(vector<int> price, int start, int end, int year, Memo &memo) {
		// base condition
		if (start > end) {
			return 0;
		}

		// check does the earlier the same calculation done ?
		if (memo[start][end][year] != 0) {
			// for verification of hitiing or not?
			cout << "You hit the rocket!!!" << endl;
			return memo[start][end][year];
		}

		// suppose you picked from left
		int incStart = year * price[start] + maxPrice_memo(price, start + 1, end, year + 1, memo);
		int incEnd = year * price[end] + maxPrice_memo(price, start, end - 1, year + 1, memo);
		memo[start][end][year] = max(incStart, incEnd);
		return memo[start][end][year];
	}

/*
	How to handle the tabulization dp for wine profit maximization problem??
	TBD - Help???
*/
	int maxPrice_tabu(vector<int> price, int start, int end, int year) {
		Memo memo(price.size(), vector<vector<int>>(price.size(), vector<int>(price.size(), INT_MIN)));
		
		for (int i = 0; i <= start; ++i) {
			for (int j = 0; j < i; ++j) {
				for (int y = 1; y <= price.size(); ++y) {
					//memo[i][j][y] = y*max(memo[i][j][y], 0); - This is the exact calculation
					memo[i][j][y] = 0; // but below code have also same impact but better optimization
				}
			}
		}


		// suppose you picked from left
		int incStart = year * price[start] + maxPrice_tabu(price, start + 1, end, year + 1);
		int incEnd = year * price[end] + maxPrice_tabu(price, start, end - 1, year + 1);
		memo[start][end] = max(incStart, incEnd);
		return memo[start][end][year];
	}
};

int main() {
	//int price[] = { 2,3,5,1,4 };
	
	vector<int> price = { 2,3,5,1,4 };
	int start = 0; // it's 0 because this is the year fromwhich you start selling
	int end = price.size() - 1;
	int year = 1;
	
	WinePrice wp;

#ifndef APP01
	cout << wp.maxPrice_brut(price, start, end, year) << endl;
	// completed
#endif // APP01

#ifndef APP02
	Memo memo(price.size(), vector<vector<int>>(price.size(), vector<int>(1+price.size(), 0)));

	cout << wp.maxPrice_memo(price, start, end, year, memo);
#endif // APP02

	return 0;
}
#endif // !FORREF





