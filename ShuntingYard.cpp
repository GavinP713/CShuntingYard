#include <iostream>
#include <string>
#include "ShuntingYard.h"
using namespace std;

void ShuntingYard::input(string input) {
  Queue* output = new Queue();
  Stack* operators = new Stack();

  for (int i = 0; i < input.length(); i++) {
    // if a number
    if (int(input[i]) >= 48 && int(input[i]) <= 57) {
      cout << "--- Number added to queue " << input[i] << endl;
      output->enqueue(input[i]);
    }
    // symbol
    else {
      cout << "Symbol added to stack " << input[i] << endl;
      operators->push(input[i]);
    }
  }
}
