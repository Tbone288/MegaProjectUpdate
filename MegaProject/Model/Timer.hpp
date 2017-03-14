//
//  Timer.hpp
//  MegaProject
//
//  Created by Odom, Tyler on 3/9/17.
//  Copyright © 2017 Odom, Tyler. All rights reserved.
//

#ifndef Timer_h
#define Timer_h

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>

class Timer
{
private:
    clock_t executionTime;
public:
    Timer();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayTimerInformation();
    long getExecutionTimeInMicroseconds();
};

#endif /* Timer_h */
