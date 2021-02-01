#include <iostream>
#include "ABL.h"

using namespace std;

int main()
{
	arrayListType<int> intList(5);

	int counter, number, position;

	cout << "Enter 5 integers: ";
	for (counter = 0; counter < 5; counter++) {
		cin >> number;
		intList.insertAt(counter, number);
	}

	cout << endl;
	cout << "The list you entered is: ";
	intList.print();
	cout << endl;

	cout << "Enter the position of item to be deleted: ";
	cin >> position;
	intList.removeAt(position);

	if (position >= 5)
		cout << "The list does not change:  " << endl;
	else {
		cout << "After removing the element at position " << position << ", the list is:";
		intList.print();
	}

	cout << "Enter the position and an integer to be inserted: ";
	cin >> position;
	cin >> number;

	if (position >= 5)
		cout << "Position is out of range." << "The list does not change. " << endl;
	else if (position < 5)
		intList.insertAt(position, number);

	cout << "\nFinal list: "; intList.print();
	// system("pause");
	return 0;
}

/*
Enter 5 integers: 45 16 9 15 77

The list you entered is: 45 16 9 15 77

Enter the position of item to be deleted: 1
After removing the element at position 1, the list is: 45 9 15 77

Enter the position and an integer to be inserted: 6 100
Position is out of range.The list does not change.
Final list: 45 9 15 77


*/

/*
Enter 5 integers: 55 16 3 7 10

The list you entered is: 55 16 3 7 10

Enter the position of item to be deleted: 5
The location of the item to be removed is out of range.
The list does not change.

Enter the position and an integer to be inserted: 5 101
Position is out of range.The list does not change.
Final list: 55 16 3 7 10


*/

/*
Enter 5 integers: 55 16 10 7 25

The list you entered is: 55 16 10 7 25

Enter the position of item to be deleted: 2
After removing the element at position 2, the list is: 55 16 7 25

Enter the position and an integer to be inserted: 3 5
Final list: 55 16 7 5 25


*/
