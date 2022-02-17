/*
    Problem statement#
    Given a sequence of characters, find the length of the longest palindromic subsequence in it.

    For example, if the given sequence is BBABCBCAB, the output should be 7 as BABCBAB is the longest palindromic subsequence in it. 
    A sequence is a palindromic sequence if that sequence reads the same backward as forwards, e.g. madam.

    Note: For the given sequence BBABCBCAB, subsequence BBBBB and BBCBB are also palindromic subsequences, but these are not the longest.

*/

//#define FORREF

#ifndef FORREF
using namespace std;
#include<iostream>
#include<string>
#include<vector>


typedef vector<vector<int>> Memo;

struct LongestPalindromSubSeq
{
    /*
        The below code is simple recursive solution
        Now my job is to make the noramal recursive solution to Memoization based solution
    */
    int subSeq(char seq[], int left, int right, Memo &memo) {
        if (memo[left][right] != -1) {
            cout << "Yes, recursion call duplicate found!!!" << endl;
            return memo[left][right];
       }
        else
        {
            // this is when you have odd number character palindrom
            if (left == right) {
                memo[left][right] = 1;
            }
            // this is when you have even number character palindrom
            else if (seq[left] == seq[right] && (left == right - 1)) {
                memo[left][right] = 2;
            }
            else if (seq[left] == seq[right]) {
                memo[left][right] = 2 + subSeq(seq, left + 1, right - 1, memo);
            }
            else
            {
                memo[left][right] = max(subSeq(seq, left + 1, right, memo), subSeq(seq, left, right - 1, memo));
            }
        }
        return memo[left][right];
    }
};

int main()
{
    char seq[] = { 'B','B','A','B','C','B','C','A','B' };
    int n = 9;
    LongestPalindromSubSeq lps;

    // It's kind of global for main function scope to all the called method inside this main method
    Memo memo(n, vector<int>(n, -1)); 
    cout << "Length of maximum palindrome Subsequence is " << lps.subSeq(seq, 0, n - 1, memo);
    
    return 0;
}


#endif // FORREF


