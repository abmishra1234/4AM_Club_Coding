/*
	Convert Digits to Strings
	Learn to use Recursion to solve coding problems.

	Problem statement:
		Given a number n, convert each digit of that number 
		to its corresponding string. Make sure the order is correct.
		Given a number n, convert each digit of that number to 
		its corresponding string. Make sure the order is correct.
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include <iostream>
#include <string>
#include <vector>


struct Digit2String {

	string s[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	vector<int> digits;

	void Print(int n) {
		string output = "";
		Convert(n);
		int vsize = digits.size();
		for (int i = vsize - 1; i >= 0; --i) {
			output += (s[digits[i]] + ' ');
		}
		cout << output << endl;
	}

	// recursive method for getting digits
	void Convert(int n) {
		if (n > 0) {
			digits.push_back(n % 10);
			n /= 10;
			Convert(n);
		}
	}
};

int main() {
	Digit2String ds;
	ds.Print(234);
}

#endif // FORREF
