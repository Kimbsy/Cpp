#include <iostream>

using namespace std;

int sumArray(int array[], int size)
{
  int sum = 0;

  for (int i = 0; i < size; i++)
  {
    sum += array[i];
  }

  return sum;
}

int main()
{
  int values[10];

  for (int i = 0; i < 10; i++)
  {
    cout << "Enter value " << i << ": ";
    cin >> values[i];
  }
  cout << sumArray(values, 10) << endl;
}
