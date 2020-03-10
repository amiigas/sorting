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

void heapify(int array[], int size, int index) {

    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int lastParent = size/2-1;
    int largerChild;

    if (index <= lastParent) {

        if (rightChild <= size-1) {
            largerChild = (array[leftChild] >= array[rightChild]) ? leftChild : rightChild;
        } else {
            largerChild = leftChild;
        }

        if (array[index] < array[largerChild]) {
            swap(array[index], array[largerChild]);
        }

        heapify(array, size, largerChild);
    }
}

void heapsort(int array[], int size) {

    int lastParent = size/2-1;

    // first create max heap
    for (int i = lastParent ; i >= 0 ; i--) {
        heapify(array, size, i);
    }

    for (int i = 0; i < size ; i++) {
        swap(array[size-1-i], array[0]);
        heapify(array, size-1-i, 0);
    }


}