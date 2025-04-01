#include <iostream>
#include <string>
using namespace std;

void employee_profile() {
   
    string name;
    int age;
    double hourly_wage {23.50};
    
    // Take the name and age from user
    cout << "Enter your first name and age separated by space : ";
    cin >> name >> age; 
    cout << name << " " << age << " " << hourly_wage;
}

int main(){
    employee_profile(); 
    return 0;
}