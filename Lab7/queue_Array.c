// Objectives:
// • Implement a simple linear queue.
// • Perform enqueue, dequeue, peek, isEmpty, and isFull operations.
// Tasks:
// 1. Define an array queue[MAX] and variables front and rear.
// 2. Implement enqueue operation with overflow check.
// 3. Implement dequeue operation with underflow check.
// 4. Implement peek/front operation.
// 5. Implement display function to show all elements.
// Expected Outcome:
// • Students will understand FIFO behavior and the limitations of linear queue
// (space wastage).
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

int isFull();
int isEmpty();

void Enqueue(int);
void Dequeue();
void Peek();
void Display();
int main() {
  Enqueue(34);
  Enqueue(24);
  Enqueue(4);
  Enqueue(14);

  Dequeue();
  Display();
}

int isFull() {
  return rear == MAX - 1; // evaluates to 1 (true) or 0 (false)
}
int isEmpty() { return (front == -1 || front > rear); }

void Enqueue(int data) {
  if (!isFull())               // conditinoing
    (front == -1 && rear == -1 // if queue is empty the ternary will true and
                               // add the data at rear
         ? (front = rear = 0, queue[rear] = data,
            printf("\nFirst Element Inserted in the Queue"))
         : (rear++, queue[rear] = data, // thhis is else statment
            printf("\nElement Inserted in the Queue")));
}

void Dequeue() {
  if (!isEmpty())
    (printf("Element with Value %d deleted from the Queue", queue[front]),
     front++, (front > rear ? (front = rear = -1) : 0));
  else
    printf("\nQUEUE UNDERFLOW");
}

void Display() {
  printf("\nQUEUE :\n");

  for (int i = front; i <= rear; i++) {
    printf("%d  ", queue[i]);
  }
}