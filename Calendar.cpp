#include "Calendar.h"
#include <iostream>
#include <string>
#include <vector>





Calendar::Calendar(int startingYear)  //constructor--creates a stretch of calendar dates based on the starting year
{

    std::cout<<"Monday January 1st 2024 falls on day "<<DayfinderJan1(2024)<<std::endl;




}
//==============================================================================
//⁡⁣⁢⁣𝗳𝘂𝗻𝗰𝘁𝗶𝗼𝗻 𝘁𝗼 𝗲𝘅𝗲𝗰𝘂𝘁𝗲 ​‌‌‍ℤ𝕖𝕝𝕝𝕖𝕣'𝕤 ℂ𝕠𝕟𝕘𝕣𝕦𝕖𝕟𝕔𝕖​--𝗿𝗲𝘁𝘂𝗿𝗻𝘀 𝘁𝗵𝗲 𝗱𝗮𝘆 𝟬-𝟲 (𝗦𝗔𝗧-𝗙𝗥𝗜)⁡
int DayfinderJan1(int year)
{
    int h; //day of the week that the date in question would fall on
    int q=1; //day/date of the month   (Jan 1)
    int m=13; //adjusted month (Jan and Feb are 13 and 14 of the previous year***)
    int K=23; //year of the century (year % 100) 2024-1
    int J=20; //zero based century (year//100)---2024= 20  century

    //when looking for Jan 1 (m=13  and year K=(year % 100)-1  *previous year

    h=(q+(13*(m+1)/5)+K+(K/4)+(J/4)-2*J)% 7;


    return h;       //send back the result

    
}
