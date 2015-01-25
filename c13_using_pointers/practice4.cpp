#include <iostream>
#include <string>

using namespace std;

int returnTwo(int x, int* y)
{
  int temp = *y;

  *y = x + temp;

  return x * temp;
}

int main()
{
  int x = 4;
  int y = 5;

  int* sum = & y;

  int product = returnTwo(x, sum);

  cout << product << " " << *sum << endl;
}
