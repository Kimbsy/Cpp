#include <iostream>

using namespace std;

struct EnemyShip
{
  int xCoord;
  int yCoord;
  int weaponPower;
};

EnemyShip getNewEnemy()
{
  EnemyShip ship;

  ship.xCoord = 0;
  ship.yCoord = 0;
  ship.weaponPower = 20;

  return ship;
}

EnemyShip upgradeWeapons(EnemyShip ship)
{
  ship.weaponPower += 10;

  return ship;
}

int main()
{
  EnemyShip enemy = getNewEnemy();
  enemy = upgradeWeapons(enemy);
}
