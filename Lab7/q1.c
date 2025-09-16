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
struct Queue {
  int queue[MAX];
  int front;
  int rear;
};

void init(struct Queue *q);
int enqueue(struct Queue *q, int data);
void dequeue(struct Queue *q);
void peek();
void display();
_Bool isEmpty(struct Queue *q);
int main() {}

void init(struct Queue *q) {
  q->front = -1;
  q->rear = 0;
}
// check overflow
_Bool isFull(struct Queue *q) { return (q->rear == MAX); }
// check underflow
_Bool isEmpty(struct Queue *q) { return (q->front == q->rear - 1); }
// enqueue opp
int enqueue(struct Queue *q, int data) {
  if (isFull(q)) {
    printf("Queue is full");
  }
  q->queue[q->rear] = data;
  q->rear++;
  return 0;
};

// dequeue
void dequeue(struct Queue *q) {
  isEmpty(q) ? printf("empty queue") : q->front++;
}
// peek

// display
