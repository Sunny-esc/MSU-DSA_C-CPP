#include <iostream>
using namespace std;


class Node {
public:
 int data; // Data in the node
 Node* next; // Pointer to next node
 // Constructor init to NULL
 Node(int val) {
 data = val;
 next = NULL;
 }
};

class LinkedList {
 Node* head; // Pointer to the head of the list
public:

LinkedList() { head = NULL; } // Constructor initializes

 void insertAtBeginning(int val);
 void insertAtEnd(int val);
 void deleteFromBeginning();
 void deleteFromEnd();
 void display();
};
// Insert at beginning of list
void LinkedList::insertAtBeginning(int val) {
 Node* newNode = new Node(val);
newNode->next = head;
 head = newNode;
}
// Insert at end of list
void LinkedList::insertAtEnd(int val) {
 Node* newNode = new Node(val);
 if (!head) {
 head = newNode;
 return;
 }
 Node* temp = head;
  while (temp->next != NULL) // traverse to end
 temp = temp->next;
 temp->next = newNode; // link last node to new node
}


// Delete first node
void LinkedList::deleteFromBeginning() {
 if (!head) {
 cout << "List is empty.\n";
 return;
 }
 Node* temp = head;
 head = head->next; // move head forward
 delete temp; // delete old head
 cout << "Deleted from beginning.\n";
}
// Delete last node
void LinkedList::deleteFromEnd() {
 if (!head) {
 cout << "List is empty.\n";
 return;
 }
 if (!head->next) {
        delete head;
 head = NULL;
 cout << "Deleted last node.\n";
 return;
 }
 Node* temp = head;
 while (temp->next->next != NULL) // go to second-last node
 temp = temp->next;
 delete temp->next; // delete last
 temp->next = NULL; // update second-last node's next
 cout << "Deleted from end.\n";
}

// Display the list
void LinkedList::display() {
 if (!head) {
 cout << "List is empty.\n";
 return;
 }
 Node* temp = head;
 cout << "List: ";
 while (temp) {
 cout << temp->data << " -> ";
 temp = temp->next;
 }
 cout << "NULL\n";
}

// Main function with menu
int main() {
 LinkedList list;
 int choice, value;
 while (true) {
 cout << "\n--- Singly Linked List Menu ---\n 1. Insert at Beginning\n 2. Insert at End\n";

 cout << "3. Delete from Beginning\n";
 cout << "4. Delete from End\n";
 cout << "5. Display\n";
 cout << "6. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 // Switch case for operations
 switch (choice) {
 case 1:
 cout << "Enter value to insert: ";
 cin >> value;
 list.insertAtBeginning(value);
 break;
 case 2:
 cout << "Enter value to insert: ";
 cin >> value;
 list.insertAtEnd(value);
 break;
 case 3:
 list.deleteFromBeginning();
 break;
 case 4:
 list.deleteFromEnd();
 break;
 case 5:
 list.display();
 break;
 case 6:
 return 0;
 default:
 cout << "Invalid choice!\n";
 }
 }
 return 0;
}
