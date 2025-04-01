#include<iostream>
using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program checks if the user is allowed to drive.
 *
 * @param[in]  age        The user's age
 * @param[in]  has_car    Whether the user has a car or not
 *
 * @return     0
 */
int main(){
    int age {};
    bool has_car = false;

    cout << "Enter your age: ";
    cin >> age;
    cout << "Do you have a car? if yes enter 1 if no enter 0: ";
    cin >> has_car;

    
    if (age < 16)
    {
        int years = 16-age;
        cout << "Sorry, come back in "<< years << " years and be sure you own a car when you come back.";
    }
    else{
        if (has_car == false)
        {
            cout<< "Sorry, you need to buy a car before you can drive!";
        }
        else
        {
            cout << "Yes - you can drive!";
        }
    }


    return 0;
}