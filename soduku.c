#include <stdio.h>

int main(){
    printf("hello");
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
