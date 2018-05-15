//
// Created by sajmon on 15.05.18.
//

#ifndef INSERTION_QUEUE_H
#define INSERTION_QUEUE_H
#include "SmartInsertion.h"
#include "AbstractPriorityQueue.h"

template <typename typ>
class InsertionQueueOfficious : public SmartInsertion<typ>, public AbstractPriorityOfficiousQueue<typ> {
public:
    InsertionQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Insertion") {
        std::cout
                << "\n";
    }

private:
    void putOfficious(typ &a) {
        (*this) += a;
        SmartInsertion<typ>::doInsertion();
    }

    typ getOfficious() {
        typ ret = SmartInsertion<typ>::getFirst();
        SmartInsertion<typ>::doInsertion();
        return ret;
    }
};


template <typename typ>
class InsertionQueueLazy : public SmartInsertion<typ>, public
AbstractPriorityLazyQueue<typ> {
public:
    InsertionQueueLazy() : AbstractPriorityLazyQueue<typ>("Insertion"){ std::cout << "\n"; }
private:
    void putLazy(typ& a) {
        (*this) += a;
    }
    typ getLazy(){
        if(SmartInsertion<typ>::getDataSize() < 0L) throw

                    QueueException(QUEUE_EMPTY);

        SmartInsertion<typ>::doInsertion();
        SmartDataTable<typ>::printDataTable("przed usunieciem z kolejki, ale juz po sortowaniu:");
        return SmartInsertion<typ>::getFirst();
    }
};

#endif // INSERTION_QUEUE_H
