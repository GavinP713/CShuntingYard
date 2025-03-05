#include <iostream>
#include <string>
#include <vector>
#include "Stack.h"
#include "Queue.h"
#include "ShuntingYard.h"
using namespace std;

struct symbol {
  char o;
  int precedence;
  string associativity;
};

int precedence (char token, vector<symbol> table);
string associativity(char token, vector<symbol> table);

int main() {
  string tokens = "1+2*3+5";
  Queue* output = new Queue();
  Stack* stack = new Stack();

  // create operator table
  vector<symbol> table = {
    { '^', 4, "right" },
    { 'x', 3, "left" },
    { '/', 3, "left" },
    { '+', 2, "left" },
    { '-', 2, "left" },
    
  };
  
  // shunting yard algorithm:
  for (int i = 0; i < tokens.length(); i++) {
    char token = tokens[i];
    cout << "- i=" << i << " " << "\"" << token << "\"" << endl;
    
    // token is a number
    // (dec value of char ranges between 0-9 in ascii)
    if (int(token) >= 48 && int(token) <= 57) {
      cout << "-- token is a number, popping to output" << endl;
      output->enqueue(token);
    }
    // assumes anything else is an operator
    else {
      if (token == '(') {
	cout << "-- token is a left parantheses, pushing to stack" << endl;
	stack->push(token);
      }
      else if (token == ')') {
	cout << "-- token is a right parantheses" << endl;
	while (stack->peek()->value != '(') {
	  cout << "--- popping to output" << endl;
	  output->enqueue(stack->pop()->value);
	}
	cout << "-- discarding final parentheses" << endl;
	delete stack->pop();
      }
      else {
	cout << "-- token is an operator" << endl;
	
	// quick references and "refactoring" for convenience sake       
	char o1 = token;
	char o2; // ! seg fault when head is initially null !

	while (stack->peek() != nullptr) {
	  o2 = stack->peek()->value;
	  if (o2 != '(' && (precedence(o2, table) > precedence(o1, table) || (precedence(o1, table) == precedence(o2, table) && associativity(o1, table) == "left"))) {
	    cout << "--- popping to output" << endl;
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
  cout << "loop done, popping stack to output" << endl;

  // put rest of stack onto output
  while(stack->peek() != nullptr) {
    cout << "- pop(" << stack->peek()->value << ")" << endl;
    output->enqueue(stack->pop()->value);
  }

  // print output
  cout << "printing output: " << endl;
  while (output->dequeue() != 0);
  
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
