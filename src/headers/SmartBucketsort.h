//
// Created by sajmon on 16.05.18.
//

#ifndef SMARTBUCKET_SORT_H
#define SMARTBUCKET_SORT_H

#include "SmartDataTable.h"
#include "SimpleObject.h"
#include <stdlib.h>
template <typename typ>
class SmartBucketsort : public SmartDataTable<typ> {
public:

    void bucketsort(long maxValue){ // maxValue - maksymalna wartość danej wpisywanej do kolejki
        long bucket[maxValue];
        long i;
        for(i = 0; i <= maxValue; i++){
            bucket[i] = 0; //zerowanie licznika
        }
                for(i = 0; i < SmartDataTable<typ>::getDataSize()+1; i++) {
                    bucket[(*this)[i].getValue()]++; // zliczanie wystapien wartosci elementow zbioru sortowanego
                }
        long j = SmartDataTable<typ>::getDataSize();
        for(i = 0; i <= maxValue; i++) {
            while (bucket[i]--) {
                (*this)[j--] = i;// zapisywanie do danych do kolejki
            }
        }
    }
};

#endif //SMARTBUCKET_SORT_H
