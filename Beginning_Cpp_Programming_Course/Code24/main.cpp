#include<iostream>
#include<string>
using namespace std;


/**
 * @brief      Main function
 *
 * @details    This program takes a string of a full name without a space and
 *             reformats it to have a space. The program uses the insert() function
 *             to put a space between the first and last names.
 *
 * @return     0 if the program runs correctly
 */

int main(){
    string unformatted_full_name {"StephenHawking"};
    string first_name(unformatted_full_name,0,7);
    string last_name(unformatted_full_name,7,7);

    string formatted_full_name {};
    formatted_full_name = first_name + last_name;


    formatted_full_name.insert(7," ");

    cout <<  formatted_full_name << endl;

    return 0;
}