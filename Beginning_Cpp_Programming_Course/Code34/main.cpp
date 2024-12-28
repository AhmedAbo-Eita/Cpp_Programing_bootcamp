#include <iostream>
using namespace std;

int function_activation_count {0};

double a_penny_doubled_everyday(int , double);


int main(){

    int n {0};
    double amount {0.0};
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter amount: ";
    cin >> amount;
    cout << "The total amount is: " << a_penny_doubled_everyday(n, amount) << endl;
    a_penny_doubled_everyday(n, amount);
    return 0;
}

double a_penny_doubled_everyday(int n , double amount)
{
    if (n <= 1)
        return amount;
    return a_penny_doubled_everyday(--n, amount*2); 
}
