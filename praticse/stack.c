#include <stdio.h>
#define max 100

int stk[max];
int top = -1;

void push(int val);
void pop();
void peek();
void display();

int main() {
  int val, choice;
  while (choice != 5) {
    printf("\n****** MAIN MENU || STACK(array) || C ******");
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
  if (top == max - 1) {
    printf("\nSTACK OVERFLOW");
  } else {
    top++;
    stk[top] = val;
    printf("%d pushed into stack.", val);
  }
}

void pop() {
  int val;
  if (top == -1) {
    printf("\nSTACK UNDERFLOW");
  } else {
    val = stk[top];
    top--;
    printf("%d popped from the stack.", val);
  }
}

void peek() {
  if (top == -1) {
    printf("STACK UNDERFLOW");
  } else {
    printf("\ntop of the stack = %d", stk[top]);
  }
}

void display() {
  int i;
  if (top == -1) {
    printf("\nSTACK UNDERFLOW");
  } else {
    printf("\nSTACK:");
    for (i = top; i >= 0; i--) {
      printf("\n %d", stk[i]);
    }
  }
}