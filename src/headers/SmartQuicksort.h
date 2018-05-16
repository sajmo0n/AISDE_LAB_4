//
// Created by sajmon on 15.05.18.
//

#ifndef SMART_QUICKSORT_H
#define SMART_QUICKSORT_H


#include "SmartDataTable.h"
#include "SimpleObject.h"

template <typename typ>
class SmartQuicksort : public SmartDataTable<typ> {
public:
    // trzeba zaimplementowac QUICKSORTA narazie jest tutaj szablon z INSERTIONSORT

    void quicksort(long left, long right) {
        long i,j;
        long pivot;
        i = (left + right) / 2;
        pivot = (*this)[i].getValue();
        (*this)[i] = (*this)[right];
        for(j = i = 0L; i < right; i++)
            if((*this)[i].getValue() < pivot)
            {
                SmartDataTable<typ>::swap(i, j);
                j++;
            }
        (*this)[right] = (*this)[j];
        (*this)[j] = pivot;
        if(0L < j - 1)  quicksort(0L, j - 1);
        if(j + 1 < right) quicksort(j + 1, right);
    }
};
#endif

