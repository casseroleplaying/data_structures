#pragma once

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct treeNode {
    int number;
    string name, symbol;
    treeNode *left, *right;
};

class BST {
public:
    BST();
    ~BST();

    treeNode* allocNode();
    void insert(string name, string symbol, int num);
    int calcHeight(treeNode* n);
    void deleteTree(treeNode* n);
    int getHeight();

    treeNode* getRoot() const;
    int countLeaves() const;
    treeNode* searchTree(treeNode* np, string n) const;
    void printPrefix(treeNode* n) const;
    void printInfix(treeNode* n) const;
    void printPostfix(treeNode* n) const;

private:
    treeNode* root;
    int numLeaves;
};

// BST() - constructor
// Postcondition - initializes root pointer to null and number of leaves to zero
BST::BST()
{
    root = nullptr;
    numLeaves = 0;
}

// ~BST() - destructor
// Postcondition - destroys objest and frees all dynamically allocated memory
BST::~BST() { deleteTree(root); }

// allocNode() - attempts allocation of a new node for the binary search tree
// Postcondition - returns a pointer to the new node on success
//               - displays error and exits program on failure
treeNode* BST::allocNode()
{
    try {
        treeNode* np = new treeNode;
        return np;
    }
    catch (bad_alloc bad) {
        cerr << "Error, failed to dynamically allocate a new node.\n";
        exit(1);
    }
}

// insert() - inserts a node containing name into the binary search tree
// Postcondition - node is inserted at the proper placement according to the 
//               - properties of a BST. If the name was already in a tree node, 
//               - it is not added.
void BST::insert(string name, string symbol, int num)
{
    treeNode* temp = root;
    treeNode* np = allocNode();

    np->name = name;
    np->symbol = symbol;
    np->number = num;
    np->left = np->right = nullptr;

    if (root == nullptr)
        root = np;

    // find the proper location for the new node, proceeding iteratively through
    // the tree and assigning non-duplicate name at the appropriate terminal point
    while (temp != nullptr) {

        if (np->name == temp->name)
            temp = nullptr;

        else if (np->name < temp->name && temp->left == nullptr) {
            temp->left = np;
            temp = nullptr;
        }

        else if (np->name < temp->name)
            temp = temp->left;

        else if (np->name > temp->name&& temp->right == nullptr) {
            temp->right = np;
            temp = nullptr;
        }

        else if (np->name > temp->name)
            temp = temp->right;
    }

    numLeaves++;
}

// calcHeight() - returns an integer value representing the height of the tree
int BST::calcHeight(treeNode* n)
{
    // add nothing if we hit a terminal node
    if (n == nullptr)
        return 0;

    // recursively process sub trees
    int leftHeight = calcHeight(n->left);
    int rightHeight = calcHeight(n->right);

    // calculate based off the longest path to a single node
    return max(leftHeight + 1, rightHeight + 1);
}

// deleteTree() - deletes all nodes in the tree
// Postcondition - all dynamically allocated memory is freed and the tree is empty
void BST::deleteTree(treeNode* n)
{
    // base case: the tree is empty/fully deleted
    if (n == nullptr)
        return;

    // recursively delete every node via postfix traversal
    deleteTree(n->left);
    deleteTree(n->right);
    free(n);
}

// getRoot() - returns a pointer to the root of the tree
treeNode* BST::getRoot() const { return root; }

// getHeight() - returns the height of the tree 
int BST::getHeight() { return calcHeight(root); }

// countLeaves() - returns the number of leaves in the tree
int BST::countLeaves() const { return numLeaves; }

// searchTree() - searches the tree for key
//              - on success, returns a pointer to the node containing the key
//              - on failure, returns a mull pointer
treeNode* BST::searchTree(treeNode* np, string key) const
{
    if (!isupper(key[0]))
        key[0] = toupper(key[0]);

    for (int i = 1; i < key.length(); i++) {
        if (!islower(key[i]))
            key[i] = tolower(key[i]);
    }

    // search concludes if key found or tree is empty
    if (np == nullptr || np->name == key)
        return np;

    // search the left sub tree if needed
    if (key < np->name)
        return searchTree(np->left, key);

    // search right sub tree if needed
    return searchTree(np->right, key);
}

// printPrefix() - prints the tree contents in Prefix order
void BST::printPrefix(treeNode* n) const
{
    cout << n->number << " " << n->name << " [" << n->symbol << "]\n";

    if (n->left != nullptr)
        printPrefix(n->left);

    if (n->right != nullptr)
        printPrefix(n->right);
}

// printInfix() - prints the tree contents in Infix order
void BST::printInfix(treeNode* n) const
{
    if (n->left != nullptr)
        printInfix(n->left);

    cout << n->number << " " << n->name << " [" << n->symbol << "]\n";

    if (n->right != nullptr)
        printInfix(n->right);
}

// printPostfix() - prints the tree contents in Postfix order
void BST::printPostfix(treeNode* n) const
{
    if (n->left != nullptr)
        printPostfix(n->left);

    if (n->right != nullptr)
        printPostfix(n->right);

    cout << n->number << " " << n->name << " [" << n->symbol << "]\n";
}
