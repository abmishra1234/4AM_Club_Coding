/*
	Longest Common Subsequence


*/

//#define FORREF
#define APP01

#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>


typedef vector<vector<int>> Memo;

struct LongestSubsequenceSeries {

    int lcs_rec(char s1[], const int &s1_len, char s2[], const int &s2_len, int s1_ind, int s2_ind, Memo &memo) {
        if (s1_ind >= s1_len || s2_ind >= s2_len) {
            return 0;
        }

        int lcs1 = 0, lcs2 = 0, lcs3 = 0;

        if (s1[s1_ind] == s2[s2_ind]) {
            memo[s1_ind][s2_ind] = 1;
            lcs1 = 1 + lcs_rec(s1, s1_len, s2, s2_len, s1_ind + 1, s2_ind + 1, memo);
        }
        else {
            lcs2 = lcs_rec(s1, s1_len, s2, s2_len, s1_ind + 1, s2_ind, memo);
            lcs3 = lcs_rec(s1, s1_len, s2, s2_len, s1_ind, s2_ind+1, memo);
        }
        
        return max(lcs1, max(lcs2, lcs3));
    }

};

// Driver code
int main() {
    char s1[] = { 'A','B','C','D','G','H' }, s2[] = { 'A','E','D','F','H','R' };
    int m = 6, n = 6;
   int LCS[7][7] = { 0 };

   // calling code below
    LongestSubsequenceSeries lss;
    Memo memo(m + 1, vector<int>(n + 1, 0));

#ifndef APP01
    cout << lss.lcs_rec(s1, m, s2, n, 0, 0, memo);
    cout << endl;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (memo[i][j]) {
                cout << s1[i] << "";
            }
        }
    }
    cout << endl;
#endif // APP01

    return 0;
}





#endif // FORREF

