#include <iostream>

using namespace std;
int main(){
    // Variable to store the input number
    int favorite_number;

    // Take input from user
    cout << "Enter your favorite number between 1 and 100 =  ";
    cin >> favorite_number;

    // Write message to user
    cout << "Amazing, That is my favorite number too. " << endl;

    cout << "No really, " << favorite_number << " is my favorite number." << endl;

    return 0;

}