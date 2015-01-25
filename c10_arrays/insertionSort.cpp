#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int findSmallestRemainingElement(int array[], int size, int index);
void swap(int array[], int firstIndex, int secondIndex);

void sort(int array[], int size)
{
  // loop through array
  for (int i = 0; i < size; i++)
  {
    // find smallest number with index greater than i
    int index = findSmallestRemainingElement(array, size, i);
    // swap numbers
    swap(array, i, index);
  }
}

int findSmallestRemainingElement(int array[], int size, int index)
{
  // start at the beginning of unsorted numbers
  int indexOfSmallestValue = index;

  // loop through array
  for (int i = index + 1; i < size; i++)
  {
    // if new number is smaller, use it's index
    if (array[i] < array[indexOfSmallestValue])
    {
      indexOfSmallestValue = i;
    }
  }

  // return index ofsmallest unsorted number
  return indexOfSmallestValue;
}

void swap(int array[], int firstIndex, int secondIndex)
{
  // use temp variable to swap array elements
  int temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}

/**
 * helper function to display before and after arrays
 */
void displayArray(int array[], int size)
{
  cout << "{";
  for (int i = 0; i < size; i++)
  {
    // comma list formatting
    if (i != 0)
    {
      cout << ", ";
    }
    cout << array[i];
  }
  cout << "}";
}

int main()
{
  int num;

  cout << "enter num of array:\n";
  cin << num;

  // declare array
  int array[10];

  // seed random
  srand(time(NULL));

  for (int i= 0; i < 10; i++)
  {
    // initialise with small random numbers
    array[i] = rand() % 100;
  }

  // show original
  cout << "Original array:\n";
  displayArray(array, 10);
  cout << endl;

  // sort array
  // (arrays passed into functions can be edited, unlike variables)
  sort(array, 10);

  // show sorted
  cout << "Sorted array:\n";
  displayArray(array, 10);
  cout << endl;
}
