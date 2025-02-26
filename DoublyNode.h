#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

class DoublyNode {
 public:
  DoublyNode(int _value);
  DoublyNode* next;
  DoublyNode* previous;
  int value;
};

#endif
