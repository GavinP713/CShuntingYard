#ifndef TREESTACKSINGLYNODE_H
#define TREESTACKSINGLYNODE_H

#include "TreeStackSinglyNode.h"
#include "TreeNode.h"

class TreeStackSinglyNode {
 public:
  TreeStackSinglyNode (TreeNode* _value);
  TreeStackSinglyNode* next;
  TreeNode* value;
};

#endif
