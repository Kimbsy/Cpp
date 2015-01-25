#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void beer();
void calculator();

int main()
{
  string option1 = "option 1";
  string option2 = "option 2";
  string option3 = "option 3";
  string option4 = "option 4";

  string choice;

  cout << "please select an option:\n";

  for (int i = 0; i < 4; i++)
  {
    cout << "option " << i + 1 << endl;
  }

  getline(cin, choice, '\n');

  while (choice != option1 && choice != option2 && choice != option3 && choice != option4)
  {
    cout << "//////////////////\n";
    cout << "//invalid choice//\n";
    cout << "//////////////////\n";

    cout << "please select an option:\n";

    for (int i = 0; i < 4; i++)
    {
      cout << "option " << i + 1 << endl;
    }

    getline(cin, choice, '\n');
  }

  if (choice == option1)
  {
    beer();
  }
  else if (choice == option2)
  {
    calculator();
  }
  else if (choice == option3)
  {
    cout << "You chose option 3\n";
  }
  else if (choice == option4)
  {
    cout << "You chose option 4\n";
  }
}

/**
 * 99 bottles of beer on the wall
 */
void beer()
{
  for (int i = 99; i > 0; i--)
  {
    cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\nTake one down, pass it around, " << i - 1 << " bottles of beer on the wall.\n";
  }

  cout << "Go home, you're drunk.\n";
}

/**
 * basic calculator
 */

double add(double x, double y)
{
  return x + y;
}
double subtract(double x, double y)
{
  return x - y;
}
double multiply(double x, double y)
{
  return x * y;
}
double divide(double x, double y)
{
  return x / y;
}

void calculator()
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
    cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << add(arg1, arg2) << "\n";
  }
  else if (op == '-')
  {
    cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << subtract(arg1, arg2) << "\n";
  }
  else if (op == '*')
  {
    cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << multiply(arg1, arg2) << "\n";
  }
  else if (op == '/')
  {
    cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << divide(arg1, arg2) << "\n";
  }
}
