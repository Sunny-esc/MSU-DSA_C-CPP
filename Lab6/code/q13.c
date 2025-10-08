#include <stdio.h>
#include <string.h>
#define MAX 20

int top = -1;
char stk[MAX];

void push(char c);
char pop();

int main() {
  char expr[MAX], tmp;
  int i, flag = 1;

  printf("Enter Expression : ");
  gets(expr);

  for (i = 0; i < strlen(expr); i++) {
    if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
      push(expr[i]);
    } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
      if (top == -1) {
        flag = 0;
        break;
      } else {
        tmp = pop();
        if (expr[i] == ')' && (tmp == '{' || tmp == '[')) {
          flag = 0;
        }
        if (expr[i] == '}' && (tmp == '(' || tmp == '[')) {
          flag = 0;
        }
        if (expr[i] == ']' && (tmp == '{' || tmp == '(')) {
          flag = 0;
        }
      }
    }
  }

  if (top != -1) {
    flag = 0;
  }

  if (flag == 1) {
    printf("\nValid Expression !!\n");
  } else {
    printf("\nInvalid Expression !!\n");
  }
  return 0;
}

void push(char c) {
  if (top == MAX - 1) {
    printf("\nSTACK OVERFLOW !!");
  } else {
    stk[++top] = c;
  }
}

char pop() {
  if (top == -1) {
    printf("\nSTACK UNDERFLOW !!");
    return '\0';
  } else {
    return stk[top--];
  }
}