//
//  DataStructureController.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 2/8/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Node.hpp"
#include <string>

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node <int> numberNode;
    Node<string> wordNode;
    void testNodes();
    
public:
    DataStructureController();
    void start();
};

#endif /* DataStructureController_hpp */