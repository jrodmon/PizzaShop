// Specification file for the Hash class
// Written by: RodJaron Monteagudo
///The purpose of this file is to store the Customer objects in the HashTable using the Linear probing method
///It has the insert, delete, and search functions and can display load factor and number of collisions

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "HashNode.h"

template<class ItemType>
class HashTable
{
private:
	HashNode<ItemType>* hashAry;
	int hashSize;
    int count;

public:
	HashTable() { count = 0; hashSize = 53; hashAry = new HashNode<ItemType>[hashSize]; }
	HashTable(int n)	{ count = 0; hashSize = n;	hashAry = new HashNode<ItemType>[hashSize]; }
	~HashTable(){ delete [] hashAry; }

	int getCount() const	{ return count; }
    int getSize() const { return hashSize; }
    double getLoadFactor() const {return 100.0 * count / hashSize; }
    bool isEmpty() const	{ return count == 0; }
    bool isFull()  const	{ return count == hashSize; }

    bool insert( const ItemType &itemIn, int h(const ItemType &key, int size) );
    bool remove( ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size));
    int  search( ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size));

};

template<class ItemType>
bool HashTable<ItemType>::insert( const ItemType &itemIn, int h(const ItemType &key, int size) )
{
    if ( count == hashSize)
        return false;

    int bucket = h(itemIn, hashSize); // set bucket equal to hash code
    int nCol = 0;

    while(hashAry[bucket].getOccupied() == 1)    // loop until it reaches an empty spot
    {
        nCol++;                                     // if spot is occupied, increment number of collision by 1
        bucket = (bucket + 1) % hashSize;           // increments bucket to the next spot in hash
    }

    hashAry[bucket].setItem(itemIn);             // insert item in bucket
    hashAry[bucket].setOccupied(1);              // set bucket to occupied
    hashAry[bucket].setNoCollisions(nCol);       // set number of collisions
    count++;

    return true;
}

template<class ItemType>
bool HashTable<ItemType>::remove( ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size))
{
    int bucket = h(key, hashSize);
    int bucketsProbed = 0;
    ItemType emptyBucket;

    while (bucketsProbed < hashSize)        // while the num of buckets probed is less than the size of hash
    {
        if (hashAry[bucket].getItem() == key)   // if the item in bucket is the same as the key
        {
            itemOut = hashAry[bucket].getItem();    //copy data from hash node to itemOut
            hashAry[bucket].setItem(emptyBucket);   //replace data in hash node with empty record
            count--;
            return true;
        }
        bucket = (bucket + 1) % hashSize;
        bucketsProbed++;
    }

    return false;
}

template<class ItemType>
int HashTable<ItemType>::search(ItemType &itemOut, const ItemType &key, int h(const ItemType &key, int size))
{
    int bucket = h(itemOut, hashSize);
    int startBucket = bucket;

    do
    {
        if(hashAry[bucket].getOccupied() != 0 && hashAry[bucket].getItem().getName() == key.getName())  // if key found
        {
            itemOut = hashAry[bucket].getItem();         // copy data to itemOut
            return hashAry[bucket].getNoCollisions();
        }
        bucket = (bucket + 1) % hashSize;     // move bucket to next location
    }
    while (bucket != startBucket);      // runs loop until returns to start bucket

    return -1;
}

#endif // HASHTABLE_H_
