#include <iostream>

using namespace std;

/**
 * 99 bottles of beer on the wall
 */
int main()
{
  for (int i = 99; i > 0; i--)
  {
    cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\nTake one down, pass it around, " << i - 1 << " bottles of beer on the wall.\n";
  }

  cout << "Go home, you're drunk.\n";
}
