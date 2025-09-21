#include <stdio.h>
#include <string.h>
#define MAX 100
char stk[MAX];
int top = -1;

void Push(char c);
char Pop();

int main() {
  char str[MAX], rev[MAX];
  int i, count = 0;

  printf("Enter a String : ");
  scanf("%s", str);
  printf("\nORIGINAL STRING : %s", str);

  for (i = 0; str[i] != '\0'; i++) {
    Push(str[i]);
  }
  while (top != -1) {
    rev[count++] = Pop();
  }
  rev[count] = '\0';

  printf("\n\nREVERSED STRING : %s\n", rev);
  return 0;
}

void Push(char c) {
  if (top == MAX - 1) {
    printf("Stack Overflow\n");
  } else {
    top++;
    stk[top] = c;
  }
}

char Pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return '\0';
  } else {
    return stk[top--];
  }
}