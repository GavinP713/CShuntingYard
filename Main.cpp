#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "Stack.h"
#include "Queue.h"
#include "TreeStack.h"
#include "TreeStackSinglyNode.h"
using namespace std;

struct symbol {
  char o;
  int precedence;
  string associativity;
};

int precedence (char token, vector<symbol> table);
string associativity(char token, vector<symbol> table);
void printTree(TreeNode* node, int depth);

int main() {
  cout << "enter infix equation with no spaces" << endl;
  char tokens[128];
  cin >> tokens;

  Queue* output = new Queue();
  Stack* stack = new Stack();

  // create operator table
  vector<symbol> table = {
    { '^', 4, "right" },
    { '*', 3, "left" },
    { '/', 3, "left" },
    { '+', 2, "left" },
    { '-', 2, "left" },
    
  };
  
  // shunting yard algorithm:
  for (int i = 0; i < 128; i++) {
    char token = tokens[i];
    
    // token is a number
    // (dec value of char ranges between 0-9 in ascii)
    if (int(token) >= 48 && int(token) <= 57) {
      output->enqueue(token);
    }
    // end of expression
    else if (int(token) == 0) {
      break;
    }
    // assumes anything else is an operator
    else {
      if (token == '(') {
	stack->push(token);
      }
      else if (token == ')') {
	while (stack->peek()->value != '(') {
	  output->enqueue(stack->pop()->value);
	}
	delete stack->pop();
      }
      else {
	// quick references and "refactoring" for convenience sake       
	char o1 = token;
	char o2;

	while (stack->peek() != nullptr) {
	  o2 = stack->peek()->value;
	  if (o2 != '(' && (precedence(o2, table) > precedence(o1, table) || (precedence(o1, table) == precedence(o2, table) && associativity(o1, table) == "left"))) {
	    output->enqueue(stack->pop()->value);

	    if (stack->peek() != nullptr) o2 = stack->peek()->value;
	    else break;
	  }
	  else break;
	}

	stack->push(token); 
      }     
    }
  }
  
  // put rest of stack onto output
  while(stack->peek() != nullptr) {
    output->enqueue(stack->pop()->value);
  }
  
  // create expression tree
  TreeStack* treeStack = new TreeStack();
  char token = output->dequeue();
  while (int(token) != 0) { // while not an end line
    // number
    if (int(token) >= 48 && int(token) <= 57) {
      TreeNode* node = new TreeNode(token);
      treeStack->push(node);
    }
    // operator
    else {
      // parent first two nodes under operator
      TreeNode* node = new TreeNode(token);
      node->left = treeStack->pop()->value;
      node->right = treeStack->pop()->value;
      
      treeStack->push(node);
    }
    token = output->dequeue();
  }
  
  // print stack
  cout << "expression tree: " << endl;
  printTree(treeStack->peek()->value, 0);
  
  return 1;
}

int precedence(char token, vector<symbol> table) {
  // check if token matches any operators, and return precedence if so
  for (int i = 0; i < table.size(); i++) {
    if (token == table[i].o) return table[i].precedence;
  }

  // token does not match any symbol in table
  return 0;
}

string associativity(char token, vector<symbol> table) {
  // check if token matches any operators, and return associativity if so
  for (int i = 0; i < table.size(); i++) {
    if (token == table[i].o) return table[i].associativity;
  }

  // token does not match any symbol in table
  return "";
}

void printTree(TreeNode* node, int depth) {
  if (node->right != nullptr) { // check for null
    printTree(node->right, depth + 1);
  }

  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }

  cout << node->value << endl;

  if (node->left != nullptr) { // check for null
    printTree(node->left, depth + 1);
  }
}
