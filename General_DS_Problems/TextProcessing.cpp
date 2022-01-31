/*
	String:
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<string>
#include<algorithm>


int main()
{
	// A string is very similar to a std::vector
	string name("Abiansh Mishra");
	auto strIt = find_if(name.begin() + 1, name.end(), [](char c) {return isupper(c); });
	if (strIt != name.end())
	{
		string firstName = string(name.begin(), strIt);
		string lastName = string(strIt, name.end());
		cout << firstName << endl;
		cout << lastName << endl;
	}

	// 



	return 0;
}

#endif // FORREF

