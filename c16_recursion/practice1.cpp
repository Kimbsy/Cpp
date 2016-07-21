#include <iostream>

using namespace std;

/**
 * The power function.
 *
 * @param x The base.
 * @param y The exponent.
 * @return The base to the power of the exponent.
 */
int pow(int x, int y)
{
  if (y < 2) {
    return x;
  }

  return x * pow(x, y - 1);
}

/**
 * Recursively compute the power function pow(x, y) = x ^ y.
 */
int main()
{
  int x, y;
  cout << "Enter values for x and y:" << endl;
  cin >> x >> y;
  cout << x << " ^ " << y << " = " << pow(x, y) << endl;
}
