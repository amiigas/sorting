//
// Created by Aleksy on 2020-03-04.
//

#include <random>
#include <iostream>

#include "dataArray.h"

using namespace std;

default_random_engine generator;
uniform_int_distribution<int> distribution(1,10);

DataArray::DataArray(int s) {
    data = new int[s];
    size = s;
}

DataArray::~DataArray() {
    delete[] data;
}

void DataArray::fill(double sortedPercentage) {

    int sorted = static_cast<int>(size*sortedPercentage/100);

    if (sortedPercentage == 100.0) {        //sorted percentage of 100.0 means sorted and inverted
        for (int i = 0; i < size; ++i) {
            data[i] = size-(i+1);
        }
    } else {
        for (int i = 0; i < sorted ; ++i) {
            data[i] = i;
        }

        for (int i = sorted; i < size; ++i) {
            data[i] = distribution(generator);
        }
    }

    distribution.reset();
}

ostream& operator << (ostream &stream, const DataArray &dataArray){

    for (int i = 0; i < dataArray.size; ++i) {
        stream << dataArray.data[i] << " " ;
    }
    stream << endl;

    return stream;
}