// • Implement a queue using singly linked list.
// • Understand dynamic memory allocation and pointer management.

// Tasks:
// 1. Create a node structure with data and next.
// 2. Implement enqueue at the rear.
// 3. Implement dequeue at the front.
// 4. Implement peek operation.
// 5. Display queue elements.
// Expected Outcome:
// • Queue size can grow dynamically.
// • Students will understand difference between array-based and linked-list
// queue.
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct node {
  int data;
  struct node *next;
};

struct queue {
  struct node *front;
  struct node *rear;
};
struct queue *q;
void createqueue();
int enqueue(int data);
void dequeue();
void Peek();
void Display();

int main() {
  createqueue();

  enqueue(24);
  enqueue(2);
  enqueue(5);
  enqueue(2);
  enqueue(4);
  dequeue();
  Peek();
  Display();
  return 0;
}

// check overflow
// check underflow

void createqueue() {
  q = (struct queue *)malloc(sizeof(struct node));
  q->front = NULL;
  q->rear = NULL;
}
// enqueue opp
int enqueue(int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  if (q->front == NULL) {
    q->front = ptr;
    q->rear = ptr;
    q->front->next = q->rear->next = NULL;
  } else {
    q->rear->next = ptr;
    q->rear = ptr;
    q->rear->next = NULL;
  }
  printf("Element added to the Queue");
}

// dequeue
void dequeue() {
  struct node *ptr = q->front;
  if (q->front == NULL) {
    printf("\nQUEUE UNDERFLOW");
  } else {
    q->front = q->front->next;
    printf("Element removed from the Queue");
    free(ptr);
  }
}

void Peek() {
  if (q->front == NULL) {
    printf("\nQUEUE UNDERFLOW");
  } else {
    printf("\nElement at front of the Queue = %d", q->front->data);
  }
}

void Display() {
  struct node *ptr = q->front;
  if (ptr == NULL) {
    printf("\nQUEUE UNDERFLOW");
  } else {
    printf("\nQUEUE : \n");
    while (ptr != q->rear) {
      printf("%d <- ", ptr->data);
      ptr = ptr->next;
    }
    printf("%d  ", ptr->data);
  }
}
