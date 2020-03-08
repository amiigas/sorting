//
// Created by Aleksy on 2020-03-04.
//

#ifndef DATAARRAY_H
#define DATAARRAY_H

#include <iostream>

class DataArray {

    public:
        int* data;
        int size;

        DataArray(int s);
        ~DataArray();
        void fill(double sortedPercentage);


};

std::ostream& operator << (std::ostream &stream, const DataArray &dataArray);

#endif
