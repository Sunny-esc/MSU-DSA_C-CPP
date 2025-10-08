#include<stdio.h>
#include <stdlib.h>

#define max 10

//arr
int stack[max];
//top
int top =-1;

//handle the input or output error while pushing or poping
void handle_error(const char *message) {
    printf("Error: %s\n", message);
    exit(EXIT_FAILURE); // Exit the program
}
//push
void push(int data){
    //check if stack is full
    if(top == max-1){
        handle_error("stack is full");
    }
    //
    top++;
    stack[top]=data;


}
//pop
void pop(){
    //check if stack is empty
    if(top == -1 ){
        handle_error("stack is empty");
    }
    stack[top--];
}
//peek
int peek(){
    //check if stack is empty
    if(top == -1 ){
        handle_error("stack is empty");
    }

    //return the top element
    printf("Top element is =%d ",stack[top]);
    return 0;
}
int display(){
    //check if stack is empty
    if(top == -1 ){
        handle_error("stack is empty");
    }
    int i;
    //return all elements
    printf("displaying the elments \n");
    for(i=0;i<=top;i++){
        printf(" %d ->",stack[i]);
    }
    printf("\n");
    return 0;
}

int main(){
    int choice,data;
    //menu driven
    do{
    printf("\n Enter the choice \n 1.Push \n 2.Pop \n 3.Peek \n 4. Dispplay \n 5.exit \n ::=");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Enter the data to push=");
            scanf("%d",&data);
            push(data);
            printf("Pushed == %d \n ",data);
        break;
        case 2:

            pop();
            printf("pop \n" );
        break;

        case 3:
          printf("peek opp = %d \n",peek());


        break;
         case 4:
          printf(" %d",display());


        break;
        case 5:
            printf("exiting the menu");
        break;

    }}while(choice != 5);
    return 0;
}
