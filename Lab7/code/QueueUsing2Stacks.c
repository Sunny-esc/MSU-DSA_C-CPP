#include <stdio.h>
#define max 20

int queue[max], front1 = -1, rear1 = -1, front2 = max, rear2 = max;

void InsertA(int);
int DeleteA();
void DisplayA();

void InsertB(int);
int DeleteB();
void DisplayB();

int main()
{
    int choice = 0, value, op1 = 0, op2 = 0;

    while (choice != 3) // Main loop
    {
        printf("\n\n****** MAIN MENU || QUEUE || (C) ******");
        printf("\n1. operations for 1st STACK-QUEUE");
        printf("\n2. operations for 2nd STACK-QUEUE");
        printf("\n3. exit from the program !");

        printf("\nEnter the Choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            op1 = 0; // Reset menu choice for queue 1
            while (op1 != 4)
            {
                printf("\n\n**** MENU || QUEUE 1 ****");
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display");
                printf("\n4. Exit to main menu");

                printf("\nEnter the operation :");
                scanf("%d", &op1);

                switch (op1)
                {
                case 1:
                    printf("\nEnter Value :");
                    scanf("%d", &value);
                    InsertA(value);
                    break;

                case 2:
                    DeleteA();
                    break;

                case 3:
                    DisplayA();
                    break;

                case 4:
                    printf("\nExiting to main menu...");
                    break;

                default:
                    printf("\nTRY AGAIN");
                    break;
                }
            }
            break;

        case 2:
            op2 = 0; // Reset menu choice for queue 2
            while (op2 != 4)
            {
                printf("\n\n**** MENU || QUEUE 2 ****");
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display");
                printf("\n4. Exit to main menu");

                printf("\nEnter the operation :");
                scanf("%d", &op2);

                switch (op2)
                {
                case 1:
                    printf("\nEnter Value :");
                    scanf("%d", &value);
                    InsertB(value);
                    break;

                case 2:
                    DeleteB();
                    break;

                case 3:
                    DisplayB();
                    break;

                case 4:
                    printf("\nExiting to main menu...");
                    break;

                default:
                    printf("\nTRY AGAIN");
                    break;
                }
            }
            break;

        case 3:
            printf("\nExiting from the Program !!\n");
            break;

        default:
            printf("\nInvalid choice, Enter again !!");
        }
    }
    return 0;
}

void InsertA(int value)
{
    if (rear1 == rear2 - 1)
    {
        printf("\nOVERFLOW");
        return;
    }
    if (rear1 == -1 && front1 == -1)
    {
        rear1 = front1 = 0;
        queue[rear1] = value;
    }
    else
    {
        queue[++rear1] = value;
    }
    printf("\nValue %d added to Queue 1", queue[rear1]);
}

int DeleteA()
{
    if (front1 == -1)
    {
        printf("\nUNDERFLOW");
        return -1;
    }
    printf("\nValue %d removed from Queue 1", queue[front1]);
    front1++;
    if (front1 > rear1)
    {
        front1 = rear1 = -1;
    }
    return 0;
}

void DisplayA()
{
    int i;
    if (front1 == -1)
    {
        printf("\nEMPTY QUEUE 1");
        return;
    }
    printf("\nQueue 1: ");
    for (i = front1; i <= rear1; i++)
    {
        printf("%d  ", queue[i]);
    }
}

void InsertB(int value)
{
    if (rear2 == rear1 + 1)
    {
        printf("\nOVERFLOW");
        return;
    }
    if (rear2 == max && front2 == max)
    {
        rear2 = front2 = max - 1;
        queue[rear2] = value;
    }
    else
    {
        queue[--rear2] = value;
    }
    printf("\nValue %d added to Queue 2", queue[rear2]);
}

int DeleteB()
{
    if (front2 == max)
    {
        printf("\nUNDERFLOW");
        return -1;
    }
    printf("\nValue %d removed from Queue 2", queue[front2]);
    front2--;
    if (front2 < rear2)
    {
        front2 = rear2 = max;
    }
    return 0;
}

void DisplayB()
{
    int i;
    if (front2 == max)
    {
        printf("\nEMPTY QUEUE 2");
        return;
    }
    printf("\nQueue 2: ");
    for (i = front2; i >= rear2; i--)
    {
        printf("%d  ", queue[i]);
    }
}
