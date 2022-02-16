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

struct LongestPalindromSubSeq
{

    int subSeq(char seq[], int left, int right) {
        if (left > right) {
            return 0;
        }
        else if (left == right) {
            return 1;
        }
        else {
            int maxlen = 0;
            if (seq[left] == seq[right]) {
                maxlen = max(maxlen, 2 + subSeq(seq, left + 1, right - 1));
            }
            else
            {
                maxlen = max(subSeq(seq, left + 1, right), subSeq(seq, left, right - 1));
            }
        
            return maxlen;
        }
    }

};




int main()
{
    char seq[] = { 'B','B','A','B','C','B','C','A','B' };
    int n = 9;
    LongestPalindromSubSeq lps;

    cout << "Length of maximum palindrome Subsequence is " << lps.subSeq(seq, 0, n - 1);
    return 0;
}


#endif // FORREF


