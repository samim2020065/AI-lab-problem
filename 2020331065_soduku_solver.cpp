#include <bits/stdc++.h>
using namespace std;

#define N 9  

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) cout << "---------------------"<<endl;
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) cout << "| ";
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int board[N][N], int row, int col, int num) {
    
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}


bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {  
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))  
                            return true;
                        board[row][col] = 0;  
                    }
                }
                return false;  
            }
        }
    }
    return true; 
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku Puzzle:"<<endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << endl<<"Solved Sudoku Puzzle:"<<endl;
        printBoard(board);
    } else {
        cout << endl<<"No solution exists!"<<endl;
    }

    return 0;
}
