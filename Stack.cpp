#include <iostream>
#include "Stack.h"
using namespace std;

void Stack::push(char value) {
  SinglyNode* newNode = new SinglyNode(value);
  newNode->next = head;
  head = newNode;
}

SinglyNode* Stack::pop() {
  SinglyNode* oldHead = head;

  // update link
  head = head->next;

  return oldHead;
}

SinglyNode* Stack::peek() {
  return head;
}
