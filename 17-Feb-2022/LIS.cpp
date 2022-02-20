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
			maxlen = max(maxlen, solve_rec(arr, n - 1));
		}
		return maxlen;
	}
};






// driver code  
int main() {
	int arr[] = { 10,9,3,5,4,11,7,8 };
	int n = 8;

	LIS lis;
	cout << lis.solve_rec(arr, n) << endl;
	


	return 0;
}



#endif // !FORREF


