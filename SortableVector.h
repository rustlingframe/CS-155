/* SortableVector.h -
 *
 * Author:     Alvaro Espinoza Merida
 * Module:     13
 * Project:    Homework 13 , Programming Project 3
 *
 * Description:
 * Write a class template named SortableVector.
 * The class should be derived from the SimpleVector class presented in this chapter.
 * It should have a member function that sorts the array elements in ascending order.
 * (Use the sorting algorithm of your choice.)
 *
 * CONSTRUCTOR:
 *          SortableVector():SimpleVector<T>(){} - default constructor creates a default constructor from superclass
 *          SortableVector(int size): SimpleVector<T>(size)- creates a vector the size of the int argument creates object using
 *          super class intstructor
 *
 * FUNCTIONS:
 *          void sort - sorts the vector using a selection sort algorithm

 *
 */

#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H

#include "SimpleVector.h"

#include <iostream>
using namespace std ;

template <class T>
class SortableVector : public SimpleVector<T>{

    public:
    //Default Constructor
    SortableVector():SimpleVector<T>(){};
    //Constructor
    SortableVector(int size):SimpleVector<T>(size){};

    void sort();



};
/**
 * void sort - sorts the vector using a selection sort algorithm
 * ALGORITHAM:
 * 1. for loop for 0 to size of underlying array
 * 2. nested for loop for each index of the array
 * 3. compare first for loop index varieable with second for loop index to see if first index is less than second index
 * 4. if  first index is less than second switch values at each postition
 *
 * */
template<class T>
void SortableVector<T>::sort() {

    for(int i = 0; i < this->size();i++ )
    {
        for(int j = 0;j < this->size();j++)
        {
            if(this->operator[](i) < this->operator[](j)){
                T temp = this->operator[](i);
                this->operator[](i) = this->operator[](j);
                this->operator[](j) = temp;

            }
        }
    }
}


#endif
