// Program to implement an AVL tree and it's basic functions
// AVL tree invented in 1962 by Georgy Adelson-Velsky and Evgenii Landis
// The world's first self-balancing binary search tree! 

#include <iostream>
#include <limits>
#include "AVL.h"
using namespace std;

void mainMenu(AVL *&b, int &choice);
void searchMenu(AVL *&b);

int main()
{
    int choice = 0;
    AVL *b = nullptr;           // tree root pointer

    while (choice != 7) {
        mainMenu(b, choice);
    }

    return 0;
}

// mainMenu() - menu allows user options to modify, search, and view information
//            - about AVL tree b
void mainMenu(AVL *&b, int &choice)
{
    int x;

    cout << "\n-----------------------"
        << "\nAVL Tree Implementation\n-----------------------\n"
        << "1. Insert element(s) into the tree\n"
        << "2. Display balanced AVL tree\n"
        << "3. Inorder traversal\n"
        << "4. Preorder traversal\n"
        << "5. Postorder traversal\n"
        << "6. Search tree\n"
        << "7. Exit\n"
        << "Enter your choice: ";
        cin >> choice;

    switch (choice) {
    case (1):
        cout << "Enter value to be inserted: ";
        cin >> x;
        b = b->insert(b, x);
        break;

    case (2):
        cout << "Balanced AVL tree:\n\n";
        b->printAsTree(b, 0);
        break;

    case (3):
        cout << "Inorder traversal:\n";
        b->printInfix(b);
        break;

    case (4):
        cout << "Preorder traversal:\n";
        b->printPrefix(b);
        break;

    case (5):
        cout << "Postorder traversal:\n";
        b->printPostfix(b);
        break;

    case (6):
        searchMenu(b);
        break;

    case (7):
        cout << "Quitting program, goodbye:)\n";
        break;

    default:
        cout << "Please enter a valid option 1-6\n";
        break;
    }
}


// searchMenu() - allows the user to search for a key in the tree
void searchMenu(AVL *&b)
{
    char searchAgain = 'y';
    int key;

    while (searchAgain == 'y' || searchAgain == 'Y') {

        cout << "\nEnter an integer to search for in tree: ";
        cin >> key;

        if (b->searchTree(b, key))
            cout << "Found " << key << " in tree :)\n";
        else
            cout << "Did not find " << key << " in tree :(\n";

        cout << "\nSearch again? (y/n): ";
        cin >> searchAgain;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}