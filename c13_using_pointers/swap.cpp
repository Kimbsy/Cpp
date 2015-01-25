#include <iostream>

using namespace std;

void swap1(int left, int right)
{
  int temp = left;
  left = right;
  right = temp;
}

void swap2(int* left, int* right)
{
  int temp = *left;
  *left = *right;
  *right = temp;
}

int main()
{
  int x = 1, y = 2;
  cout << x << " " << y << endl;

  swap1(x, y);
  cout << x << " " << y << endl;

  swap2(&x, &y);
  cout << x << " " << y << endl;
}
