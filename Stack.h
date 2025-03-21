#ifndef STACK_H
#define STACK_H

#include "SinglyNode.h"

class Stack {
 public:
  void push(char value);
  SinglyNode* pop();
  SinglyNode* peek();
 private:
  SinglyNode* head;
};

#endif
