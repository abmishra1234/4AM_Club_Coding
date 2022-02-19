/*
	Edit Distance Problem

*/

//#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>


struct EditDist {
    int solve(string str1, string str2, int m, int n) {
        if (m == 0 && n == 0) {
            return 0;
        }
        else if (m == 0) {
            return n;
        }
        else if (n == 0) {
            return m;
        }
        else {
            int minop = INT_MAX;

            if (str1[m - 1] == str2[n - 1]) {
                // this is the case when you will find the same last character
                minop = min(minop, solve(str1, str2, m - 1, n - 1));
            }
            else
            {
                minop = 1 + min(solve(str1, str2, m - 1, n), min(solve(str1, str2, m, n - 1), solve(str1, str2, m - 1, n - 1)));
            }
            return minop;
        }
    }
};

int main() {
    string s1 = "sunday";
    string s2 = "saturday";
    EditDist ed;
    cout << ed.solve(s1, s2, s1.length(), s2.length());
//    cout << editDist(s1, s2) << endl;

    return 0;
}


#endif // !FORREF

