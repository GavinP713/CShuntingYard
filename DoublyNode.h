#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

class DoublyNode {
 public:
  DoublyNode(char _value);
  DoublyNode* next;
  DoublyNode* previous;
  char value;
};

#endif
