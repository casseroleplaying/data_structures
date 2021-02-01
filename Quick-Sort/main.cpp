// Program to time 4 different implementations of quick sort on an integer array
// populates 4 integer arrays with indentical random values and sorts them using:
// 1. quicksort with middle pivot
// 2. quicksort with median pivot
// 3. quicksort with middle pivot deferring to insertion sort for sub-arrays < 20 in size
// 4. quicksort with median pivot deferring to insertion sort for sub-arrays < 20 in size
// outputs results in ascending order according to compute time

#include <iostream>
#include "utilities.h"
using namespace std;

int main()
{
    sorts test4[4];  
    char run = 'Y';
    int size;

    // populate descriptive output strings
    test4[0].desc = "Quick sort with pivot middle element\n";
    test4[1].desc = "Quick sort with pivot median element\n";
    test4[2].desc = "Quick sort and insertion sort with pivot middle element\n";
    test4[3].desc = "Quick sort and insertion sort with pivot median element\n";

    while (run == 'Y' || run == 'y') {

        size = 0;
        
        while (size < 2) {
            cout << "\nEnter array size to be sorted: ";
            cin >> size;
        }

        // allocate arrays of user specified size
        for (int i = 0; i < 4; i++)
            test4[i].arr = new int [size];

        // seed rand() with current time
        srand(time(0));

        // populate arrays with random numbers between 0 and RAND_MAX
        for (int i = 0; i < size; i++)
            test4[0].arr[i] = test4[1].arr[i] = test4[2].arr[i] = test4[3].arr[i] = rand();

        // perform 4 different quicksorts on identical arrays and record time elapsed
        test4[0].ticks = clock();
        qSort(test4[0].arr, 0, size - 1, 0, 0);
        test4[0].ticks = clock() - test4[0].ticks;
        test4[0].sec = test4[0].ticks / (double) CLOCKS_PER_SEC;

        test4[1].ticks = clock();
        qSort(test4[1].arr, 0, size - 1, 0, 0);
        test4[1].ticks = clock() - test4[1].ticks;
        test4[1].sec = test4[1].ticks / (double) CLOCKS_PER_SEC;

        test4[2].ticks = clock();
        qSort(test4[2].arr, 0, size - 1, 0, 0);
        test4[2].ticks = clock() - test4[2].ticks;
        test4[2].sec = test4[2].ticks / (double) CLOCKS_PER_SEC;

        test4[3].ticks = clock();
        qSort(test4[3].arr, 0, size - 1, 0, 0);
        test4[3].ticks = clock() - test4[3].ticks;
        test4[3].sec = test4[3].ticks / (double) CLOCKS_PER_SEC;

        // sort our sorts! (ascending by time elapsed)
        qSortStructs(test4, 0, 4);

        // output results in ascending order of compute time
        cout << "\nSort results in ascending order of compute time:\n";
        for (int i = 0; i < 4; i++)
            cout << i + 1 << ". " << test4[i].ticks << " clock ticks"
                 << " (" << test4[i].sec << " seconds): " << test4[i].desc;

        // free dynamically allocated arrays
        for (int i = 0; i < 4; i++)
            delete[] test4[i].arr;

        cout << "\nWould you like to enter another array size (Y / N)? ";
        cin >> run;
    }

    return 0;
}