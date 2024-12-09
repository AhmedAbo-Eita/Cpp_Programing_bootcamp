// Day Code	Display
// 0	Sunday
// 1	Monday
// 2	Tuesday
// 3	Wednesday
// 4	Thursday
// 5	Friday
// 6	Saturday
// other	Error - illegal day code

#include <iostream>
using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program takes an integer day code from the user and outputs the day of the week.
 *
 * @return     0
 **/
int main()
{
    int day_code {};
    
    cout << "Enter the day code: ";
    cin >> day_code;

    switch (day_code) {
        case 0:
            cout << "Sunday";
            break;
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        default: 
            cout << "Error - illegal day code";
    }

    return 0;
}