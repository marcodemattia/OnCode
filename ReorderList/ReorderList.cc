#include <iostream>
#include <vector>

/**
 * Border case: the list is empty or it has only one element. Return it.
 * 
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  void reorderList(ListNode *head) {
    if( head == 0 || head->next == 0 ) return;
    fillPointers(head);
    int numNodes = pointers.size();
    std::cout << "size = " << numNodes << std::endl;
    int i=0;
    ListNode * p = head;
    std::cout << "p->val = " << p->val << std::endl;
    while( i<numNodes/2 ) {
      std::cout << "numNodes-1 - i = " << numNodes-1-i << std::endl;
      p->next = pointers[numNodes-1 - i];
      p = p->next;
      std::cout << "p->val = " << p->val << std::endl;
      if( numNodes != 2*(i+1) ) {
	std::cout << "i+1 = " << i+1 << std::endl;
	p->next = pointers[i+1];
	p = p->next;
	std::cout << "p->val = " << p->val << std::endl;
      }
      ++i;
    }
    p->next = 0;
  }

  void fillPointers(ListNode * node)
  {
    ListNode * p = node;
    while( p != 0 ) {
      pointers.push_back(p);
      p = p->next;
    }
  }

  std::vector<ListNode *> pointers;
};


void printNodes(const ListNode * node)
{
  int i=0;
  const ListNode * p = node;
  while( p != 0 ) {
    std::cout << "node("<<i<<") = " << p->val << std::endl;
    p = p->next;
    ++i;
  }
  std::cout << "number of nodes = " << i << std::endl;
}


int main()
{
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  // n1.next = &n2;
  // n2.next = &n3;
  // n3.next = &n4;
  // n4.next = &n5;
  std::cout << "original list:" << std::endl;
  printNodes(&n1);
  std::cout << std::endl;

  Solution a;
  a.reorderList(&n1);
  std::cout << "reordered list:" << std::endl;
  printNodes(&n1);
}
