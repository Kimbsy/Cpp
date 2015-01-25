#include <iostream>

using namespace std;

/**
 * Prints memory addresses of elements in a 2 dimensional array
 * 
 */
int main()
{
  // declare dimensions
  int width;
  int height;

  // initialize with values
  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;

  // pointer to pointer is array of 3 pointers (hence int*[3])
  int** table = new int*[height];

  // each pointer stores the address of an array of 3 ints
  for (int i = 0; i < height; i++)
  {
    table[i] = new int[width];

    // print out adresses for elements
    for (int j = 0; j < width; j++)
    {
      cout << & table[i][j] << endl;
    }
  }

  // dont forget to free memory after
  for (int i = 0; i < height; i++)
  {
    delete[] table[i];
  }
  delete[] table;
}
