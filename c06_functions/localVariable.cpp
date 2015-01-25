#include <iostream>

using namespace std;

void changeArgument(int x)
{
  x = x + 5;
}

int main()
{
  int y = 4;

  changeArgument(y);

  // still prints 4
  cout << y << endl; 
}
