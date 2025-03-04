#include "Stack.h"

void Stack::push(char value) {
  SinglyNode* newNode = new SinglyNode(value);
  newNode->next = head;
  head = newNode;
}

SinglyNode* Stack::pop() {
  SinglyNode* newHead = head->next;
  SinglyNode* oldHead = head;

  // update link
  head = newHead;
  
  return oldHead;
}

SinglyNode* Stack::peek() {
  return head;
}
