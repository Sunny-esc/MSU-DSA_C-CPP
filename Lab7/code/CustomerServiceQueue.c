#include <stdio.h>
#define max 100

int service_queue[max];

int vip_front = -1, vip_rear = -1;
int normal_front = max, normal_rear = max;

void AddVipCustomer(int);
void AddNormalCustomer(int);
void ServeNextCustomer();
void DisplayQueues();

int main()
{
    int choice = 0, ticket_no = 1;

    while (choice != 4)
    {
        printf("\n\n***** CUSTOMER SERVICE QUEUE || (C) *****");
        printf("\n1. Add VIP Customer");
        printf("\n2. Add Normal Customer");
        printf("\n3. Serve Next Customer");
        printf("\n4. Exit from Program");
        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AddVipCustomer(ticket_no++);
            break;
        case 2:
            AddNormalCustomer(ticket_no++);
            break;
        case 3:
            ServeNextCustomer();
            break;
        case 4:
            printf("\nClosing service for the day !!");
            break;
        default:
            printf("\nInvalid Choice !!\nTry again !!");
            break;
        }
        DisplayQueues();
    }
    return 0;
}

void AddVipCustomer(int ticket)
{
    if (vip_rear == normal_rear - 1)
    {
        printf("\nQUEUE OVERFLOW: Cannot add more customers.");
        return;
    }
    if (vip_front == -1)
    {
        vip_front = vip_rear = 0;
    }
    else
    {
        vip_rear++;
    }
    service_queue[vip_rear] = ticket;
    printf("\nVIP Customer with Ticket #%d has been added.", ticket);
}

void AddNormalCustomer(int ticket)
{
    if (normal_rear == vip_rear + 1)
    {
        printf("\nQUEUE OVERFLOW: Cannot add more customers.");
        return;
    }
    if (normal_front == max)
    {
        normal_front = normal_rear = max - 1;
    }
    else
    {
        normal_rear--;
    }
    service_queue[normal_rear] = ticket;
    printf("\nNormal Customer with Ticket #%d has been added.", ticket);
}

void ServeNextCustomer()
{
    if (vip_front != -1)
    {
        printf("\nServing VIP Customer with Ticket #%d.", service_queue[vip_front]);
        if (vip_front == vip_rear)
        {
            vip_front = vip_rear = -1;
        }
        else
        {
            vip_front++;
        }
    }
    else if (normal_front != max)
    {
        printf("\nServing Normal Customer with Ticket #%d.", service_queue[normal_front]);
        if (normal_front == normal_rear)
        {
            normal_front = normal_rear = max;
        }
        else
        {
            normal_front--;
        }
    }
    else
    {
        printf("\nUNDERFLOW: No customers are waiting to be served.");
    }
}

void DisplayQueues()
{
    int i;
    printf("\n\n--- Current Waiting Customers ---");

    if (vip_front == -1)
    {
        printf("\nVIP Queue: [EMPTY]");
    }
    else
    {
        printf("\nVIP Queue (Front to Rear): ");
        for (i = vip_front; i <= vip_rear; i++)
        {
            printf("%d  ", service_queue[i]);
        }
    }

    if (normal_front == max)
    {
        printf("\nNormal Queue: [EMPTY]");
    }
    else
    {
        printf("\nNormal Queue (Front to Rear): ");
        for (i = normal_front; i >= normal_rear; i--)
        {
            printf("%d  ", service_queue[i]);
        }
    }
    printf("\n---------------------------------");
}