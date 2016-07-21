#include <iostream>

using namespace std;

// The next available id.
int nextId = 0;

/**
 * Define the struct for the items in the list.
 */
struct ListItem
{
  int id;
  ListItem* nextItem;
};

/**
 * Add items to a linked list recursively.
 *
 * @param list  Pointer to the first item in the linked list.
 * @param count How many items to add.
 *
 * @return The list of items.
 */
ListItem* addItems(ListItem* list, int count)
{
  if (count == 0) {
    return list;
  }

  ListItem* item = new ListItem;
  item->id = nextId;
  nextId++;
  item->nextItem = list;

  return addItems(item, count - 1);
}

/**
 * Remove all items from a linked list recursively.
 *
 * @param list Pointer to the first item in the linked list.
 *
 * @return The empty list of items.
 */
ListItem* removeItems(ListItem* list)
{
  ListItem* nextItem = list->nextItem;

  if (nextItem == NULL) {
    return nextItem;
  }

  delete list;

  return removeItems(nextItem);
}

/**
 * Print the elements of the list to the screen.
 *
 * @param list Pointer to the first element in the list.
 */
void printList(ListItem* list)
{
  if (list == NULL) {
    cout << "List is empty" << endl;
    return;
  }

  ListItem* curr = list;

  while (curr != NULL) {
    cout << curr->id << " ";
    curr = curr->nextItem;
  }
  cout << endl;
}

/**
 * Recursively add and remove elements from a linked list.
 */
int main()
{
  ListItem* list = NULL;

  cout << "Adding items..." << endl;
  list = addItems(list, 10);
  printList(list);

  cout << "Removing items..." << endl;
  list = removeItems(list);
  printList(list);
}
