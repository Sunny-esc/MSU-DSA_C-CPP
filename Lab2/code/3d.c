#include<stdio.h>
//This file contains Assgiment 2 question 3

int main(){
    int array[2][3][4]={
        {{1,2,3,4},{5,6,7,8},{9,10,11,12}},
        {{13,14,15,16},{17,18,19,20},{21,22,23,24}}
    };
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                printf("%2d \n",array[i][j][k]);
            }
        }
       
    }
       printf("\n\nDisplaying elements layer by layer:\n");
    for (int i = 0; i < 2; i++) {
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                printf("%2d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}