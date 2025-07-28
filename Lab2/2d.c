#include <stdio.h>

//This file contains Assgiment 2 question 2

int main(){
    int row1,col1;
    printf("Enter the number of rows for B:");
    scanf("%d", &row1);
    printf("Enter the number of columns For B:");
    scanf("%d", &col1);
    int array[row1][col1];
    printf("-------------------------------------\n");
    printf("2D Array:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
   
    printf("-------------------------------------\n");

    int row2,col2;
    printf("Enter the number of rows:");
    scanf("%d", &row2);
    printf("Enter the number of columns:");
    scanf("%d", &col2);
    int B[row2][col2];
    printf("-------------------------------------\n");
    printf("2D Array:\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    printf("-------------------------------------\n");
    printf("2D Array A:\n");
     for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("\t  %d ", array[i][j]);
        }
        printf("\n");
    }
    printf("2D Array B:\n");
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            printf("\t  %d ", B[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
    printf("addition of A and B:\n");
    if(row1 == row2 && col1 == col2){
        int c[row1][col1];
            for (int i = 0; i < row1; i++)
            {
            for (int j=0;j<col1;j++){
                c[i][j]=array[i][j]+B[i][j];
                printf("\t  %d ", c[i][j]);
            }
            printf("\n");
            }
            
     
    }
     printf("-------------------------------------\n");
    printf("Multiplication of A and B:\n");
    if(col1 == row2 ){
        int c[row1][col1];
            for (int i = 0; i < row1; i++)
            {
            for (int j=0;j<col1;j++){
                c[i][j]=array[i][j]*B[i][j];
                printf("\t  %d ", c[i][j]);
            }
            printf("\n");
            }
            
        
    }
       printf("-------------------------------------\n");
        printf("Transpose of result:\n");
        int c[row1][col1];
        for(int i=0;i<col1;i++){

            for(int j=0;j<row1;j++){
            c[i][j]=array[i][j]*B[i][j];
            printf("\t  %d ", c[j][i]);

            }
            printf("\n");
        }

              printf("-------------------------------------\n");
        printf("DETERMINATof 2*2 MATRIX:\n");
        int result=0;
      
                if(row1==2 && col1==2){
                    result=(array[0][0]*array[1][1])-(array[0][1]*array[1][0]);
                    printf("\t  %d ", result);
                }
                else{
                    printf("DETERMINANT is not possible for this matrix\n");
                    return 0;
                } 
            
            printf("-------------------------------------\n");
        return 0;
}

