#include <iostream>
#include <cstring>

using namespace std;

/**
 * @brief      Main function
 *
 * @details    This program calculates and displays the lengths of a first name, 
 *             last name, and the whole name combined. It uses C-style strings 
 *             to store the first and last names, concatenates them to form the 
 *             whole name, and then calculates the lengths of each using the 
 *             strlen function. The result is printed to the console.
 */

int main(){
char first_name[10] = "Bjarne";
char last_name[20] = "Stroustrup";

int first_name_length = strlen(first_name);
int last_name_length = strlen(last_name);

char whole_name[50] {};

strcpy(whole_name,first_name);
strcat(whole_name," ");
strcat(whole_name,last_name);

int whole_name_length = strlen(whole_name);


cout << "The length of the first name, " << first_name << ", is " << first_name_length << " letters long and the length of the last name, " << last_name << ", is " << last_name_length << " letters long. This means that the length of the whole name must be " << whole_name_length << " letters long.";
    return 0;
}