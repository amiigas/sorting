//
// Created by Aleksy on 2020-03-09.
//

#include "introsort.h"
#include "quicksort.h"

void insertionSort(int array[], int start, int end) {

    int firstUnsorted = start+1;

    // looks for first unsorted element
    for (int i = start ; array[i] <= array[i+1] ; i++) {
        firstUnsorted++;
    }

    while (firstUnsorted <= end) {

        // finds the right place for element by swaping
        for (int i = firstUnsorted ; i >= 0 && array[i] < array[i-1] ; i--) {
            swap(array[i],array[i-1]);
        }
        firstUnsorted++;
    }
}