#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int randRange(int low, int high)
{
  // get a random number
  // use modulus to get it between 0 and the size of our range
  // (size is difference + 1)
  // add the lower limit of our range
  return rand() % (high - low + 1) + low;
}

int main()
{
  // seed random
  srand(time(NULL));

  cout << randRange(4, 10) << endl;
}
