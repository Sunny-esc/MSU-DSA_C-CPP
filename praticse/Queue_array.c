#include <stdio.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

int isFull() { return (rear == MAX - 1); }

int isEmpty() { return (front == -1 || front > rear); }

void enqueue(int val) {
  if (isFull()) {
    printf("\nQueue is FULL\n");
    return;
  }
  if (front == -1)
    front = 0;
  queue[++rear] = val;
  printf("\nInserted: %d", val);
}

void dequeue() {
  if (isEmpty()) {
    printf("\nQueue is EMPTY\n");
    return;
  }
  printf("\nDeleted: %d", queue[front]);
  front++;

  if (front > rear)
    front = rear = -1;
}

void peek() {
  if (isEmpty()) {
    printf("\nQueue is EMPTY\n");
  } else {
    printf("\nFront Element: %d", queue[front]);
  }
}

void display() {
  if (isEmpty()) {
    printf("\nQueue is EMPTY\n");
    return;
  }
  printf("\nQueue Elements: ");
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  display();
  peek();
  dequeue();
  display();
  return 0;
}
