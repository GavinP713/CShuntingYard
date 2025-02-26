#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyNode.h"

class Queue {
 public:
  Queue();
  void enqueue(int value);
  int dequeue();
 private:
  DoublyNode* head;
  DoublyNode* tail;
};

#endif
