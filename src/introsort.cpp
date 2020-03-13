//
// Created by Aleksy on 2020-03-09.
//

#include "introsort.h"
#include "quicksort.h"

void insertionSort(int array[], int start, int end) {

    int firstUnsorted = start+1;

    // looks for first unsorted element
    for (int i = start ; i < end-start ; i++) {
        if (array[i] <= array[i+1]) {
            firstUnsorted++;
        } else {
            break;
        }
    }

    while (firstUnsorted <= end) {

        // finds the right place for element by swaping
        for (int i = firstUnsorted ; i > 0 && array[i] < array[i-1] ; i--) {
            swap(array[i],array[i-1]);
        }
        firstUnsorted++;
    }
}

void heapify(int array[], int size, int start, int index) {

    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int lastParent = size/2-1;
    int largerChild = leftChild;

    if (rightChild <= size-1) {
        largerChild = (array[start+leftChild] >= array[start+rightChild]) ? leftChild : rightChild;
    }

    if (array[start+index] < array[start+largerChild] && size != 1) {
        swap(array[start+index], array[start+largerChild]);
    }

    if (largerChild <= lastParent) {
        heapify(array, size, start, largerChild);
    }
}

void heapsort(int array[], int start, int end) {

    int size = end-start+1;
    int lastParent = size/2-1;

    // first create max heap
    for (int i = lastParent ; i >= 0 ; i--) {
        heapify(array, size, start, i);
    }

    for (int i = 0 ; i < size-1 ; i++) {
        swap(array[end-i], array[start]);
        heapify(array, size-1-i, start, 0);
    }
}

void introsort(int array[], int start, int end, int depth) {

    if (start < end) {
        if (end-start+1 < 10) {

            insertionSort(array, start, end);

        } else if (depth == 0) {

            heapsort(array, start, end);

        } else {

            int i = divide(array, start, end);

            introsort(array, start, i - 1, depth - 1);
            introsort(array, i + 1, end, depth - 1);
        }
    }
}
