#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include "SinglyNode.h"
#include "TreeNode.h"

class ExpressionTree {
 public:
  void push(TreeNode* value);
  SinglyNode* pop();
  SinglyNode* peek();
 private:
  SinglyNode* head;
};

#endif
