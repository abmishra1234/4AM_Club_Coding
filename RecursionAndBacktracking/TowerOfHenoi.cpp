/*
	Tower of Hanoi
	Problem statement
	Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
	The objective of the puzzle is to move the entire stack of disks to another rod, obeying the following simple rules:
		- Only one disk can be moved at a time.
		- Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack 
		  i.e. a disk can only be moved if it is the uppermost disk on a stack.
		- No disk may be placed on top of a smaller disk.

		Implementation
		So now we can move ahead to the coding part.

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

void Toh(int n, char src, char dest, char helper) {
	if (n == 0)
		return;
	Toh(n - 1, src, helper, dest);
	cout << "Move " << n << " From " << src << " to " << dest << endl;
	Toh(n - 1, helper, dest, src);
}

int main() {
	int n = 3;
	Toh(n, 'A', 'C', 'B');

	return 0;
}
#endif // FORREF

