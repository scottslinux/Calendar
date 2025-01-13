#include "Calendar.h"
#include <iostream>
#include <string>
#include <vector>



//==============================================================================
//⁡⁣⁢⁣𝗳𝘂𝗻𝗰𝘁𝗶𝗼𝗻 𝘁𝗼 𝗲𝘅𝗲𝗰𝘂𝘁𝗲 ​‌‌‍ℤ𝕖𝕝𝕝𝕖𝕣'𝕤 ℂ𝕠𝕟𝕘𝕣𝕦𝕖𝕟𝕔𝕖​--𝗿𝗲𝘁𝘂𝗿𝗻𝘀 𝘁𝗵𝗲 𝗱𝗮𝘆 𝟬-𝟲 (𝗦𝗔𝗧-𝗙𝗥𝗜)⁡

int Calendar::DayfinderJan1(int month,int day,int year)
{
    int h; //day of the week that the date in question would fall on
    int q=day; //day/date of the month   (Jan 1)

    //adjusted month (Jan and Feb are 13 and 14 of the previous year***)
    if(month==1 || month==2)
        {
            month+=12;  // adjust month to 13th or 14th
            year-=1;    // of the prior year
        }
    int m=month;
    int K=year % 100; //year of the century (year % 100) 2024-1
    int J=year/100; //zero based century (year//100)---2024= 20  century

    //when looking for Jan 1 (m=13  and year K=(year % 100)-1  *previous year

    h=(q+(13*(m+1)/5)+K+(K/4)+(J/4)-2*J)% 7;


    return h;       //send back the result

    
}
//==============================================================================


Calendar::Calendar()  //constructor--creates a stretch of calendar dates based on the starting year
{
    
   
    daynames.push_back("Saturday");
    daynames.push_back("Sunday");
    daynames.push_back("Monday");
    daynames.push_back("Tuesday");
    daynames.push_back("Wednesday");
    daynames.push_back("Thursday");
    daynames.push_back("Friday");
    
    
    
}
//==============================================================================
int Calendar::CreateCalendar(int year)   //function to create a calendar for a given year
{
    //find the first day of the month
    int daycounter=Calendar::DayfinderJan1(1,1,year);  //start the count at the first of the month
    
    //check for leap year

    if (leapcheck(year))
        month_limits[1]=29;
            else
                month_limits[1]=28;



    for(int month=1;month<=12;month++)
    {
        for(int i=1;i<=month_limits[month-1];i++)
            {
                if(daycounter>6) daycounter=0;
                std::cout<<month<<"/"<<i<<"/"<<year
                    <<"\t"<<daynames[daycounter++]<<std::endl;

            }
        std::cout<<"*******************************************************\n";
    }


    return 0;

}

//==============================================================================
//                      ⁡⁣⁣⁢𝗟𝗲𝗮𝗽 𝗬𝗲𝗮𝗿 𝗖𝗵𝗲𝗰𝗸⁡
bool Calendar::leapcheck(int year)
{
    //⁡⁢⁢⁡⁣⁣⁢A year is a leap year if it is divisible by 4 and not by 100⁡
    //⁡⁣⁣⁢Or it is evenly divisible by 400⁡

    if((year % 4 ==0 )&& (year % 100 !=0) )
        return true;
            else 
                if (year % 400==0)
                    return true;
                        else 
                            return false;


}
//==============================================================================
    void Calendar::loadCalendar(int startingyear,int duration)   //load it up 
{
 //find the first day of the month
    int daycounter=Calendar::DayfinderJan1(1,1,startingyear);  //start the count at the first of the month
    int calendarIndex=0;
    CalendarData TempDay;

    for (int year=startingyear;year<=(startingyear+duration);year++)
    {
        //check for leap year

        if (leapcheck(year))
            month_limits[1]=29;
                else
                    month_limits[1]=28;



        for(int month=1;month<=12;month++)
        {
            for(int i=1;i<=month_limits[month-1];i++)
                {
                    if(daycounter>6) daycounter=0;
                    
                    TempDay.day=i;
                    TempDay.month=month;
                    TempDay.year=year;

                    DAY.push_back(TempDay);
                    std::cout<<"day # "<<calendarIndex++<<".."<<TempDay.month<<"/"<<TempDay.day<<
                                "/"<<TempDay.year<<"\n";

                    

                }
        }
        



    }

    for(int i=0;i<DAY.size();i++)
        std::cout<<"day # "<<i<<".."<<DAY[i].month<<"/"<<DAY[i].day<<
                                "/"<<DAY[i].year<<"\n";


    return;



}