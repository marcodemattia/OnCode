#include <iostream>
#include <stack>

using namespace std;

/**
 * Use a stack to keep track of the sequence of open parentheses. When a closed parenthesis is
 * found check the top of the stack. If it matches remove it (pop), if it does not match return
 * false. If the stack at the end is not empty return false. Careful to the case of the first
 * parenthesis being a closed one, without a special protection the stack will try to access
 * an empty "top()" and crash.
 */

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
      if (c=='(' || c=='[' || c=='{') {
        st.push(c);
      }
      else {
        if (st.size() == 0) return false;
        else if ((st.top() == '(' && c == ')') ||
                 (st.top() == '[' && c == ']') ||
                 (st.top() == '{' && c == '}')) st.pop();
        else return false;
      }
    }
    if (st.size() > 0 ) return false;
    return true;
  }
};

int main()
{
  Solution a;
  string s("()[]{}");
  // string s("([)]");
  // string s("[");

  if (a.isValid(s)) std::cout << "true" << std::endl;
  else std::cout << "false" << std::endl;
  
  return 0;
}