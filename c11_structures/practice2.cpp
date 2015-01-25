#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Ship
{
  int xPos;
  int yPos;

  int dir[2];
};

Ship newShip(int width, int height)
{
  Ship ship;

  ship.xPos = rand() % width;
  ship.yPos = rand() % height;

  if (rand() % 2)
  {
    ship.dir[0] = 1;
  }
  else
  {
    ship.dir[0] = -1;
  }

  if (rand() % 2)
  {
    ship.dir[1] = 1;
  }
  else
  {
    ship.dir[1] = -1;
  }

  return ship;
}

Ship moveShip(Ship ship)
{
  ship.xPos += ship.dir[0];

  ship.yPos += ship.dir[1];

  return ship;
}

int main()
{

  // screen dimensions
  int width = 1024;
  int height = 768;

  // set random number
  srand(time(NULL));

  Ship fleet[10];

  // initialize ships
  for (int i = 0; i < 10; i++)
  {
    fleet[i] = newShip(width, height);
  }

  bool anyMoved;

  do
  {
    // apparently this is a really bad way of clearing the  screen
    if (system("CLS"))
    {
      system("clear");
    }

    anyMoved = false;
    for (int i = 0; i < 10; i++)
    {
      // if not off screen already
      if (!(fleet[i].xPos < 0 || fleet[i].xPos > width || fleet[i].yPos < 0 || fleet[i].yPos > height))
      {
        fleet[i] = moveShip(fleet[i]);
        anyMoved = true;
      }

      cout << i << "\t(" << fleet[i].xPos << ", " << fleet[i].yPos << ")\n";
    }
  } while (anyMoved);
}
