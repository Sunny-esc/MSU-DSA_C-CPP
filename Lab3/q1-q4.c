#include <stdio.h>
#include <stdlib.h> // Header File for malloc(),calloc(),realloc()

struct node // Structure for the nodes we create
{
    int data;
    struct node *next;
};

struct node *head = NULL;                     // Head pointer which indicates first node
struct node *CreateNode(int value);           // function to create a new node, NOTE : this func. won't be called directly by the users but by the other functions
void InsertAtBeg(int value);                  // function to insert a new node at the beginning of the LL
void InsertAtEnd(int value);                  // function to insert a new node at the end of the LL
void InsertAfterNode(int value, int after);   // function to insert a new node after a given node in the LL
void InsertBeforeNode(int value, int before); // function to insert a new node before a given node in the LL
void DeleteFromBeg();                         // function to delete a node from the beginning of the LL
void DeleteFromEnd();                         // function to delete a node from the end of the LL
void Display();                               // function to display the created LL

int main()
{
    int choice = 0, value, after, before;
    while (choice != 8)
    {
        printf("\n\n************ MAIN MENU (C) ************");
        printf("\n1 : Add a node at Beginning");
        printf("\n2 : Add a node at the End");
        printf("\n3 : Add a node after a Node");
        printf("\n4 : Add a node before a node");
        printf("\n5 : Delete a node from the Beginning");
        printf("\n6 : Delete a node from the End");
        printf("\n7 : Display the Linked List");
        printf("\n8 : END the Operation !!!");
        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // calling InsertAtBeg(value) function to add a node in the Beginning of the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            InsertAtBeg(value);
            printf("\nNode Added at the beginning.");
            break;

        case 2: // calling InsertAtEnd(value) function to add a node in the End of the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            InsertAtEnd(value);
            printf("\nNode Added at the end.");
            break;

        case 3: // calling InsertAfterNode(value,after) function to add a node after a node in the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            printf("Enter the Value of node coming before the new node : ");
            scanf("%d", &after);
            InsertAfterNode(value, after);
            printf("\nNode Added after the Node having value %d.", after);
            break;

        case 4: // calling InsertBeforeNode(value,before) function to add a node before a node in the LL
            printf("Enter Value to Add : ");
            scanf("%d", &value);
            printf("Enter the Value of node coming after the new node : ");
            scanf("%d", &before);
            InsertBeforeNode(value, before);
            printf("\nNode Added before the Node having value %d.", before);
            break;

        case 5: // calling DeleteFromBeg() function to delete a node from the Beginning of the LL
            DeleteFromBeg();
            printf("\nNode Deleted from the Beginning.");
            break;

        case 6: // calling DeleteFromEnd() function to delete a node from the End of the LL
            DeleteFromEnd();
            printf("\nNode Deleted from the End.");
            break;

        case 7: // calling Display() function to Display the created LL
            printf("\nLinked List: ");
            Display();
            break;

        case 8: // exiting from the program
            printf("\nExit !!!");
            break;

        default:
            printf("\nInvalid option. Try again.");
            break;
        }
    }
    return 0;
}

struct node *CreateNode(int value) // Creating a new node NOTE : this function won't be called directly by the user
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertAtBeg(int value) // Inserting at beginning
{
    struct node *new_node = CreateNode(value);
    new_node->next = head;
    head = new_node;
}

void InsertAtEnd(int value) // Inserting at end
{
    struct node *new_node = CreateNode(value);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void InsertAfterNode(int value, int after) // inserting after a node
{
    struct node *new_node = CreateNode(value);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr != NULL && ptr->data != after)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void InsertBeforeNode(int value, int before) // inserting before a node
{
    struct node *new_node = CreateNode(value);
    if (head == NULL)
    {
        head = new_node;
    }
    else if (head->data == before)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL && ptr->next->data != before)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void DeleteFromBeg() // Deleting from the Beginning
{
    if (head == NULL)
    {
        printf("\nEmpty List !!!");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}

void DeleteFromEnd() // Deleting from the End
{
    if (head == NULL)
    {
        printf("\nEmpty List !!!");
        return;
    }
    struct node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void Display() // Displaying the list
{
    int count = 0; // counting total nodes
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        count++; // increasing count by one
        ptr = ptr->next;
    }
    printf("END\n");
    printf("Total number of nodes : %d", count);
}
