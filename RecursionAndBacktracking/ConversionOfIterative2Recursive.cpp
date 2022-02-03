/*
	This  sample of code for understanding the approach to convert
	Iterative code into the Recursive code.

    We will see the otherwise conversion in next example
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include <iostream>
#include <string>

// For making the below code to work recursively
// introducing one class for it

struct ToRecursive {

    void Convert(string name, int ind, string &out/* this is special character array so already by reference only*/) {
        // base condition decide later
        if (ind == name.length())
            return;

        char current = name[ind];
        bool duplicate = false;
        // you have ro check the duplicate and remove it
        string tname = "";
        for (size_t i = ind + 1; i < name.length(); ++i) {
            if (current == name[i]) {
                duplicate = true;
                name = name.substr(0, i) + name.substr(i + 1, name.length());
            }
        }
        
        if (false == duplicate) {
            out += current;
        }

        Convert(name, ind + 1, out);
    }
};

int main() {

    string name = "Hello Worldd";
    
    // Below 04 line is added to use the recursive method converted here
    ToRecursive tr;
    string out= "";
    tr.Convert(name, 0, out);
    cout << out << endl;

    //The first for loop which iterates over every character
    // This below code was for iterative method
#if 0
    for ( size_t i = 0; i < name.length(); i++) {
        int duplicate = 0;
        char current = name[i];
        // The second for loop which removes all other duplicate occurences
        for (size_t j = i + 1; j < name.length(); j++) {

            if (current == name[j]) {
                //Removing the duplicate occurence
                duplicate = 1;
                name = name.substr(0, j) + name.substr(j + 1, name.length() - 1);
                cout << name << endl;
            }
        }
        if (duplicate == 0) {
            cout << current << endl;
        }
    }
#endif  // 0
}


#endif // FORREF

