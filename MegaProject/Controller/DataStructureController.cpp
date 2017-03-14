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
    
}

void DataStructureController :: start()
{
    cout << "Going to test the Timing of DoubleList" << endl;
    testListTiming();
    cout << "Finished testing" << endl;
}

void DataStructureController:: testAdvancedFeatures()
{
    int showDestructor = 0;
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string> (words);
    
    cout << "These should match:" << endl;
    cout << words.getFromIndex(0) << " should be the same as " << copiedWords.getFromIndex(0) << endl;
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
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

void DataStructureController :: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should go 1, 2, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    cout << "Size should read 3 and is " << sample.getSize() << endl;
    
}

void DataStructureController :: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index=0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExcecutionTimeInMicroSeconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExcecutionTimeInMicroSeconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow = averageSlow/1000.00;
    averageFast = averageFast/1000.00;
    totalTimer.stopTimer();
    
    cout <<"The average speed for the getFromIndex method was: " << averageSlow << " microseconds." << endl;
    
    cout << "The average speed for the getFromIndex method was: " << averageFast << " microseconds." << endl;
}

void DataStructureController :: testIntStack()
{
    Stack<int> numberStack;
    numberStack.add(2315);
    numberStack.push(32);
    int testValue = numberStack.pop();
    cout << "Test value is " << testValue << " and should be 32" << endl;
    
}
    
    void DataStructureController :: testFoodQueue()
    {
        Queue<FoodItem> tastyFood;
        FoodItem szechwan("tiger tail donut");
        
        tastyFood.enqueue(szechwan);
        FoodItem boring;
        tastyFood.add(boring);
        
        FoodItem removed = tastyFood.dequeue();
        cout << "The item removed from the queue was: " << removed.getFoodName() << " and should be: tiger tail donut" << endl;
    }
}
