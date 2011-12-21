#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define HALT_PROG(message) haltProg(message, __FILE__, __LINE__)

void haltProg(string message, string filename, int line){

  cout << "program halting: " << message << endl;
  cout << filename << " - line " << line << endl;
  abort();

}

int main() {


  HALT_PROG("hi shit aslkjfkljsd");
  return 0;

}
