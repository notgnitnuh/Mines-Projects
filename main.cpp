#include <iostream>
#include <stdlib.h>
#include "QuadraticProbing.h"

using namespace std;

double avgProbe(int items);

int main()
{
    int items=0;
    double avg;

    while(items >= 0)
    {
        cout << "enter number of items to insert: ";
        cin >> items;
        avg = avgProbe(items);
        cout << endl << "The average number of probes for the last of " << items 
             << " inserts was " << avg << endl;
    }
    
    return 0;
}


//insert n items, run 100 times, return avg of final probes
double avgProbe(int items)
{
    int k, i, j;
    double avg = 0;
    HashTable<int> table(101);
    

    //insert "items" random values into the Hashtable
    for(j=0; j<100; j++)
    {
        for(i=0; i<items; i++)
        {
            k = rand()  % 1000;
            while(table.contains(k))
                k=rand() % 1000; 
            table.insert(k);
        }
        cout << table.getProbes() << endl;
        avg += table.getProbes();
        table.makeEmpty();
    }
    
    return avg/100;
}