//
//  FileController.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 3/27/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef FileController_h
#define FileController_h

#include "../Model/DoubleList.hpp" //Default Structure
#include "../Model/FoodItem.hpp" //Datatypes
#include "../Model/CrimeData.hpp"
#include <string> //String Type
#include <fstream> //File operations
#include <iostream> //console access
#include <sstream> //String as stream

using namespace std; //Keyword support

class FileController
{
private:
    DoubleList<FoodItem> foodItemList;
public:
    DoubleList<FoodItem> readFoodItemDataFromFileAsList(string filename);
    void writeFoodItemDataStatistics(DoubleList<FoodItem> source, string filename);
};


#endif /* FileController_h */
