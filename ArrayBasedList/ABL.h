#pragma once

#include <iostream>
using namespace std;

template <class elemType>

class arrayListType {
public:

    void print() const;
    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the 
     //   standard output device.

    void insertAt(int location, const elemType& insertItem);
    //Function to insert an item in the list at the 
    //position specified by location. The item to be inserted 
    //is passed as a parameter to the function.
    //Postcondition: Starting at location, the elements of the
    //    list are shifted down. If the list is full or location is
    //    out of range, an appropriate message is displayed.

    void removeAt(int location);
    //Function to remove the item from the list at the 
    //position specified by location 
    //Postcondition: The list element at list[location] is removed
    //    and length is decremented by 1. If location is out of 
    //    range,an appropriate message is displayed.

    arrayListType(int size = 5) {}
    //constructor
    //Creates an array with the default array size is 5
    //Postcondition: The list points to the array, length = 0, 

    arrayListType(const arrayListType<elemType>& otherList);
    //copy constructor

    ~arrayListType();
    //destructor
    //Deallocates the memory occupied by the array.

protected:
    elemType* list;  //array to hold the list elements
    int length;      //to store the length of the list
    int maxSize;     //to store the maximum size of the list
}; // end class

template <class elemType>
void arrayListType<elemType>::print() const
{

}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{

}

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{

}

/*template <class elemType>
arrayListType<elemType>::arrayListType(int size = 5)
{

}*/

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{

}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{

}
