#include <iostream> // header file
using namespace std;

class Node // class for the node structure
{
public:
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList // class for the LL functions
{
private:
  Node *head; // head pointer

public:
  LinkedList() { head = nullptr; }

  ~LinkedList() // Free memory when program ends
  {
    Node *current = head;
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }

  void
  InsertAtBeg(int value) // function to add a node at the beginning of the LL
  {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "\nNode added at the beginning.";
  }

  void InsertAtEnd(int value) // function to add a node at the end of the LL
  {
    if (head == nullptr) {
      InsertAtBeg(value);
      return;
    }
    Node *newNode = new Node(value);
    Node *ptr = head;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = newNode;
    cout << "\nNode added at the end.";
  }

  void InsertAfterNode(
      int value,
      int after) // function to add a node after a given node in the LL
  {
    if (head == nullptr) {
      InsertAtBeg(value);
      return;
    }
    Node *ptr = head;
    while (ptr != nullptr && ptr->data != after) {
      ptr = ptr->next;
    }
    if (ptr == nullptr) {
      cout << "\nNode with value " << after << " not found!";
      return;
    }
    Node *newNode = new Node(value);
    newNode->next = ptr->next;
    ptr->next = newNode;
    cout << "\nNode added after " << after << ".";
  }

  void InsertBeforeNode(
      int value,
      int before) // function to add a node before a given node in the LL
  {
    if (head == nullptr) {
      InsertAtBeg(value);
      return;
    }
    if (head->data == before) {
      InsertAtBeg(value);
      return;
    }
    Node *ptr = head;
    while (ptr->next != nullptr && ptr->next->data != before) {
      ptr = ptr->next;
    }
    if (ptr->next == nullptr) {
      cout << "\nNode with value " << before << " not found!";
      return;
    }
    Node *newNode = new Node(value);
    newNode->next = ptr->next;
    ptr->next = newNode;
    cout << "\nNode added before " << before << ".";
  }

  void InsertAtPos(
      int value,
      int pos) // function to add a node at a specific position in the LL
  {
    if (pos <= 0) {
      cout << "\nInvalid position!";
      return;
    }
    if (pos == 1) {
      InsertAtBeg(value);
      return;
    }
    Node *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != nullptr; i++) {
      ptr = ptr->next;
    }
    if (ptr == nullptr) {
      cout << "\nInvalid position!";
      return;
    }
    Node *newNode = new Node(value);
    newNode->next = ptr->next;
    ptr->next = newNode;
    cout << "\nNode added at position " << pos << ".";
  }

  void DeleteFromBeg() // function to delete a node from the beginning of the LL
  {
    if (head == nullptr) {
      cout << "\nEmpty list!";
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "\nNode deleted from beginning.";
  }

  void DeleteFromEnd() // function to delete a node from the end of the LL
  {
    if (head == nullptr) {
      cout << "\nEmpty list!";
      return;
    }
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      cout << "\nNode deleted from end.";
      return;
    }
    Node *ptr = head;
    while (ptr->next->next != nullptr) {
      ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = nullptr;
    cout << "\nNode deleted from end.";
  }

  void DeleteAfterNode(
      int after) // function to delete a node after a given node in the LL
  {
    Node *ptr = head;
    while (ptr != nullptr && ptr->data != after) {
      ptr = ptr->next;
    }
    if (ptr == nullptr || ptr->next == nullptr) {
      cout << "\nValue not found or no node after " << after << ".";
      return;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    cout << "\nNode deleted after " << after << ".";
  }

  void DeleteByVal(int value) // function to delete a node by its value
  {
    if (head == nullptr) {
      cout << "\nEmpty list!";
      return;
    }
    if (head->data == value) {
      Node *temp = head;
      head = head->next;
      delete temp;
      cout << "\nNode with value " << value << " deleted.";
      return;
    }
    Node *ptr = head;
    while (ptr->next != nullptr && ptr->next->data != value) {
      ptr = ptr->next;
    }
    if (ptr->next == nullptr) {
      cout << "\nNode with value " << value << " not found!";
      return;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    cout << "\nNode with value " << value << " deleted.";
  }

  void Search(int value) // function to search a value in the LL
  {
    Node *ptr = head;
    int pos = 1;
    while (ptr != nullptr) {
      if (ptr->data == value) {
        cout << "\n" << value << " found at position " << pos << ".";
        return;
      }
      ptr = ptr->next;
      pos++;
    }
    cout << "\nNode with value " << value << " not found!";
  }

  void Display() // function to display all values in the LL
  {
    if (head == nullptr) {
      cout << "\nList is empty.";
      return;
    }
    Node *ptr = head;
    int count = 0;
    cout << "\nLinked List: ";
    while (ptr != nullptr) {
      cout << ptr->data << " -> ";
      ptr = ptr->next;
      count++;
    }
    cout << "END\n";
    cout << "Total number of nodes: " << count;
  }
};

int main() {
  LinkedList list;
  int choice = 0, value, key;

  while (choice != 12) {
    cout << "\n\n************ MAIN MENU (C++) ************";
    cout << "\n1 : Add a node at Beginning";
    cout << "\n2 : Add a node at the End";
    cout << "\n3 : Add a node after a Node";
    cout << "\n4 : Add a node before a Node";
    cout << "\n5 : Add a node at position";
    cout << "\n6 : Delete a node from the Beginning";
    cout << "\n7 : Delete a node from the End";
    cout << "\n8 : Delete a node after a Node";
    cout << "\n9 : Delete a node by Value";
    cout << "\n10: Search an element";
    cout << "\n11: Display the Linked List";
    cout << "\n12: END the Operation !!!";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter Value to Add: ";
      cin >> value;
      list.InsertAtBeg(value);
      break;

    case 2:
      cout << "Enter Value to Add: ";
      cin >> value;
      list.InsertAtEnd(value);
      break;

    case 3:
      cout << "Enter Value to Add: ";
      cin >> value;
      cout << "Enter the value of node after which to insert: ";
      cin >> key;
      list.InsertAfterNode(value, key);
      break;

    case 4:
      cout << "Enter Value to Add: ";
      cin >> value;
      cout << "Enter the value of node before which to insert: ";
      cin >> key;
      list.InsertBeforeNode(value, key);
      break;

    case 5:
      cout << "Enter Value to Add: ";
      cin >> value;
      cout << "Enter position: ";
      cin >> key;
      list.InsertAtPos(value, key);
      break;

    case 6:
      list.DeleteFromBeg();
      break;

    case 7:
      list.DeleteFromEnd();
      break;

    case 8:
      cout << "Enter value of node after which to delete: ";
      cin >> key;
      list.DeleteAfterNode(key);
      break;

    case 9:
      cout << "Enter value to delete: ";
      cin >> value;
      list.DeleteByVal(value);
      break;

    case 10:
      cout << "Enter value to search: ";
      cin >> value;
      list.Search(value);
      break;

    case 11:
      list.Display();
      break;

    case 12:
      cout << "\nExit !!!";
      break;

    default:
      cout << "\nInvalid option. Try again.";
    }
  }
  return 0;
}