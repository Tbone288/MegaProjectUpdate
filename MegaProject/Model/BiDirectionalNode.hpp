//
//  BiDirectionalNode.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 2/27/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    BiDirectionalNode<Type> * previous;
    BiDirectionalNode<Type> * nextPointer;
    Type data;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous,
        BiDirectionalNode<Type> * next);
};

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>()
{
    
}

BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node<Type>(data)
{
    
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getNextPointer()
{
    return this->previous;
}

template <class Type>
BiDirectionalNode<Type> :: BirectionalNode<Type> : Node<Type>()
{
    this->nextPointer = nullptr;
    this->previous = nullptr;
}

template <class Type>
BiDirectionalNode<Type> :: BirectionalNode<data> : Node<Type>(data)


#endif /* BiDirectionalNode_h */
