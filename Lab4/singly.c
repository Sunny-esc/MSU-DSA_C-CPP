#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// declare struct about Node
struct Node {
  int data;
  struct Node *next;
};
struct Node *head = NULL;
struct Node *CreateNode(int value);
// function declaration

void insertAtbeg(int data);
void insertAtend(int data);

// insert at position
void insertAtbefore(int data, int before);
void insertAtafter(int data, int after);
void insertAtpos(int data, int position);

// delete list
void DeleteFromBeg();
void DeleteFromEnd();
void DeleteAfterNode(int after);
void DeleteByVal(int value);

// display list
void Search(int value);
void Display();

// main
int main() {
  // variable declare
  int choice = 0, value, key;
  while (choice != 12) {
    printf("\n\n************ MAIN MENU (C) ************");

    printf("\n1 : Add a Node at Beginning");
    printf("\n2 : Add a Node at the End");
    printf("\n3 : Add a Node after a Node");
    printf("\n4 : Add a Node before a Node");
    printf("\n5 : Add a Node at position");

    printf("\n6 : Delete a Node from the Beginning");
    printf("\n7 : Delete a Node from the End");
    printf("\n8 : Delete a Node after a Node");
    printf("\n9 : Delete a Node by value");

    printf("\n10: Search an element");
    printf("\n11: Display the Linked List");
    printf("\n12: END the Operation !!!");

    printf("\n\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: // calling insertAtBeg(value) function to add a Node in the
            // Beginning of the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      insertAtbeg(value);
      break;

    case 2: // calling insertAtEnd(value) function to add a Node in the End of
            // the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      insertAtend(value);
      break;

    case 3: // calling insertAfterNode(value,key) function to add a Node after a
            // Node in the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      printf("Enter the Value of Node coming before the new Node : ");
      scanf("%d", &key);
      insertAtafter(value, key);
      break;

    case 4: // calling insertBeforeNode(value,key) function to add a Node before
            // a Node in the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      printf("Enter the Value of Node coming after the new Node : ");
      scanf("%d", &key);
      insertAtbefore(value, key);
      break;

    case 5: // calling insertAtPos(value,key) function to add a Node on given
            // postion in the LL
      printf("Enter Value to Add : ");
      scanf("%d", &value);
      printf("Enter the postion at-which it is to be added : ");
      scanf("%d", &key);
      insertAtpos(value, key);
      break;

    case 6: // calling DeleteFromBeg() function to delete a Node from the
            // Beginning of the LL
      DeleteFromBeg();
      break;

    case 7: // calling DeleteFromEnd() function to delete a Node from the End of
            // the LL
      DeleteFromEnd();
      break;

    case 8: // calling DeleteAfterNode(key) function to delete a Node after a
            // given Node
      printf("Enter the value of Node coming before the Node : ");
      scanf("%d", &key);
      DeleteAfterNode(key);
      break;

    case 9: // calling DeleteByVal(value) function to delete a Node by its value
      printf("Enter the value of Node you want to delete : ");
      scanf("%d", &value);
      DeleteByVal(value);
      break;

    case 10: // calling Search(value) function to search for an element
      printf("Enter the value you want to search : ");
      scanf("%d", &value);
      Search(value);
      break;

    case 11: // calling Display() function to Display the LL
      Display();
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

// newNode
struct Node *CreateNode(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
};
// insert at beg
void insertAtbeg(int data) {
  struct Node *new_Node = CreateNode(data);
  new_Node->next = head;
  head = new_Node;
  printf("\nNode Added at the beginning.");
}
// insert at end
void insertAtend(int data) {
  if (head == NULL) {
    insertAtbeg(data);
    printf("\nNode Added at the beginning.");
    return;
  }
  struct Node *new_Node = CreateNode(data);
  struct Node *ptr = head;
  while (ptr != NULL) {
    ptr = ptr->next;
  };
  ptr->next = new_Node;
  printf("\nNode Added at the end.");
}

// insert at position
void insertAtbefore(int data, int before) {
  struct Node *new_Node = CreateNode(data);

  if (head == NULL) {
    insertAtbeg(data);
    return;
  } else if (head->data == before) {
    new_Node->next = head;
    head = new_Node;
  } else {
    struct Node *ptr = head;
    while (ptr->next != NULL && ptr->next->data != before) {
      ptr = ptr->next;
    }
    new_Node->next = ptr->next;
    ptr->next = new_Node;
    printf("\nNode Added before the Node having value %d.", before);
  }
}

void insertAtafter(int data, int after) {
  if (head == NULL) {
    insertAtbeg(data);
    return;
  }
  struct Node *new_Node = CreateNode(data);
  struct Node *ptr = head;
  while (ptr != NULL && ptr->data != after) {
    ptr = ptr->next;
  }
  new_Node->next = ptr->next;
  ptr->next = new_Node;
  printf("\nNode Added after the Node having value %d.", after);
}

void insertAtpos(int data, int position) {
  if (head == NULL && position == 0) {
    insertAtbeg(data);
    return;
  }
  struct Node *new_Node = CreateNode(data);
  struct Node *ptr = head;
  for (int i = 0; i < position; i++) {
    if (ptr == NULL) {
      printf("\nInvalid Position !!");
      return;
    }
    ptr = ptr->next;
  }
  new_Node->next = ptr->next;
  ptr->next = new_Node;
  printf("\nNode Added at position %d.", position);
}

// delete list
// function to delete a Node from the beginning of the LL
void DeleteFromBeg() {
  if (head == NULL) {
    printf("\nEmpty List !!!");
    return;
  }
  struct Node *ptr = head;
  head = head->next;
  free(ptr);
  printf("\nNode Deleted from the Beginning.");
};
// function to delete a Node from the end of the LL
void DeleteFromEnd() {
  if (head == NULL) {
    printf("\nEmpty List !!!");
    return;
  }
  struct Node *ptr = head;
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }
  free(ptr->next);
  ptr->next = NULL;
  printf("\nNode Deleted from the End.");
};
// function to delete a Node after a given Node in the LL
void DeleteAfterNode(int after) {
  struct Node *ptr = head;
  while (ptr != NULL && ptr->data != after) {
    ptr = ptr->next;
  }
  if (ptr == NULL || ptr->next == NULL) {
    printf("\nValue not found !!\nTry again !!!");
    return;
  }
  struct Node *temp = ptr->next;
  ptr->next = temp->next;
  free(temp);
  printf("\nNode deleted after the Node having value %d.", after);
};
void DeleteByVal(int value) {
  if (head == NULL) {
    printf("\nEmpty List !!!");
    return;
  }
  struct Node *ptr = head;
  while (ptr->next != NULL && ptr->next->data != value) {
    ptr = ptr->next;
  }
  if (ptr->next == NULL) {
    printf("\nNode with value %d not found in the LL !! ", value);
    return;
  }
  struct Node *temp = ptr->next;
  ptr->next = temp->next;
  free(temp);
  printf("\nNode with value %d deleted from the LL.", value);
};

// display list
void Search(int value) {
  struct Node *ptr = head;
  int pos = 1;
  while (ptr != NULL) {
    if (ptr->data == value) {
      printf("\n%d found at Node having position %d\n", ptr->data, pos);
      return;
    }
    ptr = ptr->next;
    pos++;
  }
  printf("\nNode with value %d not found in the LL !\n", value);
}; // function to Search an element from the LL
void Display() {
  int count = 0; // counting total Nodes
  struct Node *ptr = head;
  if (ptr == NULL) {
    printf("List is empty.\n");
    return;
  }
  printf("\nLinked List: ");
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    count++; // increasing count by one
    ptr = ptr->next;
  }
  printf("END\n");
  printf("Total number of Nodes : %d", count);
}; // function to display the LL
