#include <iostream>
#include <string>

using namespace std;

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
}
