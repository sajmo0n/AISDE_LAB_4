//
// Created by sajmon on 16.05.18.
//

#ifndef SMARTBUCKET_SORT_H
#define SMARTBUCKET_SORT_H

#include "SmartDataTable.h"
#include "SimpleObject.h"

template <typename typ>
class SmartBucketsort : public SmartDataTable<typ> {
public:

    void bucketsort(const long WMIN, const long WMAX){
        long lw[WMAX - WMIN + 1],i,j;

// najpierw zerujemy liczniki

        for(i = WMIN; i <= WMAX; i++) lw[i - WMIN] = 0;

// zliczamy w odpowiednich licznikach wystąpienia
// wartości elementów sortowanego zbioru

        for(i = 0; i < SmartDataTable<typ>::getDataSize(); i++) lw[(*this)[i].getValue() - WMIN]++;

// zapisujemy do zbioru wynikowego numery niezerowych liczników
// tyle razy, ile wynosi ich zawartość

        j = 0;
        for(i = WMIN; i <= WMAX; i++) while(lw[i - WMIN]--) (*this)[j++] = i;

    }

    };

#endif //SMARTBUCKET_SORT_H
