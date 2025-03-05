#ifndef TREENODE_H
#define TREENODE_H

#include "TreeNode.h"

class TreeNode {
 public:
  TreeNode(char _value);
  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;
  char value;
};

#endif
