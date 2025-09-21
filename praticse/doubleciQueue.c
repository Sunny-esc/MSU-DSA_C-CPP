#include <stdio.h>
#define max 5

int queue[max];
int front = -1, rear = -1;

void Enqueue(int);
void Dequeue();
void Peek();
void Display();

int main()

    return 0;
}

void Enqueue(int value) {
  if ((rear + 1) % max == front) {
    printf("\nQUEUE OVERFLOW");
    return;
  }
  if (front == -1 && rear == -1) {
    front = rear = 0;
  } else {
    rear = (rear + 1) % max;
  }
  queue[rear] = value;
  printf("\nElement Added to C.Queue = %d", queue[rear]);
}

void Dequeue() {
  if (front == -1 && rear == -1) {
    printf("\nQUEUE UNDERFLOW");
    return;
  }

  printf("\nElement Removed from the C.Queue = %d", queue[front]);

  if (front == rear) {
    front = rear = -1;
  } else {
    front = (front + 1) % max;
  }
}

void Peek() {
  if (front == -1 && rear == -1) {
    printf("\nQUEUE UNDERFLOW");
  } else {
    printf("\nElement at the front of the C.Queue = %d", queue[front]);
  }
}

void Display() {
  int i;
  printf("\nQUEUE : \n");
  if (front == -1 && rear == -1) {
    printf("\nQUEUE UNDERFLOW");
    return;
  }
  for (i = front; i != rear; i = (i + 1) % max) {
    printf("%d  ", queue[i]);
  }
  printf("%d  ", queue[i]);
}