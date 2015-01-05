#include <iostream>

/**
 * Definition for singly-linked list.
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode * node1 = l1;
    ListNode * node2 = l2;
    ListNode * result = new ListNode(0);
    ListNode * tempPreviousResult = result;
    ListNode * tempResult = result;
    int carry = 0;
    int newElement = 0;
    while (node1 != NULL || node2 != NULL) {

      if (node1 == NULL) {
	newElement = node2->val;
	node2 = node2->next;
      }
      else if (node2 == NULL) {
	newElement = node1->val;
	node1 = node1->next;
      }
      else {
	newElement = node1->val + node2->val;
	node1 = node1->next;
	node2 = node2->next;
      }

      if (newElement + carry >= 10) {
	tempResult->val = newElement - 10 + carry;
	carry = 1;
      }
      else {
	tempResult->val = newElement + carry;
	carry = 0;
      }
      tempPreviousResult = tempResult;
      tempResult->next = new ListNode(0);
      tempResult = tempResult->next;
    }

    if (carry == 1) tempResult->val = 1;
    else {
      delete tempResult;
      tempPreviousResult->next = NULL;
    }
    return result;
  }
};

int main()
{
  Solution a;

  // ListNode * l1 = new ListNode(2);
  // l1->next = new ListNode(4);
  // l1->next->next = new ListNode(3);
  // 
  // ListNode * l2 = new ListNode(5);
  // l2->next = new ListNode(6);
  // l2->next->next = new ListNode(4);

  ListNode * l1 = new ListNode(1);
  l1->next = new ListNode(8);

  ListNode * l2 = new ListNode(0);

  ListNode * result = a.addTwoNumbers(l1, l2);

  while (result != 0) {
    std::cout << result->val << std::endl;
    result = result->next;
  }
}
