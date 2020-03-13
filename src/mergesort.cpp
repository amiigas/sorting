//
// Created by Aleksy on 2020-03-06.
//

#include "mergesort.h"

void mergesort(int array[], int start, int end) {

    if (start<end) {

        int m = start+(end-start)/2;     //  start+(end-start)/2 instead of (start+end)/2 prevents integer overflow

        mergesort(array,start,m);
        mergesort(array,m+1,end);

        merge(array,start,m,end);
    }

}

void merge(int array[], int start, int mid, int end) {

    int i,j,k;
    int itemsL = mid-start+1;
    int itemsR = end-mid;

    int L[itemsL], R[itemsR];

    for (i = 0 ; i < itemsL ; i++) {
        L[i] = array[start+i];
    }
    for (j = 0 ; j < itemsR ; j++) {
        R[j] = array[mid+1+j];
    }

    i = 0;
    j = 0;
    k = start;

    while(i < itemsL && j < itemsR) {

        if(L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < itemsL) {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < itemsR) {
        array[k] = R[j];
        j++;
        k++;
    }
}