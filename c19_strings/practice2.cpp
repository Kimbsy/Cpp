#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Get the data from the user.
 *
 * @param rows Pointer to a vector of strings representing the rows of data.
 */
void readInput(vector<string>* rows)
{
  string line;

  cout << endl << "Enter data rows terminated by an empty line:" << endl << endl;

  while (true) {
    getline(cin, line, '\n');

    if (line.length() == 0) {
      break;
    }

    rows->push_back(line);
  }
}

/**
 * Find all non-alphanumeric characters in this input row string.
 *
 * @param delims Pointer to the vector of delimiter characters.
 * @param row    The input row string.
 */
void detectPotentialDelimiters(vector<char>* delims, string& row)
{
  // String of non-delimiting characters.
  string alphaNum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  // For each delimiter found.
  for (int i = row.find_first_not_of(alphaNum, 0);
    i != string::npos;
    i = row.find_first_not_of(alphaNum, ++i))
  {
    // Find the delimiting character and add it to the unique vector of delims.
    char delim = row[i];
    if (find(delims->begin(), delims->end(), delim) == delims->end()) {
      delims->push_back(delim);
    }
  }
}

/**
 * Get rid of any delimiter characters that do not appear in this input row.
 *
 * @param delims Pointer to the vector of delimiter charcters.
 * @param row    The input row string.
 */
void removeUnusedDelimiters(vector<char>* delims, string& row)
{
  for (vector<char>::iterator itr = delims->begin(), end = delims->end();
    itr != end;
    ++itr)
  {
    if (row.find(*itr, 0) == string::npos) {
      delims->erase(itr);
    }
  }
}

/**
 * Get the user to decide which potential delimiter character to use.
 *
 * @param delims Pointer to the vector of delimiter characters.
 *
 * @return The chosen delimiter character.
 */
char promptDelimiterChoice(vector<char>* delims)
{
  int choice;
  cout << "Please choose from one of the following detected delimiters:" << endl;

  for (vector<char>::iterator itr = delims->begin(), end = delims->end();
    itr != end;
    ++itr)
  {
    int index = itr - delims->begin();
    cout << " >> " << index << " " << *itr << endl;
  }

  cin >> choice;

  return *(delims->begin() + choice);
}

/**
 * Determine which delimiter to use.
 *
 * In the case that no delimiters are found, it will default to a comma. If
 *   there are multiple options, the user is prompted for a decision.
 * 
 * @param delims Pointer to the vector of delimiter characters.
 *
 * @return The chosen delimiter character.
 */
char getDelimiter(vector<char>* delims)
{
  if (delims->size() == 1) {
    return *delims->begin();
  }

  char delim = ',';

  if (delims->size() > 1) {
    delim = promptDelimiterChoice(delims);
  }

  return delim;
}

/**
 * Extract the data values form each row given the specified delimiter.
 *
 * @param Pointer to the vector of input row strings.
 * @param The chosen delimiter character.
 *
 * @return @return Two dimensional vector of values extracted from the rows. 
 */
vector<vector<string> > extractData(vector<string>* rows, char delim)
{
  vector<vector<string> > data;

  // For each of the input row strings...
  for (vector<string>::iterator itr = rows->begin(), end = rows->end();
    itr != end;
    ++itr)
  {
    vector<string> rowData;

    int begin = 0;

    // Iterate over the string based on the delimiter.
    for (int i = itr->find_first_of(delim, 0);
      i != string::npos;
      i = itr->find_first_of(delim, i))
    {
      // slice the string up.
      rowData.push_back(itr->substr(begin, i - begin));
      i++;
      begin = i;
    }
    // One last one for the end.
    rowData.push_back(itr->substr(begin, itr->length() - begin));

    data.push_back(rowData);
  }

  return data;
}

/**
 * Parse the input strings.
 *
 * Detect any possible delimiters which appear in every input string, prompt the
 *   user for a choice if multiple options exist, then extract the data from
 *   each row based on the chosen delimiter.
 *
 * @param Pointer to the vector of input row strings.
 * @param Pointer to the vector of possible delimiter chars.
 *
 * @return Two dimensional vector of values parsed from input row strings. 
 */
vector<vector<string> > parseRows(vector<string>* rows, vector<char>* delims)
{
  // First of all find all non-alphanumeric characters which could be used as
  //   delimiters.
  for (vector<string>::iterator itr = rows->begin(), end = rows->end();
    itr != end;
    ++itr)
  {
    detectPotentialDelimiters(delims, *itr);
  }

  // Remove any characters that do not appear in every input string.
  for (vector<string>::iterator itr = rows->begin(), end = rows->end();
    itr != end;
    ++itr)
  {
    removeUnusedDelimiters(delims, *itr);
  }

  // Choose a delimiter.
  char delim = getDelimiter(delims);

  // Extract the data.
  vector<vector<string> > data = extractData(rows, delim);

  return data;
}

/**
 * Output the data parsed form the user input.
 *
 * @param data Two dimensional vector of values parsed from tabular data.
 */
void printData(vector<vector<string> > data)
{
  cout << endl;

  for (vector<vector<string> >::iterator itr = data.begin(), end = data.end();
    itr != end;
    ++itr)
  {
    for (vector<string>::iterator it2 = itr->begin(), end = itr->end();
      it2 != end;
      ++it2)
    {
      cout << *it2 << endl;
    }
    cout << endl;
  }
}

/**
 * Tabular data parser.
 *
 * Allows user to input tabluar data using any non-alphanumeric delimiter. If
 *   multiple are found, the user is prompted to specify which one to use.
 */
int main()
{
  vector<string>* rows = new vector<string>;
  vector<char>* delims = new vector<char>;

  readInput(rows);

  vector<vector<string> > data = parseRows(rows, delims);

  printData(data);
}
