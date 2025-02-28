#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyNode.h"

class Queue {
 public:
  Queue();
  void enqueue(char value);
  char dequeue();
 private:
  DoublyNode* head;
  DoublyNode* tail;
};

#endif
