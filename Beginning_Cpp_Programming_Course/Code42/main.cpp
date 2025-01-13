#include <iostream>
#include <string>
#include "Dog.h"

using namespace std;


/**
 * @brief      Main function
 *
 * @details    This program demonstrates the use of a Dog class, including setting and
 *             getting attributes such as name and age, and utilizing class methods
 *             like get_human_years() and speak(). It creates multiple Dog objects
 *             using both default and overloaded constructors and prints their details.
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

    /*************************************************/

    // get human years depends on dog age
    cout <<"Human years: " << lello.get_human_years()<< endl;

    // get speak
    cout << "Speak: " << lello.speak() << endl;
    /*************************************************/
    cout<< "---------------"<<endl;
    Dog solly;//default class constructor
    cout<< "Dog name: " << solly.get_name() << endl;
    cout << "Dog age: " << solly.get_age() << endl;

    /*************************************************/
    Dog fido {"Fido", 4};
    Dog spot {"Spot", 5};
    cout<< "---------------"<<endl;
    cout<< "Dog name: " << fido.get_name() << endl;
    cout << "Dog age: " << fido.get_age() << endl;
    cout<< "---------------"<<endl;
    cout<< "Dog name: " << spot.get_name() << endl;
    cout << "Dog age: " << spot.get_age() << endl;


    return 0;
}