#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node *CreateNode(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = n->prev = NULL;
    return n;
}

void InsertAtBeg(int val)
{
    struct node *n = CreateNode(val);
    if (!head)
    {
        head = n;
        n->next = n;
        n->prev = n;
    }
    else
    {
        struct node *tail = head->prev;
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
    }
    printf("\nInserted at beginning.");
}

void InsertAtEnd(int val)
{
    if (!head)
    {
        InsertAtBeg(val);
        return;
    }
    struct node *n = CreateNode(val);
    struct node *tail = head->prev;
    tail->next = n;
    n->prev = tail;
    n->next = head;
    head->prev = n;
    printf("\nInserted at end.");
}

void DeleteFromBeg()
{
    if (!head)
    {
        printf("\nEmpty.");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *tail = head->prev;
        struct node *temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
    printf("\nDeleted from beginning.");
}

void DeleteFromEnd()
{
    if (!head)
    {
        printf("\nEmpty.");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *tail = head->prev;
        struct node *newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        free(tail);
    }
    printf("\nDeleted from end.");
}

void DisplayForward()
{
    if (!head)
    {
        printf("\nEmpty.");
        return;
    }
    struct node *cur = head;
    printf("\nForward: ");
    do
    {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("(back)");
}

void DisplayBackward()
{
    if (!head)
    {
        printf("\nEmpty.");
        return;
    }
    struct node *tail = head->prev;
    struct node *cur = tail;
    printf("\nBackward: ");
    do
    {
        printf("%d <-> ", cur->data);
        cur = cur->prev;
    } while (cur != tail);
    printf("(back)");
}

int main()
{
    int ch = 0, v;
    while (ch != 0)
    {
        printf("\n\n1.InBeg \n2.InEnd \n3.DelBeg \n4.DelEnd \n5.DisplayF \n6.DisplayB \n0.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Val: ");
            scanf("%d", &v);
            InsertAtBeg(v);
            break;
        case 2:
            printf("Val: ");
            scanf("%d", &v);
            InsertAtEnd(v);
            break;
        case 3:
            DeleteFromBeg();
            break;
        case 4:
            DeleteFromEnd();
            break;
        case 5:
            DisplayForward();
            break;
        case 6:
            DisplayBackward();
            break;
        case 0:
            printf("\nExit.");
            break;
        default:
            printf("\nInvalid.");
        }
    }
    return 0;
}
