/* BCheckString.cpp -
 *
 * Author:     Alvaro Espinoza Merida
 * Module:     13
 * Project:    Homework 13 , Programming Project 1
 *
 * Description:
 *a class BCheckString that is derived from the STL string class. This new class will have two member functions:
 *
 * A BCheckString (string s) constructor that receives a string object passed by value
 * and passes it on to the base class constructor.
 *
 * A char operator [ ] (int k) function that throws a BoundsException object
 * if k is negative or is greater than or equal to the length of the string. If k is within the bounds of the string, this function will return the character at position k in the string.
 *
 * Constructor:
 *      BCheckString()- no argument constructor
 *
 *      BCheckString(string s)- constructor that receives a string object passed by value and passes it on to the base class constructor.
 *      @arg string inputString - string value that is passed on to the base constrcutor of the super class
 *
 * Functions:
 *      char operator[](int)- returns the char value of the string at the specified int value in the array
 *      @arg int: index value
 *      @return char: char value at specified index value in array
 *
 *
 */
#include <iostream>
#include "BCheckString.h"
/**
 *      BCheckString(string s)- constructor that receives a string object passed by value and passes it on to the base class constructor.
 *      @arg string inputString - string value that is passed on to the base constrcutor of the super class
 * */
BCheckString::BCheckString(const std::string inputString) : std::string(inputString){}
/**
 * BCheckString()- no argument constructor
 * */
BCheckString::BCheckString() : std::string(){}

/**
 *  char operator[](int)- returns the char value of the string at the specified int value in the array
 *      @arg int: index value
 *      @return char: char value at specified index value in array
 * */
char BCheckString::operator[](int index) {

    if(index < 0 || this->length() <= index)
    {
        throw BoundsException();
    }
    else
        {
            return std::string::operator[](index);
        }

}