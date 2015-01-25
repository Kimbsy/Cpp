#include <iostream>

using namespace std;

int main()
{
  double arg1;
  double arg2;
  char op;

  cout << "enter operation:\n";
  cin >> arg1;
  cin >> op;
  cin >> arg2;

  if (op == '+')
  {
    cout << arg1 << " " << op << " " << arg2 << " = " << arg1 + arg2 << "\n";
  }
  else if (op == '-')
  {
    cout << arg1 << " " << op << " " << arg2 << " = " << arg1 - arg2 << "\n";
  }
  else if (op == '*')
  {
    cout << arg1 << " " << op << " " << arg2 << " = " << arg1 * arg2 << "\n";
  }
  else if (op == '/')
  {
    cout << arg1 << " " << op << " " << arg2 << " = " << arg1 / arg2 << "\n";
  }
}
