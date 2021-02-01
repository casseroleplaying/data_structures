#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct treeNode {
    int number;
    string name, symbol;
    treeNode* left, * right;
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

    void printAsTree(treeNode* n, int level) const;

private:
    treeNode* root;
    int numLeaves;
};

#endif