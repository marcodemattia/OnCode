#include <iostream>
#include <unordered_set>

/**
 * Simple, brute force approach by filling an std::unordered_set with the pointers to the elements
 * in the list already checked. If we find the same pointer twice there is a cycle.
 * It can be done without any extra space by storing the pointers in the value of the ListNode.
 * While going through the list set the next node value to the pointer of the current ListNode.
 * At any point, if the next node contains a pointer equal to the previous node's pointer there is
 * a cycle. This is based on the assumption that the value of the next node is never already
 * equal to the pointer of the previous node, which might happen.
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
  bool hasCycle(ListNode *head) {

    if( head == 0 ) return false;
    addresses.insert(head);

    ListNode * node = head;
    while( true ) {
      if( node->next == 0 ) return false;
      if( addresses.find(node->next) != addresses.end() ) return true;
      addresses.insert(node->next);
      node = node->next;
    }
    return false;
  }

  std::unordered_set<ListNode*> addresses;
};

int main()
{
  ListNode n1(0);
  ListNode n2(0);
  ListNode n3(0);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n1;

  Solution a;
  if( a.hasCycle(&n1) ) std::cout << "has cycle" << std::endl;
  else std::cout << "no cycle" << std::endl;


  return 0;
}
