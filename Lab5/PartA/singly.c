#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail = NULL;

struct node *CreateNode(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    return n;
}

void InsertAtBeg(int val)
{
    struct node *n = CreateNode(val);
    if (!tail)
    {
        tail = n;
        n->next = n;
    }
    else
    {
        n->next = tail->next;
        tail->next = n;
    }
    printf("\nInserted at beginning.");
}

void InsertAtEnd(int val)
{
    struct node *n = CreateNode(val);
    if (!tail)
    {
        tail = n;
        n->next = n;
    }
    else
    {
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
    printf("\nInserted at end.");
}

void InsertAfter(int val, int after)
{
    if (!tail)
    {
        InsertAtBeg(val);
        return;
    }
    struct node *cur = tail->next;
    do
    {
        if (cur->data == after)
        {
            struct node *n = CreateNode(val);
            n->next = cur->next;
            cur->next = n;
            if (cur == tail)
                tail = n;
            printf("\nInserted after %d.", after);
            return;
        }
        cur = cur->next;
    } while (cur != tail->next);
    printf("\nValue %d not found.", after);
}

void DeleteFromBeg()
{
    if (!tail)
    {
        printf("\nEmpty.");
        return;
    }
    struct node *head = tail->next;
    if (head == tail)
    {
        free(head);
        tail = NULL;
    }
    else
    {
        tail->next = head->next;
        free(head);
    }
    printf("\nDeleted from beginning.");
}

void DeleteFromEnd()
{
    if (!tail)
    {
        printf("\nEmpty.");
        return;
    }
    struct node *head = tail->next;
    if (head == tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        struct node *cur = head;
        while (cur->next != tail)
            cur = cur->next;
        cur->next = head;
        free(tail);
        tail = cur;
    }
    printf("\nDeleted from end.");
}

void Display()
{
    if (!tail)
    {
        printf("\nEmpty.");
        return;
    }
    struct node *cur = tail->next;
    printf("\nList: ");
    do
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != tail->next);
    printf("(back to head)");
}

int main()
{
    int ch = 0, v, key;
    while (ch != 0)
    {
        printf("\n\n1.InBeg \n2.InEnd \n3.InAfter \n4.DelBeg \n5.DelEnd \n6.Display \n0.Exit \nChoice : ");
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
            printf("Val: ");
            scanf("%d", &v);
            printf("After: ");
            scanf("%d", &key);
            InsertAfter(v, key);
            break;
        case 4:
            DeleteFromBeg();
            break;
        case 5:
            DeleteFromEnd();
            break;
        case 6:
            Display();
            break;
        case 0:
            printf("\nExit.");
            break;
        default:
            printf("\nInvalid Choice !!");
        }
    }
    return 0;
}
