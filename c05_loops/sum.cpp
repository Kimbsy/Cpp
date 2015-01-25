#include <iostream>


using namespace std;

int main()
{
  int total = 0;
  int input;

  do
  {
    cin >> input;
    total += input;
  }
  while (input != 0);

  cout << "total = " << total << endl;
}
