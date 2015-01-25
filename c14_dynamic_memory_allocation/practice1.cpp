#include <iostream>

using namespace std;

/**
 * Creates dynamically sized multiplication table using 2d pointer array
 * 
 */
int main() {
  // declare dimensions
  int width;
  int height;

  // initialize with values
  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;

  /////////////////////
  // create 2D array //
  /////////////////////

  // pointer to pointer is array of 3 pointers (hence int*[3])
  int** table = new int*[height];

  // each pointer stores the address of an array of 3 ints
  for (int i = 0; i < height; i++)
  {
    table[i] = new int[width];

    // initialize with value
    for (int j = 0; j < width; j++)
    {
      table[i][j] = i * j;
    }
  }

  // print table
  cout << "0 ";
  for (int j = 1; j < width; j++)
  {
    cout << j << " ";
    if (j < 10)
    {
      cout << " ";
    }
  }
  cout << endl;
  
  for (int i = 1; i < height; i++)
  {
    cout << i << " ";
    for (int j = 1; j < width; j++)
    {
      cout << table[i][j] << " ";
      if (table[i][j] < 10)
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  // !!!!!! DONT FORGET TO FREE MEMORY
  for (int i = 0; i < height; i++)
  {
    delete[] table[i];
  }
  delete[] table;
}
