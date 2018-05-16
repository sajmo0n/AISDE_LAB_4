#define MAIN_FILE

#include <iostream>
#include <InsertionQueue.h>
#include "BucketQueue.h"
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
//	TournamentQueueLazy<SimpleObject<int> > theQueue;
//  HeapQueueOfficious<SimpleObject<int> > theQueue;
//  HeapQueueLazy<SimpleObject<int> > theQueue;
//	BubbleQueueOfficious<SimpleObject<int> > theQueue;
//	BubbleQueueLazy<SimpleObject<int> > theQueue;
//	SelectionQueueOfficious<SimpleObject<int> > theQueue;
//  SelectionQueueLazy<SimpleObject<int> > theQueue;
//  InsertionQueueOfficious<SimpleObject<int> > theQueue;
//	InsertionQueueLazy<SimpleObject<int> > theQueue;
  BucketsortQueueOfficious<SimpleObject<int> > theQueue;
//  BucketsortQueueLazy<SimpleObject<int> > theQueue;

    SimpleObject<int> a = SimpleObject<int>(0);
    long counterComparisons = 0;
    long counterCopyings = 0;
    long counterComparisonsNew = 0;
    long counterCopyingsNew = 0;
    long counterComparisonsDiff = 0;
    long counterCopyingsDiff = 0;

/***********************************************************************************************
 * UWAGA! ABY SKORZYSTAC Z ODPOWIEDNIEGO TESTU NALEZY ZAKOMENTOWAC POZOSTALE WARIANTY !
 ************************************************************************************************/

/*******************************************************************************************************
 TESTOWANIE KOLEJKI WARIANT NR 1 - WIECEJ WSTAWIEN NIZ WYJEC DLA ROZNYCH WIELKOSCI ZBIORU WEJSCIOWEGO
********************************************************************************************************/

    long startsize = 4500; // wielkosc losowego zbioru wejsciowego
    float divider = 0.1; //  stosunek wyjec do wstawien
        std::cout << "WIELKOSC ZBIORU WEJSCIOWEGO: " << startsize << "\n\n";
        for (int i = 1; i <= startsize; i++) {
            a.setValue(gen.getRandom(0, 100));
            theQueue.put(a);
        }

        //theQueue.printDataTable("po pierwszym wczytaniu losowym");

        for (int i = 1; i <= startsize*divider ; i++) {
            try {
                //theQueue.printDataTable("przed get");
                theQueue.get();
            }
            catch (QueueException &exc) {
                std::cout << "get: empty\n";
            }

        }

        //theQueue.printDataTable("po wyjeciach");

        std::cout << "Comparisons: " << SimpleObject<int>::getComparisons() << "\n";
        std::cout << "Copyings: " << SimpleObject<int>::getCopyings() << "\n";


/*******************************************************************************************************
    TESTOWANIE KOLEJKI WARIANT NR 2 - WIECEJ WYJEC NIZ WSTAWIEN DLA ROZNYCH WIELKOSCI ZBIORU WEJSCIOWEGO
    W TYM PRZYPADKU W KOLEJCE ZNAJDUJE SIE JUZ LOSOWE ELEMENTY
********************************************************************************************************/

    for (int i = 0; i < 4000; i++){
        a.setValue(gen.getRandom(0, 100));
        theQueue.put(a);
    }

    std::cout << "Porownania dla wstawienia kolejki teorytycznej: " << SimpleObject<int>::getComparisons() << "\n";
    std::cout << "Kopiowania dla wstawienia kolejki teorytycznej: " << SimpleObject<int>::getCopyings() << "\n";
    counterCopyings = SimpleObject<int>::getCopyings();
    counterComparisons = SimpleObject<int>::getComparisons();
    //theQueue.printDataTable("po pierwszym wczytaniu losowym");


    long startsize = 900; // wielkosc losowego zbioru wejsciowego
    float divider = 5; //  stosunek wyjec do wstawien

    std::cout << "WIELKOSC ZBIORU WEJSCIOWEGO: " << startsize << "\n\n";
    for (int i = 1; i <= startsize; i++) {
        a.setValue(gen.getRandom(0, 100));
        theQueue.put(a);
    }

    //theQueue.printDataTable("po pierwszym wczytaniu losowym");

    for (int i = 1; i <= startsize*divider ; i++) {
        try {
            //theQueue.printDataTable("przed get");
            theQueue.get();
        }
        catch (QueueException &exc) {
            std::cout << "get: empty\n";
        }

    }

    //theQueue.printDataTable("po wyjeciach");

    std::cout << "Porownania po wlasciwym tescie: " << SimpleObject<int>::getComparisons() - counterComparisons<< "\n";
    std::cout << "Kopiowania po wlasciwym tescie: " << SimpleObject<int>::getCopyings() - counterCopyings << "\n";

    /*******************************************************************************************************
 TESTOWANIE KOLEJKI WARIANT NR 3 - TA SAMA ILOSC WSTAWIEN I WYJEC DLA ROZNYCH WIELKOSCI ZBIORU WEJSCIOWEGO
********************************************************************************************************/

    long startsize = 0; // wielkosc losowego zbioru wejsciowego
    float divider = 1; //  stosunek wyjec do wstawien
    long finalsize = 5500;
    for (startsize; startsize < finalsize; startsize = startsize + 500) {
        std::cout << "-------------------------------------------------" << "\n\n";
        std::cout << "WIELKOSC ZBIORU WEJSCIOWEGO: " << startsize << "\n\n";
        for (int i = 1; i <= startsize; i++) {
            a.setValue(gen.getRandom(0, 100));
            theQueue.put(a);
        }

        //theQueue.printDataTable("po pierwszym wczytaniu losowym");

        for (int i = 1; i <= startsize; i++) {
            try {
                //theQueue.printDataTable("przed get");
                theQueue.get();
            }
            catch (QueueException &exc) {
                std::cout << "get: empty\n";
            }

        }

        theQueue.printDataTable("po wyjeciach");

        counterComparisonsNew = counterComparisons;
        counterCopyingsNew = counterCopyings;
        counterComparisons = SimpleObject<int>::getComparisons();
        counterCopyings = SimpleObject<int>::getCopyings();
        counterComparisonsDiff = counterComparisons - counterComparisonsNew;
        counterCopyingsDiff = counterCopyings - counterCopyingsNew;

        std::cout << "Porownania: " << counterComparisonsDiff << "\n";
        std::cout << "Kopiowania: " << counterCopyingsDiff << "\n";
        std::cout << "laczne porownania w petli: " << SimpleObject<int>::getComparisons() << "\n";
        std::cout << "laczne kopiowania w petli: " << SimpleObject<int>::getCopyings() << "\n";
        std::cout << "-------------------------------------------------" << "\n";

   }
    return 0;
}