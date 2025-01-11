#include <iostream>
#include <string>
using namespace std;

class Dog{
public:

string name;
int age {0};


};
/**
 * @brief      Main function
 *
 * @details    This program creates a Dog object, assigns it a name and age, and displays them to the console.
 *
 * @return     0
 */
int main()
{   

    Dog spot;
    spot.name = "Spot";
    spot.age = 5;

    cout << "Dog name: " << spot.name << endl;
    cout << "Dog age: " << spot.age << endl;

    
    return 0;
}
