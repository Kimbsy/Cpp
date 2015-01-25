#include <iostream>
#include <string>

using namespace std;

int main()
{
  string question;
  string answer1;
  string answer2;
  string answer3;

  cout << "enter question:\n";
  getline(cin, question, '\n');

  cout << "enter answer 1:\n";
  getline(cin, answer1, '\n');

  cout << "enter answer 2:\n";
  getline(cin, answer2, '\n');

  cout << "enter answer 3:\n";
  getline(cin, answer3, '\n');

  int choice;
  double total1 = 0;
  double total2 = 0;
  double total3 = 0;

  do
  {
    cout << question << endl;
    cout << "1. " << answer1 << endl;
    cout << "2. " << answer2 << endl;
    cout << "3. " << answer3 << endl;

    cin >> choice;

    if (choice == 1)
    {
      total1++;
    }
    else if (choice == 2)
    {
      total2++;
    }
    else if (choice == 3)
    {
      total3++;
    }
  }
  while (choice != 0);

  double total = total1 + total2 + total3;

  // normalise results
  total1 = (total1 / total) * 50;
  total2 = (total2 / total) * 50;
  total3 = (total3 / total) * 50;

  cout << "\nResults:\n";
  
  cout << answer1 << ":\n";
  for (int i = 0; i < total1; i++)
  {
    cout << "/";
  }
  cout << endl;

  cout << answer2 << ":\n";  
  for (int i = 0; i < total2; i++)
  {
    cout << "/";
  }
  cout << endl;

  cout << answer3 << ":\n";
  for (int i = 0; i < total3; i++)
  {
    cout << "/";
  }
  cout << endl;
}
