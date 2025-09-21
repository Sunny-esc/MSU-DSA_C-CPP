#include <stdio.h>
#define MAX 20

struct stack {
  char data[MAX];
  int top;
} s;

void push(char val) {
  if (s.top == MAX - 1) {
    printf("Overflow\n");
    return;
  }
  s.data[++s.top] = val;
}

void pop() {
  if (s.top == -1) {
    printf("Underflow\n");
    return;
  }
  s.top--;
}

int checkpair(char open, char close) {
  return ((open == '(' && close == ')') || (open == '{' && close == '}') ||
          (open == '[' && close == ']'));
}

void parenth(char expr[], int len) {
  for (int i = 0; i < len; i++) {
    if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
      push(expr[i]);
    } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
      if (s.top == -1) {
        printf("Unbalanced\n");
        return;
      }
      if (checkpair(s.data[s.top], expr[i])) {
        pop();
      } else {
        printf("Unbalanced\n");
        return;
      }
    }
  }
  if (s.top == -1)
    printf("Balanced\n");
  else
    printf("Unbalanced\n");
}

int main() {
  s.top = -1; // initialise stack
  char expr[100];
  printf("Enter expression: ");
  scanf("%s", expr);

  int len = 0;
  while (expr[len] != '\0')
    len++;

  parenth(expr, len);
  return 0;
}
