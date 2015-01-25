#include <iostream>

using namespace std;

int main()
{
  int age1, age2;

  cout << "enter age 1:\n";
  cin >> age1;
  cout << "enter age 2:\n";
  cin >> age2;

  if (age1 > 100 && age2 > 100)
  {
    cout << "woah! those guys are old!\n";
  }
  else if (age1 == age2)
  {
    cout << "they are both the same age\n";
  }
  else {
    if (age1 > age2)
    {
      cout << "person 1 is older\n";
    }
    else
    {
      cout << "person 2 is oolder\n";
    }
  }
}
