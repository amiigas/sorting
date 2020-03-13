//
// Created by Aleksy on 2020-03-06.
//

#include <iostream>
#include <chrono>
#include <cmath>

#include "test.h"
#include "dataArray.h"
#include "mergesort.h"
#include "quicksort.h"
#include "introsort.h"

#define BOLDRED "\033[1;31m"
#define BOLDGREEN "\033[1;32m"
#define BOLDRED "\033[1m\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

using namespace std;

void test(int amount, int size, double sortedPercentage) {

    chrono::duration<double, std::milli> mergesortElapsedTime(0),
                                         quicksortElapsedTime(0),
                                         introsortElapsedTime(0);

    cout << endl;
    cout << "Sorting " << amount << " arrays of size: " << size << " with " << sortedPercentage << "% of elements sorted:" << endl;

    for (int i = 0; i < amount ; ++i) {

        DataArray array(size);
        array.fill(sortedPercentage);

        // measure mergesorting time
        auto start = chrono::high_resolution_clock::now();
        mergesort(array.data, 0, array.size - 1);
        auto stop = chrono::high_resolution_clock::now();

        if (!array.isSorted()) {
            cout << BOLDRED << "Array not sorted" << RESET << endl;
            break;
        }

        chrono::duration<double, std::milli> oneSort = stop - start;
        mergesortElapsedTime += oneSort;
    }

    cout << BOLDGREEN << mergesortElapsedTime.count() << RESET << " ms " << YELLOW << "mergesort" << RESET << endl;


    for (int i = 0; i < amount ; ++i) {

        DataArray array(size);
        array.fill(sortedPercentage);

        // measure quicksorting time
        auto start = chrono::high_resolution_clock::now();
        quicksort(array.data, 0, array.size - 1);
        auto stop = chrono::high_resolution_clock::now();

        if (!array.isSorted()) {
            cout << BOLDRED << "Array not sorted" << RESET << endl;
            break;
        }

        chrono::duration<double, std::milli> oneSort = stop - start;
        quicksortElapsedTime += oneSort;
    }

    cout << BOLDGREEN << quicksortElapsedTime.count() << RESET << " ms " << YELLOW << "quicksort" << RESET << endl;


    for (int i = 0; i < amount ; ++i) {

        DataArray array(size);
        array.fill(sortedPercentage);

        // measure introsorting time
        auto start = chrono::high_resolution_clock::now();
        introsort(array.data, 0, array.size - 1, 2*log2(array.size));
        auto stop = chrono::high_resolution_clock::now();

        if (!array.isSorted()) {
            cout << BOLDRED << "Array not sorted" << RESET << endl;
            break;
        }

        chrono::duration<double, std::milli> oneSort = stop - start;
        introsortElapsedTime += oneSort;
    }

    cout << BOLDGREEN << introsortElapsedTime.count() << RESET << " ms " << YELLOW << "introsort" << RESET << endl;


}