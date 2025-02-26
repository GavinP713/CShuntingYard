#ifndef STACK_H
#define STACK_H

#include "SinglyNode.h"

class Stack {
 public:
  void push(int value);
  void pop();
  SinglyNode* peek();
 private:
  SinglyNode* head;
};

#endif
