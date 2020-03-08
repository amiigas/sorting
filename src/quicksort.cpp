//
// Created by Aleksy on 2020-03-07.
//

#include "quicksort.h"

void swap(int& i, int& j) {

    int temp = i;
    i = j;
    j = temp;
}

int divide(int array[], int start, int end) {

    int pivot = array[end];
    int i = start;

    for (int j = start ; j < end; ++j)
    {
        if (array[j] <= pivot)
        {
            swap(array[i],array[j]);
            i++;
        }
    }

    array[end] = array[i];
    array[i] = pivot;

    return i;
}

void quicksort(int array[], int start, int end) {

    if (start < end) {

        int i = divide(array, start, end);

        quicksort(array, start, i - 1);
        quicksort(array, i + 1, end);
    }
}


