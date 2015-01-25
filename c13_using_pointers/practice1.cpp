#include <iostream>
#include <string>

using namespace std;

void getName(string* first, string* last)
{
  cout << "Please enter you first name : ";
  cin >> *first;

  if (last != NULL)
  {
    cout << "Please enter your last name : ";
    cin >> *last;
  }
}

int main()
{
  string firstName;
  string lastName;

  string* first = & firstName;
  string* last = & lastName;

  getName(first, last);

  cout << "Hello " << firstName << " " << lastName << endl;
}
