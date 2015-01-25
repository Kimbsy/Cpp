#include <iostream>

using namespace std;

int main()
{
  int num;

  cout << "enter a number:\n";
  cin >> num;

  if (num < 0)
  {
    cout << "you entered a negative number\n";
  }
  else if (num == 0)
  {
    cout << "you enetered zero\n";
  }
  else
  {
    cout << "you entered a non-negative number\n";
  }
}
