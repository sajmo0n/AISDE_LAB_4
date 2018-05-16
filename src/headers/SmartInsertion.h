//
// Created by sajmon on 15.05.18.
//

#ifndef SMART_INSERTION_H
#define SMART_INSERTION_H

#include "SmartDataTable.h"

template <typename typ>
class SmartInsertion : public SmartDataTable<typ> {
public:

    void doInsertion(){
            for( long begin = 1; begin<=SmartDataTable<typ>::getDataSize(); begin++){
                for(long i=begin;i>0;i--){
                    if((*this)[i-1]<(*this)[i])
                        SmartDataTable<typ>::swap(i-1,i);
                }
            }
    }
};

#endif //SMART_INSERTION_H
