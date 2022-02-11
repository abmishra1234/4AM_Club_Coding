/*
    Sudoku Problem
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>

struct Sudoku {
    /*
        So my first thought came here that this below method should stop immediately when you found the solution
        or you should stop exploring the same path if this achieve the solution

    
    
    */

    bool canPlace(int mat[9][9], int r, int c, int size, int number) {
        // let's focus on this method now
        // first thing to check, does the same row is already having this number?
        for (int x = 0; x < size; ++x) {
            // row wise and column wise check
            if (mat[x][c] == number||mat[r][x] == number)
                return false;
        }
    
        // so now you have to verify the code for 3X3 sub grid state
        // First thing you have to do to check , the position of your point(r,c) 
        int rn = sqrt(size);
        int sr = (r / rn) * rn; // r = 4
        int sc = (c / rn) * rn; // c = 5

        for (int i = sr; i < sr + 3; ++i) {
            for (int j = sc; j < sc + 3; ++j) {
                if (mat[i][j] == number)
                    return false;
            }
        }
        return true;
    }

    bool solve(int mat[9][9], int r, int c, int size/* number of rows or cols for NXN board*/) {
        // my base case here is , you should start placing all the numbers from row 0 to N-1
        // So if your row will reach r == N, means you already placed all your numbers at right place and so return by marking it successful
        if (r == size) {
            // just print the number once
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            return true;
        }

        // another case if you reach to the point where you are at the end of beyound the last column
        // so you have to start from next level row from beginning, so your recursion should behave like this
        if (c == size) {
            return solve(mat, r + 1, 0, size);
        }

        // This is the case when you found that your current cell is not empty
        // What you will do in that case? You just move ahead with next cell
        if (mat[r][c] != 0) {
            return solve(mat, r, c + 1, size);
        }

        // now you have to place the all possible digits into your current cell and do the check of validity according to the given constraint
        for (int number = 1; number <= 9; ++number) {
            if (canPlace(mat, r, c, size, number)) {
                // if allowed, assign the number in cell and look for next cell
                mat[r][c] = number;
                bool result = solve(mat, r, c+1, size);
                if (result)
                    return true;
            }
        }
        // backtrack step
        mat[r][c] = 0;
        return false;
    }
};


int main() {
    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    Sudoku sol;

    sol.solve(mat, 0, 0, 9);
}





#endif // FORREF
