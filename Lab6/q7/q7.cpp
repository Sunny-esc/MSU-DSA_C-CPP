// Write a program to demonstrate the use of the stack container in C++ STL by
// performing:

// o Push elements
// o Pop elements
// o Access top() element
// o Display size and empty status

#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> st;

  if (st.empty()) {
    cout << " At first Stack is empty " << endl;
  }

  if (!st.empty()) {
    cout << "Stack is not empty. Top element: " << st.top() << endl;
  }
  st.push(10);
  st.push(5);
  cout << "Pushed 10->5" << endl;
  // Accessing top element
  cout << "Top element: " << st.top() << endl;
  cout << "Size of stack:" << st.size() << endl;
  // Popping an element
  st.pop();
  cout << "Top element after pop: " << st.top() << endl;

  return 0;
}