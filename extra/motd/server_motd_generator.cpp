#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int main (int argc, char* argv[])
{
  cout << argv[0];
  // font file name
  string fontFile = "motdFont";

  // check arguments are ok
  if (argc < 2) {
    cout << "Too few arguments:\n";
    cout << "      Usage: ./server_motd_generator <server_name> [<descriptor_1>] [<descriptor_2>] [...]\n";
    return 1;
  }

  // grab the new name
  string serverName = argv[1];

  cout << serverName;

  // make it lower case
  transform(serverName.begin(), serverName.end(), serverName.begin(), ::tolower);

  // and the number of descriptors
  // minus one for progam name, one for server name
  int descNum = argc - 2;

  // define order of punctuation in fontFile
  char punctArray[26] = {'!','?','.',',','/',':',';','#','@','[',']','(',')','_','<','>','1','2','3','4','5','6','7','8','9','0'};

  // each character is 9 lines high (first line is width int)
  // 9 * 52 = 468
  string fontArray[234];

  // get input from file
  ifstream inputFile(fontFile.c_str());

  // there are 9 * 52 lines in tthe fontFile
  for (int i = 0; i < 234; i++)
  {
    // get a line from the file
    string line = "";
    getline(inputFile, line);

    // stick it in fontArray
    fontArray[i] = line.c_str();
  }

  // close the file
  inputFile.close();

  // output is 8 lines high
  string outputArray[8] = { "╔", "║", "║", "║", "║", "║", "║", "╚"};

  // for each character of the server name, loop through that characters lines appending them to output
  for (int i = 0; i < serverName.length(); i++)
  {
    // figure out starting line number
    int startLine = 9 * (((int) serverName[i]) - 97);

    int k = 0;

    if (startLine >= 0)
    {
      for (int j = startLine + 1; j < (startLine + 9); j++)
      {
        outputArray[k] += fontArray[j];
        k++;
      }
    }
    else
    {
      // we're adding a space
      // top and bottom
      outputArray[0] += "════";
      outputArray[7] += "════";

      // middle
      for (int j = 1; j < 7; j++)
      {
        // 4 spaces
        outputArray[j] += "    ";
      }
    }
  }

  // add end cap
  // top and bottom
  outputArray[0] += "╗";
  outputArray[7] += "╝";
  
  // middle
  for (int i = 1; i < 7; i++)
  {
    outputArray[i] += "║";
  }




  // add  descriptors

  // find longest descriptor
  int longest = 0;
  for (int i = 2; i < argc; i++)
  {

    cout << sizeof(argv[i]);

    if (sizeof(argv[i]) > longest)
    {
      longest = sizeof(argv[i]);
    }
  }

  cout << longest << endl;




  // output
  for (int i = 0; i < 8; i++)
  {
    cout << outputArray[i] << endl;
  }

}
