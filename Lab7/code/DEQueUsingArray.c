#include <stdio.h>
#define max 100
int deque[max];
int front = -1, rear = -1;

void EnqueueFront(int);
void DequeueFront();
void PeekFront();

void EnqueueRear(int);
void DequeueRear();
void PeekRear();

void Display();

int main()
{
    int choice = 1, value;

    while (choice != 0)
    {
        printf("\n\n***** MAIN MENU || DE-QUEUE(array) || (C) *****");

        printf("\n1. Insert an Element at Front");
        printf("\n2. Delete an Element from Front");
        printf("\n3. Peek at Front in the Queue");

        printf("\n4. Insert an Element at Rear");
        printf("\n5. Delete an Element from Rear");
        printf("\n6. Peek at Rear in the Queue");

        printf("\n7. Display the Queue");
        printf("\n0. Exit from Program");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Value to Insert : ");
            scanf("%d", &value);
            EnqueueFront(value);
            break;

        case 2:
            DequeueFront();
            break;

        case 3:
            PeekFront();
            break;

        case 4:
            printf("\nEnter Value to Insert : ");
            scanf("%d", &value);
            EnqueueRear(value);
            break;

        case 5:
            DequeueRear();
            break;

        case 6:
            PeekRear();
            break;

        case 7:
            Display();
            break;

        case 0:
            printf("\nExiting from the Program !!");
            break;

        default:
            printf("\nInvalid Choice !! Try again !!");
            break;
        }
    }
    return 0;
}

void EnqueueFront(int value)
{
    if ((rear + 1) % max == front)
    {
        printf("\nDEQUE OVERFLOW");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        front = (front + max - 1) % max;
    }
    deque[front] = value;
    printf("\nElement Added in DE.Queue = %d", deque[front]);
}

void DequeueFront()
{
    if (front == -1 && rear == -1)
    {
        printf("\nDEQUE UNDERFLOW");
        return;
    }
    printf("\nElement Removed from the DE.Queue = %d", deque[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

void PeekFront()
{
    if (front == -1 && rear == -1)
    {
        printf("\nDEQUE UNDERFLOW");
    }
    else
    {
        printf("\nElement at the front of the DE.Queue = %d", deque[front]);
    }
}

void EnqueueRear(int value)
{
    if ((rear + 1) % max == front)
    {
        printf("\nDEQUE OVERFLOW");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % max;
    }
    deque[rear] = value;
    printf("\nElement Added in DE.Queue = %d", deque[rear]);
}

void DequeueRear()
{
    if (front == -1 && rear == -1)
    {
        printf("\nDEQUE UNDERFLOW");
        return;
    }
    printf("\nElement Removed from the DE.Queue = %d", deque[rear]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear + max - 1) % max;
    }
}

void PeekRear()
{
    if (front == -1 && rear == -1)
    {
        printf("\nDEQUE UNDERFLOW");
    }
    else
    {
        printf("\nElement at the Rear of the DE.Queue = %d", deque[rear]);
    }
}

void Display()
{
    int i;
    printf("\nDEQUE : \n");
    if (front == -1 && rear == -1)
    {
        printf("\nDEQUE UNDERFLOW");
        return;
    }
    for (i = front; i != rear; i = (i + 1) % max)
    {
        printf("%d  ", deque[i]);
    }
    printf("%d  ", deque[i]);
}