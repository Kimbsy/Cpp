#include <iostream>
#include <map>

using namespace std;

/**
 * Determine what the user wants to do.
 *
 * @return The choice the user made.
 */
int getChoice()
{
  cout << "Please choose one of the following options:" << endl;

  cout << " >> 1. Add a new contact." << endl;
  cout << " >> 2. List all current contacts." << endl;
  cout << " >> 3. Edit an existing contact." << endl;
  cout << " >> 4. Delete an existing contact." << endl;
  cout << " >> 5. Exit the program." << endl;

  int choice;
  cin >> choice;

  return choice;
}

/**
 * Add a contact.
 *
 * @param book Map of names and addresses.
 *
 * @return The address book map.
 */
map<string, string> addContact(map<string, string> book)
{
  string name, email;

  cout << "Enter the name of the contact:" << endl;
  cin >> name;
  cout << "Enter the email address of the contact:" << endl;
  cin >> email;

  book[name] = email;

  return book;
}

/**
 * List all contacts.
 *
 * @param book Map of names and addresses.
 */
void listContacts(map<string, string> book)
{
  for (map<string, string>::iterator itr = book.begin(), end = book.end();
       itr != end;
       ++itr)
  {
    cout << itr->first << " --> " << itr->second << endl;
  }
}

/**
 * Edit a contact.
 *
 * @param book Map of names and addresses.
 *
 * @return The address book map.
 */
map<string, string> editContact(map<string, string> book)
{
  string name, newName, newEmail;

  cout << "Enter the name of the contact you would like to edit:" << endl;
  cin >> name;

  // Ensure the contact exists.
  map<string, string>::iterator itr = book.find(name);
  if (itr == book.end()) {
    cout << "Contact not found." << endl;
    return book;
  }

  cout << "Enter the new name of the contact:" << endl;
  cin >> newName;
  cout << "Enter the new email address of the contact:" << endl;
  cin >> newEmail;

  book.erase(name);
  book[newName] = newEmail;

  return book;
}

/**
 * Delete a contact.
 *
 * @param book Map of names and addresses.
 *
 * @return The address book map.
 */
map<string, string> deleteContact(map<string, string> book)
{
  string name;

  cout << "Enter the name of the contact you would like to edit:" << endl;
  cin >> name;

  // Ensure the contact exists.
  map<string, string>::iterator itr = book.find(name);
  if (itr == book.end()) {
    cout << "Contact not found." << endl;
    return book;
  }

  book.erase(name);

  return book;
}

/**
 * The main address book program loop.
 *
 * @param book Map of names and addresses.
 */
void addressBook(map<string, string> book)
{
  bool exit  = false;
  int choice = getChoice();

  switch (choice) {
    case 1:
      cout << endl;
      book = addContact(book);
      cout << endl;
      break;
    case 2:
      cout << endl;
      listContacts(book);
      cout << endl;
      break;
    case 3:
      cout << endl;
      book = editContact(book);
      cout << endl;
      break;
    case 4:
      cout << endl;
      book = deleteContact(book);
      cout << endl;
      break;
    default:
      exit = true;
  }

  // Recurse to keep the program running.
  if (!exit) {
    addressBook(book);
  }
}

/**
 * Small address book program.
 *
 * Allows user to enter names and email addresses, remove or change entries, and
 *   list the entries.
 */
int main()
{
  map<string, string> book;

  addressBook(book);
}
