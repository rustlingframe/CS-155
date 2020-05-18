/* Square.cpp -
 *
 * Author:     Alvaro Espinoza Merida
 * Module:     13
 * Project:    Lab , Programming Project 1
 *
 * Description:
 *
 * Write a function that accepts an integer parameter and returns its integer square root (if it exists).  The function should throw an exception if it is passed an integer that is not a perfect square.
 * Do not handle the exception in the function, but instead create the exception handler in main.
 * Make the exception a new exception class which your program creates.
 *
 *
 * Exceptions: ArithmeticException{}- thrown if there is arithmetic exception and if number is not a perfect square
 *
 * Functions:
 * bool isPerfectSquare(long double value)- checks if a numeric value is a perfect square throws an exception if it is not
 * @arg- number value checked
 * @return- int value showing the perfect square
 *
 */
#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "math.h"

using namespace std;

class Square{

    private:
        long double number;

    public:

        //exception class used for notifying if there is an arithmetic exception
        class ArithmeticException{};

        Square(){}

        /**
         * bool isPerfectSquare(long double value)- checks if a int value is a perfect square throws an exception if it is not
         * * @arg- number value checked
         * * @return- int value representing perfect square
         * */
        int isPerfectSquare(long double value)
        {
            long double sqr = sqrt(value);

            if(!(sqr-floor(sqr))==0){
                throw ArithmeticException();
            } else{
                return (int)sqr;
            }
        }
};

int main (){

    Square square;

    //for loop from 0 to 25 so index value is used in isPerfectSquare() value
    for(int i = 0; i <= 25;i++){

        try{

            cout<<"Value: "<<i<<" is perfect square:"<<square.isPerfectSquare(i)<<endl;
        }
        catch(Square::ArithmeticException){
            cout<<"NOT A PERFECT SQUARE"<<endl;
        }
    }
}




#endif
