// AVL.cpp - AVL class implementation

#include "AVL.h"

// AVL() - constructor
// Postcondition - initializes class object, data is populated, height defaults 
//               - to 1 and pointers to null
AVL::AVL(int n)
{
    data = n;
    height = 1;
    left = right = nullptr;
}

// ~AVL() - destructor
// Postcondition - destroys objest and frees all dynamically allocated memory
AVL::~AVL() { deleteTree(this); }

AVL* AVL::allocNode(int n)
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
AVL* AVL::rotateL(AVL* b)
{
    // rotate b, c, d
    AVL* d = b->right;
    AVL* c = d->left;

    d->left = b;
    b->right = c;

    // update node/tree heights (order matters!)
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
AVL* AVL::rotateR(AVL* d)
{
    // rotate b, c, d
    AVL* b = d->left;
    AVL* c = b->right;

    b->right = d;
    d->left = c;

    // update node/tree heights (order matters!)
    d->height = max(treeHeight(d->left), treeHeight(d->right)) + 1;
    b->height = max(treeHeight(b->left), treeHeight(b->right)) + 1;

    return b;
}


// treeHeight() - returns the height of tree n
int AVL::treeHeight(AVL* n) const
{
    return (n == nullptr) ? 0 : n->height;
}

// balanceFactor() - returns the balance factor of tree n
int AVL::balanceFactor(AVL* n) const
{
    return (n == nullptr) ? 0 : treeHeight(n->left) - treeHeight(n->right);
}

// insert() - inserts a node containing data into the binary search tree and
//          - returns a pointer to the node.
// Postcondition - node is inserted at the proper placement according to the 
//               - properties of an AVL. Duplicate data is not added and each
//               - successful insertion is followed by rotation(s) of the tree 
//               - to maintain its balance according to the AVL algorithm
AVL* AVL::insert(AVL *b, int data)
{
    if (b == nullptr)   // if first tree/node, no balancing needed, we are done
        return allocNode(data);

    if (data < b->data)
        b->left = insert(b->left, data);

    else if (data > b->data)
        b->right = insert(b->right, data);

    else                // this handles duplicates, they are effectively ignored
        return b;

    b->height = max(treeHeight(b->left), treeHeight(b->right)) + 1;

    // calculate balance factor of inserted tree/node
    int bFactor = balanceFactor(b);

    // rebalance if needed (4 cases to consider)
    if (bFactor > 1) {                      // tree b is left heavy
        if (data > b->left->data)
            b->left = rotateL(b->left);     // b->left is right heavy
        return rotateR(b);                  // re-balance b
    }
    if (bFactor < -1) {                     // tree b is right heavy
        if (data < b->right->data)
            b->right = rotateR(b->right);   // b->right is left heavy
        return rotateL(b);                  // re-balance b
    }

    return b;           // return the root of sub tree now containing the input
}

// deleteTree() - deletes all nodes in the tree
// Postcondition - all dynamically allocated memory is freed and tree is empty
void AVL::deleteTree(AVL* n)
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
AVL* AVL::searchTree(AVL* n, int key) const
{
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
void AVL::printPrefix(AVL* n) const
{
    cout << n->data << " ";

    if (n->left != nullptr)
        printPrefix(n->left);

    if (n->right != nullptr)
        printPrefix(n->right);
}

// printInfix() - prints the tree contents in Infix order
void AVL::printInfix(AVL* n) const
{
    if (n->left != nullptr)
        printInfix(n->left);

    cout << n->data << " ";

    if (n->right != nullptr)
        printInfix(n->right);
}

// printPostfix() - prints the tree contents in Postfix order
void AVL::printPostfix(AVL* n) const
{
    if (n->left != nullptr)
        printPostfix(n->left);

    if (n->right != nullptr)
        printPostfix(n->right);

    cout << n->data << " ";
}

// printAsTree() - prints tree contents as a sideways tree
void AVL::printAsTree(AVL* n, int level) const
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