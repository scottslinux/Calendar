#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>


struct CalendarData     //keeping it simple for now
{
    int month;
    int day;
    int year;
};

//============================================================================== */
class Calendar
{
private:
    std::vector<CalendarData> dates;


public:
    Calendar(int startingYear=2024);        //default to 2024
   
};
//==============================================================================

int DayfinderJan1(int year);    //function to execute Zeller's Congruence-return 0-6 (sat-fri)
