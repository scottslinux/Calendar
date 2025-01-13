#include <iostream>
#include "Calendar.h"
using namespace std;


void daychecker(Calendar myCal)
{
    int a,b,c;

    system("clear");
    std::cout<<"************************************************************\n";
    std::cout<<"Enter a date to find out what day of the week it fell on\n";
    std::cout<<"************************************************************\n";

    std::cout<<"Enter month: ";
    std::cin>>a;
    std::cout<<"Enter day: ";
    std::cin>>b;
    std::cout<<"Enter year: ";
    std::cin>>c;
    int d=myCal.DayfinderJan1(a,b,c);
    std::cout<<a<<"/"<<b<<"/"<<c<<" fell on a "<<myCal.daynames[d]<<"\n\n" ;
    std::cout<<"************************************************************\n";




}
//=====================================================================================
void createcal(Calendar myCal)
{
    system("clear");
    std::cout<<"Enter the year: ";
    int year;
    std::cin>>year;
    myCal.CreateCalendar(year);




    return;
}
//=====================================================================================
void loading(Calendar myCal)
{
    int start=2024; //defaults
    int dur=3;

    system("clear");
    std::cout<<"Enter the year: ";
    std::cin>>start;
    std::cout<<"Time Span (years): ";
    std::cin>>dur;

    myCal.loadCalendar(start,dur);

    return;

}






//=====================================================================================

int main()
{
    //cout<<"Hello World..."<<endl;

    Calendar myCal;

    std::cout<<"************************************************\n";
    std::cout<<"a.  Check the day of the week for a given date\n";
    std::cout<<"b.  Construct a year and display the dates\n";
    std::cout<<"c.  Construct a Calendar and display the dates\n";

    std::cout<<"************************************************\n";
    std::cout<<"Enter Choice: ";
    std::string choice;
    std::cin>>choice;

    if (choice=="a")    daychecker(myCal);
    if (choice=="b")    createcal(myCal);
    if (choice=="c")    loading(myCal);

        else
            std::cout<<"wawawa....\n\n\n";






    


    return 0;
}
