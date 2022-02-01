/*
	Phone Keypad Problem
	Solve a problem based on Recursion and Backtracking.
	Problem statement
	refer the Recursion_Backtracking.pptx for this problem
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include <iostream>

struct KeypadString {
	char str[10][10] = { "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

	void Print(char in[], int in_ind, char out[], int out_ind) {
		// let's identify first the base or terminating condition for your recursion
		if (in[in_ind] == 0) {
			out[out_ind] = '\0';
			cout << out << endl;
			return;
		}

		int k = in[in_ind] - '0'; // extracted the digit
		if (k == 0 || k == 1) {
			Print(in, in_ind + 1, out, out_ind);
		}
		for (int i = 0; str[k][i] != 0; ++i) {
			out[out_ind] = str[k][i];
			Print(in, in_ind + 1, out, out_ind + 1);
		}
	}

};

int main() {
	char in[100] = { '2','3','4' };
	char out[100];
	KeypadString ks;
	ks.Print(in, 0, out, 0);
}
#endif // FORREF 

