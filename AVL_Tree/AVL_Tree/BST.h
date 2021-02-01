#ifndef BST_H
#define BST_H

#include <algorithm>
#include <iostream>
using namespace std;

class BST {
public:
    BST();
    ~BST();

    BST* allocNode(int n);
    BST* insert(BST *b, int n);
    void deleteTree(BST* n);

    int treeHeight(BST *b) const;
    BST* searchTree(BST* np, int n) const;
    void printPrefix(BST* n) const;
    void printInfix(BST* n) const;
    void printPostfix(BST* n) const;
    void printAsTree(BST* n, int level) const;

    int data, height;
    BST *left, *right;
};

// BST() - constructor
// Postcondition - initializes root pointer to null and number of leaves to zero
BST::BST()
{
    left = right = nullptr;
    height = -1;
}

// ~BST() - destructor
// Postcondition - destroys objest and frees all dynamically allocated memory
BST::~BST() { deleteTree(this); }

// allocNode() - attempts allocation of a new node for the binary search tree
// Postcondition - returns a pointer to the new node on success
//               - displays error and exits program on failure
BST* BST::allocNode(int n)
{
    try {
        BST *bstp = new BST;
        bstp->data = n;
        return bstp;
    }
    catch (bad_alloc bad) {
        cerr << "Error, failed to dynamically allocate a new node.\n";
        exit(1);
    }
}

// insert() - inserts a node containing data into the binary search tree
// Postcondition - node is inserted at the proper placement according to the 
//               - properties of a BST. If the data was already in a tree node, 
//               - it is not added.
BST* BST::insert(BST *b, int data)
{
    if (b == nullptr)
        return allocNode(data);

    else if (data < b->data)
        b->left = insert(b->left, data);

    else if (data > b->data)
        b->right = insert(b->right, data);

    else
        return b;

    b->height = max(treeHeight(b->left), treeHeight(b->right)) + 1;

    return b;
}

// deleteTree() - deletes all nodes in the tree
// Postcondition - all dynamically allocated memory is freed and the tree is empty
void BST::deleteTree(BST *n)
{
    // base case: the tree is empty/fully deleted
    if (n == nullptr)
        return;

    // recursively delete every node via postfix traversal
    deleteTree(n->left);
    deleteTree(n->right);
    free(n);
}

// height() - returns the height of the tree 
int BST::treeHeight(BST *b) const
{ 
    return (b == nullptr) ? 0 : b->height;
}

// searchTree() - searches the tree for key
//              - on success, returns a pointer to the node containing the key
//              - on failure, returns a mull pointer
BST* BST::searchTree(BST* np, int key) const
{
    // search concludes if key found or tree is empty
    if (np == nullptr || np->data == key)
        return np;

    // search the left sub tree if needed
    if (key < np->data)
        return searchTree(np->left, key);

    // search right sub tree if needed
    return searchTree(np->right, key);
}

// printPrefix() - prints the tree contents in Prefix order
void BST::printPrefix(BST* n) const
{
    cout << n->data << " ";

    if (n->left != nullptr)
        printPrefix(n->left);

    if (n->right != nullptr)
        printPrefix(n->right);
}

// printInfix() - prints the tree contents in Infix order
void BST::printInfix(BST* n) const
{
    if (n->left != nullptr)
        printInfix(n->left);

    cout << n->data << " ";

    if (n->right != nullptr)
        printInfix(n->right);
}

// printPostfix() - prints the tree contents in Postfix order
void BST::printPostfix(BST* n) const
{
    if (n->left != nullptr)
        printPostfix(n->left);

    if (n->right != nullptr)
        printPostfix(n->right);

    cout << n->data << " ";
}

// printAsTree() - prints as sideways tree
void BST::printAsTree(BST* n, int level) const
{
    if (n->right != nullptr) {
        printAsTree(n->right, level + 1);
    }

    for (int i = 0; i < level; i++)
        cout << "\t\t";

    /* if (level == 0) {
        cout << "root -> ";
        level++;
    } */

    cout << n->data << endl;

    if (n->left != nullptr) {
        printAsTree(n->left, level + 1);
    }
}

#endif
