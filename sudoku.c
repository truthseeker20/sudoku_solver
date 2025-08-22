#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solveSudoku(int board[9][9]);
int isSafe(int n, int b[9][9], int i, int j);
int rowCheck(int num,int board[9][9], int num_row, int num_col);
int colCheck(int num,int board[9][9], int num_row, int num_col);
int gridCheck(int num, int board[9][9], int num_row, int num_col);
void printBoard(int board[9][9]);

int main() {

    int board [9][9] = {0};

    bool isSolved = solveSudoku(board);

    if (isSolved) {printBoard(board);}
    else {printf("No solution exists\n");}

    return 0;

}

bool solveSudoku(int board[9][9]) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (board[i][j]==0) {
                for (int trial_num=1; trial_num<=9; trial_num++) {
                    if(!isSafe(trial_num,board,i,j)){
                        continue;
                    }
                    else {
                        board[i][j]=trial_num;
                        if(solveSudoku(board)) {
                            return true;
                        }
                        else {
                            board[i][j]=0;
                            continue;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int isSafe(int n, int b[9][9], int i, int j) {
    
    int r = rowCheck(n,b,i,j);
    int c = colCheck(n,b,i,j);
    int g = gridCheck(n,b,i,j);

    if (r==0 && c==0 && g==0) {
        return 1;
    }

    else {
        return 0;
    }

}

int rowCheck(int num, int board[9][9], int num_row, int num_col) {
    
    for (int col_iter=0; col_iter<9; col_iter++) {
        if (col_iter == num_col) continue;
        if (board[num_row][col_iter]==num) return 1;
    }
    return 0;

}

int colCheck(int num, int board[9][9], int num_row, int num_col) {
    
    for (int row_iter=0; row_iter<9; row_iter++) {
        if (row_iter == num_row) continue;
        if (board[row_iter][num_col]==num) return 1;
    }
    return 0;

}

int gridCheck(int num, int board[9][9], int num_row, int num_col) {
    int row_start = (num_row/3)*(3);
    int col_start = (num_col/3)*(3);

    for (int row_iter=row_start; row_iter<(row_start+3); row_iter++) {
        for (int col_iter=col_start; col_iter<(col_start+3); col_iter++) {
            if (row_iter==num_row && col_iter==num_col) continue;
            if (board[row_iter][col_iter]==num) return 1; 
        }
    }
    return 0;
}

void printBoard(int board[9][9]) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d ",board[i][j]);
            if (j==2 || j==5) {printf("|");}
        }
        printf("\n");
        if(i==2 || i==5) {printf("-------------------\n");}
    }
}
