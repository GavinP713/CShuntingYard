#include <iostream>
#include "ExpressionTree.h"
#include "TreeNode.h"
using namespace std;

void ExpressionTree::push(TreeNode* value) {
  SinglyNode* newNode = new SinglyNode(value);
  newNode->next = head;
  head = newNode;
}

SinglyNode* ExpressionTree::pop() {
  SinglyNode* oldHead = head;

  // update link
  head = head->next;

  return oldHead;
}

SinglyNode* ExpressionTree::peek() {
  return head;
}
