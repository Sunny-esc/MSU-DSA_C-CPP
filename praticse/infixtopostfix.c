#include <ctype.h>
#include <stdio.h>

char Stack[20];
int top = -1;

void push(char val) { Stack[++top] = val; }

char pop() { return Stack[top--]; }

int priority(char e) {
  if (e == '(')
    return 0;
  else if (e == '+' || e == '-')
    return 1;
  else if (e == '*' || e == '/')
    return 2;
  return -1;
}

int main() {
  char expr[100], *e, x;

  printf("Enter the expression: ");
  scanf("%s", expr);
  e = expr;

  while (*e != '\0') {
    if (isalnum(*e)) {
      printf("%c", *e);
    } else if (*e == '(') {
      push(*e);
    } else if (*e == ')') {
      while ((x = pop()) != '(') {
        printf("%c", x);
      }
    } else {
      while (top != -1 && priority(Stack[top]) >= priority(*e)) {
        printf("%c", pop());
      }
      push(*e);
    }
    e++;
  }

  while (top != -1) {
    printf("%c", pop());
  }
  printf("\n");
  return 0;
}
