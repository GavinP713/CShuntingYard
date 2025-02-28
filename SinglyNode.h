#ifndef SINGLYNODE_H
#define SINGLYNODE_H

#include "SinglyNode.h"

class SinglyNode {
 public:
  SinglyNode(char _value);
  SinglyNode* next;
  char value;
};

#endif
