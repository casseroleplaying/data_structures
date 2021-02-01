// Program to implement an AVL tree and it's basic functions
// Loads an English dictionary from a text file into an AVL tree
// Allows user to search for words in the dictionary
// AVL tree invented in 1962 by Georgy Adelson-Velsky and Evgenii Landis
// The world's first self-balancing binary search tree! 

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include "AVL.h"
using namespace std;

void mainMenu(AVL<string> *&b, int &choice);
void loadDictionary(AVL<string>*& b);
void searchMenu(AVL<string> *&b);

int main()
{
    int choice = 0;
    AVL<string>* b = nullptr;           // tree root pointer

    while (choice != 7) {
        mainMenu(b, choice);
    }

    return 0;
}

// mainMenu() - menu allows user options to modify, search, and view information
//            - about AVL tree b
void mainMenu(AVL<string> *&b, int &choice)
{
    cout << "\n-----------------------"
        << "\nAVL Tree Implementation\n-----------------------\n"
        << "1. Load English dictionary into the tree\n"
        << "2. Display balanced AVL tree\n"
        << "3. Inorder traversal\n"
        << "4. Preorder traversal\n"
        << "5. Postorder traversal\n"
        << "6. Lookup word in dictionary\n"
        << "7. Exit\n"
        << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case (1):
        loadDictionary(b);
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

void loadDictionary(AVL<string> *&b)
{
    int i = 0;
    string word;
    ifstream input;

    input.open("C:\\Users\\thatw\\School\\Spring_2020\\CS_236\\AVL_Dictionary\\dictionary.txt");

    if (!input.is_open()) {
        cout << "Unable to open ""\\dictionary.txt""\n";
        exit(1);
    }

    cout << "Loading dictionary into tree...";

    while (input >> word) {
        b = b->insert(b, word);
    }

    input.close();
}

// searchMenu() - allows the user to search for a key in the tree
void searchMenu(AVL<string>*& b)
{
    char searchAgain = 'y';
    string key;

    while (searchAgain == 'y' || searchAgain == 'Y') {

        cout << "\nEnter a word to search for in the (English) dictionary: ";
        cin >> key;

        if (b->searchTree(b, key))
            cout << "Found " << key << " in dictionary :)\n";
        else
            cout << "Did not find " << key << " in dictionary :(\n";

        cout << "\nSearch again? (y/n): ";
        cin >> searchAgain;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}