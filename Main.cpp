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

Queue* shuntingYard(char input[128]);
int precedence (char token, vector<symbol> table);
string associativity(char token, vector<symbol> table);
TreeStack* createExpressionTree(Queue* output);
void printTree(TreeNode* node, int depth);
void printInfix(TreeNode* node);
void printPostfix(TreeNode* node);
void printPrefix(TreeNode* node);

int main() {
  while (true) {
  cout << "enter infix equation with no spaces" << endl;
  char input[128];
  cin >> input;

  // run shunting yard algorithm and get the output queue
  Queue* output = shuntingYard(input);
  
  // create expression tree
  TreeStack* tree = createExpressionTree(output);

  cout << "enter print command: \t \"tree\" \t \"infix\" \t \"postfix\" \t \"prefix\"" << endl;
  cin >> input;
  
  if (strcmp(input, "tree") == 0) {
    printTree(tree->peek()->value, 0);
  }
  else if (strcmp(input, "infix") == 0) {
    printInfix(tree->peek()->value);
  }
  else if (strcmp(input, "postfix") == 0) {
    printPostfix(tree->peek()->value);    
  }
  else if (strcmp(input, "prefix") == 0) {
    printPrefix(tree->peek()->value);
  }
  cout << endl;

  cout << "continue?    y/n" << endl;
  cin >> input;
  if (strcmp(input, "n") == 0) return 1;
  }
  
  return 1;
}

Queue* shuntingYard(char input[128]) {
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
    char token = input[i];
    
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

  return output;
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

TreeStack* createExpressionTree(Queue* output) {
  TreeStack* treeStack = new TreeStack();

  // convert output to expression tree
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

  return treeStack;
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

void printInfix(TreeNode* node) {
  if (node->right != nullptr) {
    printInfix(node->right);
  }

  cout << node->value;

  if (node->left != nullptr) {
    printInfix(node->left);
  }
}

void printPostfix(TreeNode* node) {
  if (node->right != nullptr) {
    printPostfix(node->right);
  }
  
  if (node->left != nullptr) {
    printPostfix(node->left);
  }

  cout << node->value;
}

void printPrefix(TreeNode* node) {
  cout << node->value;
  
  if (node->right != nullptr) {
    printPrefix(node->right);
  }
  
  if (node->left != nullptr) {
    printPrefix(node->left);
  }
}
