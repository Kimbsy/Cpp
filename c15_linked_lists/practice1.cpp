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
 * Create a new ListItem and add it to the list.
 *
 * @param list Pointer to the first item in the list.
 *
 * @return The item which was added.
 */
ListItem* addItemToList(ListItem* list)
{
  ListItem* item = new ListItem;

  item->id       = nextId;
  item->nextItem = list;

  nextId++;

  return item;
}

/**
 * Remove the item with the matching id from the list.
 *
 * @param list Pointer to the first item in the list.
 * @param id   The id of the item to remove.
 */
void removeListItem(ListItem* list, int id)
{
  ListItem* curr = list;
  ListItem* prev = NULL;

  while (curr != NULL) {
    if (curr->id == id) {
      prev->nextItem = curr->nextItem;
      delete curr;
      break;
    }
    prev = curr;
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
    cout << curr->id << " ";
    curr = curr->nextItem;
  }
  cout << endl;
}

/**
 * Create a linked list, then remove an item from the list.
 */
int main()
{
  ListItem* list = NULL;

  for (int i = 0; i < 10; i++) {
    list = addItemToList(list);
    printList(list);
  }

  int choice;
  cout << "Which number would you like to remove?" << endl;
  cin >> choice;

  removeListItem(list, choice);
  printList(list);
}
