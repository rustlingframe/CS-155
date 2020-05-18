#include <iostream>
#include <vector>
#include "BCheckString.h"


int main() {

    BCheckString string;
    std::vector<int> vector;
    vector.pop_back();
    char indexValuel;
    int index;

    while(true){
        std::cout<<"Enter a String:"<<std::endl;
        getline(std::cin,string);

        if(string.length() > 0){

            std::cout<<"Enter a char index:"<<std::endl;
            std::cin >>index;

            try {
                indexValuel = string[index];
                std::cout<<indexValuel<<std::endl;

            }
            catch (BCheckString::BoundsException &ex){
                std::cout<<"Char index out of range"<<std::endl;
            }


        }
        return 0;

    }
}