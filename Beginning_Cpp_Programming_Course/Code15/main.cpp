#include <iostream>
using namespace std;


/**
 * @brief      Main function
 *
 * @details    This program takes an integer age from the user and outputs whether the user is old enough to drive.
 *
 * @return     0
 **/
int main() {
    int age {};
    //taking age from user
    cout << "Enter your age: ";
    cin >> age;
    //explain if the driver can drive or not 

    if (age >= 16)
    {
        cout << "Yes - you can drive!";
    }
    else
    {
        int n_years = 16 - age;
        cout << "Sorry, come back in " << n_years << " years" ;
    }

    return 0;
}