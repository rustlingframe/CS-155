/* SimpleVectorModified.h -
 *
 * Author:     Alvaro Espinoza Merida
 * Module:     13
 * Project:    Homework 13 , Programming Project 1
 *
 * Description:
 * Modify the SimpleVector class template presented in this chapter,
 * to include the member functions push_back and pop_back. These functions should emulate
 * the STL vector class member functions of the same name. (See Table 16-4.) The push_back function
 * should throw an exception if the array is full. The push_back function should accept an argument and
 * insert its value at the end of the array. The pop_back function should accept no argument and remove
 * the last element from the array . The pop_back function should throw an exception is the array is empty.
 *
 * ADDED Variables:
 *          int position- keeps track of the postion of where new values are added to useing the [] operator for assigment
 * MODIFIED FUNCTIONS:
 *      void push_back(T) - adds generic value to the end of the the underlying array in SimpleVectorModified class
 *      @throws ArrayFull{} - throws this exception class if the position it is being added to is larger then the arraySize
 *
 *      T pop_back - removes the last value in the end of the underlying array in the simpleVectorModified class
 *      @return - the value that was just removed from the end
 *      @throws ArrayEmpty - thows this exception class if the position variable is less then 0
 *
 *
 */

#ifndef SIMPLEVECTORMODIFIED_H
#define SIMPLEVECTORMODIFIED_H


#include <iostream>
#include <cstdlib>
using namespace std ;

template <class T>
class SimpleVectorModified {

private:
    T *aptr ;
    int arraySize ;
    int position;
    void subError() ;                     // Handles subscripts out of range

public:
    //Exception Classes
    class ArrayFull{};

    class ArrayEmpty{};

    SimpleVectorModified()                    // Default constructor
    { aptr = 0 ; arraySize = 0 ;}
    SimpleVectorModified(int) ;                   // Constructor

    SimpleVectorModified(const SimpleVectorModified &) ;  // Copy constructor
    ~SimpleVectorModified() ;// Destructor
    int size(){ return arraySize;}

    T &operator[](const int &);          // Overloaded [] operator
    void push_back(T) ;
    T pop_back() ;
} ;
//*************************************************************
//         Constructor for SimpleVector class                 *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVectorModified<T>::SimpleVectorModified(int s) {

    arraySize = s ;
    aptr = new T [s] ;

    for (int count = 0 ; count < arraySize ; count++)
        aptr[count] = T() ;
}

//************************************************
// Copy Constructor for SimpleVector class       *
//************************************************
template <class T>
SimpleVectorModified<T>::SimpleVectorModified(const SimpleVectorModified &obj) {

    arraySize = obj.arraySize ;
    aptr = new T [arraySize] ;
    for(int count = 0 ; count < arraySize ; count++)
        aptr[count] = obj[count];
}

//***************************************
// Destructor for SimpleVector class    *
//***************************************
template <class T>
SimpleVectorModified<T>::~SimpleVectorModified() {

    if (arraySize > 0)
        delete [] aptr ;
}

//*************************************************************
//              SubError function                             *
// Displays an error message and terminates the program when  *
// a subscript is out of range.                               *
//*************************************************************
template <class T>
void SimpleVectorModified<T>::subError() {

    cout << "ERROR: Subscript out of range.\n" ;
    exit(0) ;
}

//*************************************************************
//             Overloaded [] operator                         *
// This function returns a reference to the element           *
// in the array indexed by the subscript.                     *
//*************************************************************
template <class T>
T &SimpleVectorModified<T>::operator[](const int &sub) {

    if (sub < 0 || sub >= arraySize)
        subError() ;
    position = sub;
    return aptr[sub] ;
}

/**
 * void push_back(T) - adds generic value to the end of the the underlying array in SimpleVectorModified class
 * @throws ArrayFull{} - throws this exception class if the position it is being added to is larger then the arraySize
 * */
template <class T>
void SimpleVectorModified<T>::push_back(T val) {

    if(position + 1 >= arraySize){
        throw ArrayFull();
    }
    else{
        aptr[position + 1] = val;
        position++;
    }
}

/**
 *      T pop_back - removes the last value in the end of the underlying array in the simpleVectorModified class
 *      @return - the value that was just removed from the end
 *      @throws ArrayEmpty - thows this exception class if the position variable is less then 0
 * */
template <class T>
T SimpleVectorModified<T>::pop_back() {

    if(position <= 0){
        throw ArrayEmpty();
    }
    else{
        aptr[position] = T();
        position--;
    }
    return aptr[position];
}

#endif