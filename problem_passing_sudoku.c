#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool solveSudoku(int **board, int order);
int isSafe(int n, int **b, int i, int j, int o);
int rowCheck(int num,int **board, int num_row, int num_col, int order);
int colCheck(int num,int **board, int num_row, int num_col, int order);
int gridCheck(int num, int **board, int num_row, int num_col, int order);
void printBoard(int **board, int order);

int main(int argc, char* argv[]) {
    
    int temp_variable;

    if (argc>2 || argc<=1) {
        printf("Usage: %s <filename.txt>.\n",argv[0]);
        return 1;
    }

    int puzzle_num_count = 0;

    FILE* puzzle_file = fopen(argv[1],"r");

    if (puzzle_file==NULL) {
        printf("Error: File can't be opened.\n");
        return 1;
    }

    while(fscanf(puzzle_file,"%d",&temp_variable)==1) {
        puzzle_num_count++;
    }

    rewind(puzzle_file);

    int order = (int) sqrt(puzzle_num_count);

    if (order==0) {
        printf("Error: given puzzle file is empty.\n");
        return 1;
    }

    int root = (int) sqrt(order);

    if (root*root != order) {
        printf("Error: given puzzle's order is not a perfect square.\n");
        return 1;
    }

    int** board = (int**) malloc(order*sizeof(int*));//array of pointers, where each element is pointing to first element of row, which is an int 

    for (int row=0; row<order; row++) {
        *(board+row) = (int*)malloc(sizeof(int)*order);
    } 

    for (int row=0; row<order; row++) {
        for (int col=0; col<order; col++) {
            fscanf(puzzle_file,"%d",&board[row][col]);
        }
    }    

    fclose(puzzle_file);

    printf("\n\nProblem:\n");
    printBoard(board,order);

    bool isSolved = solveSudoku(board,order);

    if (isSolved) {
        printf("\n\nSolution:\n");
        printBoard(board,order);
    }
    else {printf("No solution exists\n");}

    for (int row=0; row<order; row++) {
        free(*(board+row));
    }

    free(board);

    return 0;

}

bool solveSudoku(int **board, int order) {
    for (int i=0; i<order; i++) {
        for (int j=0; j<order; j++) {
            if (*(*(board+i)+j)==0) {
                for (int trial_num=1; trial_num<=order; trial_num++) {
                    if(!isSafe(trial_num,board,i,j,order)){
                        continue;
                    }
                    else {
                        *(*(board+i)+j)=trial_num;
                        if(solveSudoku(board,order)) {
                            return true;
                        }
                        else {
                            *(*(board+i)+j)=0;
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

int isSafe(int n, int **b, int i, int j, int o) {

    int r = rowCheck(n,b,i,j,o);
    int c = colCheck(n,b,i,j,o);
    int g = gridCheck(n,b,i,j,o);

    if (r==0 && c==0 && g==0) {
        return 1;
    }

    else {
        return 0;
    }

}

int rowCheck(int num, int **board, int num_row, int num_col, int order) {

    for (int col_iter=0; col_iter<order; col_iter++) {
        if (col_iter == num_col) {continue;}
        if (*(*(board+num_row)+col_iter)==num) {return 1;}
    }
    return 0;

}

int colCheck(int num, int **board, int num_row, int num_col, int order) {

    for (int row_iter=0; row_iter<order; row_iter++) {
        if (row_iter == num_row) {continue;}
        if (*(*(board+row_iter)+num_col)==num) {return 1;}
    }
    return 0;

}

int gridCheck(int num, int **board, int num_row, int num_col, int order) {
    int box_size = sqrt(order);
    int row_start = (num_row/box_size)*box_size;
    int col_start = (num_col/box_size)*box_size;

    for (int row_iter=row_start; row_iter<(row_start+box_size); row_iter++) {
        for (int col_iter=col_start; col_iter<(col_start+box_size); col_iter++) {
            if (row_iter==num_row && col_iter==num_col) {continue;}
            if (*(*(board+row_iter)+col_iter)==num) {return 1;} 
        }
    }
    return 0;
}

void printBoard(int **board, int order) {
    int box_size=sqrt(order);
    printf("\n");
    for (int i=0; i<order; i++) {
        for (int j=0; j<order; j++) {
            printf("%d ",*(*(board+i)+j));
            for (int k=1; k<box_size; k++) {
                if (j==((box_size)*k)-1) {printf("| ");}
            }
        }
        printf("\n");
        for (int k=1; k<box_size; k++) {
            if (i==((box_size)*k)-1) {
                for (int l=1; l<(order*2)+2; l++) {
                    printf("-");
                }
                printf("\n");
            }
        }
    }
    printf("\n");
}
