// 4. Implement a stack using a singly linked list with push, pop, and display
// in C.
// #include <algorithm>
// #include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

// define struct
struct node {
  int data;
  struct node *next;

} *top = NULL;
// void push
int push(int);
// void pop
void pop();
// void display
void display();
// int main
int main() {
  int choice, data;
  // hard coded push pop display
  // push(22);
  // push(22);
  // push(22);
  // push(22);
  // display();
  // pop();
  // pop();
  do {
    printf(
        "Enter the options \n 1.push \n 2.pop \n 3 .display \n 4.abort === \n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the data:=");
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      pop();
    case 3:
      display();
    }
  } while (choice != 4);
  return 0;
}

int push(int data) {
  // create  a new node
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  if (top == NULL) {
    newnode->next = NULL;
  }
  newnode->next = top;
  top = newnode;
  printf("insertation sucessful \n");
  return 0;
}

void pop() {
  if (top == NULL) {
    printf("the stack is empty");
  }
  struct node *temp = top;
  printf("deleted :%d", temp->data);
  top = temp->next;
  free(temp);
}

void display() {
  if (top == NULL) {
    printf("the stack is empty \n");
  }
  struct node *temp = top;
  while (temp->next != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("%d--->NULL", temp->data);
}