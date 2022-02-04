/*
	Removing Spaces in a String
	What do we mean by spaces?

	spaces meaning white spaces. 
	
	There are two possib;itites here
	1. spaces may be single or contiguous multiple
	2. spaces may be one or multiple places

	Logic Building:
	Ex: input : "  Home is  mine!"
	   output : "Homeismine!"

	   1. do ...while loop may work better
	   2. make one whaite space counter and than adjust the character as the shift is required.

	   Let's illustrate the example now 
	   
	   input : "  Home is  mine!"
	   int wsCnt = 0;
	   Loop:
	   
	   check the character
	   Case 01 : character is white space -> wsCnt++
	   Case 02 : character is not a white space -> shift the character as per wsCnt > 0 than only
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct WhiteSpace {

	// The below code is for iterative approach
	void remove_iter(string& text, int ind, int textLen) {
		int wsCnt = 0;
		do {
			if (text[ind] == ' ') {
				wsCnt++;
			}
			else {
				swap(text[ind - wsCnt], text[ind]);
			}
		} while (ind++ < textLen);
		//text = text.substr(0, text.length() - wsCnt);
	}

	// Below code is using recursion
	void remove(string& text, int ind, int wsCnt, int textLen) {
		// 1. Identify the base or terminating condition
		if (ind >= textLen) {
			// this is your terminating condition
			text[ind] = '\0';
			return;
		}

		// you found the white space
		if (text[ind] == ' ') {
			// increase the wsCnt by 1 & advance ind by 1
			remove(text, ind + 1, wsCnt + 1, textLen);
		}
		else {
			swap(text[ind - wsCnt], text[ind]);
			remove(text, ind + 1, wsCnt, textLen);
		}
	}
};

int main()
{
	string text = "  Home is  mine!";
	cout << text << endl;
	WhiteSpace ws;
	ws.remove(text, 0, 0, text.length());
	//removeSpaces(text, 0, text.length());
	cout << text << endl;
}
#endif //FORREF 
