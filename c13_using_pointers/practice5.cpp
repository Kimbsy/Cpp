#include <iostream>
#include <string>

using namespace std;

int main()
{
  string first = "first variable";
  string second = "second variable";

  if (&first < &second)
  {
    cout << first << " => " << &first << endl;
    cout << second << " => " << &second << endl;
  }
}
