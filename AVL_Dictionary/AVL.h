#pragma once
// AVL.h - AVL class header
// Since every node of a tree is...a tree(!) the AVL class defined below has no
// explicit node pointer, each class object is a root!
// to create a root pointer, simply declare a pointer to an AVL object

#ifndef AVL_H
#define AVL_H

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class AVL {
public:
    AVL(T n);
    ~AVL();

    AVL<T>* allocNode(T n);
    AVL<T>* rotateL(AVL<T>* n);
    AVL<T>* rotateR(AVL<T>* n);
    AVL<T>* insert(AVL<T>* n, T data);
    void deleteTree(AVL<T>* n);

    int treeHeight(AVL<T>* n) const;
    int balanceFactor(AVL<T>* n) const;
    AVL<T>* searchTree(AVL<T>* np, T n) const;
    void printPrefix(AVL<T>* n) const;
    void printInfix(AVL<T>* n) const;
    void printPostfix(AVL<T>* n) const;
    void printAsTree(AVL<T>* n, int level) const;

    T data;
    int height;
    AVL* left, * right;
};

// AVL() - constructor
// Postcondition - initializes class object, data is populated, height defaults 
//               - to 1 and pointers to null
template <class T>
AVL<T>::AVL(T n)
{ 
    data = n;
    height = 1;
    left = right = nullptr;
}

// ~AVL() - destructor
// Postcondition - destroys objest and frees all dynamically allocated memory
template <class T>
AVL<T>::~AVL() { deleteTree(this); }

template <class T>
AVL<T>* AVL<T>::allocNode(T n)
{
    try {
        AVL* AVLp = new AVL(n);
        return AVLp;
    }
    catch (bad_alloc bad) {
        cerr << "Error, failed to dynamically allocate a new node.\n";
        exit(1);
    }
}

// rotateL() - rotates tree with root b to the left, returns tree with root d
//             pre: b      post: d
//                 / \          / \
//                a   d        b   e
//                   / \      / \
//                  c   e    a   c
template <class T>
AVL<T>* AVL<T>::rotateL(AVL<T> *b)
{
    AVL<T> *d = b->right;
    AVL<T> *c = d->left;

    d->left = b;
    b->right = c;

    b->height = max(treeHeight(b->left), treeHeight(b->right)) + 1;
    d->height = max(treeHeight(d->left), treeHeight(d->right)) + 1;

    return d;
}

// rotateR() - rotates tree with root d to the right, returns tree with root b
//             pre: d      post: b
//                 / \          / \
//                b   e        a   d
//               / \              / \
//              a   c            c   e
template <class T>
AVL<T>* AVL<T>::rotateR(AVL<T> *d)
{
    AVL<T> *b = d->left;
    AVL<T> *c = b->right;

    b->right = d;
    d->left = c;

    d->height = max(treeHeight(d->left), treeHeight(d->right)) + 1;
    b->height = max(treeHeight(b->left), treeHeight(b->right)) + 1;

    return b;
}


// treeHeight() - returns the height of tree n
template <class T>
int AVL<T>::treeHeight(AVL<T> *n) const
{
    return (n == nullptr) ? 0 : n->height;
}

// balanceFactor() - returns the balance factor of tree n
template <class T>
int AVL<T>::balanceFactor(AVL<T> *n) const
{
    return (n == nullptr) ? 0 : treeHeight(n->left) - treeHeight(n->right);
}

// insert() - inserts a node containing data into the binary search tree and
//          - returns a pointer to the node.
// Postcondition - node is inserted at the proper placement according to the 
//               - properties of an AVL. Duplicate data is not added and each
//               - successful insertion is followed by rotation(s) of the tree 
//               - to maintain its balance according to the AVL algorithm
template <class T>
AVL<T>* AVL<T>::insert(AVL<T> *b, T data)
{
    if (b == nullptr)
        return allocNode(data);

    if (data < b->data)
        b->left = insert(b->left, data);

    else if (data > b->data)
        b->right = insert(b->right, data);

    else
        return b;

    b->height = max(treeHeight(b->left), treeHeight(b->right)) + 1;

    // calculate balance factor of inserted bode
    int bFactor = balanceFactor(b);

    // rebalance if needed
    if (bFactor > 1) {
        if (data > b->left->data)
            b->left = rotateL(b->left);
        return rotateR(b);
    }
    if (bFactor < -1) {
        if (data < b->right->data)
            b->right = rotateR(b->right);
        return rotateL(b);
    }

    return b;
}

// deleteTree() - deletes all nodes in the tree
// Postcondition - all dynamically allocated memory is freed and tree is empty
template <class T>
void AVL<T>::deleteTree(AVL<T> *n)
{
    // base case: the tree is empty/fully deleted
    if (n == nullptr)
        return;

    // recursively delete every node via postfix traversal
    deleteTree(n->left);
    deleteTree(n->right);
    free(n);
}

// searchTree() - searches the tree for key
//              - on success, returns a pointer to the node containing the key
//              - on failure, returns a null pointer
template <class T>
AVL<T>* AVL<T>::searchTree(AVL<T> *n, T key) const
{
    // remove case-sensitivity
    for (int i = 0; i < key.length(); i++) {
        if (!islower(key[i]))
            key[i] = tolower(key[i]);
    }

    // search concludes if key found or tree is empty
    if (n == nullptr || n->data == key)
        return n;

    // search the left sub tree if needed
    if (key < n->data)
        return searchTree(n->left, key);

    // search right sub tree if needed
    return searchTree(n->right, key);
}

// printPrefix() - prints the tree contents in Prefix order
template <class T>
void AVL<T>::printPrefix(AVL<T>*n) const
{
    cout << n->data << " ";

    if (n->left != nullptr)
        printPrefix(n->left);

    if (n->right != nullptr)
        printPrefix(n->right);
}

// printInfix() - prints the tree contents in Infix order
template <class T>
void AVL<T>::printInfix(AVL<T>*n) const
{
    if (n->left != nullptr)
        printInfix(n->left);

    cout << n->data << " ";

    if (n->right != nullptr)
        printInfix(n->right);
}

// printPostfix() - prints the tree contents in Postfix order
template <class T>
void AVL<T>::printPostfix(AVL<T>*n) const
{
    if (n->left != nullptr)
        printPostfix(n->left);

    if (n->right != nullptr)
        printPostfix(n->right);

    cout << n->data << " ";
}

// printAsTree() - prints tree contents as a sideways tree
template <class T>
void AVL<T>::printAsTree(AVL<T>*n, int level) const
{
    if (n->right != nullptr) {
        printAsTree(n->right, level + 1);
    }

    for (int i = 0; i < level; i++)
        cout << "\t\t";

    cout << n->data << endl;

    if (n->left != nullptr) {
        printAsTree(n->left, level + 1);
    }
}

#endif