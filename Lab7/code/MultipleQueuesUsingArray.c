#include <stdio.h>
#define max 100

int queue[max];
int front1 = -1, rear1 = -1;
int front2 = max, rear2 = max;

void Enqueue1(int);
void Dequeue1();
void Display1();

void Enqueue2(int);
void Dequeue2();
void Display2();

int main()
{
    int choice = 0, value, op;

    while (choice != 3)
    {
        printf("\n\n***** MAIN MENU || MULTIPLE QUEUES in Array || (C) *****");
        printf("\n1. Operations for Queue 1");
        printf("\n2. Operations for Queue 2");
        printf("\n3. Exit from Program");
        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            op = 0;
            while (op != 4)
            {
                printf("\n\n--- Menu for Queue 1 ---");
                printf("\n1. Enqueue Element");
                printf("\n2. Dequeue Element");
                printf("\n3. Display Queue 1");
                printf("\n4. Back to Main Menu");
                printf("\n\nEnter your operation : ");
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    printf("\nEnter Value to Enqueue : ");
                    scanf("%d", &value);
                    Enqueue1(value);
                    break;
                case 2:
                    Dequeue1();
                    break;
                case 3:
                    Display1();
                    break;
                case 4:
                    printf("\nReturning to main menu...");
                    break;
                default:
                    printf("\nInvalid Operation !!");
                    break;
                }
            }
            break;

        case 2:
            op = 0;
            while (op != 4)
            {
                printf("\n\n--- Menu for Queue 2 ---");
                printf("\n1. Enqueue Element");
                printf("\n2. Dequeue Element");
                printf("\n3. Display Queue 2");
                printf("\n4. Back to Main Menu");
                printf("\n\nEnter your operation : ");
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    printf("\nEnter Value to Enqueue : ");
                    scanf("%d", &value);
                    Enqueue2(value);
                    break;
                case 2:
                    Dequeue2();
                    break;
                case 3:
                    Display2();
                    break;
                case 4:
                    printf("\nReturning to main menu...");
                    break;
                default:
                    printf("\nInvalid Operation !!");
                    break;
                }
            }
            break;

        case 3:
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
    if (rear1 == rear2 - 1)
    {
        printf("\nQUEUE OVERFLOW");
        return;
    }
    if (front1 == -1)
    {
        front1 = rear1 = 0;
    }
    else
    {
        rear1++;
    }
    queue[rear1] = value;
    printf("\nElement %d added to Queue 1", value);
}

void Dequeue1()
{
    if (front1 == -1)
    {
        printf("\nQUEUE 1 UNDERFLOW");
        return;
    }
    printf("\nElement %d removed from Queue 1", queue[front1]);
    if (front1 == rear1)
    {
        front1 = rear1 = -1;
    }
    else
    {
        front1++;
    }
}

void Display1()
{
    if (front1 == -1)
    {
        printf("\nQUEUE 1 IS EMPTY");
        return;
    }
    printf("\nQueue 1 (Front to Rear): ");
    for (int i = front1; i <= rear1; i++)
    {
        printf("%d  ", queue[i]);
    }
}

void Enqueue2(int value)
{
    if (rear2 == rear1 + 1)
    {
        printf("\nQUEUE OVERFLOW");
        return;
    }
    if (front2 == max)
    {
        front2 = rear2 = max - 1;
    }
    else
    {
        rear2--;
    }
    queue[rear2] = value;
    printf("\nElement %d added to Queue 2", value);
}

void Dequeue2()
{
    if (front2 == max)
    {
        printf("\nQUEUE 2 UNDERFLOW");
        return;
    }
    printf("\nElement %d removed from Queue 2", queue[front2]);
    if (front2 == rear2)
    {
        front2 = rear2 = max;
    }
    else
    {
        front2--;
    }
}

void Display2()
{
    if (front2 == max)
    {
        printf("\nQUEUE 2 IS EMPTY");
        return;
    }
    printf("\nQueue 2 (Front to Rear): ");
    for (int i = front2; i >= rear2; i--)
    {
        printf("%d  ", queue[i]);
    }
}