//
// Created by sajmon on 16.05.18.
//

#ifndef BUCKETSORT_QUEUE_H
#define BUCKETSORT_QUEUE_H
#include "SmartBucketsort.h"
#include "AbstractPriorityQueue.h"


template <typename typ>
class BucketsortQueueOfficious : public SmartBucketsort<typ>, public AbstractPriorityOfficiousQueue<typ>{
public:
    BucketsortQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Bucketsort"){ std::cout << "\n"; }

private:
    void putOfficious(typ& a) {
        (*this) += a;
        SmartBucketsort<typ>::bucketsort(1000);
    }

    typ getOfficious(){
        typ ret = SmartBucketsort<typ>::getFirst();
        SmartBucketsort<typ>::bucketsort(1000);
        return ret;
    }
};

template <typename typ>
class BucketsortQueueLazy : public SmartBucketsort<typ>, public AbstractPriorityLazyQueue<typ> {
public:
    BucketsortQueueLazy() : AbstractPriorityLazyQueue<typ>("Bucketsort"){ std::cout << "\n"; }

private:
    void putLazy(typ& a) {
        (*this) += a;
    }

    typ getLazy(){
        if(SmartBucketsort<typ>::getDataSize() < 0L) throw QueueException(QUEUE_EMPTY);

        SmartBucketsort<typ>::bucketsort(1000);
        //SmartDataTable<typ>::printDataTable("przed usunieciem z kolejki, ale juz po sortowaniu:");
        return SmartBucketsort<typ>::getFirst();
    }
};

#endif //BUCKETSORT_QUEUE_H
