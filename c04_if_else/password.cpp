#include <iostream>
#include <string>

using namespace std;

int main()
{
  string username;
  string password;

  cout << "Enter  your username:\n";
  getline(cin, username, '\n');

  cout << "Enter your password:\n";
  getline(cin, password, '\n');

  if (username == "root" && password == "root")
  {
    cout << "Access allowed\n";
  }
  else if (username == "superuser" && password == "superuser")
  {
    cout << "Access allowed\n";
  }
  else if (username == "bossman" && password == "bossman")
  {
    cout << "Access allowed\n";
  }
  else if (username == "dave" && password == "dave")
  {
    cout << "Access allowed\n";
  }
  else {
    cout << "************\n";
    cout << "Acces denied\n";
    cout << "************\n";
    cout << "try again\n";

    cout << "Enter  your username:\n";
    getline(cin, username, '\n');

    cout << "Enter your password:\n";
    getline(cin, password, '\n');

    if (username == "root" && password == "root")
    {
      cout << "Access allowed\n";
    }
    else if (username == "superuser" && password == "superuser")
    {
      cout << "Access allowed\n";
    }
    else if (username == "bossman" && password == "bossman")
    {
      cout << "Access allowed\n";
    }
    else if (username == "dave" && password == "dave")
    {
      cout << "Access allowed\n";
    }
    else
    {
      cout << "fuck you you're not getting in\n";
    }
  }

  // keep going
}
