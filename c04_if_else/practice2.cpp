#include <iostream>

using namespace std;

int main()
{
  int pass1 = 45;
  int pass2 = 18;

  int userPass;

  cout << "enter pass code:\n";
  cin >> userPass;

  if (userPass == pass1 || userPass == pass2)
  {
    cout << "woooo\n";
  }
  else
  {
    cout << "boooo\n";
  }
}
