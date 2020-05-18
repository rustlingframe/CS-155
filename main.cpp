/*File Name: main.cpp
 *Author: Alvaro Espinoza
 * Module:10
 * Project: 1
 * Problem Statement:
 *
 * Start with a pillbox having 10 empty slots.
 * Your job is to put 10 pills (lettered A, B, C... J) by
 * selecting a slot randomly for each pill until finding an empty slot.
 * For each pill, record the number of attempts it took to find an empty
 * slot for that pill.
 *
 *struct Pill - strcure represent Pill with char value for the letter of the pill and
 * an int for the attempts
 *          Constructors-
 *              Pill() - no arguments sets default values for char and int
 *              Pill(char letter, int attempts)- sets argument values to letter and attempts instance varibales
 * main()-
 * ALGORITHAM:
 *  1. Set the seed of the C++ random number generator
 * to create a different set of numbers each time your program is run.
 *  2. Create an array of 10 unique pointers to Pill structures
 *  3.Create a loop for which processes a single pill (lettered A, B, C... through J).
 *  4. IN LOOP: For that pill, generate another loop that creates a random number between 0 and 9.
 *  Make sure that you track the number
 *  of attempts it takes to find an open slot in the pillbox.
 *  5. IN LOOP:If the slot at that index is not available
 *  , go back and try another random number, increasing the number of attempts by 1.
 *  6.If the slot is available, then create a new Pill structure for this pill
 *  letter and the number of attempts it took to find an available slot for this pill.
 *  7.Exit the loop generating random numbers, and start looking for a slot for the next pill..
 *  8. When all 10 pills have been placed into a slot in the pillbox, print a report
 *
 *  EXTRA CREDIT ALGORITHAM:
 *  1. for loop through the array of uniquePointer structs Pill
 *  2. for in the for  loop through the array of uniquePointer structs Pill
 *  3. if letter from array index from first loop is less than the letter index in second loop swap the uniue pointers
 *  4. display the new order of the uniqiue pointer struct Pill array
 * */


#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
using namespace std;


const int ARRAY_SIZE = 10;

struct Pill
{
    char letter;
    int attempts;
    int originalPosition;
    Pill()
    {
        letter = ' ';
        attempts =0;

    }

    Pill(char letter,int attempts)
    {
        this->letter= letter;
        this->attempts = attempts;

    }

};
int main() {

    srand(time(NULL));
    unique_ptr<Pill>slotsPtr[10];
    string letters = "ABCDEFGHIJ";


    int attempts = 0;
    int randomNumber;
    bool foundSpot = false;



    for (int i =0; i < 10;i++)
    {

        attempts =1;
        foundSpot = false;

        while(!foundSpot)
        {
            randomNumber = rand()%10;
            if(slotsPtr[randomNumber] == nullptr)
            {
                unique_ptr<Pill> newPill(new Pill(letters[i], attempts)) ;
                slotsPtr[randomNumber] = move(newPill) ;
                foundSpot = true;

            }
            else
            {
                attempts++;

            }

        }


    }

    cout<<right<<"Slots"<<setw(12)<<"Pill"<<setw(12)<<"Attempts"<<endl;
    for (int i =0; i < ARRAY_SIZE;i++)
    {

        cout<<right<<i<<setw(12)<<slotsPtr[i]->letter<<setw(12)<<slotsPtr[i]->attempts<<endl;
        slotsPtr[i]->originalPosition = i;

    }


    cout<<"\nSorting the array of pointers by pill letter"<<endl;
    for(int i = 0; i < ARRAY_SIZE;i++){
        for(int j = 0; j < ARRAY_SIZE;j++){
            if(slotsPtr[i]->letter < slotsPtr[j]->letter)
            {
                slotsPtr[i].swap(slotsPtr[j]);

            }
        }
    }

    cout<<right<<"Slots"<<setw(12)<<"Pill"<<setw(12)<<"Attempts"<<endl;
    for (int i =0; i < ARRAY_SIZE;i++) {

        cout << right << slotsPtr[i]->originalPosition << setw(12) << slotsPtr[i]->letter << setw(12) << slotsPtr[i]->attempts << endl;
    }





        return 0;
}