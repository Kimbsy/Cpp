#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

int main (int argc, char* argv[])
{
  // font file name
  string fontFile = "motdFontTopBar";

  // check arguments are ok
  if (argc < 2) {
    cout << "Too few arguments:\n";
    cout << "      Usage: ./server_motd_generator <server_name> [<descriptor_1>] [<descriptor_2>] [...]\n";
    return 1;
  }

  // grab the new name
  string serverName = argv[1];

  // make it lower case
  transform(serverName.begin(), serverName.end(), serverName.begin(), ::tolower);

  // and the number of descriptors
  // minus one for progam name, one for server name
  int descNum = argc - 2;

  // define order of punctuation in fontFile
  char punctArray[26] = {'!','?','.',',','/',':',';','#','@','[',']','(',')','_','<','>','1','2','3','4','5','6','7','8','9','0'};

  // each character is 9 lines high (first line is width int)
  // 8 * 52 = 416
  string fontArray[416];

  // get input from file
  ifstream inputFile(fontFile.c_str());

  // there are 8 * 52 lines in the fontFile
  for (int i = 0; i < 416; i++)
  {
    // get a line from the file
    string line = "";
    getline(inputFile, line);

    // stick it in fontArray
    fontArray[i] = line.c_str();
  }

  // close the file
  inputFile.close();

  // output is 7 lines high (we'll do the 8th serperately)
  string outputArray[7] = { "╔", "║", "║", "║", "║", "║", "║"};

  // for each character of the server name, loop through that characters lines appending them to output
  for (int i = 0; i < serverName.length(); i++)
  {
    // figure out starting line number
    int startLine = 8 * (((int) serverName[i]) - 97);

    int k = 0;

    if (startLine >= 0)
    {
      for (int j = startLine + 1; j < (startLine + 8); j++)
      {
        outputArray[k] += fontArray[j];
        k++;
      }
    }
    else
    {
      // we're adding a space
      // top
      outputArray[0] += "════";

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

    if (strlen(argv[i]) > longest)
    {
      longest = strlen(argv[i]);
    }
  }

  // create bottom line
  string bottom = "╚╦";

  // extra 2 for spaces
  for (int i = 0; i < (longest + 2); i++)
  {
    bottom += "═";
  }

  bottom += "╦";

  // divide by 3 bytes
  for (int i = 0; i < (strlen(outputArray[0].c_str()) / 3) - (longest + 6); i++) {
    bottom += "═";
  }

  bottom += "╝";

  // output
  for (int i = 0; i < 7; i++)
  {
    cout << outputArray[i] << endl;
  }

  cout << bottom << endl;

  // descriptors
  for (int i = 2; i < argc; i++)
  {
    if (i != 2)
    {
      cout << " ║ " << string(longest, ' ') << " ║\n";
    }

    int extraSpace = longest - strlen(argv[i]);
    cout << " ║ " << argv[i] << string(extraSpace, ' ') << " ║\n";
  }

  // descriptor bottom
  cout << " ╚";
  for (int i = 0; i < (longest + 2); i++)
  {
    cout << "═";
  }
  cout << "╝";

  cout << endl;

}
