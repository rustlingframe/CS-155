/* Sequence Accumulation.cpp -
 *
 * Author:     Alvaro Espinoza Merida
 * Module:     13
 * Project:    Lab , Programming Project 2
 *
 * Description: a program that forms and returns the "sum" of all items in the vector v
 * passed to it.  For example, if T is a numeric type such as int or double, the numeric sum
 * will be returned, and if T represents the STL string type, then the result of concatenation
 * is returned.
 *
 * Functions:
 *
 * T accum(vector<T> vector)- function that adds all the values of the vector
 * @arg- vector of generic type
 * return- sum of all vector values added or concatenated together
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;
template <typename T>

/**
 * T accum(vector<T> vector)- function that adds all the values of the vector
 * @arg- vector of generic type
 * return- sum of all vector values added or concatenated together
 * @tparam T */
T accum(vector<T> vector){

    T sum = T();
    for(auto iter = vector.begin(); iter != vector.end();iter++){
        sum += *iter;
    }
    return sum;

}

int main()
{
    //For loop from 0 - 4 to get four user input numbers and put values into a vector
    cout<<"Enter four numbers to be added together: "<<endl;
    vector<int> intVector;
    double input;
    for(int i = 0; i < 4 ;i++){

        cout<<"Enter "<<i+1<<" number:"<<endl;
        cin>>input;
        intVector.push_back(input);
    }

    cout<<"Sum of all numbers: "<<accum(intVector)<<"\n"<<endl;

    //For loop from 0 - 4 to get four user input strings and put values into a vector
    cout<<"Enter four strings to be concatenated together: "<<endl;
    vector<string> stringVector;
    string stringInput;
    getline(cin,stringInput);

    for(int i = 0; i < 4 ;i++){

        cout<<"Enter "<<i+1<<" string:"<<endl;
        getline(cin,stringInput);
        stringVector.push_back(stringInput);
    }

    cout<<"Concatenated string: "<<accum(stringVector)<<endl;

}






