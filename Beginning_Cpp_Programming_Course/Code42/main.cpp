#include <iostream>
#include <string>
#include "Dog.h"

using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program creates a Dog object named "Lello", assigns it a name and age, 
 *             and displays them to the console using getter methods.
 *
 * @return     0
 */

int main()
{
    // define class member 
    Dog lello;

    // set the name of member and print it 
    lello.set_name("Lello");
    cout<< "Dog name: " << lello.get_name() << endl;

    // set the age of member and print it 
    lello.set_age(3);
    cout << "Dog age: " << lello.get_age() << endl;

    // get human years depends on dog age
    cout <<"Human years: " << lello.get_human_years()<< endl;

    // get speak
    cout << "Speak: " << lello.speak() << endl;

    cout<< "---------------"<<endl;

    Dog solly;//default class constructor
    cout<< "Dog name: " << solly.get_name() << endl;
    cout << "Dog age: " << solly.get_age() << endl;



    return 0;
}