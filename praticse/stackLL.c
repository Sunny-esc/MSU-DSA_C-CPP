#include <stdio.h>
#include <stdlib.h>

struct stack {
  int data;
  struct stack *next;
};

struct stack *top = NULL;
void push(int val);
void pop();
void peek();
void display();

int main() {
  int val, choice;
  while (choice != 5) {
    printf("\n****** MAIN MENU || STACK(LL) || C ******");
    printf("\n1. PUSH");
    printf("\n2. POP");
    printf("\n3. PEEK");
    printf("\n4. DISPLAY");
    printf("\n5. EXIT");

    printf("\n Enter the choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("\nEnter Number : ");
      scanf("%d", &val);
      push(val);
      break;

    case 2:
      pop();
      break;

    case 3:
      peek();
      break;

    case 4:
      display();
      break;

    case 5:
      printf("\nEXIt FROM PROGRAM !!\n");
      break;

    default:
      printf("\nINVALID CHOICE !!\nTRY AGAIN.\n");
      break;
    }
  }
  return 0;
}

void push(int val) {
  struct stack *NewNode = (struct stack *)malloc(sizeof(struct stack));
  NewNode->data = val;
  if (top == NULL) {
    NewNode->next = NULL;
    top = NewNode;
  } else {
    NewNode->next = top;
    top = NewNode;
  }
}

void pop() {
  struct stack *ptr = top;
  if (ptr == NULL) {
    printf("\nSTACK UNDERFLOW");
  } else {
    top = top->next;
    printf("\n %d popped from the stack.", ptr->data);
    free(ptr);
  }
}

void peek() {
  if (top == NULL) {
    printf("\nSTACK UNDERFLOW");
  } else {
    printf("\ntop of the stack = %d", top->data);
  }
}

void display() {
  struct stack *ptr = top;
  if (ptr == NULL) {
    printf("\nSTACK UNDERFLOW");
  } else {
    while (ptr != NULL) {
      printf("\n %d", ptr->data);
      ptr = ptr->next;
    }
  }
}