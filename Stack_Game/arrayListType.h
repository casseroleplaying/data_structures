#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H

#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#define MAX 5           // default list size is 5

template <class elemType>
class arrayListType {
public:
    arrayListType();
    arrayListType(int n);
    arrayListType(const arrayListType<elemType>& otherList);
    arrayListType& operator=(const arrayListType& source);
    ~arrayListType();

    bool insertAt(int location, elemType insertItem);
    bool removeAt(int location);
    bool searchAndRemove(elemType key);
    void qSort(int left, int right);
    void shuffleArray();
    void swap(int i, int j);

    void print() const;
    int getLength() const { return length; }
    int getMaxSize() const { return maxSize; }
    int getTotal() const;
    elemType getElement(int n) const { return *(list + n); }

protected:
    elemType* list;  // array to hold the list elements
    int length;      // current length of the list
    int maxSize;     // maximum size of the list
};

/******** class implementation in .h file due to use of templates **********/

// arrayListType() - default constructor
// Postcondition: list points to dynmically allocated array of size MAX
//      length is initialized to zero, and maxmimum size is set to MAX
template <class elemType>
arrayListType<elemType>::arrayListType()
{
    list = new elemType[MAX];
    length = 0;
    maxSize = MAX;
}

// arrayListType() - overloaded constructor
// Postcondition: list points to dynmically allocated array of size n
//      length is initialized to zero, and maxmimum size is set to n
template <class elemType>
arrayListType<elemType>::arrayListType(int n)
{
    list = new elemType[n];
    length = 0;
    maxSize = n;
}

// ArrayListType() - copy constructor
// Postcondition: deep copies class object otherList into this instance
template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    list = new elemType[maxSize];
    length = otherList.length;

    for (int i = 0; i < maxSize; ++i)
        *(list + i) = *(otherList.list + i);
}

// = overloads the assignment operator for copying a class object outside of declaration
// Postcondition: returns a reference to a (deep) copy of source object 
template <class elemType>
arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType& source)
{
    if (this != &source) {
        if (maxSize > 0)
            delete list;
        maxSize = source.maxSize;
        list = new elemType[maxSize];
        length = source.length;

        for (int i = 0; i < maxSize; ++i)
            *(list + i) = *(source.list + i);
    }
    return *this;
}

// ~arrayListType() - destructor, deletes the list
// Postcondition: list is empty and all dynamically allocated memory is cleared
template <class elemType>
arrayListType<elemType>::~arrayListType() { delete list; list = NULL; }

// insertAt() - inserts an item in the list at index location.
// Postcondition: Starting at location, elements of the list are shifted up one index. 
//    If the list is full or location is out of range, an appropriate message is displayed.
template <class elemType>
bool arrayListType<elemType>::insertAt(int location, elemType insertItem)
{
    int current = length;

    if (length == maxSize || location < 0 || location > maxSize - 1) {
        cout << "List full and/or location is out of range, cannot insert.\n";
        return 0;
    }
    else {
        while (current > location) {                    // shift array elements
            *(list + current) = *(list + current - 1);
            --current;
        }
        *(list + location) = insertItem;                // insert item at location
        ++length;                                       // update length
    }
    return 1;
}

// removeAt() - removes the item from the list at index location. 
// Postcondition: element at list[location] is removed and length decremented
//    If location is out of range, an appropriate message is displayed.
template <class elemType>
bool arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location > maxSize - 1) {
        cout << "Postion is out of range, unable to remove from list.\n";
        return 0;
    }
    while (location < maxSize) {
        *(list + location) = *(list + location + 1);    // shift array elements, overwriting
        ++location;                                     // item to be removed
    }
    --length;                                           // update length
    return 1;
}

// searchAndRemove() - searches the list for an item matching the key
// Postcondition: If found removes the item from the list
template <class elemType>
bool arrayListType<elemType>::searchAndRemove(elemType key)
{
    for (int i = 0; i < length; ++i)                    // search array
        if (*(list + i) == key) {                       // if match found, remove         
            cout << "Found " << key << " at position " << i << endl;
            removeAt(i);
            return true;
        }
    cout << key << " not found in array.\n";
    return false;
}

// quickSort() - Recursively sorts the array
// Poscondition: list is sorted in ascending order
template <class elemType>
void arrayListType<elemType>::qSort(int left, int right)
{
    int last;

    if (left >= right)                                  // base case, end recursion
        return;

    swap(left, (left + right) / 2);                       // move partition to beginning of list
    last = left;
    for (int i = left + 1; i <= right; i++)             // work through partitoned array
        if (*(list + i) < *(list + left))               // swap if out of order
            swap(++last, i);

    swap(left, last);                                   // restore the partition element
    qSort(left, last - 1);                              // recursively work through list
    qSort(last + 1, right);
}

// shuffleArray() - randomly shuffles list contents
// Postcondition: list has been rearranged in random order
template <class elemType>
void arrayListType<elemType>::shuffleArray()
{
    unsigned seed = time(0);                            // get random seed
    shuffle(list, list + length, default_random_engine(seed));
}

// swap() - swaps items at index i and j
// Postcondition: items at list[i] and list [j] have been swapped
template <class elemType>
void arrayListType<elemType>::swap(int i, int j)
{
    int temp = *(list + i);                             // swap list[i] and list[j]
    *(list + i) = *(list + j);
    *(list + j) = temp;
}

// print() - outputs the elements of the list
// Postcondition: Elements of the list are output on the standard output device.
template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; ++i)
        cout << *(list + i) << " ";
    cout << "\n";
}

// getTotal() - returns an integer value that is the sum of the list contents
template <class elemType>
int arrayListType<elemType>::getTotal() const
{
    int total = 0;
    for (int i = 0; i < length; ++i)
        total += *(list + i);
    return total;
}

#endif