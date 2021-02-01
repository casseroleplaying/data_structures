#include "binheap.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int type, size = 1, choice = 0, n;
    string line;
    
    cout << "\nLet's make a binary heap!\n"
        << "\nEnter type of heap (0 for min heap, anything else for max heap): ";
    cin >> type;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while (size < 2) {
        cout << "Enter maximum size of the heap (must be > 1): ";
        cin >> size;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    BinaryHeap bh(size, type);

    cout << "Enter integers to add to heap: ";
    getline(cin, line);
    istringstream iss(line);

    while (iss >> n)
        bh.insertElem(n);

    while (choice != 4) {
        cout << "\n 1. Display the " << bh.getHeapType() << " heap."
            << "\n 2. Add an item"
            << "\n 3. Remove the " << bh.getHeapType() << " item"
            << "\n 4. Exit\n\nEnter choice: ";

        cin >> choice;

        switch (choice) {
        case (1):
            bh.printHeap();
            break;

        case (2):
            cout << "Insert item: ";
            cin >> n;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bh.insertElem(n);
            break;

        case (3):
            cout << "Deleted root value: " << bh.deleteRoot() << "\n";
            break;

        default:
        cout << "This was fun, Goodbye :)";
            break;
        }
    }
    return 0;
}

// test input: 7 5 16 85 95 4 11 65 43 10 13 9