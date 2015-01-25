#include <iostream>
#include <string>

using namespace std;

string getThreeDigitText(int num);
string getTwoDigitName(int num);
string getTenName(int num);

void error(int num, string function);

int main()
{
  int num;

  do
  {
    cout << "\nEnter your number:\n\n";
    cin >> num;

    string output;

    if (num < 0)
    {
      // prepend minus
      output += "minus ";
      // set to positive (adding double itself)
      num += (2 * (-num));
    }

    // if more than three digits
    if (num > 999 || num < -999)
    {
      output += getThreeDigitText(num / 1000) + " thousand ";
    }

    output += getThreeDigitText(num % 1000);

    cout << output << "\n\n";
  } while (num != 0);
}

string getThreeDigitText(int num)
{
  // get number of hundreds (int will truncate)
  int hundreds = num / 100;

  // get remainder
  int rem = num % 100;

  if (hundreds > 0)
  {
    return getTwoDigitName(hundreds) + " hundred and " + getTwoDigitName(rem);
  }
  else
  {
    return getTwoDigitName(rem);
  }
}

string getTwoDigitName(int num)
{
  if (num < 20)
  {
    switch (num % 10)
    {
      case 0:
        if (num < 10)
        {
          return "";
        }
        else
        {
          return "ten";
        }
        break;
      case 1:
        if (num < 10)
        {
          return "one";
        }
        else
        {
          return "eleven";
        }
        break;
      case 2:
        if (num < 10)
        {
          return "two";
        }
        else
        {
          return "twelve";
        }
        break;
      case 3:
        if (num < 10)
        {
          return "three";
        }
        else
        {
          return "thriteen";
        }
        break;
      case 4:
        if (num < 10)
        {
          return "four";
        }
        else
        {
          return "fourteen";
        }
        break;
      case 5:
        if (num < 10)
        {
          return "five";
        }
        else
        {
          return "fifteen";
        }
        break;
      case 6:
        if (num < 10)
        {
          return "six";
        }
        else
        {
          return "sixteen";
        }
        break;
      case 7:
        if (num < 10)
        {
          return "seven";
        }
        else
        {
          return "seventeen";
        }
        break;
      case 8:
        if (num < 10)
        {
          return "eight";
        }
        else
        {
          return "eighteen";
        }
        break;
      case 9:
        if (num < 10)
        {
          return "nine";
        }
        else
        {
          return "nineteen";
        }
        break;
      default:
        error(num, "getTwoDigitName()");
        break;
      }
  }
  else
  {
    // get number of tens (int will truncate)
    int tens = num / 10;

    // get remainder
    int rem = num % 10;

    return getTenName(tens) + getTwoDigitName(rem);
  }
}

string getTenName(int tens)
{
  switch (tens)
  {
    case 2:
      return "twenty ";
      break;
    case 3:
      return "thirty ";
      break;
    case 4:
      return "fourty ";
      break;
    case 5:
      return "fifty ";
      break;
    case 6:
      return "sixty ";
      break;
    case 7:
      return "seventy ";
      break;
    case 8:
      return "eighty ";
      break;
    case 9:
      return "ninety ";
      break;
    default:
      error(tens, "getTenName()");
      break;
  }
}

void error(int num, string function)
{
  cout << "/**\n";
  cout << " * ERROR. Invalid number: " << num << endl;
  cout << " * in function: " << function << endl;
  cout << " **/\n";
}
