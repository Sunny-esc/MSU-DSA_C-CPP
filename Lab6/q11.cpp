#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
  string str = "", rev = "";
  cout << "Enter a String : ";
  cin >> str;

  stack<char> stk;

  for (char c : str) {
    stk.push(c);
  }
  while (!stk.empty()) {
    rev += stk.top();
    stk.pop();
  }

  cout << "\nORIGINAL STRING : " << str;
  cout << "\nREVERSED STRING : " << rev;
  return 0;
}