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
 * Create an new ListItem with a given name, add it to the list in the correct
 *   place.
 *
 * @param list Pointer to the first element in the list.
 * @param name The name of the new ListItem.
 *
 * @return Pointer to the first element in the list.
 */
ListItem* addItemToListAlphabetically(ListItem* list, string name)
{
  ListItem* item = new ListItem;

  item->id = nextId;
  item->name = name;

  // If the list is empty, just return the new item.
  if (list == NULL) {
    return item;
  }

  // Check if the new ListItem should be at the start of the list.
  if (list->name > item->name) {
    item->nextItem = list;
    return item;
  }

  // Traverse the list to find where the new ListItem should go.
  ListItem* curr = list;

  while (curr != NULL) {
    if (curr->nextItem == NULL || curr->nextItem->name > item->name) {
      item->nextItem = curr->nextItem;
      curr->nextItem = item;
      break;
    }

    curr = curr->nextItem;
  }

  return list;
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
    "Firetail",
    "Stiletto",
    "Claymore",
    "Hoarder",
    "Bellicose",
  };

  for (string name : names) {
    list = addItemToListAlphabetically(list, name);
    printList(list);
  }
}