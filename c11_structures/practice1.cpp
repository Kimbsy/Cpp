#include <iostream>
#include <string>

using namespace std;

struct Person
{
  string name;
  int age;
  double height;
};

Person newPerson()
{
  Person dude;

  cout << "enter name : ";
  cin >> dude.name;

  cout << "enter age : ";
  cin >> dude.age;

  cout << "enter height : ";
  cin >> dude.height;

  return dude;
}

int main()
{
  Person people[3];

  for (int i = 0; i < 3; i++)
  {
    cout << "Plese enter details for person " << i + 1 << endl;
    people[i] = newPerson();
  }
}
