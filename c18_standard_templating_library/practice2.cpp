#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Vector of player scores.
vector<long> scores;
// Vector of player names.
vector<string> names;

/**
 * Get a new high score.
 *
 * @param score Pointer to the player's score variable.
 * @param name  Pointer to the player's name variable.
 */
void getInput(long* score, string* name)
{
  cout << "Enter your score:" << endl;
  cin >> *score;
  cout << "Enter your name" << endl;
  cin >> *name;
}

/**
 * Display the current high score list.
 */
void showScores()
{
  // Get longest name.
  int maxLength = 0;
  for (int i = 0; i < names.size(); i++) {
    int length = names[i].length();
    maxLength  = maxLength < length ? length : maxLength;
  }

  cout << endl;
  for (int i = 0; i < scores.size(); i++) {
    cout << right << setw(maxLength + 2) << names[i] << " --> " << scores[i] << endl;
  }
  cout << endl;
}

/**
 * Add a player's score and name to the appropriate places in each vector.
 *
 * @param score The player's score.
 * @param name  The player's name.
 */
void addScore(long score, string name)
{
  vector<long>::iterator scoreItr  = scores.begin();
  vector<string>::iterator nameItr = names.begin();

  if (scores.size() == 0) {
    scores.insert(scoreItr, score);
    names.insert(nameItr, name);
    return;
  }

  for (int i = 0; i < scores.size(); i++) {
    if (scores[i] < score) {
      
      scores.insert(scoreItr + i, score);
      names.insert(nameItr + i, name);
      return;
    }
  }

  scores.insert(scores.end(), score);
  names.insert(names.end(), name);
  return;
}

/**
 * The main highScore program loop.
 */
void highScore()
{
  long score;
  string name;

  getInput(&score, &name);
  addScore(score, name);
  showScores();

  // Recurse to kepp the program running.
  highScore();
}

/**
 * High score program.
 *
 * Implemented using vectors, allow user to continuously add new high scores.
 */
int main()
{
  highScore();
}
