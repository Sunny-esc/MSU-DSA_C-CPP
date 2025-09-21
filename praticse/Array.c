#include <stdio.h>
#define COL 3
#define ROW 3
//This file contains Assgiment 2 question 1
int main(){
    int array[ROW][COL]={
        {1,2,3},{4,5,6},{7,8,9}
    };
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("\t %d ",array[i][j]);
        }
        printf("\n");
        
    }
    printf("\n2D Array in Column-Major Order (Simulated):\n");
    for(int j=0;j<COL;j++){
        for(int i=0;i<ROW;i++){
            printf("\t %d ",array[i][j]);
        }
        printf("\n");
        
    }
    printf("\n2D NULL MATRIX:\n");
      for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            array[i][j] = 0; // Initialize to zero
        
            printf("\t %d ",array[i][j]);
        }
        printf("\n");
        
    }    
      printf("\n2D IDENTITY MATRIX:\n");
      for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
             if(i==j){
                array[i][j]=1;
            }else{
                array[i][j]=0;
               
             }
            printf("\t %d ",array[i][j]);
        }
        printf("\n");
        
    } 
      printf("\n2D check square MATRIX:\n");
            if(ROW == COL){
                printf("The martix is square");
            }
            else{
                printf("The matrix is not square");
                
            }        
            return 0;
        }
        
     
    



