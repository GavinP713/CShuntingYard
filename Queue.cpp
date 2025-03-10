#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
  head = nullptr;
  tail = nullptr;
}

void Queue::enqueue(char value) {
  DoublyNode* newNode = new DoublyNode(value);

  // create initial links
  if (tail == nullptr) {
    newNode->previous = tail;
    newNode->next = head;
    // set head
    head = newNode;
  }
  // change links
  else {
    newNode->previous = tail->previous;
    newNode->next = tail;
    tail->previous = newNode;
  }

  // set tail
  tail = newNode;
}

char Queue::dequeue() {
  // queue empty, return endline
  if (head == nullptr) {
    //cout << "Queue is empty" << endl;
    return char(0);
  }
  // queue not empty, return head
  else {
    // save value of head so it can return after head is deleted from memory
    char value = head->value;

    // last node in queue
    if (head->previous == nullptr) {
      // clear node from memory
      delete head;
      // update links
      head = nullptr;
      tail = nullptr;
    }
    // multiple nodes in queue
    else {
      // update links
      DoublyNode* newHead = head->previous;
      newHead->next = head->next;
    
      // assign new head
      delete head;
      head = newHead;
    }

    cout << value << endl;
    return value;
  }
}
