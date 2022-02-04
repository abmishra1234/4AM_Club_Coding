/*
	Is this given String a Palindrome?

	Problem Statement
	Before we dive into the problem at hand, let’s find out what a palindrome is. 
	A palindrome is a string which reads the same backward and forwards such 
	as mom or dad, or even madam. In this problem, we will 
	have to determine whether the given string is a palindrome or not!

	Lets solve this problem from different approaches.

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<string>

struct Palindrome {
	// Iterative Approach
	bool isPalindrom_iter(string word, int left, int right) {
		while (left < right) {
			if (word[left] != word[right]) {
				return false;
			}
			++left;
			--right;
		}

		return true;
	}

	// Recursive Approach
	bool isPalindrom(string word, int left, int right) {
		bool res = false;

		if (left >= right) {
			return true;
		}
		else
		{
			if (word[left] != word[right]) {
				return false;
			}
			return isPalindrom(word, left + 1, right - 1);
		}
	}
};

int main() {

	string text[3] = { "madam","no","dad" };
	Palindrome pa;

	for (int i = 0; i < 3; i++) {
		int answer = pa.isPalindrom(text[i], 0, text[i].length() - 1);
		if (answer)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}


#endif // FORREF


