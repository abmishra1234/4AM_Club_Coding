/*
	Removing Duplicates in a String
	What does removing duplicates mean?

	Duplicate descibed like, Given a string that has repeating adjacent characters, 
	we only want to keep one of each character. To do this, we aim to 
	eliminate the repeating characters. 
	
	The illustration below shows this process.
	EXample:
	input  : "Hello Woorldd"
	output : "Helo World"

	One key observation, you will make quickly here that duplication 
	with repeating character we are talking here...

	So, this simplifies our problem complexity. Now, we are sure in problem that you
	need only one variable for handling the duplicate.

	(1) Another valid assumption here that length of string is always more than 1, otherwise
	there are no case of duplicacy.
	
	(2) How to remove duplicacy? 

	int lsftCnt = 0;
	char prev = text[0];
	int ind = 1;

	Loop: ind < textLen
	if(text[ind] == prev) // duplicate condition 
	{
		++lsftCnt;
		++ind;
	}
	else {
		// non duplicate case
		if(lsftCnt > 0) {
			text[ind-lsftCnt] = text[ind];
		}
		++ind;
	}
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct Duplicate {
	// Iterative
	void remove_iter(string& text, int ind, int lsftCnt, int textLen) {
		// Hello Woorldd
		char prev = text[0];

		while (ind < textLen) { // true
			if (text[ind] == prev) // duplicate condition 
			{
				++lsftCnt;
			}
			else {
				// non duplicate case
				prev = text[ind];
				if (lsftCnt > 0) {
					text[ind - lsftCnt] = prev;
				}
			}
			++ind;
		}
		// just truncate the extra duplicate character removed here
		text = text.substr(0, textLen - lsftCnt);
	}

	// Recursion
	void remove(string& text, int ind, int lsftCnt, int textLen, char prev) {
		// 1. Identify the base or terminating condition
		if (ind >= textLen) {
			// this is your terminating condition
			text = text.substr(0, textLen - lsftCnt);
			return;
		}
		else {
			if (text[ind] == prev) {
				remove(text, ind + 1, lsftCnt + 1, textLen, prev); // 1
			}
			else {
				if (lsftCnt > 0) {
					text[ind - lsftCnt] = text[ind];
				}
				remove(text, ind + 1, lsftCnt, textLen, text[ind]); // 2
			}
		}
	}
};

int main()
{
	string text = "Hello Woorldd";
	cout << text << endl;
	Duplicate ds;
	ds.remove(text, 1, 0, text.length(), text[0]);
	//removeSpaces(text, 0, text.length());
	cout << text << endl;
}
#endif //FORREF 
