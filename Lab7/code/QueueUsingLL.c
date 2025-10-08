#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *q;

void CreateQueue();
void Enqueue(int);
void Dequeue();
void Peek();
void Display();

int main()
{
    int choice = 1, value;
    CreateQueue();

    while (choice != 0)
    {
        printf("\n\n***** MAIN MENU || QUEUE(LL) || (C) *****");
        printf("\n1. Insert an Element");
        printf("\n2. Delete an Element");
        printf("\n3. Peek in the Queue");
        printf("\n4. Display the Queue");
        printf("\n0. Exit from Program");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Value to Insert : ");
            scanf("%d", &value);
            Enqueue(value);
            break;

        case 2:
            Dequeue();
            break;

        case 3:
            Peek();
            break;

        case 4:
            Display();
            break;

        case 0:
            printf("\nExiting from the Program !!");
            break;

        default:
            printf("\nInvalid Choice !!\nTry again !!");
            break;
        }
    }
    return 0;
}

void CreateQueue()
{
    q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
}

void Enqueue(int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
    printf("Element added to the Queue");
}

void Dequeue()
{
    struct node *ptr = q->front;
    if (q->front == NULL)
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        q->front = q->front->next;
        printf("Element removed from the Queue");
        free(ptr);
    }
}

void Peek()
{
    if (q->front == NULL)
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        printf("\nElement at front of the Queue = %d", q->front->data);
    }
}

void Display()
{
    struct node *ptr = q->front;
    if (ptr == NULL)
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        printf("\nQUEUE : \n");
        while (ptr != q->rear)
        {
            printf("%d <- ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d  ", ptr->data);
    }
}