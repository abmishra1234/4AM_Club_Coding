/*
	Longest Common Subsequence
    Problem statement
        Given two sequences, find the length of the longest subsequence present in both of them.
        A subsequence is a sequence that appears in the same relative order but is not necessarily contiguous. 
        For example, abc, abg, bdf, aeg, acefg…etc., are subsequences of abcdefg. 
        So a string of length n has {2^{n}} different possible subsequences.
    
        Let us consider an example to understand this problem better.
        1. LCS for input Sequences ABCDGH and AEDFHR is ADH of length 3.
        2. LCS for input Sequences AGGTAB and GXTXAYB is GTAB of length 4.


*/

//#define FORREF
//#define APP01
#define APP02
#define APP03

#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<stack>


typedef stack<char> Sequence;
typedef vector<vector<int>> Memo;

struct LongestSubsequenceSeries {

    /*
        There are two problem here
        1. Find the longest common subsequence - Completed
        2. Find the longest common subsequence string - TBD
    */
    int lcs_rec(char s1[], char s2[], int s1Len, int s2Len) {
        if (s1Len == 0 || s2Len == 0) {
            return 0;
        }
        
        int lcs1 = 0, lcs2 = 0, lcs3 = 0;

        if (s1[s1Len-1] == s2[s2Len-1]) {
            lcs1 = 1 + lcs_rec(s1, s2, s1Len-1, s2Len-1);
        }
        else {
            lcs2 = lcs_rec(s1, s2, s1Len - 1, s2Len);
            lcs3 = lcs_rec(s1, s2, s1Len, s2Len-1);
        }
        
        return max(lcs1, max(lcs2, lcs3));
    }



};

// Driver code
int main() {
    // AGGTAB , GXTXAYB 
    //char s1[] = { 'A','G','G','T','A','B' }, s2[] = { 'G','X','T','X','A','Y', 'B'};
    char s1[] = { 'A','B','C','D','G','H' }, s2[] = { 'A','E','D','F','H','R' };
    int m = 6, n = 6;
   int LCS[7][7] = { 0 };

   // calling code below
    LongestSubsequenceSeries lss;
    Sequence seq;

#ifndef APP01
    cout << lss.lcs_rec(s1, s2, m, n);
    cout << endl;

#endif // APP01



    return 0;
}





#endif // FORREF

