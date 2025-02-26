#include "Stack.h"

void Stack::push(int value) {
  SinglyNode* newNode = new SinglyNode(value);
  newNode->next = head;
  head = newNode;
}

void Stack::pop() {
  SinglyNode* newHead = head->next;
  
  delete head;

  head = newHead;
}

SinglyNode* Stack::peek() {
  return head;
}
