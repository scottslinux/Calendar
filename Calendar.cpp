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
    :monthnames{"January","February","March","April","May","June","July","August","September","October","November","December"},
    daynames{"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"}
{
    
  /*
    daynames.push_back("Saturday");
    daynames.push_back("Sunday");
    daynames.push_back("Monday");
    daynames.push_back("Tuesday");
    daynames.push_back("Wednesday");
    daynames.push_back("Thursday");
    daynames.push_back("Friday");
   
    monthnames.push_back("January");
    monthnames.push_back("February");
    monthnames.push_back("March");
    monthnames.push_back("April");
    monthnames.push_back("May");
    monthnames.push_back("June");
    monthnames.push_back("July");
    monthnames.push_back("August");
    monthnames.push_back("September");
    monthnames.push_back("October");
    monthnames.push_back("November");
    monthnames.push_back("December");

    */

  
    
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
//                  ⁡⁣⁢⁣𝗖𝗿𝗲𝗮𝘁𝗲 𝗖𝗮𝗹𝗲𝗻𝗱𝗮𝗿 𝗶𝗻 𝘁𝗵𝗲 𝗩𝗲𝗰𝘁𝗼𝗿⁡

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
                    TempDay.dayofWeek=daycounter;
                    TempDay.month=month;
                    TempDay.year=year;

                    DAY.push_back(TempDay);
                    //std::cout<<"day # "<<calendarIndex++<<".."<<daynames[TempDay.dayofWeek]<<
                      //  "\t"<<TempDay.month<<"/"<<TempDay.day<<"/"<<TempDay.year<<"\n";

                    ++daycounter;
                    

                }
        }
        



    }
    //display the vector
    for(int i=0;i<DAY.size();i++)
        std::cout<<"day # "<<i<<".."<<daynames[DAY[i].dayofWeek]<<"\t"<<DAY[i].month<<"/"<<DAY[i].day<<
                                "/"<<DAY[i].year<<"\n";


    return;



}
//==============================================================================
//                      ⁡⁣⁢⁣​‌‍‌ℂ𝕒𝕝𝕖𝕟𝕕𝕒𝕣 𝔽𝕠𝕣𝕞𝕒𝕥 𝕆𝕦𝕥𝕡𝕦𝕥​⁡

void Calendar::CalendarGrid(Calendar &myCal)     //
{
    int firstpos;
    int size=myCal.DAY.size();      //how many dates are in the vector

    std::cout<<"____________________________________________________\n";
    std::cout<<"\t\t"<<monthnames[DAY[0].month-1]<<" "<<DAY[0].year<<"\n";
    std::cout<<"____________________________________________________\n";

    std::cout<<"Sun\tMon\tTue\tWed\tThu\tFri\tSat\n";
    std::cout<<"____________________________________________________\n";
    
    // Decide where the 1st of the month should be positioned
    //left margin is SUN 0 and right is SAT 6
    int daycounter=0;

    if (myCal.DAY[0].dayofWeek==0)  //adjust for no tabs
        firstpos=0;
        else
            firstpos=myCal.DAY[0].dayofWeek-1;

    for(int i=0;i<firstpos;i++) //tab over to that spot
        std::cout<<"\t";

    for(int weeks=0;weeks<5;weeks++)
    {
        for (int days=firstpos; days<7;days++)
        {   
            std::cout<<myCal.DAY[daycounter++].day<<"\t";

        }
        std::cout<<std::endl;
        firstpos=0;

    }
    std::cout<<"____________________________________________________\n";

    std::cout<<"\n\n\n\n";

    

    return;
}