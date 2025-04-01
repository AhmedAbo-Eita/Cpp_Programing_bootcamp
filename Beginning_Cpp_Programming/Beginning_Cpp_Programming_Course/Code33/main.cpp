#include <iostream>
using namespace std;


/**
 * @brief      Calculates the sum of the digits of a given number
 *
 * @param[in]  n     The number to calculate the sum of digits for
 *
 * @return     The sum of the digits of n
 */
int sum_of_digits(int n) {
    if(n==0)
    {
        return 0;
    }
    return (n%10) + sum_of_digits(n/10);
}


int main(){
    cout << sum_of_digits(1000);
    return 0;
}