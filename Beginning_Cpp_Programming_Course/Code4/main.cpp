/************************************ 
*auther: Ahmed Aboeita
*date: 9/11/2024
* In this exercise, you will write code using cin 
*and the extraction operator >> 
*to allow a user to enter their date of birth. 
**************************************/

#include <iostream>
using namespace std;

void date_of_birth() {
    int m {};
    int d {};
    int y {};
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //---- WRITE YOUR CODE BELOW THIS LINE----
    
    // Assume that the user will enter their date of birth 
    // in the order of month, day, year,
    cout << "Enter your birthday in Month/day/year serateted by space: ";
    cin >> m >> d >> y;
    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- Do NOT MODIFY THE CODE BELOW THIS LINE----
    cout << m << " " << d << " " << y;
}

int main(){
    date_of_birth();
    return 0;
}