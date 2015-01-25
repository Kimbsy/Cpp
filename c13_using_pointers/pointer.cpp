#include <iostream>

using namespace std;


int main()
{
  int x; // normal int
  int *pointToX; // pointer to an integer

  pointToX = &x; // assign the address of x to pointToX

  cout << "please enter a number : ";
  cin >> x; // put a value in x (could alternatively use *pointToX)

  cout << pointToX << endl; // basic pointer gets address
  cout << *pointToX << endl; // note use of * to get value at address

  *pointToX = 10;
  cout << x << endl;
}
