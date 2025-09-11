#include <stdio.h>
#include <stdlib.h> // Header File for malloc(),calloc(),realloc()

struct node // Structure for the nodes we create
{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL; // Head pointer which indicates first node
struct node *tail = NULL; // Tail pointer which indicates last node

struct node *CreateNode(
    int value); // function to create a new node, NOTE : this func. won't be
                // called directly by the users but by the other functions

void InsertAtBeg(
    int value); // function to insert a new node at the beginning of the LL
void InsertAtEnd(
    int value); // function to insert a new node at the end of the LL
void InsertAfterNode(
    int value,
    int after); // function to insert a new node after a given node in the LL
void InsertBeforeNode(
    int value,
    int before); // function to insert a new node before a given node in the LL
void InsertAtPos(
    int value,
    int pos); // function to insert a new node at given position in the LL

void DeleteFromBeg(); // function to delete a node from the beginning of the LL
void DeleteFromEnd(); // function to delete a node from the end of the LL
void DeleteAtPos(int pos); // function to delete a node by its position

void Search(int value); // function to Search an element in the LL
void Display();         // function to display the created LL
void DisplayReverse();  // function to display the created LL in reverse order

int main() {
  int choice = 0, value, key;
  while (choice != 12) {
    printf("\n\n************ MAIN MENU | DOUBLY LL | (C) ************");

    printf("\n1 : Add a node at Beginning");
    printf("\n2 : Add a node at the End");
    printf("\n3 : Add a node after a Node");
    printf("\n4 : Add a node before a node");
    printf("\n5 : Add a node by position");

    printf("\n6 : Delete a node from the Beginning");
    printf("\n7 : Delete a node from the End");
    printf("\n8 : Delete a node by its position");

    printf("\n9 : Search for an element");
    printf("\n10: Display the Linked List");
    printf("\n11: Display the Linked List in reverse order");
    printf("\n12: END the Operation !!!");

    printf("\n\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: // calling InsertAtBeg(value) function to add a node in the
            // Beginning of the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      InsertAtBeg(value);
      break;

    case 2: // calling InsertAtEnd(value) function to add a node in the End of
            // the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      InsertAtEnd(value);
      break;

    case 3: // calling InsertAfterNode(value,after) function to add a node after
            // a node in the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      printf("Enter the Value of node coming before the new node : ");
      scanf("%d", &key);
      InsertAfterNode(value, key);
      break;

    case 4: // calling InsertBeforeNode(value,before) function to add a node
            // before a node in the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      printf("Enter the Value of node coming after the new node : ");
      scanf("%d", &key);
      InsertBeforeNode(value, key);
      break;

    case 5:
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      printf("Enter postion at-which node is to be added : ");
      scanf("%d", &key);
      InsertAtPos(value, key);
      break;

    case 6: // calling DeleteFromBeg() function to delete a node from the
            // Beginning of the LL
      DeleteFromBeg();
      break;

    case 7: // calling DeleteFromEnd() function to delete a node from the End of
            // the LL
      DeleteFromEnd();
      break;

    case 8:
      printf("Enter pos of the node you want to delete : ");
      scanf("%d", &key);
      DeleteAtPos(key);
      break;

    case 9:
      printf("Enter Value to find in the LL : ");
      scanf("%d", &value);
      Search(value);
      break;

    case 10: // calling Display() function to Display the created LL
      printf("\nLinked List: ");
      Display();
      break;

    case 11: // calling DisplayReverse() function to Display the created LL in
             // reverse order
      printf("\nLinked List in reverse order : ");
      DisplayReverse();
      break;

    case 12: // exiting from the program
      printf("\nExit !!!");
      break;

    default:
      printf("\nInvalid option. Try again.");
      break;
    }
  }
  return 0;
}

struct node *CreateNode(int value) // Creating a new node NOTE : this function
                                   // won't be called directly by the user
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = value;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void InsertAtBeg(int value) // Inserting at beginning
{
  struct node *new_node = CreateNode(value);
  if (head == NULL) {
    head = new_node;
    tail = new_node;
    return;
  }
  new_node->next = head;
  head->prev = new_node;
  head = new_node;

  printf("\nNode Added at the beginning.");
}

void InsertAtEnd(int value) // Inserting at end
{
  struct node *new_node = CreateNode(value);

  if (head == NULL) {
    head = new_node;
    tail = new_node;
    return;
  }

  tail->next = new_node;
  new_node->prev = tail;
  tail = new_node;

  printf("\nNode Added at the end.");
}

void InsertAfterNode(int value, int after) {
  if (head == NULL) {
    InsertAtBeg(value);
    return;
  }

  struct node *ptr = head;
  while (ptr != NULL && ptr->data != after) {
    ptr = ptr->next;
  }

  if (ptr == NULL) {
    printf("Node with value %d not found.\n", after);
    return;
  }

  struct node *new_node = CreateNode(value);
  new_node->next = ptr->next;
  new_node->prev = ptr;

  if (ptr->next != NULL) {
    ptr->next->prev = new_node;
  } else {
    tail = new_node;
  }

  ptr->next = new_node;

  printf("\nNode Added after the Node having value %d.", after);
}

void InsertBeforeNode(int value, int before) {
  if (head->data == before) {
    InsertAtBeg(value);
    return;
  }

  struct node *ptr = head;
  while (ptr != NULL && ptr->data != before) {
    ptr = ptr->next;
  }

  if (ptr == NULL) {
    printf("Node with value %d not found.\n", before);
    return;
  }

  struct node *new_node = CreateNode(value);
  new_node->next = ptr;
  new_node->prev = ptr->prev;

  if (ptr->prev != NULL) {
    ptr->prev->next = new_node;
  }
  ptr->prev = new_node;
  if (ptr->prev == NULL) {
    head = new_node;
  }

  printf("\nNode Added before the Node having value %d.", before);
}

void InsertAtPos(int value, int pos) {
  if (pos == 0) {
    InsertAtBeg(value);
    return;
  }
  struct node *new_node = CreateNode(value);
  struct node *ptr = head;
  for (int i = 0; i < pos - 2 && ptr != NULL; i++) {
    if (ptr == NULL) {
      printf("\nInvalid Position !!");
      return;
    }
    ptr = ptr->next;
  }
  new_node->next = ptr->next;
  new_node->prev = ptr;
  if (ptr->next != NULL) {
    ptr->next->prev = new_node;
  }
  ptr->next = new_node;
  printf("\nNew node Added at postion %d", pos);
}

void DeleteFromBeg() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  struct node *ptr = head;
  head = head->next;

