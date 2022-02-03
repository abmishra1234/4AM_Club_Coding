/*
	Reverse String using recursion
	input string : "abinash mishra"
	output string : "arhsim hsaniba"
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct Reverse {
	void doReverse(string& inpStr, int left, int right) {
		// this is your base or exit condition
		if (left >= right) {
			return;
		}
		else
		{
			swap(inpStr[left], inpStr[right]);
			doReverse(inpStr, left + 1, right - 1);
		}
	}
};

int main() {

	string sentence = "abinash mishra";
	string word = "Hello";
	int index = 0;

	cout << "Reversing the sentence: " << sentence << endl;
	Reverse rev;
	rev.doReverse(sentence, 0, sentence.length()-1);
	cout << sentence << endl;

	cout << "Reversing the word: " << word << endl;
	rev.doReverse(word, 0, word.length() - 1);
	cout << word << endl;
}

#endif // FORREF

