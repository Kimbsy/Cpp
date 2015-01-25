#include <iostream>

using namespace std;

// small function to demonstrate scope
// (does NOT havce acces to countFunctionCalls)
int doStuff()
{
  return 2 + 3;
}

// global variables can be initialised jus like other variables
int countFunctionCalls = 0;

void fun()
{
  // global variable is available here
  countFunctionCalls++;
}

int main()
{
  fun();
  fun();
  fun();

  // global variable also available here
  cout << "Function fun() was called " << countFunctionCalls << " times\n";
}
