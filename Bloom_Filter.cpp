/*
	This is the sample code for Bloom Filter.
	It is not fully tested and consider code only for basic understanding.
*/

#define FORREF
#ifndef FORREF
using namespace std;

#include<iostream>
#include<string>

#define ll long long


/*
	Please note here that as you make unique entry in your bloom filter array, it will give you less duplicate entry.
	but it may impact your performance. So Architect has to take some decision based on their current context.

	for demonstration of concept , I have created some hash method but for actual production code it is better to use
	some standard hash for ex: MD5 etc...
*/

// hash 1
int h1(string s, int arrSize)
{
	ll int hash = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		hash = (hash + ((int)s[i]));
		hash = hash % arrSize;
	}
	return (int)hash;
}

// hash 2
int h2(string s, int arrSize)
{
	ll int hash = 1;
	for (size_t i = 0; i < s.size(); i++)
	{
		hash = hash + pow(19, i) * s[i];
		hash = hash % arrSize;
	}
	return (int)hash % arrSize;
}

// hash 3
int h3(string s, int arrSize)
{
	ll int hash = 7;
	for (int i = 0; i < s.size(); i++)
	{
		hash = (hash * 31 + s[i]) % arrSize;
	}
	return hash % arrSize;
}

// hash 4
int h4(string s, int arrSize)
{
	ll int hash = 3;
	int p = 7;
	for (int i = 0; i < s.size(); i++) {
		hash += hash * 7 + s[0] * pow(p, i);
		hash = hash % arrSize;
	}
	return hash;
}


// loookup operation
bool lookup(bool* bitarray, int arrSize, string s)
{
	int a = h1(s, arrSize);
	int b = h2(s, arrSize);
	int c = h3(s, arrSize);
	int d = h4(s, arrSize);

	if (bitarray[a] && bitarray[b] && bitarray[c] && bitarray[d])
		return true;
	else
		return false;
}

// insert operation
void insert(bool* bitarray, int arrSize, string s)
{
	// check if the element in already present or not
	if (lookup(bitarray, arrSize, s))
		cout << s << " is Probably already present" << endl;
	else
	{
		// you are creating the hash value for bitarray index to be set
		int a = h1(s, arrSize);
		int b = h2(s, arrSize);
		int c = h3(s, arrSize);
		int d = h4(s, arrSize);

		// you are setting the bit below
		bitarray[a] = true;
		bitarray[b] = true;
		bitarray[c] = true;
		bitarray[d] = true;

		cout << s << " inserted" << endl;
	}
}

// Driver Code
int main()
{
	bool bitarray[256] = { false };
	int arrSize = 256;
	string sarray[30]
		= { "delhi", "bengaluru",	 "abinash",
			"purpose", "bloom", "filter",
			"blossom", "bolster",	 "bonny",
			"bonus", "bonuses",	 "coherent",
			"cohesive", "colorful",	 "comely",
			"comfort", "bluff",		 "generosity",
			"generous", "generously", "genial",
			"bluff", "cheater",	 "hate",
			"war",	 "humanity",	 "racism",
			"hurt",	 "nuke", "gloomy"};
	for (int i = 0; i < 30; i++) {
		insert(bitarray, arrSize, sarray[i]);
	}

	// now lookup call please
	cout << lookup(bitarray, 256, "delhi") << endl;
	cout << lookup(bitarray, 256, "bluff") << endl;

	cout << lookup(bitarray, 256, "Madras") << endl;
	cout << lookup(bitarray, 256, "date") << endl;

	return 0;
}

#endif // FORREF

