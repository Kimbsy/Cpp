#include <iostream>

using namespace std;

/**
 * Define the struct for the nodes in the tree.
 */
struct Node
{
  int key;
  string value;
  Node* left;
  Node* right;
};

/**
 * Create a node with a specific key and add it to the tree.
 *
 * @param tree  Pointer to the top node of the tree.
 * @param key   The key of the new node.
 * @param value The value of the new node.
 *
 * @return Pointer to the top node of the new tree.
 */
Node* insert(Node* tree, int key, string value)
{
  // Base case: reached an empty tree, insert node here.
  if (tree == NULL) {
    Node* newTree = new Node;
    newTree->key = key;
    newTree->value = value;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
  }

  // determine which subtree to insert into.
  if (key < tree->key) {
    // Recurse on the left subtree of this node.
    tree->left = insert(tree->left, key, value);
  }
  else {
    // Recurse on the right subtree of this node.
    tree->right = insert(tree->right, key, value);
  }

  return tree;
}

/**
 * Find a node in the tree with a specified key if any.
 *
 * @param tree Pointer to the top node of the tree.
 * @param key  The key of the node to find.
 *
 * @return Pointer to the node with the matching key or NULL if none found.
 */
Node* search(Node* tree, int key)
{
  // Base case: this node is NULL, the key does not exist, return NULL.
  // Base case: this node has a matching key, return this node.
  if (tree == NULL || tree->key == key) {
    return tree;
  }

  // Determine which subtree to search.
  if (key < tree->key) {
    // Recurse on the left subtree of this node.
    return search(tree->left, key);
  }
  else {
    // Recurse on the right subtree of this node.
    return search(tree->right, key);
  }
}

/**
 * Find the node with the highest key in the tree.
 *
 * @param tree Pointer to the top node of the tree.
 *
 * @return The node with the highest key.
 */
Node* findMax(Node* tree)
{
  // Base case: node is NULL, return NULL.
  // Base case: node has no right subtree, this node is max, return node.
  if (tree == NULL || tree->right == NULL) {
    return tree;
  }

  // Recurse on the right subtree of this node.(
    return findMax(tree->right);
}

/**
 * Remove the specified node from the tree (given that the node has the highest
 *   key in the tree).
 *
 * @param tree    Pointer to the top node in the tree.
 * @param maxNode Pointer to the node with the highest key in the tree.
 *
 * @return Pointer to the top node of the new tree.
 */
Node* removeMaxNode(Node* tree, Node* maxNode)
{
  // This shouldn't happen.
  if (tree == NULL) {
    return NULL;
  }

  // Base case: found the node, replace it.
  if (tree == maxNode) {
    // We know that tree->right is NULL from the findMaxNode function.
    return tree->left;
  }

  // Recurse on the right subtree.
  tree->right = removeMaxNode(tree->right, maxNode);
}

/**
 * Remove the node with the matching key from the tree.
 *
 * @param tree Pointer to the top node in the tree.
 * @param key  The key of the node to remove.
 *
 * @return The new tree with the node removed.
 */
Node* remove(Node* tree, int key)
{
  if (tree == NULL) {
    return NULL;
  }

  // If this is the correct node, remove it.
  if (tree->key == key) {
    // In two cases the node only has one subtree.
    if (tree->left == NULL) {
      Node* rightSubtree = tree->right;
      delete tree;
      // This could be NULL, but that's fine.
      return rightSubtree;
    }
    if (tree->right == NULL) {
      Node* leftSubtree = tree->left;
      delete tree;
      // This will always be a valid node if we've got to this point.
      return leftSubtree;
    }

    // Find the highest keyed node in the left subtree.
    Node* maxNode = findMax(tree->left);
    maxNode->left = removeMaxNode(tree->left, maxNode);
    maxNode->right = tree->right;

    delete tree;
    return maxNode;
  }
  // Otherwise determine which subtree to remove from.
  else if (key < tree->key) {
    // Recurse on the left subtree.
    tree->left = remove(tree->left, key);
  }
  else {
    // Recurse on the right subtree.
    tree->right = remove(tree->right, key);
  }

  return tree;
}

/**
 * Delete the whole tree.
 *
 * @param tree The tree do destroy.
 */
void destroyTree(Node* tree)
{
  if (tree != NULL)
  {
    // Recurse on both subtrees, then delete this node.
    destroyTree(tree->left);
    destroyTree(tree->right);
    delete tree;
  }
}

/**
 * Print the values of all nodes in a tree in either ascending or descending
 *   order.
 *
 * @param tree      Pointer to the top node of the tree.
 * @param direction Which direction to traverse the tree in.
 */
void printTree(Node* tree, string direction = "ASC")
{
  if (tree == NULL)
  {
    return;
  }

  if (direction == "DESC") {
    printTree(tree->right, direction);
    cout << tree->value << endl;
    printTree(tree->left, direction);
  }
  else {
    printTree(tree->left, direction);
    cout << tree->value << endl;
    printTree(tree->right, direction);
  }
}

/**
 * Determine if a tree is sorted correctly.
 *
 * @param tree Pointer to the top node of the tree.
 *
 * @return Whether the tree is sorted.
 */
bool checkSorting(Node* tree)
{
  // Base case: tree is NULL, tree is sorted.
  if (tree == NULL) {
    return true;
  }

  // Ensure that the subtrees have appropriate keys.
  bool sorted = true;
  if (tree->left != NULL) {
    sorted = sorted && tree->left->key < tree->key;
  }
  if (tree->right != NULL) {
    sorted = sorted && tree->right->key > tree->key;
  }

  // Recurse on the left and right subtrees.
  return sorted && checkSorting(tree->left) && checkSorting(tree->right);
}

/**
 * Determine if a binary tree is sorted.
 */
int main()
{
  Node* tree = NULL;

  tree = insert(tree, 2, "Main engine start");
  tree = insert(tree, 3, "Activate main engine hydrogen burnoff system");
  tree = insert(tree, 10, "Arm solid rocket booster range safety safe and arm devices");
  tree = insert(tree, 9, "Start orbiter aerosurface profile test, followed by main engine gimbal profile test");
  tree = insert(tree, 8, "Retract gaseous oxygen vent arm, or 'beanie cap'");
  tree = insert(tree, 11, "Start auxiliary power units");
  tree = insert(tree, 4, "Activate launch pad sound suppression system");
  tree = insert(tree, 13, "Start automatic ground launch sequencer");  
  tree = insert(tree, 7, "Crew members close and lock their visors");
  tree = insert(tree, 12, "Retract orbiter access arm");
  tree = insert(tree, 6, "Orbiter transfers from ground to internal power");
  tree = insert(tree, 1, "Lift off");
  tree = insert(tree, 5, "Ground launch sequencer is go for auto sequence start");

  bool isSorted = checkSorting(tree);

  cout << "The tree is ";
  if (!isSorted) {
    cout << "not ";
  }
  cout << "sorted." << endl;
}
