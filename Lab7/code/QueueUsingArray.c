#include <stdio.h>
#define max 100

int queue[max];
int front = -1, rear = -1;

int isFull();
int isEmpty();

void Enqueue(int);
void Dequeue();
void Peek();
void Display();

int main()
{
    int choice = 1, value;

    while (choice != 0)
    {
        printf("\n\n***** MAIN MENU || QUEUE(array) || (C) *****");
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

int isFull()
{
    if (rear == max - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    return 0;
}

void Enqueue(int value)
{
    if (isFull())
    {
        printf("\nQUEUE OVERFLOW");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value;
        printf("\nFirst Element Inserted in the Queue");
    }
    else
    {
        rear++;
        queue[rear] = value;
        printf("\nElement Inserted in the Queue");
    }
}

void Dequeue()
{
    if (isEmpty())
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        printf("Element with Value %d deleted from the Queue", queue[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void Peek()
{
    if (isEmpty())
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else
    {
        printf("\nFirst Element of the Queue is : %d", queue[front]);
    }
}

void Display()
{
    printf("\nQUEUE :\n");
    if (isEmpty())
    {
        printf("\nEMPTY QUEUE");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d  ", queue[i]);
        }
    }
}