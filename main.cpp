#include <iostream>
#include <stdlib.h>
#include "QuadraticProbing.h"

using namespace std;

void avgProbe(int items);

int main()
{
    int items;

    cout << "Enter number of items to insert: ";
    cin >> items;

    do
    {
        avgProbe(items);
        cout << "Enter number of items to insert: ";
        cin >> items;
    }while(items >= 0);

    return 0;
}

void avgProbe(int items)
{
    int k =1, i, j;
    double avg1 =0;
    double avg2 =0;
    HashTable<int> table1(101);
    HashTable<int> table2(101);
    bool contains[1000];            //check against when inserting

    //insert "items" random values into the Hashtable
    for(j=0; j<100; j++)
    {
        for(i=0; i<items; i++)
        {
            k = rand()  % 1000;
            while(contains[k])      //ensure no duplicates
                k=rand() % 1000; 
            table1.insert(k);       //quadratic probing
            table2.linearInsert(k); //linear probing
        }
        avg1 += table1.getProbes(); //quadratic 
        avg2 += table2.getProbes(); //Linear
        table1.makeEmpty();
        table2.makeEmpty();
    }
    avg1 = avg1/100;
    avg2 = avg2/100;
    cout << "The average number of probes for the last of " << items 
            << " quadratic inserts was " << avg1;
    cout << endl << "The average number of probes for the last of " << items 
            << " linear inserts was " << avg2 << endl << endl;
}