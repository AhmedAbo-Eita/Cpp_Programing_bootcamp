// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>

using namespace std;

/**
 * @brief      Calculates and displays the change for a given amount in cents.
 *
 * @details    This program prompts the user to enter an amount in cents and 
 *             calculates the equivalent change in dollars, quarters, dimes, 
 *             nickels, and pennies. It then displays the calculated values.
 *
 * @return     0
 **/

int main() {
    int amount{0};
    cout<< "Enter an amount in cents : ";
    cin >> amount;
    int res{0};

    int dollars =       amount/100;
    res =               amount%100;

    int quarters =      res/25;
    res =               res%25;

    int dimes =         res/10;
    res =               res%10;

    int nickels =       res/5;
    res =               res%5;

    int pennies =       res;
    

    cout << "dollars \t : " << dollars << endl;
    cout << "quarters \t : " << quarters << endl;
    cout << "demies \t\t : " << dimes << endl;
    cout << "nickels \t : " << nickels << endl;
    cout << "pennies \t : " << pennies << endl;


    return 0;
}


