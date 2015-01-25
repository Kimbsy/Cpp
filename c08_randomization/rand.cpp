#include <iostream>
// needed for rand()
#include <cstdlib>
// neede for time()
#include <ctime>

using namespace std;

int main()
{
  // seed once at the start of the program
  srand(time(NULL));

  cout << rand() << endl;
}
