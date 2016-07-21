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
  string name;
  ListItem* nextItem;
};

/**
 * Create a new ListItem with a given name and add it to the list.
 *
 * @param list Pointer to the first item in the list.
 * @param name The name of the new ListItem.
 *
 * @return The item which was added.
 */
ListItem* addItemToList(ListItem* list, string name)
{
  ListItem* item = new ListItem;

  item->id       = nextId;
  item->name     = name;
  item->nextItem = list;

  nextId++;

  return item;
}

/**
 * Get the first item from the list with a matching name.
 *
 * @param list Pointer to the first item in the list.
 * @param name The name to serach for.
 *
 * @return The item with the matching name.
 */
ListItem* getItemFromListByName(ListItem* list, string name)
{
  ListItem* curr = list;

  while (curr != NULL) {
    if (curr->name == name) {
      return curr;
    }
    curr = curr->nextItem;
  }
}

/**
 * Print the elements of the list to the screen.
 *
 * @param list Pointer to the first element in the list.
 */
void printList(ListItem* list)
{
  ListItem* curr = list;

  while (curr != NULL) {
    cout << curr->name << " ";
    curr = curr->nextItem;
  }
  cout << endl;
}

/**
 * Add items to list in alphabetical order.
 */
int main()
{
  ListItem* list = NULL;

  string names[] = {
    "Hookbill",
    "Nighthawk",
    "Cormorant",
    "Brutix",
    "Wyvern",
  };

  for (string name : names) {
    list = addItemToList(list, name);
  }
  printList(list);

  cout << "Enter the name of an item:" << endl;
  string searchName;
  cin >> searchName;
  
  ListItem* foundItem = getItemFromListByName(list, searchName);
  cout << "Id found: " << foundItem->id << endl;
}