//
//  DataStructureController.cpp
//  MegaProject
//
//  Created by Odom, Tyler on 2/8/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/IntNodeArray.hpp"
using namespace std;

DataStructureController :: DataStructureController()
{
    wordNode = Node<string> ("derpy mcderpface");
    numberNode = Node<int>();
}

void DataStructureController::testNodes()
{
    cout << "The contents of the Node<string>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}

void DataStructureController :: start()
{
    cout << "Starting the project" << endl;
    cout << "Switching to the array testing" << endl;
    testNodes();
    cout << "Finished testing" << endl;
}

void DataStructureController:: testIntArray()
{
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for (int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot "<< index << endl;
    }
    
    for(int index = 0; index < temp.getSize(); index++)
    {
        cout << temp.getFromIndex(index) << "is at spot " << index << endl;
    }
    
}
