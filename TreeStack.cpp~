#include <iostream>
#include "TreeStack.h"
#include "TreeStackSinglyNode.h"
#include "TreeNode.h"
using namespace std;

void TreeStack::push(TreeNode* value) {
  TreeStackSinglyNode* newNode = new TreeStackSinglyNode(value);
  newNode->next = head;
  head = newNode;
}

TreeStackSinglyNode* TreeStack::pop() {
  TreeStackSinglyNode* oldHead = head;

  // update link
  head = head->next;

  return oldHead;
}

TreeStackSinglyNode* TreeStack::peek() {
  return head;
}
