#include <iostream>

using namespace std;

/**
 * Get the inputs form the user.
 *
 * @param needle   Pointer to the needle variable.
 * @param haystack Pointer to the haystack variable.
 */
void readInput(string* needle, string* haystack)
{
  cout << "Enter the needle string." << endl;
  cin >> *needle;
  cout << "Enter the haystack string." << endl;
  cin >> *haystack;
}

/**
 * Count the number of instaces of needle in haystack.
 *
 * @param needle   Pointer to the needle variable.
 * @param haystack Pointer to the haystack variable.
 */
int countSubstrings(string* needle, string* haystack)
{
  int count = 0;

  cout << *haystack << endl;
  cout << *needle << endl;

  for (int i = haystack->find(*needle, 0);
    i != string::npos;
    i = haystack->find(*needle, ++i))
  {
    count++;
  }

  return count;
}

/**
 * Substring counting program.
 */
int main()
{
  string* needle   = new string;
  string* haystack = new string;

  readInput(needle, haystack);

  int count = countSubstrings(needle, haystack);

  cout << "There are " << count << " instaces of" << endl;
  cout << endl << *needle << endl;
  cout << endl << "in" << endl;
  cout << endl << *haystack << endl;
}
