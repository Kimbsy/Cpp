#include <iostream>
#include <string>

using namespace std;

int main()
{
  string password;

  do
  {
    cout << "please enter your password:" << endl;
    cin >> password;
  } while (password != "foobar");

  cout << "access granted" << endl;
}