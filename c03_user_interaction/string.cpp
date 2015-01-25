#include <iostream>
// strings needs extra header file
#include <string>

using namespace std;

int main()
{
  // string userFirstName;
  // string userLastName;

  // cout << "Please enter your first name: \n";
  // cin >> userFirstName;
  // cout << "Please enter your last name: \n";
  // cin >> userLastName;

  // // concat strings with +
  // string userFullName = userFirstName + " " + userLastName;


  /////////////////////////////////////
  // alternate method with getline() //
  /////////////////////////////////////

  string userFullName;

  cout << "Please enter your full name: \n";
  getline(cin, userFullName, '\n');

  cout << "Hello " << userFullName << "\n";
}
