#ifndef UTILITIES_H
#define UTILITIES_H

// struct to hold information for each different approach to quick sort
struct sorts {
    std::string desc;
    int *arr;
    clock_t ticks;
    double sec;
};

int median(int v[], int left, int right, int mid);
void insertSort(int v[], int size);
void qSort(int v[], int left, int right, bool med, bool insert);
void qSortStructs(sorts v[], int left, int right);
void swap(int v[], int i, int j);
void swapStruct(sorts v[], int i, int j);

// insertSort() - sorts array v of size size in ascending order
void insertSort(int v[], int size)
{
    int i, j, k;

    for (i = 1; i < size; i++) {
        k = v[i];
        j = i - 1;

        while (j >=0 && v[j] > k) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = k;
    }
}

// qSort() - modified qSort adapted from:
//         - "The C Programming Language Second Edition" Kernighan, Brian and Rithie, Dennis
//         - recursively sorts array v in ascending order by splitting into subarrays along a pivot/partition
//         - pivot/partition = middle or median of 3 (v[left], v[middle], v[right]) based on spec
//         - defers to insertion sort for subarrays of size < 20 if specified 
void qSort(int v[], int left, int right, bool med, bool insert)
{
    int i, last;

    // defer to insertion sort if specified and subarray size < 20
    if (insert && right - left < 20)
        insertSort(v, right - left);

    else {
        // do nothing if array size < 2
        if (left >= right)
            return;
        // partition using median of 3 if specified, else use middle element
        if (med)
            swap(v, left, median(v, left, right, (left+right) / 2));
        else
            swap(v, left, (left + right) / 2);

        last = left;

        // paritally sort subarray
        for (i = left + 1; i <= right; i++)
            if (v[i] < v[left])
                swap(v, ++last, i);
        
        // restore partition element and recur
        swap(v, left, last);
        qSort(v, left, last-1, med, insert);
        qSort(v, last+1, right, med, insert);
    }
}

// qSortStructs() - modified qSort to sort array of structs according to
//                - compute time represented by ticks
void qSortStructs(sorts v[], int left, int right)
{
    int i, last;
        
    if (left >= right)
        return;

    swapStruct(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if (v[i].ticks < v[left].ticks)
            swapStruct(v, ++last, i);
    
    swapStruct(v, left, last);
    qSortStructs(v, left, last-1);
    qSortStructs(v, last+1, right);
}

// median() - returns the index of v where v[index] is the median value of
//          - v[left], v[middle], v[right]
int median(int v[], int left, int right, int mid)
{
    int median = right;

    if (v[left] < v[mid] && v[mid] < v[right])
        median = mid;
    else if (v[mid] < v[left] && v[left] < v[right])
        median = left;

    return median;
}

// swap() - swaps v[i] and v[j]
void swap(int v[], int i, int j)
{
    int temp;   
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// swapStruct() - swaps v[i] and v[j]
void swapStruct(sorts v[], int i, int j)
{
    sorts temp;  
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#endif