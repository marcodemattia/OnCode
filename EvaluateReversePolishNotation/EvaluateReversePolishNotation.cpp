#include <iostream>
#include <stack>
#include <vector>
#include <string>

/**
 * The reverse polish notation can be better understood when thinking of a stack. The
 * numbers in the array are pushed in the stack and when an operator is met the last
 * two numbers are popped out, the operator is applied with the next to last and the
 * last being the first and second numbers in the operation, respectively. This order
 * is clearly important only for subtraction and division. The result is popped back
 * in the stack. At the end the only element left in the stack will be the result.
 * We use an std::stack. By design, the pop() method returns void to avoid possibly
 * costly return by value of the removed element (since it is a templated class and
 * returning by reference would leave a dangling pointer, for correctness it would
 * have to return by value). The top() method is used to extract the last inserted
 * element (the stack is a LIFO container) before removing it with pop().
 */

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    if (tokens.size() == 0) return 0;
    else if (tokens.size() == 1) {
      if (tokens[0] != "" && tokens[0] != "+" && tokens[0] != "-" &&
          tokens[0] != "*" && tokens[0] != "/") {
        return stoi(tokens[0]);
      }
      return 0;
    }
    std::stack<int> s;
    for (auto token : tokens) {
      if (token == "+") {
        int num1 = s.top();
        s.pop();
        int num2 = s.top();
        s.pop();
        s.push(num2+num1);
      }
      else if (token == "-") {
        int num1 = s.top();
        s.pop();
        int num2 = s.top();
        s.pop();
        s.push(num2-num1);
      }
      else if (token == "*") {
        int num1 = s.top();
        s.pop();
        int num2 = s.top();
        s.pop();
        s.push(num2*num1);
      }
      else if (token == "/") {
        int denom = s.top();
        s.pop();
        int num = s.top();
        s.pop();
        s.push(num/denom);
      }
      else {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};

int main()
{
  // vector<string> RPN = {"2", "1", "+", "3", "*"};
  // vector<string> RPN = {"4", "13", "5", "/", "+"};
  vector<string> RPN = {""};
  
  Solution a;
  std::cout << "result = " << a.evalRPN(RPN) << std::endl;
  
  return 0;
}