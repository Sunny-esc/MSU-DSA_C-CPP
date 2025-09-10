#include <iostream>
#include <stack>
#include <string>
using namespace std;

class ParenthesisCheck {
public:
  stack<char> stk;
  bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')' || open == '{' && close == '}' ||
            open == '[' && close == ']');
  }

  bool isBalanced(const string &expr) {
    for (char c : expr) {
      if (c == '(' || c == '[' || c == '{') {
        stk.push(c);
      } else if (c == ')' || c == '}' || c == ']') {
        if (stk.empty())
          return false;
        char open = stk.top();
        stk.pop();
        if (!isMatchingPair(open, c))
          return false;
      }
    }
    return stk.empty();
  }
};

int main() {
  ParenthesisCheck checker;
  string expr;

  cout << "enter the expression : ";
  cin >> expr;

  if (checker.isBalanced(expr)) {
    cout << "balanced parenthesis" << endl;
  } else {
    cout << "unbalanced parenthesis" << endl;
  }
  return 0;
}