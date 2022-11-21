#include <stdio.h>

int grid[9][9] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 4},
   {0, 4, 5, 2, 0, 6, 3, 0, 0}
};


int main(){
    printf("hello");
}

int isPresentInCol(int col, int num){ //check whether num is present in col or not
    for (int row = 0; row < 9; row++){
        if (grid[row][col] == num){
            return 1;
        }
   }
   return 0;
}

int isValid(int row,int col,int num){
    return (!isPresentInBox(row - row%3,col - col%3,num) && !isPresentInCol(col,num) && !isPresentInRow(row,num));
}



int solveIt(){
    int row,col;
    if (!getEmptyPlace(&row,&col)){
        return 1; // all places are filled
    }
    for (int num=1;num<=9;num++){
        if (isValid(row,col,num)){
            grid[row][col] = num;
            if (solveIt()){
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}
 
int printGrid(){
    for (int i=0;i<9;i++){
        if (i==0 )
            printf("-------------------------\n");
        else if (i%3 == 0){
            printf("--------+-------+--------\n");
        }
        for (int j=0;j<9;j++){
            if (j == 0)
                printf("| ");
            else if (j%3 == 0){
                printf("| ");
            }
            printf("%d ",grid[i][j]);
        }
        printf("|\n");
    }
    printf("-------------------------\n");
}
