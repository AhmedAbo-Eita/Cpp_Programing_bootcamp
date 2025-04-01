#include <iostream>
using namespace std;

void print_grocery_list(int apples = 3,int oranges = 7,int mangos = 13);

/**
 * @brief      Main function
 * @details    This program demonstrates the use of default arguments in a function. 
 *             It calls the print_grocery_list function with different numbers of arguments to 
 *             showcase how default parameters can be overridden. 
 *             The first call uses all default values, 
 *             the second call overrides the default for apples, and 
 *             the third call overrides the defaults for apples and oranges.
 */

int main(){
    print_grocery_list();
    print_grocery_list(5);
    print_grocery_list(7,11);



    return 0;
}

void print_grocery_list( int apples ,int oranges,int mangos )
{
    cout << apples << " apples" << "\n" << oranges << " oranges" << "\n" << mangos << " mangos" << "\n";
}