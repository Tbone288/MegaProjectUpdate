//
//  DoubleList.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 3/9/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

#include "DoublyLinkedList.hpp"
#include <assert.h>

template<class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndexFast(int index);
    Type remove(int index);
    Type getFromIndex(int index);
};


template<class Type>
DoubleList<Type> :: DoubleList()
{
    
}

template<class Type>
void DoubleList<Type> :: add(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
    }
    else
    {
        this->getEnd()->setNextPointer(addedNode);
        addedNode->setPreviousPointer(this->getEnd());
    }
    this->setEnd(addedNode);
    this->setSize(this->getSize() + 1);
}

template<class Type>
DoubleList<Type> :: ~DoubleList()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
    
}

template<class Type>
void DoubleList<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= this->getSize());
    if(index == 0)
    {
        addFront(value);
    }
    else if(index == 0)
    {
        addEnd(value);
    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = this->getFront();
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        previous->setNextPointer(insertedNode);
        insertedNode->setNextPointer(current);
        
        this->getSize() + 1;
    }
    
}

template<class Type>
void DoubleList<Type> :: addAtIndexFast(int index, Type value)
{
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() / 2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference->getNextPoiner();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this->getSize() - 1; position > index;  position--)
        {
            reference = reference->getPreviousPointer();
        }
    }
    
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
    
}

template<class Type>
Type DoubleList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    
    BiDirectionalNode<Type> * reference = this->getFront();
    for(int position = 0; position < index; position++)
    {
        reference = reference->getNextPointer();
    }
    valueAtIndex = reference->getNodeData();
    
    return valueAtIndex;
}

template<class Type>
Type DoubleList<Type>:: remove(int index)
{
    Type derp;
    BiDirectionalNode<Type>* nodeToTakeOut = this->getFront();
    for(int spot =  0; spot< index; spot++)
    {
        nodeToTakeOut = nodeToTakeOut->getNextPointer();
    }
    derp= nodeToTakeOut->getNodeData();
    if(this->getSize() > 1)
    {
        BiDirectionalNode<Type>* prev = nodeToTakeOut->getPreviousPointer();
        BiDirectionalNode<Type>* next = nodeToTakeOut->getNextPointer();
        
        if(prev != nullptr)
        {
            prev->setNextPointer(next);
        }
        if(next != nullptr)
        {
            next->setPreviousPointer(prev);
        }
        if(index == 0)
        {
            this->setFront(this->getFront()->getNextPointer());
            this->getFront()->getPreviousPointer();
        }
        else if(index == this->getSize() - 1)
        {
            this->setEnd(this->getEnd()->getPreviousPointer());
            this->getEnd()->setNextPointer(nullptr);
        }
    }
    else
    {
        this->setFront(nullptr);
        this->setEnd(nullptr);
    }
    
    delete nodeToTakeOut;
    
    this->setSize(this->getSize() - 1);
    return derp;
}

template<class Type>
Type DoubleList<Type> :: getFromIndexFast(int index)
{
    assert(index >=0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type>* reference;
    if(index < this->getSize() / 2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference->getNextPointer();
        }
    }
    else
    {
        reference = this->getEnd();
        for(int position = this->getSize() -1; position > index; position--)
        {
            reference = reference->getPreviousPointer();
        }
    }
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}
#endif /* DoubleList_h */
