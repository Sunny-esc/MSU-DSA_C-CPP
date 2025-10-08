// Implement stack operations using Linked List in C++ with classes and objects.
#include <cstdlib>
#include <iostream>
#include <ostream>
using namespace std;

class node {
public:
  node *next;
  int data;
  node(int val) {
    data = val;
    next = nullptr;
  }
};

class stack {
  node *top;

public:
  stack() { top = nullptr; }
  int push(int data);
  void pop();
  void display();
};

int stack::push(int data) {
  node *newnode = new node(data);
  ;

  newnode->data = data;
  if (top == NULL) {
    newnode->next = NULL;
  }
  newnode->next = top;
  top = newnode;
  cout << "insertation sucessful \n" << endl;
  return 0;
}

void stack::pop() {
  if (top == NULL) {
    cout << "the stack is empty" << endl;
    return;
  }
  struct node *temp = top;
  cout << "deleted :" << temp->data << endl;
  top = temp->next;
  delete temp;
}

void stack::display() {
  if (top == NULL) {
    cout << "the stack is empty \n" << endl;
    return;
  }
  struct node *temp = top;
  while (temp != NULL) {
    cout << temp->data << "->" << endl;
    temp = temp->next;
  }
  cout << "--->NULL" << endl;
}

int main() {
  stack s;
  s.push(12);
  s.push(13);
  s.push(14);
  s.push(15);
  s.pop();
  s.display();
}