#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief      Main function
 * @details    This program will be used as a POS (Point of Sale) system in a restaurant. The bill_total is given as well as the number_of_guests. The 5 guests will be splitting the bill evenly and so the individual_bill will be bill_total / number_of_guests. The POS will be used in three different locations, each with different guidelines for printing bills.
 *             At location 1, individual_bill_1 always rounds down to the nearest dollar.
 *             At location 2, individual_bill_2 always rounds to the nearest dollar.
 *             At location 3, individual_bill_3 always rounds up to the nearest cent.
 *             Determine what the individual_bill will be at each of the locations.
 * @return     0
 */
int main(){
    double bill_total {102.78};
    int number_of_guests {5};

    double individual_bill_1 {};
    double individual_bill_2 {};
    double individual_bill_3 {};

    individual_bill_1 = floor(bill_total/number_of_guests);
    individual_bill_2 = round(bill_total/number_of_guests);
    individual_bill_3 = ceil((bill_total/number_of_guests)*100)/100;

    cout << "The individual bill at location 1 will be $" << individual_bill_1 << "\n" << "The individual bill at location 2 will be $" << individual_bill_2 << "\n" << "The individual bill at location 3 will be $" << individual_bill_3;

    return 0;
}