/*
	So, I want to complete some of the coding assignement now as quickly as possible today.
	one problem i picked rightnwo is Rat in a Maze Problem.

	A maze or board of size N*N is given...
	Also source block is given the top left corner
	
*/

using namespace std;
#include <iostream>
#include<vector>

#define FORREF

typedef vector<vector<int>> Vect;


#ifndef FORREF
struct Maze {

   


    /*
        Let's define this method now

        input maze :  
        {0, X, X, X}
        {0, 0, X, 0}
        {X, 0, X, X}
        {0, 0, 0, 0}

        you are expecting to return 
        solution like below

        [0, 1, 1,0]

        {1, 0, 0, 0}
        {1, 1, 0, 0}
        {0, 1, 0, 0}
        {0, 1, 1, 1}
    */

    vector<int> mvx = { 0, 1 };
    vector<int> mvy = { 1, 0 };


    void printSolution(Vect &solution, const int& xdst, const int& ydst) {
        for (int i = 0; i <= xdst; ++i) {
            for (int j = 0; j <= ydst; ++j) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool ratInMaze(char maze[10][10], Vect &solution, int r, int c, const int& xdst, const int& ydst) {
        // Let's think about the base case of this problem
        // when you will stop?
        // when you reach at destination or there is no path possible
        if (r == xdst && c == ydst) {
            // you reached at the destination
            solution[r][c] = 1; // you are etting the destination flag
            printSolution(solution, xdst, ydst);
            return true;
        }
        
        if (r > xdst || c > ydst) {
            return false;
        }

        if (maze[r][c] == 'X') {
            return false;
        }

        solution[r][c] = 1;

        bool rightside = ratInMaze(maze, solution, r, c + 1, xdst, ydst);
        bool downside = ratInMaze(maze, solution, r+1, c, xdst, ydst);

        solution[r][c] = 0;
        if (rightside || downside)
            return true;

        return false;
    }
};

int main() {
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };


// int solution[10][10] = { 0 };
    Vect solution(10, vector<int>(10, 0));
    Maze mazeObj;
    bool ans = mazeObj.ratInMaze(maze, solution, 0, 0, 3, 3);
}


#endif // !FORREF





