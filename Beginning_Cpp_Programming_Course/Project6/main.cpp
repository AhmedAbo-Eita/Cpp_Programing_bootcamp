/*********************************************************/
//*********Cleaning Service Calculator Challenge*********//
/********************************************************/


#include <iostream>
using namespace std;

//cost of cleaning rooms depends on its size
const double price_small_room = 25;
const double price_large_room = 35;
// cost of tax
const double tax = .06;

//validation 
const int validation = 30;

int main()
{
    // Welcome message
    cout << "Estimate for Carpet Cleaning Service\n";
    

    // input number of rooms
    int num_of_large_rooms;
    int num_of_small_rooms;

    // take input from user number of small rooms and large rooms 
    cout << "Enter the number of Large rooms: ";
    cin >> num_of_large_rooms;


    cout << "Enter the number of small rooms: ";
    cin >> num_of_small_rooms;


    //calculate cost of cleaning
    double price_of_large_rooms = num_of_large_rooms*price_large_room; 
    double price_of_small_rooms = num_of_small_rooms*price_small_room;
    double total_cost = price_of_large_rooms+price_of_small_rooms;

    //calculate cost of tax
    double tax_of_large_rooms = tax * price_of_large_rooms;
    double tax_of_small_rooms = tax * price_of_small_rooms;
    double total_tax = tax_of_large_rooms + tax_of_small_rooms;

    

    //print messages 
    cout << "Price per small room = $" << price_small_room << endl;
    cout << "Price per large room = $" << price_large_room << endl;

    cout << "Cost = $"<< total_cost <<endl;
    cout << "Tax = $" << total_tax << endl;

    cout << "======================================\n";

    cout << "Total estimate = $" << total_cost+total_tax << endl;
    
    cout << "This estimate is valid for "<< validation << " days\n";



    return 0;
}
