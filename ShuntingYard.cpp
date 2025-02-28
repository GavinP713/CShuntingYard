#include <iostream>
#include "ShuntingYard.h"
using namespace std;

void ShuntingYard::input(char input[128]) {
  Queue* output = new Queue();
  Stack* operators = new Stack();

  for (int i = 0; i < 128; i++) {
    if (int(input[i]) >= 48 && int(input[i]) <= 57) {
    }
  }
}
