#include <iostream>

using namespace std;

int main()
{
  int firstVariable;
  int secondVariable;

  cout << "Please enter your first number:\n";

  cin >> firstVariable;

  cout << "Please enter your second number\n";

  cin >> secondVariable;

  cout << firstVariable << " + " << secondVariable << " = " << firstVariable + secondVariable << "\n";
  cout << firstVariable << " - " << secondVariable << " = " << firstVariable - secondVariable << "\n";
  cout << firstVariable << " * " << secondVariable << " = " << firstVariable * secondVariable << "\n";
  cout << firstVariable << " / " << secondVariable << " = " << firstVariable / secondVariable << "\n";
}
