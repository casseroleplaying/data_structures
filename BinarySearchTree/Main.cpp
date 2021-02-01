// Program to implement a basic binary search tree containing integer values
// User can choose how many values they'd like in the tree and enter them from
// the standard input. Duplicate values will not ba added to the tree. 


#include <iostream>
#include <limits>
#include "BST.h"
using namespace std;

void mainMenu(BST& b);
void searchMenu(BST& b);
void treeInfo(BST& b);

int main()
{
    char answer = 'y';

    cout << "Let's make a binary search tree!\n";
    
    while (answer == 'y') {
        BST b;
        mainMenu(b);
        treeInfo(b);
        searchMenu(b);

        cout << "\nWould you like to make another binary search tree? (y/n): ";
        cin >> answer;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    system("pause");
    return 0;
}

// mainMenu() - prompts the user for the number of integers to add to a binary
//            - search tree, takes the input values and adds to the tree
// Postcondition - a binary search tree has been instantiated and built out from
//               - user input
void mainMenu(BST& b)
{
    int x, size;

    cout << "How many integer values would you like in the tree? ";
    cin >> size;
    cout << "Enter integer values (no duplicates please!) for the tree: ";
    for (int i = 0; i < size; i++) {
        cin >> x;
        b.insert(x);
    }
}
// treeInfo() - prints the tree contents via 3 traversal methods
//            - prints the number of leaves in tree and its height
void treeInfo(BST& b)
{
    cout << "\nTree contents in Infix order:\n";
    b.printInfix(b.getRoot());

    cout << "\n\nTree contents in Prefix order:\n";
    b.printPrefix(b.getRoot());

    cout << "\n\nTree contents in Postfix order:\n";
    b.printPostfix(b.getRoot());

    cout << "\n\nNumber of leaves in tree: " << b.countLeaves();
    cout << "\nHeight of tree: " << b.getHeight() << endl;
}

// searchMenu() - allows the user to search for a key in the tree
void searchMenu(BST &b)
{
    char searchAgain = 'y';
    int key;
    
    while (searchAgain == 'y' || searchAgain == 'Y') {

        cout << "\nEnter an integer to search for in tree: ";
        cin >> key;

        if (b.searchTree(b.getRoot(), key))
            cout << "Found " << key << " in tree :)\n";
        else
            cout << "Did not find " << key << " in tree :(\n";

        cout << "\nSearch again? (y/n): ";
        cin >> searchAgain;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}