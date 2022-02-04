/*
	Let's find the total number of vowels
	
	Problem Statement:
	Given a sentence you will find that the letters can be divided into two segments; 
	Consonants and Vowels. Vowels are the letters; A, E, I, O, U or a, e, i, o, u. 
	In this challenge, you need to find the total numbers of vowels in a given string.

	Let's solve your problem by different approaches.
*/
#define FORREF
#ifndef FORREF

using namespace std;
#include<iostream>
#include<string>

struct Vowels {
    // recursion based
    int countApproach01(string text, int len, int index) {
        int count = 0;
        if (index >= len)
            return 0;
        else {
            char ch = toupper(text[index]);
            if (ch == 'A'|| ch == 'E'|| ch == 'I'|| ch == 'O'|| ch == 'U') {
                count++;
            }
            return (count + countApproach01(text, len, index + 1));
        }
    }

    // iterative
    int countApproach02(string text, int len, int index) {
        int count = 0;
        while (index < len) {
            char ch = toupper(text[index++]);
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Vowels vw;

    cout << "The string is: Hello World" << endl;
    cout << "The total number of vowels in this string are: " << vw.countApproach02("Hello World", 10, 0) << endl;

    cout << "The string is: STR" << endl;
    cout << "The total number of vowels in this string are: " << vw.countApproach02("STR", 3, 0) << endl;

    cout << "The string is: AEIOUaeiouSs" << endl;
    cout << "The total number of vowels in this string are: " << vw.countApproach02("AEIOUaeiouSs", 12, 0) << endl;

}



#endif // FORREF

