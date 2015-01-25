#include <iostream>
// setprecision() header file
#include <iomanip>

using namespace std;

/**
 * divides first number by second number
 * @return 0
 */
int main() {
  double first;
  double second;

  cout << "Enter first number\n";
  cin >> first;
  cout << "enter second number\n";
  cin >> second;

  // set arbitrarily high precision for cout (so it won't truncate decimals)
  cout << setprecision(99) << first << " / " << second << " = " << first / second << "\n";
}
