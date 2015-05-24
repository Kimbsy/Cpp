#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <typeinfo>

using namespace std;

/**
 * Command line version of Conway's Game of Life.
 *
 * sudo apt-get install libncurses5-dev
 * g++ gameOfLife.cpp -o gameOfLife -lncurses
 * ./gamOfLife <filename>
 */

int getNext(int prev, int tl, int tc, int tr, int ml, int mr, int bl, int bc, int br);

/**
 * Main function
 */
int main(int argc, char* argv[]) {

  ///////////
  // setup //
  ///////////

  // declare grid dimensions
  int width;
  int height;

  string fileName = "glider";

  if (argc < 2)
  {
    cout <<"Incorrect number of arguments." << endl;
    cout << "Usage: \n  ./gameOfLife <filename>" << endl;
    return 1;
  }

  // get dimensions from file
  ifstream inputFile(argv[1]);

  string line = "";
  
  // first line is width
  getline(inputFile, line);
  width = atoi(line.c_str());

  // then height
  getline(inputFile, line);
  height = atoi(line.c_str());

  // get initial input from file
  string* input = new string[height];
  for (int i = 0; i < height; i++)
  {
    getline(inputFile, line);
    input[i] = line;
  }

  inputFile.close();

  // create 2d array
  // pointer to pointer is array of pointers (int*[])
  int** grid = new int*[height];
  int** next = new int*[height];

  // eah pointer sores the address of an array of ints
  for (int i = 0; i < height; i++)
  {
    grid[i] = new int[width];
    next[i] = new int[width];

    // initialize with values
    for (int j = 0; j < width; j++)
    {
      grid[i][j] = 0;
      // the "- '0'" is because we're converting from ascii so we want to take away the offset
      next[i][j] = input[i][j] - '0';
    }
  }

  //////////////
  // do stuff //
  //////////////
  
  // run loop
  bool run = true;

  while (run)
  {

    // copy next frame into current
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        grid[i][j] = next[i][j];
      }
    }

    // draw the grid
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        char c = '.';
        if (grid[i][j]) {c = '#';}
        cout << c << " ";
      }
      cout << endl;
    }


    for (int i = height;  i < (2 * height); i++)
    {
      for (int j = width; j < (2 * width); j++)
      {
        // calculate the next frame (modulu gives infinite plane effect)
        next[i % height][j % width] = getNext(
          grid[(i) % height][(j) % width],
          grid[(i-1) % height][(j-1) % width],
          grid[(i-1) % height][(j) % width],
          grid[(i-1) % height][(j+1) % width],
          grid[(i) % height][(j-1) % width],
          grid[(i) % height][(j+1) % width],
          grid[(i+1) % height][(j-1) % width],
          grid[(i+1) % height][(j) % width],
          grid[(i+1) % height][(j+1) % width]
        );
      }
    }

    // wait
    usleep(120000);

    // clear the screen
    for (int i = 0; i < height; i++)
    {
      // print "go up a line", "clear line"
      fputs("\033[A\033[2K", stdout);
    }
  }

  /////////////
  // cleanup //
  /////////////

  // free memory
  for (int i = 0; i < height; i++)
  {
    delete[] grid[i];
  }
  delete[] grid;
}

/**
 * Firgure out whether th current grid cell should be alive or dead
 * based on the 8 surroundgin cells.
 * 
 * @param  prev   Current grid cell
 * @param  tl     Top left cell
 * @param  tc     Top center cell
 * @param  tr     Top right cell
 * @param  ml     Middle left cell
 * @param  mr     Middle right cell
 * @param  bl     Bottom left cell
 * @param  bc     Bottom center cell
 * @param  br     Bottom right cell
 * @return        0 or 1 for alive or dead (prev for no change)
 */
int getNext(int prev, int tl, int tc, int tr, int ml, int mr, int bl, int bc, int br)
{
  int neighbourSum = tl + tc + tr + ml + mr + bl + bc + br;

  if (prev)
  {
    // check for overcrowding
    if (neighbourSum >= 4)
    {
      return 0;
    }

    // check for isolation
    if (neighbourSum <= 1)
    {
      return 0;
    }
  }
  else
  {
    // check for birth
    if (neighbourSum == 3)
    {
      return 1;
    }
  }

  // otherwise no changes
  return prev;
}
