#include <iostream>

using namespace std;

/**
 * Recursively print an array in reverse order.
 *
 * @param countdown The array of strings to print.
 * @param size      The number of elements in the array.
 * @param stage     Which element we have got to.
 */
void printReverseArray(string countdown[], int size, int stage = 0)
{
  if (stage == size) {
    return;
  }
  printReverseArray(countdown, size, stage + 1);
  cout << countdown[stage] << endl;
}

/**
 * Recursively print an array of strings in reverse order.
 */
int main()
{
  string countdown[] = {
    "Lift off",
    "Main engine start",
    "Activate main engine hydrogen burnoff system",
    "Activate launch pad sound suppression system",
    "Ground launch sequencer is go for auto sequence start",
    "Orbiter transfers from ground to internal power",
    "Crew members close and lock their visors",
    "Retract gaseous oxygen vent arm, or 'beanie cap'",
    "Start orbiter aerosurface profile test, followed by main engine gimbal profile test",
    "Arm solid rocket booster range safety safe and arm devices",
    "Start auxiliary power units",
    "Retract orbiter access arm",
    "Start automatic ground launch sequencer",
  };

  printReverseArray(countdown, 13);
}
