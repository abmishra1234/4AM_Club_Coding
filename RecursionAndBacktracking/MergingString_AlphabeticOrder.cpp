/*
	Problem Understanding
	Heading - Merging Strings in Alphabetic Order

	What do we mean by merging alphabetically?

	Given two strings that are already in alphabetic order, 
	we can combine them to create a string that is 
	sorted alphabetically and is a combination of the two strings given.

	Let's understand with example
	1-> input1 - "acdz"
	2-> input2 - "bdsxy"
	3-> output - "abcddsxyz"

	Let's discuss the approach.

	By observing the problem, i get immediate thought of merge step in merge sort
	If you recall what this merge step is doing for us, it seems clear that here
	our job is to iterate both string and compare the both positional character in
	alphabetic order and accordingly pick the element and put into output string.

	since there is no boundation of length of these two string so, you might have to 
	iterate the string which ever is left out from string comparison loop.

	And finally either print or return back your string.
*/

#define FORREF
#ifndef FORREF

#include <iostream>
#include <string>
#include<vector>

using namespace std;

struct Merge {
	// iterative method
	string mergeStrings_iter(string one, string two) { // alphabetical order
		string output = "";
		int oneStrInd = 0, twoStrInd = 0;

		while (oneStrInd < one.length() && twoStrInd < two.length()) {
			if (one[oneStrInd] < two[twoStrInd]) {
				output += one[oneStrInd++];
			}
			else {
				output += two[twoStrInd++];
			}
		}

		while (oneStrInd < one.length()) {
			output += one[oneStrInd++];
		}

		while (twoStrInd < two.length()) {
			output += two[twoStrInd++];
		}

		return output;
	}

	// recursive method
	string mergeStrings(string one, string two, int oneStrInd, int twoStrInd, string output) {
		// this is your recursion base condition
		if (oneStrInd >= one.length() && twoStrInd >= two.length()) {
			return output;
		}

		while (oneStrInd < one.length() && twoStrInd < two.length()) {
			if (one[oneStrInd] < two[twoStrInd]) {
				output += one[oneStrInd];
				mergeStrings(one, two, oneStrInd+1, twoStrInd, output); // 1
			}
			else
			{
				output += two[twoStrInd];
				mergeStrings(one, two, oneStrInd, twoStrInd+1, output); // 2
			}
		}
		
		while (oneStrInd < one.length()) {
			output += one[oneStrInd];
			mergeStrings(one, two, oneStrInd + 1, twoStrInd, output); // 1
		}

		while (twoStrInd < two.length()) {
			output += two[twoStrInd];
			mergeStrings(one, two, oneStrInd, twoStrInd + 1, output); // 2
		}
	}

	// Better Optimized recursive code - Do the practice
	string alphabeticMerge(string one, string two) {
		if (one[0] == '\0')
		{
			if (two[0] == '\0') {

				return one;
			}
			return two;
		}

		else if (two[0] == '\0')
			return one;

		else if (one[0] > two[0])
			return two[0] + alphabeticMerge(one, two.substr(1));

		return one[0] + alphabeticMerge(one.substr(1), two);

   }
};

int main() {
	string one = "adefz";
	string two = "bcfgy";
	Merge mg;
	string answer = mg.mergeStrings_iter(one, two);
	cout << answer << endl;
}

#endif //FORREF