  if (head != NULL) {
    head->prev = NULL;
  } else {
    tail = NULL;
  }

  free(ptr);

  printf("\nNode Deleted from the Beginning.");
}

void DeleteFromEnd() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  if (head->next == NULL) {
    free(head);
    head = NULL;
    tail = NULL;
  } else {
    struct node *ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(ptr);
  }

  printf("\nNode Deleted from the End.");
}

void DeleteAtPos(int pos) {
  if (head == NULL) {
    printf("List is Empty.\n");
    return;
  }
  if (pos == 0) {
    DeleteFromBeg();
    return;
  }
  struct node *ptr = head;
  for (int i = 0; i < pos - 1 && ptr != NULL; i++) {
    ptr = ptr->next;
  }
  if (ptr == NULL) {
    printf("\nInvalid Position.");
    return;
  }
  ptr->prev->next = ptr->next;
  if (ptr->next != NULL) {
    ptr->next->prev = ptr->prev;
  }
  free(ptr);
  printf("\nNode Deleted from position %d.", pos);
}

void Search(int value) {
  struct node *ptr = head;
  int pos = 1;
  while (ptr != NULL) {
    if (ptr->data == value) {
      printf("\nNode with Value %d found at position %d\n", ptr->data, pos);
      return;
    }
    ptr = ptr->next;
    pos++;
  }
  printf("\nNode with value %d not found in the LL !\n", value);
}

void Display() {
  struct node *ptr = head;
  int count = 0;
  if (ptr == NULL) {
    printf("List is empty.\n");
    return;
  }

  while (ptr != NULL) {
    printf("%d <-> ", ptr->data);
    ptr = ptr->next;
    count++;
  }
  printf("END\n");
  printf("Total nodes: %d\n", count);
}

void DisplayReverse() {
  struct node *ptr = tail;
  int count = 0;
  if (ptr == NULL) {
    printf("List is empty.\n");
    return;
  }

  while (ptr != NULL) {
    printf("%d <-> ", ptr->data);
    ptr = ptr->prev;
    count++;
  }
  printf("NULL\n");
  printf("Total nodes: %d\n", count);
}