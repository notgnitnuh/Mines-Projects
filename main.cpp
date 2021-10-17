#include <iostream>
#include <stdlib.h>
#include "QuadraticProbing.h"

void avgProbe(int items);

int main()
{
    int items=0;

    while(items >= 0)
    {
        cout << "Enter number of items to insert: ";
        cin >> items;
        avgProbe(items);
    }
    
    return 0;
}

//insert n items, run 100 times, return avg of final probes
void avgProbe(int items)
{
    int k, i, j;
    double avg1 = 0;
    double avg2 = 0;
    HashTable<int> table1(101);
    HashTable<int> table2(101);
    

    //insert "items" random values into the Hashtable
    for(j=0; j<100; j++)
    {
        for(i=0; i<items; i++)
        {
            k = rand()  % 1000;
            while(table1.contains(k))
                k=rand() % 1000; 
            table1.insert(k);
            table2.insert(k);
        }
        avg1 += table1.getProbes();
        avg2 += table2.getProbes();
        table1.makeEmpty();
        table2.makeEmpty();
    }
    avg1 = avg1/100;
    avg2 = avg2/100;

    cout << endl << "The average number of probes for the last of " << items 
            << " quadratic inserts was " << avg1 << endl;
    cout << endl << "The average number of probes for the last of " << items 
            << " linear inserts was " << avg2 << endl;

}