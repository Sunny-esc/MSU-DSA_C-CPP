// 8. Write a program in C to implement two stacks in one array such that:

// o Stack 1 grows from left to right.
// o Stack 2 grows from right to left.
// o The program should support push1(), push2(), pop1(), pop2() and check for
// overflow/underflow conditions.

// 9. Repeat the above in C++ using a class-based implementation.

#include <iostream>
using namespace std;
#define max 10

class mStacks {
public:
  int stack[max], top1 = -1, top2 = max;

  void push1(int val) {
    if (top1 == top2 - 1) {
      printf("\nSTACK OVERFLOW");
    } else {
      top1++;
      stack[top1] = val;
      printf("%d pushed into the stack", stack[top1]);
    }
  }
  void pop1() {
    if (top1 == -1) {
      printf("\nSTACK UNDERFLOW");
    } else {
      printf("%d popped from the stack", stack[top1]);
      top1--;
    }
  }
  void display1() {
    if (top1 == -1) {
      printf("\nSTACK UNDERFLOW");
    } else {
      printf("stack:");
      for (int i = top1; i >= 0; i--) {
        printf("\n %d", stack[i]);
      }
    }
  }

  void push2(int val) {
    if (top2 - 1 == top1) {
      printf("\nSTACK OVERFLOW");
    } else {
      top2--;
      stack[top2] = val;
      printf("%d pushed into the stack", stack[top2]);
    }
  }
  void pop2() {
    if (top2 == max) {
      printf("\nSTACK UNDERFLOW");
    } else {
      printf("%d popped from the stack", stack[top2]);
      top2++;
    }
  }
  void display2() {
    if (top2 == max) {
      printf("\nSTACK UNDERFLOW");
    } else {
      printf("stack:");
      for (int i = top2; i < max; i++) {
        printf("\n %d", stack[i]);
      }
    }
  }
};

int main() {
  mStacks stk;
  int val, choice = 0, op;
  while (choice != 3) {
    printf("\n** MAIN MENU || MULTIPLE STACKS || ARRAY || CPP **");
    printf("\n1. OPERATIONS FOR STACK1");
    printf("\n2. OPERATIONS FOR STACK2");
    printf("\n3. EXIT FROM PROGRAM");
    printf("\n\nEnter your choice for stack : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      op = 0;
      while (op != 4) {
        printf("\n\n*** MENU || STACK1 ***");
        printf("\n1. PUSH INTO STACK1");
        printf("\n2. POP FROM STACK1");
        printf("\n3. DISPLAY STACK1");
        printf("\n4. EXIT FROM STACK OPERATIONS");
        printf("\n\nEnter your choice of operation : ");
        scanf("%d", &op);

        switch (op) {
        case 1:
          printf("\nEnter Value : ");
          scanf("%d", &val);
          stk.push1(val);
          break;

        case 2:
          stk.pop1();
          break;

        case 3:
          stk.display1();
          break;

        case 4:
          printf("EXIT FROM THE PROGAMS !!\nBACK TO MAIN MENU !!\n");
          break;

        default:
          printf("\nINVALID OPERATION !!\nTRY AGAIN !!\n");
          break;
        }
      }
      break;

    case 2:
      op = 0;
      while (op != 4) {
        printf("\n*** MENU || STACK2 ***");
        printf("\n1. PUSH INTO STACK2");
        printf("\n2. POP FROM STACK2");
        printf("\n3. DISPLAY STACK2");
        printf("\n4. EXIT FROM STACK OPERATIONS");
        printf("\n\nEnter your choice of operation : ");
        scanf("%d", &op);

        switch (op) {
        case 1:
          printf("Enter Value : ");
          scanf("%d", &val);
          stk.push2(val);
          break;

        case 2:
          stk.pop2();
          break;

        case 3:
          stk.display2();
          break;

        case 4:
          printf("EXIT FROM THE PROGAMS !!\nBACK TO MAIN MENU !!\n");
          break;

        default:
          printf("\nINVALID OPERATION !!\nTRY AGAIN !!\n");
          break;
        }
      }
      break;

    case 3:
      printf("\nEXIT FROM THE PROGRAM !!");
      break;

    default:
      printf("\nINVALID CHOICE !!\nTRY AGAIN !!\n");
      break;
    }
  }
  return 0;
}