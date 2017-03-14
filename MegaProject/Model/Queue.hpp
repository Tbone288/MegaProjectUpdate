//
//  Queue.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 3/7/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

template <class Type>
class Queue :: public DoublyLinkedList<Type>
{
private:
    
public:
    Queue();
    ~Queue();
    void add(Type data);
    Type remove(int index);
    void enqueue(Type data);
    Type dequeue();
    Type peek();
};

template <class Type>
Queue<Type> :: Queue() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
Queue<Type> :: ~Queue()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this-> getFront();
    }
}

template <class Type>
void Queue<Type> :: add(Type value)
{
    enqueue(value);
}
/*
 Add to Queue:
 Create Node
 If First -adjust front
 else set new node to ends next, and connects new nodes previous to end.
 move end to new node.
 adjust size + 1
 */

template<class Type>
void Queue<Type> :: enqueue(Type insertedvalue)
{
    BiDirectionalNode<Type> * added = new BiDirectionalNode<Type>(insertedValue);
    
    if(this->getSize() == 0 || this->getFront == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(added);
    }
    else
    {
        this->getEnd()->setNextPointer(added);
    }
    this->setEnd(added);
    this->setSize(this->getSize() + 1);
}

/*
 Remove from Queue
 Check valid index
 call dequeue
 */

template<class Type>
Type Queue<Type> :: remove(int index)
{
    assert(index == 0 && this->getSize() > 0);
    return dequeue();
}

/*
 Check size
 If size == 1
    adjust front/end to nullptr
 else
    move front to next
 delete node
 adjust size
 return value
 */

template<class Type>
Type Queue<Type> :: dequeue()
{
    assert(this->getSize() > 0);
    Type removedValue = this->getFront()->getNodeData;
    BiDirectionalNode<Type> * removeMe = this->getFront();
    
    if(this->getSize() == 1)
    {
        this->setEnd(nullptr);
        this->setFront(nullptr);
    }
    else
    {
        this->setFront(removeMe->getNextPointer());
        this->setFront()->setPreviousPointer(nullptr);
    }
   
    
    delete removeMe;
    this->setSize(this->getSize() - 1);
    
    return removedValue;
}

/*
 1. Check that the size is greater than 0.
 2. Return the front objects data.
 */
template <class Type>
Type Queue<Type> :: peek()
{
    assert(this->getSize() > 0);
    
}


#endif /* Queue_h */
