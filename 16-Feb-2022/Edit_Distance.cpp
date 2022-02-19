/*
	Edit Distance Problem

*/

//#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>

typedef vector<vector<int>> Memo;


struct EditDist {
    int solve(string str1, string str2, int m, int n) {
        if (m == 0 && n == 0) {
            return 0;
        }
        else if (m == 0) {
            return n;
        }
        else if (n == 0) {
            return m;
        }
        else {
            int minop = INT_MAX;

            if (str1[m - 1] == str2[n - 1]) {
                // this is the case when you will find the same last character
                minop = min(minop, solve(str1, str2, m - 1, n - 1));
            }
            else
            {
                minop = 1 + min(solve(str1, str2, m - 1, n), min(solve(str1, str2, m, n - 1), solve(str1, str2, m - 1, n - 1)));
            }
            return minop;
        }
    }

    int solve_memo(string str1, string str2, int m, int n, Memo &memo) {
        if (m == 0 && n == 0) {
            return 0;
        }
        else if (m == 0) {
            return n;
        }
        else if (n == 0) {
            return m;
        }
        else {

            if (memo[m][n] != INT_MAX) {
                cout << "Yes got the memo hit...." << endl;
                return memo[m][n];
            }

            if (str1[m - 1] == str2[n - 1]) {
                // this is the case when you will find the same last character
                memo[m][n] = min(memo[m][n], solve_memo(str1, str2, m - 1, n - 1, memo));
            }
            else
            {
                memo[m][n] = 1 + min(solve_memo(str1, str2, m - 1, n, memo), min(solve_memo(str1, str2, m, n - 1, memo), solve_memo(str1, str2, m - 1, n - 1, memo)));
            }

           return memo[m][n];
        }
    }


};

int main() {
    string s1 = "sunday";
    string s2 = "saturday";
    EditDist ed;
    cout << ed.solve(s1, s2, s1.length(), s2.length()) << endl;

    Memo memo(s1.length() + 1, vector<int>(s2.length() + 1,INT_MAX));
    cout << "Memo = " << ed.solve_memo(s1, s2, s1.length(), s2.length(), memo) << endl;

//    cout << editDist(s1, s2) << endl;

    return 0;
}


#endif // !FORREF

