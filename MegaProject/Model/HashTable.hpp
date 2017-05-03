//
//  HashTable.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 5/3/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <cmath>
#include <assert.h>
#include "HashNode.hpp"

using namespace std;
template<class Type>
class HashTable
{
private:
    long capacity;
    long size;
    double efficiencyPercentage;
    HashNode<Type> ** hashTableStorage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(HashNode<Type> * data);
    long handleCollision(HashNode<Type> * data, long currentPosition);
public:
    HashTable();
    ~Hashable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
    long getSize();
};

template <class Type>
long HashTable<Type> :: getSize()
{
    return getSize;
}

template<class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->hashTableStorage = HashNode<Type> * [capacity];
    std :: fill_n(hashTableStorage, capacity, nullptr);
}

template<class Type>
HashTable<Type> :: ~HashTable()
{
    delete [] hashTableStorage;
}

template<class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (this->capacity * 2) + 1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    
    return nextPrime;
}

template<class Type>
bool HashTable<Type> :: isPrime(long candidateNumber)
{
    if(candidateNumber <= 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || canndidateNumber == 3)
    {
        return true;
    }
    else if(candidateNumber % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) +1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                return false
            }
        }
        return false;
    }
}

template<class Type>
long HashTable<Type> :: findPosition(HashNode<Type> * data)
{
    long insertPosition = data->getKey() % this->capacity;
    return insertPosition;
}

template<class Type>
long HashTable<Type> :: handleCollision(HashNode<Type> * data, long currentPosition)
{
    long shift = 17;
    
    for(long position = currentPosition+ shift; position != currentPosition; position += shift)
    {
        if(position >= capacity)
        {
            position = position % capacity;
        }
        
        if(hashTableStorage[position] == nullptr)
        {
            return position;
        }
    }
    
    return -1;
}

template <class Type>
bool HashTable<Type> :: remove(Type data)
{
    bool removed = false;
    
    HashNode<Type> * find(data);
    long hashIndex = findPosition(find);
    
    if(hashTableStorage[hashIndex] != nullptr)
    {
        hashTableStorage[hashIndex] = nullptr;
        remove = true;
        this->size--;
    }
    
    return removed;
}

template<class Type>
void HashTale<Type> :: displayContents()
{
    for(long index = 0; index < capacity; index++)
    {
        if(hashTableStorage[index] != nullptr)
        {
            cout << index << ": " << hashTable[index]->getData() << endl;
        }
    }
}

template <class Type>
void HashTable<Type> :: add(Type data)
{
    this->size++;
    if(((this->size * 1.000) / this->capacity) > this->efficiencyPercentage)
    {
        resize();
    }
    
    HashNode<Type> * temp = new HashNode<Type>(data);
    long index = findPosition(temp);
    
    if(hashTableStorage[index] == nullptr)
    {
        hashTableStorage[index] = temp;
    }
    else
    {
        long updatedPosition = handleCollision(temp, index);
        hashTableStorage[updatedStorage] = temp;
    }
}

template <class Type>
void HashTable<Type> :: resize()
{
    long updatedCapacity = nextPrime();
    HashNode<Type> ** tempStorage = new HashNode<Type> * [updatedCapacity];
    
    std :: fill_n(tempStorage, updatedCapacity, nullptr);
    
    long oldCapacity = this->capacity;
    this->capicity = updatedCapacity;
    
    for (long index = 0; index < oldCapacity; index++)
    {
        if(hashTableStorage[index] != nullptr)
        {
            HashNode<Type> * temp = hashTableStorage[index];
            
            long position = findPosition(temp);
            if{tempStorage[position] == nullptr)
                {
                    tempStorage[position] = temp;
                }
                else
                {
                    long updatedPosition = handleCollision(temp, position);
                    tempStorage[updatedPosition] = temp;
                }
        }
    }
        
        hashTableStorage = tempStorage;
}


#endif /* HashTable_h */
