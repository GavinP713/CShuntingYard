#ifndef STACK_H
#define STACK_H

#include "LinkedNode.h"

class Stack {
 public:
  void push();
  voud pop();
  void peek();
 private:
  LinkedNode* head;
}

#endif
