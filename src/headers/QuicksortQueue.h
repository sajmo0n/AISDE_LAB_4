//
// Created by sajmon on 15.05.18.
//

#ifndef QUICKSORT_QUEUE_H
#define QUICKSORT_QUEUE_H
#include "SmartQuicksort.h"
#include "AbstractPriorityQueue.h"


template <typename typ>
class QuicksortQueueOfficious : public SmartQuicksort<typ>, public AbstractPriorityOfficiousQueue<typ>{
public:
    QuicksortQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Quicksort"){ std::cout << "\n"; }

private:
    void putOfficious(typ& a) {
        (*this) += a;
        SmartQuicksort<typ>::quicksort(0L, SmartDataTable<typ>::getDataSize());
    }

    typ getOfficious(){
        typ ret = SmartQuicksort<typ>::getFirst();
        SmartQuicksort<typ>::quicksort(0L, SmartDataTable<typ>::getDataSize());
        return ret;
    }
};

template <typename typ>
class QuicksortQueueLazy : public SmartQuicksort<typ>, public AbstractPriorityLazyQueue<typ> {
public:
    QuicksortQueueLazy() : AbstractPriorityLazyQueue<typ>("Quicksort"){ std::cout << "\n"; }

private:
    void putLazy(typ& a) {
        (*this) += a;
    }

    typ getLazy(){
        if(SmartQuicksort<typ>::getDataSize() < 0L) throw QueueException(QUEUE_EMPTY);

        SmartQuicksort<typ>::quicksort(0L, SmartDataTable<typ>::getDataSize());
        return SmartQuicksort<typ>::getFirst();
    }
};

#endif
