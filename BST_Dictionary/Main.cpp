// 

#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "BST.h"
using namespace std;

void loadElements(BST& b);
void searchMenu(BST& b);
void printElements(BST& b);

int main()
{
    cout << "Let's make a binary search tree!\n";

    BST b;
    loadElements(b);
    searchMenu(b);
    printElements(b);

    system("pause");
    return 0;
}

// mainMenu() - prompts the user for the number of integers to add to a binary
//            - search tree, takes the input values and adds to the tree
// Postcondition - a binary search tree has been instantiated and built out from
//               - user input
void loadElements(BST& b)
{
    int i = 0;
    string name, symbol;
    ifstream input;

    input.open("D:\\Spring_2020\\CS_236\\BST_Dictionary\\chemical_elements.txt");

    if (!input.is_open()) {
        cout << "Unable to open ""D:\\Spring_2020\\CS_236\\BST_Dictionary\\chemical_elements.txt""\n";
        exit(1);
    }

    cout << "Loading list of chemical elements...";

    while (input >> name >> symbol) {
        b.insert(name, symbol, ++i);
    }

    input.close();
}

// treeInfo() - prints the tree contents via 3 traversal methods
//            - prints the number of leaves in tree and its height
void printElements(BST& b)
{
    cout << "\nChemical Elements: \n";
    b.printInfix(b.getRoot());
    cout << "\n\nNumber of elements: " << b.countLeaves() << endl;
}

// searchMenu() - allows the user to search for a key in the tree
void searchMenu(BST& b)
{
    char searchAgain = 'y';
    string key;
    treeNode *np;

    while (searchAgain == 'y' || searchAgain == 'Y') {

        cout << "\nEnter an element to search for in tree: ";
        cin >> key;

        np = b.searchTree(b.getRoot(), key);
        if (np)
            cout << "Found element: " << np->number << " " << key
                 << " [" << np->symbol << "]\n";
        else
            cout << "Did not find " << key << " in tree :(\n";

        cout << "\nSearch again? (y/n): ";
        cin >> searchAgain;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}