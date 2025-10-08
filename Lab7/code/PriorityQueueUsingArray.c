#include <stdio.h>
#define max 100

struct element
{
    int value;
    int priority;
};

struct element pq[max];
int len = 0;

void Enqueue(int, int);
void Dequeue();
void Display();
int GetPriority();

int main()
{
    int choice = 1, value, priority;

    while (choice != 0)
    {
        printf("\n\n***** MAIN MENU || PRIORITY QUEUE(array) || (C) *****");
        printf("\n1. Insert an Element");
        printf("\n2. Delete an Element");
        printf("\n3. Display the Queue");
        printf("\n0. Exit from Program");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Value to Insert : ");
            scanf("%d", &value);
            printf("Enter Priority for Element : ");
            scanf("%d", &priority);
            Enqueue(value, priority);
            break;

        case 2:
            Dequeue();
            break;

        case 3:
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

void Enqueue(int value, int priority)
{
    if (len == max)
    {
        printf("\nPRIORITY QUEUE OVERFLOW");
        return;
    }
    pq[len].value = value;
    pq[len].priority = priority;
    len++;
    printf("Element Added to the Priority Queue");
}

int GetPriority()
{
    int h = 0;
    for (int i = 1; i < len; i++)
    {
        if (pq[i].priority > pq[h].priority)
        {
            h = i;
        }
    }
    return h;
}

void Dequeue()
{
    if (len == 0)
    {
        printf("\nPRIORITY QUEUE UNDERFLOW");
        return;
    }
    int high = GetPriority();
    printf("\nElement with Value: %d and Priority: %d REMOVED", pq[high].value, pq[high].priority);
    for (int i = high; i < len; i++)
    {
        pq[i] = pq[i + 1];
    }
    len--;
}

void Display()
{
    if (len == 0)
    {
        printf("\nPRIORITY QUEUE UNDERFLOW");
        return;
    }
    printf("PRIORITY QUEUE :\n");
    for (int i = 0; i < len; i++)
    {
        printf("Value : %d\t|| Priority : %d\n", pq[i].value, pq[i].priority);
    }
}