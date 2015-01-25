#include <iostream>

using namespace std;

struct PlayerInfo
{
  int skillLevel;
  string name;
};

int main()
{
  // like normal variables, you can make an array out of structs
  PlayerInfo players[5];

  for (int i = 0; i < 5; i++)
  {
    // access PlayerInfo struct at index, then access field of that struct using '.' syntax
    cout << "Please enter the name for player : " << i << endl;
    cin >> players[i].name;

    cout << "Please enter skill level for " << players[i].name << endl;
    cin >> players[i].skillLevel;
  }

  for (int i = 0; i < 5; i++)
  {
    cout << players[i].name
         << " is at skill level : "
         << players[i].skillLevel
         << endl;
  }
}
