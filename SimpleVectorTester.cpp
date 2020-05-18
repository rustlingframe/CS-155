/* SimpleVectorTester.cpp -
 *
 * Author:     Alvaro Espinoza Merida
 * Module:     13
 * Project:    Homework 13 , Programming Project 3
 *
 * Description: Tester file that runs programming challenges 2 and 3 from homework
 *
 *Project 2 ALGORITHAM:
 * 1. create two vectors of the size 10 one for holding doubles and the other strings
 * 2. loop through double vector and add vlaues by muliplyting loop index by 8.76 EXIT LOOP
 * 3. in same loop intialize string vector values to index cast to string
 * 4. loop through both arrays and display values string should show postion and double a value EXIT LOOP
 * 5. ask for userinput for a double value and string value that will be used for position
 * 6. try double vector push_back on double value from user input
 * 7. catch ArrayFull Exception
 * 8. try string vector push_back on string value from user input
 * 9. catch ArrayFull Exception
 * 10.try for loop from 0 to SIZE + 1 and use pop_back function on both SortableVectors
 *
 * EXTRA CREDIT:
 * ALGORITHAM:
 * 1. CRREATE two SortableVector objects one holding strings the other doubles
 * and two arrays not in order of random name and doubles
 * 2.for loop from 0 to SIZE and add values from arrays to there respective vectors
 * 3. DISPLAY EACH unsorted vectors data
 * 4. call sort() on both vectors
 * 5. display both arrays
 *
 */

#include "SimpleVectorModified.h"
#include "SortableVector.h"
#include <iostream>

int main(){
    const int SIZE = 10;

    //creating SimpleVectorModifieid objects for testing
    SimpleVectorModified <double> doubleVector(SIZE);
    SimpleVectorModified <string> stringVector(SIZE);

    for(int i = 0; i < SIZE;i++){
        doubleVector[i] = i *8.76;
        stringVector[i] = std::to_string(i);
    }

    cout<<"Printing the vectors for problem 2:"<<endl;
    for(int i = 0; i < SIZE;i++){
       cout<<"Position:"<<stringVector[i]<<":"<<doubleVector[i]<<endl;
    }

    double value;
    std:: string position;
    cout<<"Enter a value:"<<endl;
    cin>>value;
    cout<<"Enter the position in string"<<endl;
    cin>>position;

    try {
        doubleVector.push_back(value);
    }
    catch (SimpleVectorModified<double>::ArrayFull){
        cout<<"ERROR: Array is FULL"<<endl;
    }
    try {
        stringVector.push_back(position);
    }
    catch (SimpleVectorModified<std::string>::ArrayFull){
        cout<<"ERROR: Array is FULL"<<endl;
    }

    cout<<"DELETEING ALL VALUES TO GET EXCEPTION TO ERASED"<<endl;
    try{
        for(int i = 0; i < SIZE+1;i++){
            stringVector.pop_back();
        }
        for(int i = 0; i < SIZE+1;i++){
            doubleVector.pop_back();
        }
    }
    catch (SimpleVectorModified<std::string>::ArrayEmpty){
        cout<<"\nERROR: Array is EMPTY"<<endl;
    }

    cout<<"********EXTRA CREDIT***********"<<"\n"<<endl;
    SortableVector<double> extraCreditDoubleVector;
    SortableVector<std::string> extraCreditStringVector;
    double array[SIZE] = {2,5,9,23,16,3,7,4,6,1};
    string nameArray[SIZE] = {"Alfredo","Lily","Brandon","Zion","Alvaro","Richard","David","Daphne","Cole","Kendrick"};

    for(int i = 0; i < SIZE;i++){
        extraCreditDoubleVector.push_back(array[i]);
        extraCreditStringVector.push_back(nameArray[i]);
    }

    cout<<"Unsorted double Array: "<<endl;
    for(int i = 0 ; i < SIZE; i++){
        cout<<extraCreditDoubleVector[i]<<" ";
    }
    cout<<"\n"<<endl;

    cout<<"Unsorted string Array: "<<endl;
    for(int i = 0 ; i < SIZE; i++){
        cout<<extraCreditStringVector[i]<<" ";
    }
    cout<<"\n"<<endl;

    extraCreditDoubleVector.sort();
    extraCreditStringVector.sort();

    cout<<"Sorted double Array: "<<endl;
    for(int i = 0 ; i < extraCreditDoubleVector.size(); i++){
        cout<<extraCreditDoubleVector[i]<<" ";
    }
    cout<<"\n"<<endl;

    cout<<"Sorted string Array: "<<endl;
    for(int i = 0 ; i < extraCreditStringVector.size(); i++){
        cout<<extraCreditStringVector[i]<<" ";
    }

}

