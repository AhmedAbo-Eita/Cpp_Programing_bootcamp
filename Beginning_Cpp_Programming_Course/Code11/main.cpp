#include <iostream>

using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program shows how to use basic arithmetic operators on an integer variable.
 *
 * @return     0
 **/
int main(){
    int number {4};
    int original_number {number};

    //-- Multiply number by 2 and assign the result back to number
    number = number*2;
    cout << "number = " << number << endl;
    //-- Add 9 to number and assign the result back to number
    number = number + 9;
    cout << "number = " << number << endl;
    //-- Subtract 3 from number and assign the result back to number
    number = number - 3;
    cout << "number = " << number << endl;
    //-- Divide number by 2 and assign the result back to number
    number = number / 2; 
    cout << "number = " << number << endl;
    //-- Subtract original_number from number and assign the result back to number
    number = number - original_number;
    cout << "number = " << number << endl;
    //-- Take the modulus 3 (%) of number and assign it back to number
    number = number % 3;
    cout << "number = " << number << endl;

    return 0;
}