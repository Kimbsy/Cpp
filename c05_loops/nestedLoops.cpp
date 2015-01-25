#include <iostream>

using namespace std;

/**
 * draws multiplication table
 * @return 0
 */
int main()
{
  for (int i = 0; i < 10; i++)
  {
    //  \t is the tab character
    cout << '\t' << i;
  }

  cout << '\n';

  for (int i = 0; i < 10; i++)
  {

    cout << i;

    for (int j = 0; j < 10; j++)
    {
      cout << '\t' << i * j;
    }

    cout << '\n';
  }
}
