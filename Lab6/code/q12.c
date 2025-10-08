#include <stdio.h>
#define max 100
int stk[max], top = -1;

void Push(int value);
int Pop();

int main() {
  int n, i, val, num[max];

  printf("Enter the size of the array : ");
  scanf("%d", &n);

  printf("Enter Values for the array : \n");
  for (i = 0; i < n; i++) {
    printf("for index %d : ", i);
    scanf("%d", &num[i]);
  }

  printf("\nORIGINAL ARRAY :");
  for (i = 0; i < n; i++) {
    printf("\nValue at index %d = %d", i, num[i]);
  }

  for (i = 0; i < n; i++) {
    Push(num[i]);
  }
  for (i = 0; i < n; i++) {
    val = Pop();
    num[i] = val;
  }

  printf("\n\nREVERSED ARRAY :");
  for (i = 0; i < n; i++) {
    printf("\nValue at index %d = %d", i, num[i]);
  }
  return 0;
}

void Push(int value) {
  top++;
  stk[top] = value;
}

int Pop() {
  int val;
  if (top == -1) {
    return 0;
  } else {
    val = stk[top];
    stk[top--];
    return val;
  }
}