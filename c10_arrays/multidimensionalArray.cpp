#include <iostream>

using namespace std;

int main()
{
  // 8X8 grid like a chessboard
  int table[8][8];

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      // set each element to a value
      table[i][j] = i * j;
    }
  }

  cout << "Multiplication table:\n";
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cout << "[ " << i << " ][ " << j << " ] = " << table[i][j] << " \n";
    }
  }
}
