//
// Created by sajmon on 16.05.18.
//

#ifndef BUCKETSORT_QUEUE_H
#define BUCKETSORT_QUEUE_H
#include "SmartBucket.h"
#include "AbstractPriorityQueue.h"


template <typename typ>
class BucketsortQueueOfficious : public SmartBucket<typ>, public AbstractPriorityOfficiousQueue<typ>{
public:
    BucketsortQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Bucketsort"){ std::cout << "\n"; }

private:
    void putOfficious(typ& a) {
        (*this) += a;
        SmartBucket<typ>::bucketsort(1000);
    }

    typ getOfficious(){
        typ ret = SmartBucket<typ>::getFirst();
        SmartBucket<typ>::bucketsort(1000);
        return ret;
    }
};

template <typename typ>
class BucketsortQueueLazy : public SmartBucket<typ>, public AbstractPriorityLazyQueue<typ> {
public:
    BucketsortQueueLazy() : AbstractPriorityLazyQueue<typ>("Bucketsort"){ std::cout << "\n"; }

private:
    void putLazy(typ& a) {
        (*this) += a;
    }

    typ getLazy(){
        if(SmartBucket<typ>::getDataSize() < 0L) throw QueueException(QUEUE_EMPTY);

        SmartBucket<typ>::bucketsort(1000);
        //SmartDataTable<typ>::printDataTable("przed usunieciem z kolejki, ale juz po sortowaniu:");
        return SmartBucket<typ>::getFirst();
    }
};

#endif //BUCKETSORT_QUEUE_H
