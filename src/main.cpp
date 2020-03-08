

#include <iostream>
#include <vector>

#include "dataArray.h"
#include "test.h"

#define NO_OF_ARRAYS 1

using namespace std;

int main() {

    cout << endl << "Program tests time performance of three sorting algorithms: mergesort, quicksort and introsort."
         << endl << "Press enter to start." ;

    if (cin.get() == '\n') {

        vector<int> arrayLengths = {10, 100};
        vector<double> sortedPercentage = {0.0, 25.0, 50.0, 75.0, 95.0, 99.0, 99.7, 100.0};


        for (int i = 0; i < arrayLengths.size(); ++i) {
            for (int j = 0; j < sortedPercentage.size(); ++j) {

                test(NO_OF_ARRAYS, arrayLengths[i], sortedPercentage[j]);

            }

        }

    }

    return 0;

}


