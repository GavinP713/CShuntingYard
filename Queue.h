#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedNode.h"

class Queue {
 public:
  void enqueue();
  void dequeue();
 private:
  LinkedNode* head;
  LinkedNode* tail;
}

#endif
