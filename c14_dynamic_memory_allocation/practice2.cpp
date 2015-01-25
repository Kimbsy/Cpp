#include <iostream>

using namespace std;

int*** makeArray(int l, int h, int w);

int main()
{
  // declare dimensions
  int length;
  int height;
  int width;

  // initialize them
  cout << "Enter length: ";
  cin >> length;
  cout << "Enter height: ";
  cin >> height;
  cout << "Enter width: ";
  cin >> width;

  // create multidimensional array
  int*** cube = makeArray(length, height, width);

  // free up memory (don't let it crash again)
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < width; j++)
    {
      delete[] cube[i][j];
    }
    delete[] cube[i];
  }
  delete[] cube;
}

int*** makeArray(int l, int h, int w)
{
  // 3rd dimension
  int*** cube = new int**[l];

  for (int i = 0; i < l; i++)
  {
    // 2nd dmension
    cube[i] = new int*[h];

    for (int j = 0; j < h; j++)
    {
      // 1st dimension
      cube[i][j] = new int[w];

      // initialize
      for (int k = 0; k < w; k++)
      {
        cube[i][j][k] = 0;
      }
    }
  }

  return cube;
}
