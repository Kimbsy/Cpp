#include <iostream>
#include <string>
// iomnanip for cout prercision
#include <iomanip>
// string stream for string - int conversion
#include <sstream>

using namespace std;

void beer();
void calculator();

int main()
{
  string choice;

  cout << "please select an option:\n";

  for (int i = 0; i < 4; i++)
  {
    cout << "option " << i + 1 << endl;
  }

  getline(cin, choice, '\n');

  while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
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

  // create string stream buffer
  istringstream buffer(choice);

  int intChoice;

  // convert to int
  buffer >> intChoice;

  switch (intChoice)
  {
    case 1:
      beer();
      break;
    case 2:
      calculator();
      break;
    case 3:
      cout << "You chose option 3\n";
      break;
    case 4:
      cout << "You chose option 4\n";
      break;
    default:
      cout << "invalid choice\n";
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

  switch (op)
  {
    case '+':
      cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << add(arg1, arg2) << "\n";
      break;
    case '-':
      cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << subtract(arg1, arg2) << "\n";
      break;
    case '*':
      cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << multiply(arg1, arg2) << "\n";
      break;
    case '/':
      cout << setprecision(99) << arg1 << " " << op << " " << arg2 << " = " << divide(arg1, arg2) << "\n";
      break;
    default:
      cout << "invalid operation\n";
      break;
  }
}
