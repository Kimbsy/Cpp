#include <iostream>
#include <string>

using namespace std;

int main()
{
  string password;

  while (1)
  {
    cout << "please enter your password:" << endl;
    cin >> password;

    if (password == "foobar")
    {
      break;
    }
  }

  cout << "access granted" << endl;
}
