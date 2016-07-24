#include <iostream>
#include <vector>

using namespace std;

/**
 * The User struct holds the username and plaintext password.
 */
struct User
{
  string username, password;
};

vector<User> users;

/**
 * Determine what the user wants to do.
 *
 * @return The choice the user made.
 */
int getAdminChoice()
{
  cout << "Please choose one of the following options:" << endl;

  cout << " >> 1. Change password." << endl;
  cout << " >> 2. Log out." << endl;

  int choice;
  cin >> choice;
  return choice;
}

/**
 * Change a User's password.
 *
 * @param username The username of the User.
 */
void changePassword(string username)
{
  string newPassword;

  cout << "Enter your new password:" << endl;
  cin >> newPassword;

  for (vector<User>::iterator itr = users.begin(), end = users.end();
    itr != end;
    ++itr)
  {
    if (username == itr->username) {
      itr->password = newPassword;
    }
  }
}

/**
 * The adminSystem loop.
 *
 * Allows a logged User to change their password or log out.
 */
void adminSystem(string username, string password)
{
  int choice = getAdminChoice();

  switch (choice) {
    case 1:
      changePassword(username);
      break;
    case 2:
      return;
      break;
  }

  // Recurse until logout (case 2) is chosen.
  adminSystem(username, password);
}

/**
 * Determine what the user wants to do.
 *
 * @return The choice the user made.
 */
int getChoice()
{
  cout << "Please choose one of the following options:" << endl;

  cout << " >> 1. Log in." << endl;
  cout << " >> 2. Register." << endl;

  int choice;
  cin >> choice;
  return choice;
}

/**
 * Ensure that the username and password match.
 *
 * @param username The username to check.
 * @param password The password to check.
 *
 * @return Whether the credentials check out.
 */
bool checkCredentials(string username, string password)
{
  for (vector<User>::iterator itr = users.begin(), end = users.end();
    itr != end;
    ++itr)
  {
    if (username == itr->username && password == itr->password) {
      return true;
    }
  }

  return false;
}

/**
 * Allow the User to log in to the adminSystem loop.
 */
void loginUser()
{
  string username, password;

  cout << "Enter your username:" << endl;
  cin >> username;
  cout << "Enter your password:" << endl;
  cin >> password;

  if (!checkCredentials(username, password)) {
    cout << endl;
    cout << "Username and password do not match." << endl;
    cout << endl;
    return;
  }

  cout << endl;
  cout << "Successful login." << endl;
  cout << endl;

  adminSystem(username, password);
}

/**
 * Check if a username is not already used.
 *
 * @param username The username to check.
 *
 * @return Whether the username is available.
 */
bool userNameIsAvailable(string username)
{
  for (vector<User>::iterator itr = users.begin(), end = users.end();
    itr != end;
    ++itr)
  {
    if (username == itr->username) {
      return false;
    }
  }

  return true;
}

/**
 * Prompt the User for a unique username.
 *
 * @return The new username.
 */
string getUserName()
{
  string username;

  cout << "Enter a username:" << endl;
  cin >> username;

  if (!userNameIsAvailable(username)) {
    cout << endl;
    cout << "That username is unavailable" << endl;
    cout << endl;
    return getUserName();
  }

  return username;
}

/**
 * Create a new User struct and add it to the global users vector.
 *
 * @param username The new User's username.
 * @param password The new User's password.
 */
void createNewUser(string username, string password)
{
  cout << "fine" << endl;
  User user;

  user.username = username;
  user.password = password;

  users.push_back(user);
}

/**
 * Register a new User.
 */
void registerUser()
{
  string username, password;

  username = getUserName();

  cout << "Enter a password:" << endl;
  cin >> password;

  createNewUser(username, password);
}

/**
 * The main loginSystem program loop.
 */
void loginSystem()
{
  int choice = getChoice();

  switch (choice) {
    case 1:
      loginUser();
      break;
    case 2:
      registerUser();
      break;
  }

  loginSystem();
}

/**
 * Basic log in program.
 *
 * Allows a User to log in or register as a new User.
 */
int main()
{
  loginSystem();
}
