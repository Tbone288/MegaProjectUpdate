//
//  CircularList.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 3/1/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
    //No need to redefine the private data members
    
public:
    CircularList();
    ~CircularList();
    
    void add(Type data);
    Type remove(int index);
    //Other methods as needed
};

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList()
{
    //deal with circle list stuff only here
}

template <class Type>
void CircularList<Type> :: add(Type data)
{
    
}


#endif /* CircularList_h */
