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

    int m = start+(end-start)/2;
    int pivot = array[m];
    int i = start;

    swap(array[m],array[end]);

    for (int j = start ; j < end; j++)
    {
        if (array[j] <= pivot)
        {
            swap(array[i],array[j]);
            i++;
        }
    }

    swap(array[end],array[i]);

    return i;
}

void quicksort(int array[], int start, int end) {

    if (start < end) {

        int i = divide(array, start, end);

        quicksort(array, start, i - 1);
        quicksort(array, i + 1, end);
    }
}