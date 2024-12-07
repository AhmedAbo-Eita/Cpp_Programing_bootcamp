#include <iostream>
using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program determines the eligibility of an individual applying
 *             for a job as a delivery driver. The criteria for eligibility 
 *             include being 18 years or older, or being above 15 with parental 
 *             consent, possessing a valid social security number, and having 
 *             no driving accidents.
 *
 * @return     0
 */
int main(){
    int age {15};
    bool parental_consent{1},ssn{1}, accidents{1};
    
    if ( (age >= 18 || (age>15 && parental_consent)) && ssn && accidents)//WRITE ALL YOUR CODE WITHIN THE PARENTHESES
        cout << "Yes, you can work.";


    return 0;
}