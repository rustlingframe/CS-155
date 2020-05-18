/*File Name: main.cpp
 *Author: Alvaro Espinoza
 * Module:10
 * Project: 2
 * Problem Statement:
 * In this lab you will manipulate a time variable and corresponding structure,
 * print today's date and time in various formats, and determine how to adjust the
 * internal form of other dates.
 *
 *
 * ALGORITHM:
 *
 * 1. create tm object for the local time right
 * 2. display tm object variables in various outputs for the representation of time
 * 3. create tm object for my birthday
 * 4.set variables for the tm object of my birthday to approopiate values
 * 5. call mkTime variable with birthday object address as argument
 *
 * */


#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
using namespace std;

const int ARRAY_SIZE = 10;
const string WEEKS[] = {"SUNDAY","MONDAY","TUESDAY","WEDENSDAY","THURSDAY","FRIDAY","SATURDAY"};

const string MONTHS[] = {"JANUARY","FEBRUARY","MARCH",
                         "APRIL","MAY","JUNE","JULY",
                         "AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};



time_t now = time(NULL);
const int YEAR_1900=1900;
const int YEAR_2000= 2000;
int timeInWeek;
int main() {


    tm *local = localtime(&now);

    // prints date in this format 1/1/20 (m/d/yy)
    cout<< local->tm_mon+1<<"/"<<local->tm_mday<<"/"<<(YEAR_1900+local->tm_year)-YEAR_2000<<endl;
    //prints date January 1, 2020
    cout<< MONTHS[local->tm_mon]<<","<<local->tm_mday<<","<<(YEAR_1900+local->tm_year)-YEAR_2000<<endl;
    //prints the date in this format 1-Jan-2020
    cout<<local->tm_mday<<"-"<<MONTHS[local->tm_mon].substr(0,3)<<"-"<<YEAR_1900+local->tm_year<<endl;
    //prints the time in this format 17:30
    cout<<local->tm_hour<<":"<<local->tm_min<<endl;

    //prints time in this format 5:30pm / 12:00am
    if(local->tm_hour > 12)
    {
        cout<<(local->tm_hour-12)<<":"<<local->tm_min<<"pm"<<"/"<<"12:00 am"<<endl;
    }
    else
    {
        cout<<(12-local->tm_hour)<<":"<<local->tm_min<<"am"<<"12:00pm"<<endl;
    }

    //tm object being created to represent my birhtday
    tm birthday;

    birthday.tm_year = 1999-1900;
    birthday.tm_mon = 3;
    birthday.tm_mday = 27;
    birthday.tm_hour = 20;
    birthday.tm_min = 36;
    birthday.tm_sec = 34;
    birthday.tm_isdst = 0;
    //displays how many seconds after epoch I was born
    //mkTime() displays the date of birth along wiht time
    //ctime displays the number of seconds born after epoch
    time_t timeOfBirthday = mktime(&birthday) ;
    cout <<endl<< ctime(&timeOfBirthday) << endl
         << "I was born " << timeOfBirthday
         << " seconds after epoch!" << endl ;

    timeInWeek =604800;

    //displays how many seconds after epoch I was born
    //mkTime() displays the date of birth along wiht time
    //ctime displays the number of seconds born after epoch
    time_t weekBeforeTimeOfBirthday = mktime(&birthday) ;
    cout <<endl<< ctime(&weekBeforeTimeOfBirthday) << endl
         << "A weeek before I was born " << weekBeforeTimeOfBirthday - timeInWeek
         << " seconds after epoch!" << endl ;


    return 0;
}



