#ifndef BINHEAP_H
#define BINHEAP_H
#include <string>
using namespace std;

class BinaryHeap {
public:
    BinaryHeap(int n, int t);
    ~BinaryHeap();

    void minHeapify(int n);
    void maxHeapify(int n);
    void insertElem(int n);
    int deleteRoot();

    string getHeapType() const {  return heapType;  }
    int parent(int n) const;
    int leftChild(int n) const;
    int rightChild(int n) const;
    void printHeap() const;

private:
    int *binHeapArray;
    int current_size, max_size;
    string heapType;
};

#endif