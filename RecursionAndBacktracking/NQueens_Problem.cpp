/*
	N - Queens Problem
	Problem statement

	Problem statement
	You are given an empty chessboard of size N * N. 
	
	Find the number of ways to place N queens on the board, 
	such that no two queens can kill each other in one move. 
	A queen can move vertically, horizontally, and diagonally.

	Solution:
	[Backtracking Approach]
	The idea is to place queens one by one in different columns, starting from the leftmost column.
	When we place a queen in a column, we checked for clashes with already placed queens. 
	In the current column, if we find a row for which there is no clash, we mark this row & column
	as part of solution. if we don't find such a row due to clashes, we return false and backtrack.

*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct NQueenProblem {

	bool isSafe(int board[][10], int ir, int ic, int nQueen) {
		// check the horizontal classhes
		
		// up vertical
		for (int i = ir-1; i >= 0; --i) {
			if (board[i][ic])
				return false;
		}

		// down vertical
		for (int i = ir+1; i<nQueen; ++i) {
			if (board[i][ic])
				return false;
		}

		// left horizontal
		for (int i = ic - 1; i >= 0; --i) {
			if (board[ir][i])
				return false;
		}

		// right horizontal
		for (int i = ic + 1; i < nQueen; ++i) {
			if (board[ir][i])
				return false;
		}

		//Left Diagonal
		// up
		int x = ir-1;
		int y = ic-1;
		while (x >= 0 && y >= 0) {
			if (board[x][y] == 1)
				return false;
			x--;
			y--;
		}
		// down
		x = ir + 1;
		y = ic + 1;
		while (x < nQueen && y < nQueen) {
			if (board[x][y] == 1)
				return false;
			x++;
			y++;
		}

		//Right Diagonal
		// up
		x = ir-1;
		y = ic+1;
		while (x >= 0 && y < nQueen) {
			if (board[x][y] == 1)
				return false;
			x--;
			y++;
		}

		// down
		x = ir + 1;
		y = ic - 1;
		while (x < nQueen && y >= 0) {
			if (board[x][y] == 1)
				return false;
			x++;
			y--;
		}

		return true;
	}

	bool solveQueen(int board[][10], int col, int nQueen) {
		/*
			Now the first thing you have to do here is 
			place the nQueen on the board, and if all the nQueen
			is already placed , meaning if you are able to place 
			all the nQueen on board, that is the state you should terminate with
			"success" from the recursion. So this is your base or terminating condition
		*/
		if (col == nQueen) {
			cout << "Yes, the all nQueen is already placed at board, see below the position!!" << endl;
			
			// so for verification , printing the board state will be important
			// i am considering the 
			for (int i = 0; i < nQueen; ++i) {
				for (int j = 0; j < nQueen; j++) {
					if (board[i][j]) {
						cout << " Q ";
					}
					else
						cout << " - ";
				}
				cout << endl;
			}
			cout << endl;
			cout << endl;

			return true;
		}

		for (int i = 0; i < nQueen; ++i) {
			if (isSafe(board, i, col, nQueen)) {
				board[i][col] = 1;
				bool nextqueen = solveQueen(board, col + 1, nQueen);
				if (nextqueen)
					return true;
				board[i][col] = 0;
			}
		}

		return false;
	}
};

int main() {
	// Given number of queen is 04
	int n = 3;
	// Also assume that board 
	int board[10][10] = { 0 };
	// Since you need two dimensional recursion here
	// one dimension we will pass into the recursion method and another dimension we will get from for loop inside the method
	// let's see how?
	NQueenProblem np;
	if (false == np.solveQueen(board, 0, n)) {
		cout << "placement of " << n << " queen is not possible in given board!!" << endl;
	}
	return 0;
}

#endif // FORREF

