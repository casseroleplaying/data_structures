#include "binheap.h"
#include <iostream>
#include <string>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

BinaryHeap::BinaryHeap(int n, int t)
{
    binHeapArray = new int [n];
    current_size = 0;
    max_size = n;
    heapType = (t) ? "max" : "min";
}

BinaryHeap::~BinaryHeap() {  delete []binHeapArray;  }

void BinaryHeap::minHeapify(int n)
{
    int left = leftChild(n), right = rightChild(n), min = n;

    if (left < current_size && *(binHeapArray + left) < *(binHeapArray + min))
        min = left;
    if (right < current_size && *(binHeapArray + right) < *(binHeapArray + min))
        min = right;
    if (min != n) {
        swap(binHeapArray + n, binHeapArray + min);
        minHeapify(min);
    }
}

void BinaryHeap::maxHeapify(int n)
{
    int left = leftChild(n), right = rightChild(n), max = n;

    if (left < current_size && *(binHeapArray + left) > *(binHeapArray + max))
        max = left;
    if (right < current_size && *(binHeapArray + right) > *(binHeapArray + max))
        max = right;
    if (max != n) {
        swap(binHeapArray + n, binHeapArray + max);
        maxHeapify(max);
    }
}

void BinaryHeap::insertElem(int n)
{
    if (current_size == max_size) {
        cout << "\nHeap is full, cannot insert element.\n";
        return;
    }

    *(binHeapArray + current_size) = n;
    int i = current_size;
    ++current_size;

    if (heapType == "min") {
        while (i  && *(binHeapArray + parent(i)) > *(binHeapArray + i)) {
            swap(binHeapArray + i, binHeapArray + parent(i));
            i = parent(i);
        }
    } 
    else {
        while (i  && *(binHeapArray + parent(i)) < *(binHeapArray + i)) {
            swap(binHeapArray + i, binHeapArray + parent(i));
            i = parent(i);
        }
    }
} 

int BinaryHeap::deleteRoot()
{
    int root;
    
    if (!current_size) {
        cout << "\nHeap is empty! nothing to remove, returning garbage value ";
    }
    else {
        root = *binHeapArray;
        --current_size;
        *binHeapArray = *(binHeapArray + current_size);
        (heapType == "max") ? maxHeapify(0) : minHeapify(0);
    }
    return root;
}

int BinaryHeap::parent(int n) const {  return (n - 1) / 2;  }

int BinaryHeap::leftChild(int n) const {  return 2 * n + 1;  }

int BinaryHeap::rightChild(int n) const {  return 2 * n + 2;  }

void BinaryHeap::printHeap() const
{
    if (!current_size)
        cout << "\nNothing to show here! The heap is empty :(\n";
    else {
        cout << "\nContents of " << heapType << " heap: ";
        for (int i = 0; i < current_size; ++i)
            cout << *(binHeapArray + i) << " ";
        cout << "\n";
    }
}