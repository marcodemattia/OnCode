#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if( head == 0 ) return head;

    ListNode * node = head;
    while( node->next != 0 ) {
      if( node->val == node->next->val ) {
	node->next = node->next->next;
      }
      else node = node->next;
    }
    return head;
  }
};

int main()
{
  ListNode * head = new ListNode(1);
  ListNode * n1 = new ListNode(2);
  head->next = n1;
  ListNode * n2 = new ListNode(2);
  n1->next = n2;
  ListNode * n3 = new ListNode(3);
  n2->next = n3;
  ListNode * n4 = new ListNode(3);
  n3->next = n4;

  ListNode * nodei = head;
  while( nodei != 0 ) {
    std::cout << nodei->val << std::endl;
    nodei = nodei->next;
  }


  Solution a;
  ListNode * node = a.deleteDuplicates(head);

  std::cout << "result:" << std::endl;

  while( node != 0 ) {
    std::cout << node->val << std::endl;
    node = node->next;
  }

  return 0;
}
