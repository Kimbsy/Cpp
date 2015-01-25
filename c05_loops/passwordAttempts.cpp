#include <iostream>
#include <string>

using namespace std;

int main()
{
  string password;
  int attemps = 4;

  cout << "enter password\n";
  cin >> password;

  while (password != "foo" && attemps > 0)
  {
    cout << "incorrect password, " << attemps << " attemps remaining.\n";
    cout << "enter password\n";
    cin >> password;  

    attemps--;
  }
}
