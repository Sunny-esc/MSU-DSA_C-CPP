#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  int roll;
  char name[50];
  int mobile[10];
  char city[25];
  float hscmarks;
  struct student *next;
};

struct student *head = NULL;

struct student *CreateNode();
void InsertAtBeg();
void InsertAtEnd();
void DeleteFromBeg();
void DeleteFromEnd();
void CountRecords();
void SearchWithROLL();
void DisplayRecords();

int main() {
  int choice;

  while (choice != 0) {
    printf("\n\n********** MENU || STUDENTS RECORDS **********\n");
    printf("\n1 : Insert at Beginning");
    printf("\n2 : Insert at End");
    printf("\n3 : Delete from Beginning");
    printf("\n4 : Delete from End");
    printf("\n5 : Display Records");
    printf("\n6 : Count Total Records");
    printf("\n7 : Search by Roll No (PRN)");
    printf("\n0 : Exit");

    printf("\nEnter Your Choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      InsertAtBeg();
      break;

    case 2:
      InsertAtEnd();
      break;

    case 3:
      DeleteFromBeg();
      break;

    case 4:
      DeleteFromEnd();
      break;

    case 5:
      DisplayRecords();
      break;

    case 6:
      CountRecords();
      break;

    case 7:
      SearchWithROLL();
      break;

    case 0:
      printf("Exit from menu !\n");
      break;

    default:
      printf("Invalid choice! Try again.\n");
      break;
    }
  }
  return 0;
}

struct student *CreateNode() {
  struct student *NewNode = (struct student *)malloc(sizeof(struct student));
  if (!NewNode) {
    printf("Memory allocation Failure!!!\n");
    exit(1);
  }
  printf("Enter Roll No (PRN): ");
  scanf("%d", &NewNode->roll);
  printf("Enter Name: ");
  scanf(" %[^\n]", NewNode->name);
  printf("Enter Phone No: ");
  scanf(" %[^\n]", NewNode->mobile);
  printf("Enter City: ");
  scanf(" %[^\n]", NewNode->city);
  printf("Enter HSC Marks: ");
  scanf("%f", &NewNode->hscmarks);

  NewNode->next = NULL;
  return NewNode;
}

void InsertAtBeg() {
  struct student *NewNode = CreateNode();
  NewNode->next = head;
  head = NewNode;
  printf("\nRecord inserted at beginning.\n");
}

void InsertAtEnd() {
  struct student *NewNode = CreateNode();
  if (head == NULL) {
    head = NewNode;
  } else {
    struct student *temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = NewNode;
  }
  printf("\nRecord inserted at end.\n");
}

void DeleteFromBeg() {
  if (head == NULL) {
    printf("List is empty!!\n");
    return;
  }
  struct student *temp = head;
  head = head->next;
  printf("\nDeleted record of Roll No: %d\n", temp->roll);
  free(temp);
}

void DeleteFromEnd() {
  if (head == NULL) {
    printf("List is empty!!\n");
    return;
  }
  struct student *temp = head;
  if (head->next == NULL) {
    printf("\nDeleted record of Roll No: %d\n", head->roll);
    free(head);
    head = NULL;
    return;
  }
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  printf("Deleted record of Roll No: %d\n", temp->next->roll);
  free(temp->next);
  temp->next = NULL;
}

void CountRecords() {
  int count = 0;
  struct student *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  printf("\nTotal number of student records: %d\n", count);
}

void SearchWithROLL() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  int key;
  printf("Enter Roll No. to search : ");
  scanf("%d", &key);

  struct student *temp = head;
  while (temp != NULL) {
    if (temp->roll == key) {
      printf("Record Found:\n");
      printf("---------------------------------------\n");
      printf("Name   : %s\n", temp->name);
      printf("Phone  : %s\n", temp->mobile);
      printf("City   : %s\n", temp->city);
      printf("HSC Marks: %.2f\n", temp->hscmarks);
      printf("---------------------------------------\n");
      return;
    }
    temp = temp->next;
  }
  printf("No record found with Roll No: %d\n", key);
}

void DisplayRecords() {
  if (head == NULL) {
    printf("No records to display.\n");
    return;
  }
  struct student *temp = head;
  printf("\nStudent Records:\n");
  printf("---------------------------------------\n");
  while (temp != NULL) {
    printf("Roll No  : %d\n", temp->roll);
    printf("Name     : %s\n", temp->name);
    printf("Phone    : %s\n", temp->mobile);
    printf("City     : %s\n", temp->city);
    printf("HSC Marks: %.2f\n", temp->hscmarks);
    printf("---------------------------------------\n");
    temp = temp->next;
  }
}