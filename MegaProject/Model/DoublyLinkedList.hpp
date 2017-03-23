//
//  DoublyLinkedList.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 3/1/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "BiDirectionalNode.hpp"

template <class Type>
class DoublyLinkedList
{
private:
    BiDirectionalNode<Type> * front;
    BiDirectionalNode<Type> * end;
    int size;
public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList();
    int getSize() const;
    BiDirectionalNode<Type> * getFront() const;
    BiDirectionalNode<Type> * getEnd() const;
    virtual void add(Type data) = 0;
    virtual Type remove(int index) = 0;
    
    void setFront(BiDirectionalNode<Type> * front);
    void setSize(int updated);
    void setEnd(BiDirectionalNode<Type> * end);
};

template <class Type>
DoublyLinkedList<Type> :: ~DoublyLinkedList()
{
    
}

template <class Type>
DoublyLinkedList<Type> :: DoublyLinkedList()
{
    size = 0;
    front = nullptr;
    end = nullptr;
}

template <class Type>
int DoublyLinkedList<Type> :: getSize()
{
    return size;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: getFront()
{
    return front;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type> :: getEnd()
{
    return end;
}



#endif /* DoublyLinkedList_h */
