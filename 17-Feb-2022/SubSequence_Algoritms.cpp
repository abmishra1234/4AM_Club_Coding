/*
	The below two problem have some relationship, so solve them in pair
Subsequence
	- LCS : Largest Common Subsequence
	- SCS : Shortest Common Subsequence

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>

struct SubSequence {

    int lcs

};







int main() {
    char s1[] = { 'A','B','C','D','G','H' }, s2[] = { 'A','E','D','F','H','R' };
    int m = 6, n = 6;
    int LCS[7][7] = { 0 };
    cout << lcs(s1, s2, m, n, LCS);
    return 0;
}

#endif // !FORREF


