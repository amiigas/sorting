//
// Created by Aleksy on 2020-03-06.
//

#include "mergesort.h"

void mergesort(int array[], int l, int r) {

    if (l<r) {
        int m = l+(r-l)/2;     //  l+(r-l)/2 instead of (l+r)/2 prevents integer overflow

        mergesort(array,l,m);
        mergesort(array,m+1,r);

        merge(array,l,m,r);
    }

}

void merge(int array[], int l, int m, int r) {

    int i,j,k;
    int itemsL = m-l+1;
    int itemsR = r-m;

    int L[itemsL], R[itemsR];

    for (i = 0 ; i < itemsL ; ++i) {
        L[i] = array[l+i];
    }
    for (j = 0 ; j < itemsR ; ++j) {
        R[j] = array[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

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