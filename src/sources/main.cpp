#define MAIN_FILE

#include <iostream>

#include "RandomGenerator.h"
#include "HeapQueue.h"
#include "TournamentQueue.h"
#include "BubbleQueue.h"
#include "SelectionQueue.h"

#include "SimpleObject.h"



int main (int argc, char * const argv[]) {

	RandomGenerator gen(283591); // tu nalezy wstawic numer indeksu


// Wybor implementacji kolejki:

//	TournamentQueueOfficious<SimpleObject<int> > theQueue;
	TournamentQueueLazy<SimpleObject<int> > theQueue;
//  HeapQueueOfficious<SimpleObject<int> > theQueue;
//  HeapQueueLazy<SimpleObject<int> > theQueue;
//	BubbleQueueOfficious<SimpleObject<int> > theQueue;
//	BubbleQueueLazy<SimpleObject<int> > theQueue;
//	SelectionQueueOfficious<SimpleObject<int> > theQueue;
//	SelectionQueueLazy<SimpleObject<int> > theQueue;


// testowanie kolejki w petli - najpierw wkladamy potem wyjmujemy

    SimpleObject<int> a = SimpleObject<int>(0);

    for(int i = 0; i <= 10; i++)
    {
        a.setValue(gen.getRandom(1,50));
        theQueue.put(a);
    }

    theQueue.printDataTable("po pierwszym wczytaniu losowym");

    long wielkosc = theQueue.getDataSize();

    for(int i = 0; i < wielkosc; i++)
    {
        try{
		std::cout << "get: " << theQueue.get().getValue() << "\n\n";
		}
	    catch(QueueException& exc) {
		std::cout << "get: empty\n";
	    }
	    theQueue.printDataTable("po get");
    }

    std::cout << "Comparisons: " << SimpleObject<int>::getComparisons() << "\n";
    std::cout << "Copyings: " << SimpleObject<int>::getCopyings() << "\n";

    return 0;


// Proste, "silowe" testowanie kolejki
//	SimpleObject<int> a = SimpleObject<int>(8);
//	theQueue.put(a);
//	a.setValue(2);
//	theQueue.put(a);
//	a.setValue(5);
//	theQueue.put(a);
//	a.setValue(4);
//	theQueue.put(a);
//	a.setValue(1);
//	theQueue.put(a);
//	a.setValue(7);
//	theQueue.put(a);
//	a.setValue(6);
//	theQueue.put(a);
//	a.setValue(11);
//	theQueue.put(a);
//	a.setValue(3);
//	theQueue.put(a);

//   theQueue.printDataTable("po wczytaniu 1");
//
//	try{
//		std::cout << "get: " << theQueue.get().getValue() << "\n";
//	}
//	catch(QueueException& exc) {
//		std::cout << "get: empty\n";
//	}
//    theQueue.printDataTable("po get");
//	a.setValue(3);
//	theQueue.put(a);
//	a.setValue(12);
//	theQueue.put(a);
//	a.setValue(1);
//	theQueue.put(a);
//	a.setValue(5);
//	theQueue.put(a);
//	a.setValue(11);
//	theQueue.put(a);
//    theQueue.printDataTable("po wczytaniu 2");

//	try{
//		std::cout << "get: " << theQueue.get().getValue() << "\n";
//	}
//	catch(QueueException& exc) {
//		std::cout << "get: empty\n";
//	}
//    theQueue.printDataTable("po get");

//	std::cout << "Comparisons: " << SimpleObject<int>::getComparisons() << "\n";
//	std::cout << "Copyings: " << SimpleObject<int>::getCopyings() << "\n";
//
//    return 0;
}
