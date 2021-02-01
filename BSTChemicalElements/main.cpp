// Program to read from a text file the list of 118 chemical elements and 
// insert them into a binary search tree (sorted by element name).
// Allows the user to search the tree for element(s) and finaly prints out the 
// full list upon completion.

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

    return 0;
}

// mainMenu() - opens and reads an input file containing a list of the 118 chemical elements
//            - builds a binary search tree of the elements sorted by name
// Postcondition - a binary search tree has been instantiated and built out from input file
void loadElements(BST& b)
{
    int i = 0;
    string name, symbol;
    ifstream input;

    input.open("chemical_elements.txt");

    if (!input.is_open()) {
        cout << "Unable to open ""chemical_elements.txt""\n";
        exit(1);
    }

    cout << "Loading list of chemical elements...";

    while (input >> name >> symbol) {
        b.insert(name, symbol, ++i);
    }

    input.close();
}

// treeInfo() - prints the tree contents (list of chmeical elements) in Infix (alphabetical) order
void printElements(BST& b)
{
    cout << "\nChemical Elements (sorted alphabetically): \n";
    b.printInfix(b.getRoot());
    cout << "\n\nNumber of elements: " << b.countLeaves() << endl;

    cout << "Printed sideways as a tree\n\n";
    b.printAsTree(b.getRoot(), 0);
}

// searchMenu() - allows the user to search for an element in the tree
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
            cout << "Found element: " << np->number << " " << np->name << " [" << np->symbol << "]\n";
        else
            cout << "Did not find " << key << " in tree :(\n";

        cout << "\nSearch again? (y/n): ";
        cin >> searchAgain;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}