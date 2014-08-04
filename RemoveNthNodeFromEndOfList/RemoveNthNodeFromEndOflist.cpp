#include <iostream>
#include <vector>

/**
 * Navigate the list and fill a vector with the pointers to the list nodes.
 * Once the list size is known the vector can be used to find the pointers
 * to the element that must be removed and its previous and next elements,
 * if any.
 */

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == NULL) return head;
    vector<ListNode*> v;
    ListNode * node = head;
    while (node != NULL) {
      v.push_back(node);
      node = node->next;
    }

    int index = v.size() - n;
    if (index == 0) {
      return head->next;
    }
    else if (n==0) {
      v[v.size()-2]->next = NULL;
      return head;
    }
    else {
      // Note: v[index+1] might still exceed the length of the vector.
      // Instead, we take the next, which might also be NULL.
      v[index-1]->next = v[index]->next;
    }
    return head;
  }
};

int main()
{
//  ListNode n1(1);
//  ListNode n2(2);
//  n1.next = &n2;
//  ListNode n3(3);
//  n2.next = &n3;
//  ListNode n4(4);
//  n3.next = &n4;
//  ListNode n5(5);
//  n4.next = &n5;

  ListNode n1(3);
  ListNode n2(7);
  n1.next = &n2;
  ListNode n3(9);
  n2.next = &n3;
  ListNode n4(3);
  n3.next = &n4;
  ListNode n5(5);
  n4.next = &n5;
  ListNode n6(8);
  n5.next = &n6;
  ListNode n7(0);
  n6.next = &n7;
  
  Solution a;
  a.removeNthFromEnd(&n1, 1);
  
  auto node = &n1;
  while (node != NULL) {
    std::cout << "node = " << node->val << std::endl;
    node = node->next;
  }
  
  return 0;
}