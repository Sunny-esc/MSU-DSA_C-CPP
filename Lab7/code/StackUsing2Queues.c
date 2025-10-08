#include <stdio.h>
#include <stdlib.h>

#define max 100

int q1[max], q2[max];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void Enqueue1(int);
int Dequeue1();
void Enqueue2(int);
int Dequeue2();

void PushCostly(int);
void PopCostly();
void PushCheap(int);
void PopCheap();
void Display();
void ResetStack();

int main()
{
    int choice = 1, value, op;

    while (choice != 0)
    {
        printf("\n\n***** MAIN MENU || STACK using 2 QUEUES || (C) *****");
        printf("\n1. Use Push-Costly Method");
        printf("\n2. Use Pop-Costly Method");
        printf("\n0. Exit from Program");
        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        ResetStack();

        switch (choice)
        {
        case 1:
            op = 1;
            while (op != 0)
            {
                printf("\n\n--- Push-Costly Menu ---");
                printf("\n1. Push Element");
                printf("\n2. Pop Element");
                printf("\n3. Display Stack");
                printf("\n0. Back to Main Menu");
                printf("\n\nEnter your operation : ");
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    printf("\nEnter Value to Push : ");
                    scanf("%d", &value);
                    PushCostly(value);
                    break;
                case 2:
                    PopCostly();
                    break;
                case 3:
                    Display();
                    break;
                case 0:
                    printf("\nReturning to main menu...");
                    break;
                default:
                    printf("\nInvalid Operation !!");
                    break;
                }
            }
            break;

        case 2:
            op = 1;
            while (op != 0)
            {
                printf("\n\n--- Pop-Costly Menu ---");
                printf("\n1. Push Element");
                printf("\n2. Pop Element");
                printf("\n3. Display Stack");
                printf("\n0. Back to Main Menu");
                printf("\n\nEnter your operation : ");
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    printf("\nEnter Value to Push : ");
                    scanf("%d", &value);
                    PushCheap(value);
                    break;
                case 2:
                    PopCheap();
                    break;
                case 3:
                    Display();
                    break;
                case 0:
                    printf("\nReturning to main menu...");
                    break;
                default:
                    printf("\nInvalid Operation !!");
                    break;
                }
            }
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

void Enqueue1(int value)
{
    if ((rear1 + 1) % max == front1)
    {
        printf("\nQUEUE 1 OVERFLOW");
        return;
    }
    if (front1 == -1)
    {
        front1 = rear1 = 0;
    }
    else
    {
        rear1 = (rear1 + 1) % max;
    }
    q1[rear1] = value;
}

int Dequeue1()
{
    if (front1 == -1)
    {
        return -1;
    }
    int item = q1[front1];
    if (front1 == rear1)
    {
        front1 = rear1 = -1;
    }
    else
    {
        front1 = (front1 + 1) % max;
    }
    return item;
}

void Enqueue2(int value)
{
    if ((rear2 + 1) % max == front2)
    {
        printf("\nQUEUE 2 OVERFLOW");
        return;
    }
    if (front2 == -1)
    {
        front2 = rear2 = 0;
    }
    else
    {
        rear2 = (rear2 + 1) % max;
    }
    q2[rear2] = value;
}

int Dequeue2()
{
    if (front2 == -1)
    {
        return -1;
    }
    int item = q2[front2];
    if (front2 == rear2)
    {
        front2 = rear2 = -1;
    }
    else
    {
        front2 = (front2 + 1) % max;
    }
    return item;
}

void PushCostly(int value)
{
    Enqueue2(value);
    while (front1 != -1)
    {
        Enqueue2(Dequeue1());
    }

    while (front2 != -1)
    {
        Enqueue1(Dequeue2());
    }
    printf("\nElement %d Pushed to Stack", value);
}

void PopCostly()
{
    if (front1 == -1)
    {
        printf("\nSTACK UNDERFLOW");
        return;
    }
    printf("\nElement %d Popped from Stack", Dequeue1());
}

void PushCheap(int value)
{
    Enqueue1(value);
    printf("\nElement %d Pushed to Stack", value);
}

void PopCheap()
{
    if (front1 == -1)
    {
        printf("\nSTACK UNDERFLOW");
        return;
    }

    while (front1 != rear1)
    {
        Enqueue2(Dequeue1());
    }

    int item = Dequeue1();

    while (front2 != -1)
    {
        Enqueue1(Dequeue2());
    }
    printf("\nElement %d Popped from Stack", item);
}

void Display()
{
    if (front1 == -1)
    {
        printf("\nSTACK IS EMPTY");
        return;
    }
    printf("\nSTACK (Top to Bottom):\n");
    for (int i = front1; i != rear1; i = (i + 1) % max)
    {
        printf("%d\n", q1[i]);
    }
    printf("%d\n", q1[rear1]);
}

void ResetStack()
{
    front1 = rear1 = -1;
    front2 = rear2 = -1;
}
