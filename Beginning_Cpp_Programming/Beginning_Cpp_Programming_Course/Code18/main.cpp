// For loop - Sum of Odd Integers
// Write code that uses a for loop to calculate the sum of the odd integers from 1 to 15,
//inclusive. The final result should be stored in an integer variable named sum .

#include <iostream>
using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program calculates the sum of all odd numbers from 1 to 15, 
 *             inclusive, using a for loop and stores the result in an integer 
 *             variable named sum. It then displays the final sum.
 *
 * @return     0
 **/

int main (){
    // initialization of the counter 
    int counter = 0;
    int sum = 0;
    for (counter=1;counter<=15; counter++)
    {
        if (counter%2==1)
        {
            sum+=counter;
        }
    }
    cout << "The sum = " << sum << endl; 
    return 0;
} 